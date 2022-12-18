/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmiseiki <vmiseiki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 17:39:28 by vmiseiki          #+#    #+#             */
/*   Updated: 2021/09/25 12:53:10 by vmiseiki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_signal(int sig)
{
	(void)sig;
	write(1, "--------------------------------------------------\n", 51);
	write(1, "Message send. Confirmation from server recieved...\n", 51);
	write(1, "--------------------------------------------------\n", 51);
	exit(EXIT_SUCCESS);
}

int	ft_send_message(char *str, int pid)
{
	int				i;
	int				j;
	unsigned int	value;

	i = 0;
	while (str[i] != '\0')
	{
		j = 0;
		value = str[i];
		while (j < 8)
		{
			if (value % 2 == 1)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			value = value / 2;
			usleep(100);
			j++;
		}
		i++;
	}
	return (0);
}

int	ft_end_of_message(int pid)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		i++;
		kill(pid, SIGUSR1);
		usleep(100);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	int		pid;
	char	*client_pid;

	if (argc != 3)
		return (0);
	pid = ft_atoi(argv[1]);
	if (pid < 1)
		return (0);
	signal(SIGUSR1, ft_signal);
	while (1)
	{
		ft_send_message("------------------------\n", pid);
		ft_send_message("Message from client ", pid);
		client_pid = ft_itoa(getpid());
		ft_send_message(client_pid, pid);
		ft_send_message(":\n", pid);
		ft_send_message(argv[2], pid);
		ft_end_of_message(pid);
		pause();
	}
	return (0);
}
