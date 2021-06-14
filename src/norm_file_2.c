/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   norm_file_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssamadi <ssamadi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 14:52:40 by ssamadi           #+#    #+#             */
/*   Updated: 2021/06/14 17:57:49 by ssamadi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	reverce_rotate(LONG_L table_a[], LONG_L len)
{
	LONG_L	tmp;
	LONG_L	i;

	i = len;
	tmp = table_a[len - 1];
	while (i > 0)
	{
		table_a[i] = table_a[i - 1];
		i--;
	}
	table_a[0] = tmp;
}

void	push_b(LONG_L table_a[], LONG_L table_b[])
{
	LONG_L	tmp;
	LONG_L	i;
	t_all	*all;

	all = all_t();
	tmp = table_a[0];
	i = 0;
	while (i < all->len_a)
	{
		table_a[i] = table_a[i + 1];
		i++;
	}
	all->len_a--;
	i = all->len_b;
	while (i > 0)
	{
		table_b[i] = table_b[i - 1];
		i--;
	}
	table_b[0] = tmp;
	all->len_b++;
}

LONG_L	get_index(LONG_L ta[], LONG_L len, LONG_L min)
{
	LONG_L	i;

	i = 0;
	while (i < len)
	{
		if (ta[i] == min)
			return (i);
		i++;
	}
	return (-1);
}

void	ss_first_two(LONG_L table_a[], LONG_L table_b[])
{
	t_all	*all;

	all = all_t();
	swap_first_two(table_a, 'a');
	swap_first_two(table_b, 'b');
}

void	half_sort_five(LONG_L ta[], LONG_L tb[])
{
	t_all	*all;
	LONG_L	min;
	LONG_L	index;

	all = all_t();
	min = min_number(ta, all->len_a);
	index = get_index(ta, all->len_a, min);
	if (index <= 2)
	{
		while (index > 0)
		{
			write(1, "ra\n", 3);
			rotate(ta, all->len_a);
			index--;
		}
	}
	else if (index > 2)
		loop_rra(index, ta);
	write(1, "pb\n", 3);
	push_b(ta, tb);
}
