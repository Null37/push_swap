/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_atoi_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssamadi <ssamadi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 18:01:48 by ssamadi           #+#    #+#             */
/*   Updated: 2021/06/20 17:30:03 by ssamadi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

LONG_L	ft_my_atoi(const char *str)
{
	LONG_L		i;
	LONG_L		number;
	int			sign;
	int			l_counter;

	l_counter = 0;
	sign = 1;
	i = 0;
	number = 0;
	while ((str[i] >= 9 && str[i] <= 13) || (str[i] == 32))
		i++;
	if (str[i] == '+' || str[i] == '-')
		if (str[i++] == '-')
			sign = -1;
	while (str[i] != '\0')
	{
		if (!(str[i] >= 48 && str[i] <= 57))
			return (number * sign);
		number = number * 10 + (str[i++] - 48);
	}
	return (number * sign);
}

void	loop_read(t_all	*all)
{
	while (all->ret > 0)
	{
		all->ret = get_next_line(0, &all->line);
		all->line = ft_strjoin12(all->line, "\n");
		if (all->ret != 0)
		{
			all->aplc = ft_strjoin12(all->aplc, all->line);
		}
		if (check_oprtion(all->line) == -1)
		{
			free(all->line);
			free(all->aplc);
			free_all();
			write(2, "Error\n", 6);
			exit(-1);
		}
		free(all->line);
		all->line = NULL;
	}
}
