/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   norm_file_7.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssamadi <ssamadi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 16:49:46 by ssamadi           #+#    #+#             */
/*   Updated: 2021/06/15 17:26:26 by ssamadi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	loop_max_rra(LONG_L table_b[], LONG_L *index)
{
	t_all	*all;

	all = all_t();
	while (*index < all->len_b)
	{
		write(1, "rrb\n", 4);
		reverce_rotate(table_b, all->len_b);
		(*index)++;
	}
}

void	push_max_t_a(LONG_L table_a[], LONG_L table_b[])
{
	t_all	*all;
	LONG_L	max;
	LONG_L	index;
	LONG_L	size;

	all = all_t();
	max = max_number(table_b, all->len_b);
	index = get_index(table_b, all->len_b, max);
	size = all->len_b / 2;
	if (index <= size)
	{
		while (index > 0)
		{
			write(1, "rb\n", 3);
			rotate(table_b, all->len_b);
			index--;
		}
	}
	else if (index > size)
		loop_max_rra(table_b, &index);
	if (all->len_b > 0)
	{
		write(1, "pa\n", 3);
		push_a(table_a, table_b);
	}
}

void	sort_hundred(LONG_L table_a[], LONG_L table_b[],
			LONG_L table_c[], LONG_L table_min[])
{
	t_all	*all;
	LONG_L	i;

	all = all_t();
	i = 0;
	while (all->len_a > 0)
	{
		if (all->len_a > all->group)
		{
			add_min(table_c, table_min, all->group);
			all->len_min = all->group;
		}
		else
		{
			add_min(table_c, table_min, all->len_a);
			all->len_min = all->len_a;
		}
		start_sort_hundred(table_a, table_b, table_min);
	}
	while (all->len_b > 0)
		push_max_t_a(table_a, table_b);
}

void	start(void)
{
	t_all	*all;

	all = all_t();
	all->len_a = all->ac;
	all->len_c = all->ac;
	all->len_sort = all->ac;
	all->len_b = 0;
	all->table_a = malloc(sizeof(LONG_L) * all->ac);
	all->table_b = malloc(sizeof(LONG_L) * all->ac);
	all->table_c = malloc(sizeof(LONG_L) * all->ac);
	all->table_min = malloc(sizeof(LONG_L) * all->ac);
	all->sor_table = malloc(sizeof(LONG_L) * all->ac);
}

void	norm_list(char **ar)
{
	LONG_L	i;
	t_all	*all;

	all = all_t();
	i = 0;
	while (all->args && all->args[i])
	{
		all->tmp[i] = all->args[i];
		i++;
	}
	free(all->args);
	all->args = NULL;
	all->j = 0;
	while (ar[all->j])
	{
		all->tmp[i] = ar[all->j];
		i++;
		all->j++;
	}
	all->tmp[i] = NULL;
	all->args = all->tmp;
}
