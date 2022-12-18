/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmiseiki <vmiseiki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 13:26:42 by vmiseiki          #+#    #+#             */
/*   Updated: 2021/09/24 21:17:36 by vmiseiki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_pow(int nbr, int pwr)
{
	int	i;
	int	base;

	if (pwr == 0)
		return (1);
	i = 2;
	base = nbr;
	while (i <= pwr)
	{
		nbr = nbr * base;
		i++;
	}
	return (nbr);
}

void	ft_binary_to_char(char *arr)
{
	int		i;
	char	c;
	char	temp;

	i = 0;
	c = 0;
	while (i < 8)
	{
		c += (arr[i] - 48) * ft_pow(2, i);
		temp = ft_pow(2, i) + '0';
		i++;
	}
	write(1, &c, 1);
}

int	ft_end_signal(char *str)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '1')
			count++;
		i++;
	}
	if (count == 8)
		return (1);
	return (0);
}

void	ft_print_message(int sig, siginfo_t *siginfo, void *context)
{
	static int	i;
	char		res[9];

	(void)context;
	if (sig == SIGUSR1)
		res[i] = '1';
	else if (sig == SIGUSR2)
		res[i] = '0';
	i++;
	if (i == 8)
	{
		res[i] = '\0';
		ft_end_signal(res);
		if (!ft_end_signal(res))
			ft_binary_to_char(res);
		else
		{
			write(1, "\n", 1);
			kill(siginfo->si_pid, SIGUSR1);
		}
		i = 0;
	}
}

int	main(void)
{
	struct sigaction	sa;

	write(1, "Server Pid: ", 12);
	ft_putnbr_fd(getpid(), 1);
	write(1, "\n", 1);
	write(1, "------------------------\n", 25);
	write(1, "Waiting for messages....\n", 25);
	ft_memset(&sa, '\0', sizeof(sa));
	sigemptyset(&sa.sa_mask);
	sa.sa_sigaction = ft_print_message;
	sa.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
	return (0);
}
