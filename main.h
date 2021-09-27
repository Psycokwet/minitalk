/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarboni <scarboni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 18:54:29 by scarboni          #+#    #+#             */
/*   Updated: 2021/05/06 09:33:00 by scarboni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

# define BYTE_SIZE 8

# include <stddef.h>
# include <stdbool.h>

# include <signal.h>
// typedef void (*sighandler_t)(int);

// sighandler_t signal(int signum, sighandler_t handler);
// int sigemptyset(sigset_t *set);
// int sigaddset(sigset_t *set, int signum);
// int sigaction(int signum, const struct sigaction *act, struct sigaction *oldact);

# include <sys/types.h>
// int kill(pid_t pid, int sig);
// pid_t getpid(void);

#include <stdlib.h>
//void *malloc(size_t size);
//void free(void *ptr);
//void exit(int status);
   
# include <unistd.h>
//ssize_t write(int fd, const void *buf, size_t count);
// int pause(void);
// unsigned int sleep(unsigned int seconds);
// int usleep(useconds_t usec);


int		ft_atoi(const char *str);
int		ft_isdigit(int c);
char	*ft_itoa(int n);

void	ft_putstr_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
size_t	ft_strlen(const char *s);
void	ft_putchar_fd(char c, int fd);

int		ft_strncmp(const char *s1, const char *s2, size_t len_mx);
int		parse_value(char const *arg, int *result);

int	send_zero(int server_pid);
int	send_one(int server_pid);
int	send_null(int server_pid);
int	send_letter(int server_pid, char letter);

#endif
