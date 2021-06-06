/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssamadi <ssamadi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/06 12:34:52 by ssamadi           #+#    #+#             */
/*   Updated: 2021/06/06 16:44:58 by ssamadi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_is_number(int ac, char **av)
{
	int	i;

	i = ac;
	return (i - 1);
}

int	max_number(char **av)
{
	int	max;
	int	i;

	i = 2;
	max = atoi(av[1]);
	while (av[i])
	{
		if (max < atoi(av[i]))
			max = atoi(av[i]);
		i++;
	}
	return (max);
}

int	min_number(char **av)
{
	int	min;
	int	i;

	i = 2;
	min = atoi(av[1]);
	while (av[i])
	{
		if (min > atoi(av[i]))
			min = atoi(av[i]);
		i++;
	}
	return (min);
}

int	*add_t_table()
{
	return((int *)5);
}

void	add_to_table_int(char *av[], int len, int table[len])
{
	int i;

	i = 1;
	while(i < len)
	{
		table[i] = atoi(av[i]);
		i++;
	}
}

int	main(int ac, char *av[])
{
	int	check;
	int	i;
	int len;
	int table_a[ac];
	int table_b[ac];
	int table_c[ac];
	int	max;
	int	min;


	len = ac;
	add_to_table_int(av, len, table_a);
	i = 1;
	while(i < len)
	{
		printf("%d\n", table_a[i]);
		i++;
	}
	return (0);
}
