/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   norm_file_2_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssamadi <ssamadi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 14:52:40 by ssamadi           #+#    #+#             */
/*   Updated: 2021/06/19 19:00:31 by ssamadi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	reverce_rotate(LONG_L table_a[], LONG_L len)
{
	LONG_L	tmp;
	LONG_L	i;

	i = len - 1;
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
		if (i + 1 >= all->len_a)
			break ;
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
	swap_first_two_b(table_a);
	swap_first_two_b(table_b);
}

void	half_loop_bonus(t_all *all, char **sp, int i)
{
	if (ft_strncmp(sp[i], "sa", 3) == 0)
		swap_first_two_b(all->table_a);
	else if (ft_strncmp(sp[i], "sb", 3) == 0)
		swap_first_two_b(all->table_b);
	else if (ft_strncmp(sp[i], "ss", 3) == 0)
		ss_first_two(all->table_a, all->table_b);
	else if (ft_strncmp(sp[i], "pa", 3) == 0)
		push_a(all->table_a, all->table_b);
	else if (ft_strncmp(sp[i], "pb", 3) == 0)
		push_b(all->table_a, all->table_b);
	else if (ft_strncmp(sp[i], "rra", 4) == 0)
		reverce_rotate(all->table_a, all->len_a);
	else if (ft_strncmp(sp[i], "rrb", 4) == 0)
		reverce_rotate(all->table_b, all->len_b);
	else if (ft_strncmp(sp[i], "rrr", 4) == 0)
	{
		reverce_rotate(all->table_a, all->len_a);
		reverce_rotate(all->table_b, all->len_b);
	}
}
