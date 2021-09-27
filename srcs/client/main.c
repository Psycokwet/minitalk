/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarboni <scarboni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 18:54:29 by scarboni          #+#    #+#             */
/*   Updated: 2021/09/27 18:09:17 by scarboni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../main.h"

int	send_zero(int server_pid)
{
	return (kill(server_pid, SIGUSR2));
}

int	send_one(int server_pid)
{
	return (kill(server_pid, SIGUSR1));
}

int	send_null(int server_pid)
{
	int	i;

	i = 0;
	while (i < BYTE_SIZE)
	{
		if (send_zero(server_pid) != EXIT_SUCCESS)
			return (-EXIT_FAILURE);
		i++;
	}
	return (EXIT_SUCCESS);
}
int	send_letter(int server_pid, char letter)
{
	int	i;
	int	ret;

	i = 0;
	while (i < BYTE_SIZE)
	{
		if ((letter >> i) & 1)
			ret = send_one(server_pid);
		else
			ret = send_zero(server_pid);
		if (ret != EXIT_SUCCESS)
			return (ret);
		i++;
	}
	return (EXIT_SUCCESS);
}

void	start_client(int server_pid, char const *msg)
{
	size_t	length_msg;
	size_t	i;

	length_msg = ft_strlen(msg);
	i = 0;
	ft_putstr_fd("Hello, i'm the client\n", STDIN_FILENO);
	while (i < length_msg)
	{
		if (send_letter(server_pid, msg[i]) != EXIT_SUCCESS)
		{
			ft_putstr_fd("ERROR !\n", STDIN_FILENO);
			exit(-EXIT_FAILURE);
		}
		i++;
	}
	if (send_null(server_pid) != EXIT_SUCCESS)
	{
		ft_putstr_fd("ERROR !\n", STDIN_FILENO);
		exit(-EXIT_FAILURE);
	}
	ft_putstr_fd("Message sent with success !\n", STDIN_FILENO);
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
	return (EXIT_SUCCESS);
}
