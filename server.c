/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtheobal <vtheobal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/18 13:47:44 by vtheobal          #+#    #+#             */
/*   Updated: 2021/09/18 17:15:24 by vtheobal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static t_data	g_data;

void	nulling(t_data data)
{
	int	i;

	i = 0;
	while (data.buff[i] != '\0')
	{
		data.buff[i] = 0;
		i++;
	}
}

void	analysis_server(int bit)
{
	g_data.ch = g_data.ch + ((bit & 1) << g_data.size);
	g_data.size++;
	if (g_data.size == 8)
	{
		g_data.buff[g_data.i] = g_data.ch;
		g_data.i++;
		if (g_data.i == 999)
		{
			write(1, g_data.buff, g_data.i);
			g_data.i = 0;
		}
		if (!g_data.ch)
		{
			write(1, g_data.buff, g_data.i);
			ft_putstr_fd("\n", 1);
			g_data.i = 0;
			nulling(g_data);
		}
		g_data.ch = 0;
		g_data.size = 0;
	}
}

int	main(void)
{
	pid_t	pid;

	g_data.ch = 0;
	g_data.size = 0;
	g_data.i = 0;
	pid = getpid();
	if (pid == 0)
		ft_putstr_fd("wrong server pin", 1);
	else
	{
		ft_putstr_fd("pid server :", 1);
		ft_putnbr_fd(pid, 1);
		ft_putstr_fd("\n", 1);
	}
	while (1)
	{
		signal(SIGUSR1, analysis_server);
		signal(SIGUSR2, analysis_server);
		pause();
	}
}
