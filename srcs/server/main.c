/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarboni <scarboni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 18:54:29 by scarboni          #+#    #+#             */
/*   Updated: 2021/09/28 11:04:43 by scarboni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../main.h"

void	sig_sigaction(int signum, siginfo_t *info, void* context)
{
	static unsigned long	bits;
	static unsigned char	letter;
	static unsigned char	prev_letter;
	static int				prev_pid;

	(void)context;
	if (prev_pid != 0 && prev_pid != info->si_pid){
		prev_letter = 0;
		letter = 0;
		bits = 0;
	}
	prev_pid = info->si_pid;
	if (signum != SIGUSR1 && signum != SIGUSR2)
		return ;
	if (signum == SIGUSR1)
		letter = letter | 1 << bits ;
	bits ++;
	if (bits >= BYTE_SIZE * sizeof (char))
	{
		if (letter == 0)
			ft_putstr_fd("\n", STDIN_FILENO);
		else
			ft_putchar_fd(letter, STDIN_FILENO);
		if (letter == '!' && prev_letter == 'q')
			exit(EXIT_SUCCESS);
		prev_letter = letter;
		letter = 0;
		bits = 0;
	}
}

int	main(int argc, char const *argv[])
{
	struct sigaction	act;

	(void)argc;
	(void)argv;
	act = (struct sigaction){};
	act.sa_sigaction = sig_sigaction;
	act.sa_flags = SA_SIGINFO;
	ft_putstr_fd("Hello, i'm the server : ", STDIN_FILENO);
	ft_putnbr_fd(getpid(), STDIN_FILENO);
	ft_putstr_fd(" !\n", STDIN_FILENO);
	if ((sigaction(SIGUSR1, &act, NULL) | sigaction(SIGUSR2, &act, NULL))
		!= EXIT_SUCCESS)
	{
		ft_putstr_fd("An error occured while setting sigactions\n",
			STDIN_FILENO);
		return (-EXIT_FAILURE);
	}
	while (true)
		pause();
	return (EXIT_SUCCESS);
}
