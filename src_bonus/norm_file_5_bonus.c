/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   norm_file_5_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssamadi <ssamadi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 15:19:43 by ssamadi           #+#    #+#             */
/*   Updated: 2021/06/20 17:09:07 by ssamadi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	check_ith_range(LONG_L table_min[], LONG_L ta)
{
	LONG_L	i;
	t_all	*all;

	i = 0;
	all = all_t();
	while (i < all->len_min)
	{
		if (table_min[i] == ta)
			return (2);
		i++;
	}
	return (-1);
}

int	check_max_int(void)
{
	t_all	*all;
	LONG_L	i;

	all = all_t();
	i = -1;
	while (++i < all->len_a)
	{
		if (all->table_a[i] > INT32_MAX
			|| all->table_a[i] < INT32_MIN)
		{
			return (-1);
		}
	}
	return (0);
}
