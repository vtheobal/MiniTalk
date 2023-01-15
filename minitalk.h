/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtheobal <vtheobal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/18 13:43:25 by vtheobal          #+#    #+#             */
/*   Updated: 2021/09/18 16:54:44 by vtheobal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include "./libft/libft.h"
# include <signal.h>
# include <stdio.h>

typedef struct s_data
{
	char	ch;
	size_t	size;
	char	buff[1000];
	int		i;
}				t_data;

#endif
