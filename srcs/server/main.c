/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarboni <scarboni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 18:54:29 by scarboni          #+#    #+#             */
/*   Updated: 2021/09/27 15:53:38 by scarboni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../main.h"

void	sig_handler(int signum)
{
	ft_putstr_fd("Ah que cc bob\nBye!\n", STDIN_FILENO);
}

int	main(int argc, char const *argv[])
{
	(void)argc;
	(void)argv;
	struct sigaction act, old_act;
	act.sa_handler = sig_handler;
	ft_putstr_fd("Hello, i'm the server :", STDIN_FILENO);
	ft_putnbr_fd(getpid(), STDIN_FILENO);
	ft_putstr_fd("!\n", STDIN_FILENO);
	printf("RESULT %d \n", sigaction(SIGUSR1, &act, NULL));
	while (true)
		pause();
	ft_putstr_fd("Bye!\n", STDIN_FILENO);
	return (0);
}
