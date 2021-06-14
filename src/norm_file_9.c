/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   norm_file_9.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssamadi <ssamadi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 17:35:25 by ssamadi           #+#    #+#             */
/*   Updated: 2021/06/14 17:51:19 by ssamadi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	bubblesort(LONG_L arr[], LONG_L n)
{
	LONG_L	i;
	LONG_L	j;

	i = -1;
	j = -1;
	while (++i < n - 1)
	{
		while (++j < n - i - 1)
		{
			if (arr[j] > arr[j + 1])
				swap(&arr[j], &arr[j + 1]);
		}
	}
}

int	check_erros(char **av)
{
	t_all	*all;
	int		i;

	all = all_t();
	i = 0;
	while (av[i])
	{
		if (*av[i] == '-' || *av[i] == '+')
			if (t_isdigit(av[i][1]) != 1)
				return (-1);
		if (t_isdigit(*av[i]) != 1 && *av[i] != '-' && *av[i] != '+')
			return (-1);
		i++;
	}
	return (0);
}

int	check_double(int ac)
{
	LONG_L	i;
	LONG_L	j;
	t_all	*all;

	j = 0;
	i = 0;
	all = all_t();
	while (i < ac - 1)
	{
		j = 0;
		while (j < ac - 1)
		{
			if (i != j && all->table_a[i] == all->table_a[j])
				return (-1);
			j++;
		}
		i++;
	}
	return (0);
}

void	half_main(t_all *all)
{
	if (check_table_sort() == 1)
	{
		if (all->len_a == 2)
			sort_two(all->table_a);
		else if (all->len_a == 3)
			sort_three(all->table_a);
		else if (all->len_a == 4)
			sort_four(all->table_a, all->table_b);
		else if (all->len_a == 5)
			sort_five(all->table_a, all->table_b);
		else if (all->len_a >= 6 && all->len_a <= 20)
			sort_twenty(all->table_a, all->table_b);
		else if (all->len_a > 20 && all->len_a <= 150)
		{
			all->group = all->len_c / 6;
			sort_hundred(all->table_a, all->table_b,
				all->table_c, all->table_min);
		}
		else if (all->len_a > 20 && all->len_a > 150)
		{
			all->group = all->len_c / 12;
			sort_hundred(all->table_a, all->table_b,
				all->table_c, all->table_min);
		}
	}
}
