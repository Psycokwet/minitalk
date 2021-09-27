/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarboni <scarboni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 18:54:29 by scarboni          #+#    #+#             */
/*   Updated: 2021/09/27 15:52:39 by scarboni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../main.h"

void	start_client(int server_pid, char const *msg)
{
	ft_putnbr_fd(server_pid, STDIN_FILENO);
	ft_putstr_fd("Hello, i'm the client :", STDIN_FILENO);
	ft_putnbr_fd(getpid(), STDIN_FILENO);
	ft_putstr_fd("!\n", STDIN_FILENO);
	printf("%d result\n", kill(server_pid, SIGUSR1));
	// printf("%d result\n", kill(server_pid, SIGUSR2));
}

int	main(int argc, char const *argv[])
{
	int	server_pid;

	if (argc != 3)
	{
		ft_putstr_fd("Error. Usage : ./client [SERVER_PID] [MSG]\n", STDIN_FILENO);
		return (-EXIT_FAILURE);
	}
	server_pid = ft_atoi(argv[1]);
	if (parse_value(argv[1], &server_pid) != EXIT_SUCCESS)
	{
		ft_putstr_fd("Error. The second parameter is not a valid pid Usage : ./client [SERVER_PID] [MSG]\n", STDIN_FILENO);
		return (-EXIT_FAILURE);
	}
	start_client(server_pid, argv[2]);
	return (0);
}
