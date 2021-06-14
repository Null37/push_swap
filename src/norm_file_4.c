/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   norm_file_4.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssamadi <ssamadi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 15:08:41 by ssamadi           #+#    #+#             */
/*   Updated: 2021/06/14 17:58:22 by ssamadi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sort_five(LONG_L ta[], LONG_L tb[])
{
	t_all	*all;

	all = all_t();
	half_sort_five(ta, tb);
	half_sort_five(ta, tb);
	if (all->len_a == 3)
		sort_three(ta);
	push_a(ta, tb);
	push_a(ta, tb);
	write(1, "pa\npa\n", 6);
}

void	sort_two(LONG_L ta[])
{
	t_all	*all;
	LONG_L	max;

	all = all_t();
	max = max_number(ta, all->len_a);
	if (max == ta[0])
		swap_first_two(ta, 'a');
}

void	half_sort_four(LONG_L ta[], LONG_L tb[])
{
	t_all	*all;

	all = all_t();
	push_b(ta, tb);
	write(1, "pb\n", 3);
	sort_three(ta);
	push_a(ta, tb);
	write(1, "pa\n", 3);
	rotate(ta, all->len_a);
	write(1, "ra\n", 3);
}

void	sort_four(LONG_L ta[], LONG_L tb[])
{
	t_all	*all;
	LONG_L	max;
	LONG_L	index;

	all = all_t();
	max = max_number(ta, all->len_a);
	index = get_index(ta, all->len_a, max);
	if (index == 3)
	{
		reverce_rotate(ta, all->len_a);
		write(1, "rra\n", 4);
	}
	else
	{
		while (index > 0)
		{
			rotate(ta, all->len_a);
			write(1, "ra\n", 3);
			index--;
		}
	}
	half_sort_four(ta, tb);
}

void	sort_twenty(LONG_L ta[], LONG_L tb[])
{
	t_all	*all;
	LONG_L	i;
	LONG_L	b;	

	all = all_t();
	i = all->len_a;
	while (i)
	{
		half_twenty(ta, tb);
		i--;
	}
	b = all->len_b;
	while (b > 0)
	{
		write(1, "pa\n", 3);
		push_a(ta, tb);
		b--;
	}
}
