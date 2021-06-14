/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   norm_file_5.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssamadi <ssamadi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 15:19:43 by ssamadi           #+#    #+#             */
/*   Updated: 2021/06/14 17:51:19 by ssamadi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	half_addmin(LONG_L table_c[], LONG_L table_min[], LONG_L k)
{
	t_all	*all;
	LONG_L	min;
	LONG_L	index;
	LONG_L	i;

	all = all_t();
	min = min_number(table_c, all->len_c);
	index = get_index(table_c, all->len_c, min);
	i = index;
	table_min[k] = table_c[index];
	while (i < all->len_c - 1)
	{
		table_c[i] = table_c[i + 1];
		i++;
	}
	all->len_c--;
}

void	add_min(LONG_L table_c[], LONG_L table_min[], LONG_L k)
{
	t_all	*all;
	LONG_L	i;

	all = all_t();
	i = 0;
	while (i < k)
	{
		half_addmin(table_c, table_min, i);
		i++;
	}
}

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
