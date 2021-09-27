/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarboni <scarboni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 18:54:29 by scarboni          #+#    #+#             */
/*   Updated: 2021/09/27 22:56:13 by scarboni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../main.h"

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
		ft_putstr_fd("Error. Usage : ./client [SERVER_PID] [MSG]\n",
			STDIN_FILENO);
		return (-EXIT_FAILURE);
	}
	server_pid = ft_atoi(argv[1]);
	if (parse_value(argv[1], &server_pid) != EXIT_SUCCESS)
	{
		ft_putstr_fd("Error. The second parameter is not a valid pid Usage :\
 ./client [SERVER_PID] [MSG]\n", STDIN_FILENO);
		return (-EXIT_FAILURE);
	}
	start_client(server_pid, argv[2]);
	return (EXIT_SUCCESS);
}
