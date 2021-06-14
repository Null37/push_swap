/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   norm_file_6.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssamadi <ssamadi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 15:25:17 by ssamadi           #+#    #+#             */
/*   Updated: 2021/06/14 17:51:19 by ssamadi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	half_twenty(LONG_L ta[], LONG_L tb[])
{
	t_all	*all;
	LONG_L	min;
	LONG_L	index;
	LONG_L	size;

	all = all_t();
	min = min_number(ta, all->len_a);
	index = get_index(ta, all->len_a, min);
	size = all->len_a / 2;
	if (index <= size)
	{
		while (index > 0)
		{
			write(1, "ra\n", 3);
			rotate(ta, all->len_a);
			index--;
		}
	}
	else if (index > size)
		loop_rra(index, ta);
	write(1, "pb\n", 3);
	push_b(ta, tb);
}

int	half_hundred(LONG_L table_a[], LONG_L table_b[],
	LONG_L table_min[], LONG_L *d)
{
	if (check_ith_range(table_min, table_a[0]) == 2)
	{
		(*d)--;
		write(1, "pb\n", 3);
		push_b(table_a, table_b);
		return (1);
	}
	return (0);
}

void	loop_sort_hund(LONG_L table_a[], LONG_L table_b[],
	LONG_L table_min[], t_all *all)
{
	while (1)
	{
		if (all->len_a <= 0 || all->d == 0)
			break ;
		if (half_hundred(table_a, table_b, table_min, &all->d) == 1)
			continue ;
		if (all->i < all->jj && check_ith_range(table_min,
				table_a[++all->i]) == 2)
		{
			write(1, "ra\n", 3);
			rotate(table_a, all->len_a);
			all->i = 0;
			all->jj = all->len_a;
		}
		else if (all->i < all->jj && check_ith_range(table_min,
				table_a[--all->jj]) == 2)
		{
			write(1, "rra\n", 4);
			reverce_rotate(table_a, all->len_a);
			all->jj = all->len_a;
			all->i = 0;
		}
	}
}

void	start_sort_hundred(LONG_L table_a[], LONG_L table_b[],
			LONG_L table_min[])
{
	t_all	*all;

	all = all_t();
	all->d = all->len_min;
	all->i = 0;
	all->jj = all->len_a;
	loop_sort_hund(table_a, table_b, table_min, all);
}
