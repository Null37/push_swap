/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   norm_file1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssamadi <ssamadi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 14:50:10 by ssamadi           #+#    #+#             */
/*   Updated: 2021/06/14 17:56:52 by ssamadi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

LONG_L	max_number(LONG_L *av, LONG_L len)
{
	LONG_L	max;
	LONG_L	i;

	i = 1;
	max = av[0];
	while (i < len)
	{
		if (max < av[i])
			max = av[i];
		i++;
	}
	return (max);
}

LONG_L	min_number(LONG_L *av, LONG_L len)
{
	LONG_L	min;
	LONG_L	i;

	i = 1;
	min = av[0];
	while (i < len)
	{
		if (min > av[i])
			min = av[i];
		i++;
	}
	return (min);
}

void	swap_first_two(LONG_L table[], char o)
{
	int		tmp;
	t_all	*all;

	all = all_t();
	tmp = table[0];
	table[0] = table[1];
	table[1] = tmp;
	if (o == 'a')
		write(1, "sa\n", 3);
	else if (o == 'b')
		write(1, "sb\n", 3);
}

void	add_to_table_int(char *av[], LONG_L table[])
{
	LONG_L		i;
	t_all		*all;

	i = 0;
	all = all_t();
	while (av[i] != NULL)
	{
		table[i] = ft_my_atoi(av[i]);
		i++;
	}
}

void	rotate(LONG_L table_a[], LONG_L len)
{
	LONG_L	tmp;
	LONG_L	i;

	i = 0;
	tmp = table_a[0];
	while (i < len)
	{
		table_a[i] = table_a[i + 1];
		i++;
	}
	table_a[len - 1] = tmp;
}
