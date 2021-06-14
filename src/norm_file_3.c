/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   norm_file_3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssamadi <ssamadi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 15:01:54 by ssamadi           #+#    #+#             */
/*   Updated: 2021/06/14 17:58:17 by ssamadi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	loop_rra(LONG_L	index, LONG_L ta[])
{
	t_all	*all;

	all = all_t();
	while (index < all->len_a)
	{
		write(1, "rra\n", 4);
		reverce_rotate(ta, all->len_a);
		index++;
	}
}

int	half_sort_three(LONG_L	min, LONG_L	max, LONG_L *ta)
{
	t_all	*all;

	all = all_t();
	if (ta[1] == max && ta[2] == min)
	{
		write(1, "rra\n", 4);
		reverce_rotate(ta, all->len_a);
		return (-1);
	}
	if (ta[0] == max && ta[1] == min)
	{
		write(1, "ra\n", 3);
		rotate(ta, all->len_a);
		return (-1);
	}
	if (ta[0] == min && ta[1] == max)
	{
		write(1, "rra\n", 4);
		reverce_rotate(ta, all->len_a);
		swap_first_two(ta, 'a');
		return (-1);
	}
	return (0);
}

void	push_a(LONG_L ta[], LONG_L tb[])
{
	LONG_L	tmp;
	LONG_L	i;
	t_all	*all;

	all = all_t();
	tmp = tb[0];
	i = 0;
	while (i < all->len_b)
	{
		tb[i] = tb[i + 1];
		i++;
	}
	all->len_b--;
	i = all->len_a;
	while (i > 0)
	{
		ta[i] = ta[i - 1];
		i--;
	}
	ta[0] = tmp;
	all->len_a++;
}

void	sort_three(LONG_L *ta)
{
	t_all	*all;
	LONG_L	min;
	LONG_L	max;

	all = all_t();
	min = min_number(ta, all->len_a);
	max = max_number(ta, all->len_a);
	if (ta[0] == max && ta[2] == min)
	{
		write(1, "ra\n", 3);
		rotate(ta, all->len_a);
		swap_first_two(ta, 'a');
		return ;
	}
	if (ta[1] == min && ta[2] == max)
	{
		swap_first_two(ta, 'a');
		return ;
	}
	if (half_sort_three(min, max, ta) == -1)
		return ;
}
