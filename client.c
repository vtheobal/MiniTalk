/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtheobal <vtheobal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/18 14:32:19 by vtheobal          #+#    #+#             */
/*   Updated: 2021/09/18 16:40:18 by vtheobal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	analysis_client(int pid, char *str, int len)
{
	int	i;
	int	tmp;

	i = 0;
	while (i <= len)
	{
		tmp = 0;
		while (tmp < 8)
		{
			if (((str[i] >> tmp) & 1) == 1)
				kill(pid, SIGUSR2);
			else
				kill(pid, SIGUSR1);
			tmp++;
			usleep(30);
		}
		i++;
	}
}

int	main(int argc, char *argv[])
{
	int	pid;

	pid = 0;
	if (argc != 3)
		ft_putstr_fd("Error argument: [pid] [msg]\n", 1);
	else
	{
		pid = ft_atoi(argv[1]);
		analysis_client(pid, argv[2], ft_strlen(argv[2]));
	}
	return (0);
}
