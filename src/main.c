/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssamadi <ssamadi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/06 12:34:52 by ssamadi           #+#    #+#             */
/*   Updated: 2021/06/15 17:32:04 by ssamadi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_all	*all_t(void)
{
	static t_all	all;

	return (&all);
}

int	err_message(void)
{
	if (check_max_int() == -1)
	{
		write(2, "Error\n", 6);
		return (-1);
	}
	if (check_double() == -1)
	{
		write(2, "Error\n", 6);
		return (-1);
	}
	return (0);
}

int	main(int ac, char *av[])
{
	t_all	*all;

	all = all_t();
	all->args = NULL;
	if (ac > 1)
	{
		rem_args(av);
		start();
		if (check_erros(all->args) == -1)
		{
			write(2, "Error\n", 6);
			return (-1);
		}
		add_to_table_int(all->args, all->table_a);
		if (err_message() == -1)
			return (-1);
		add_to_table_int(all->args, all->table_c);
		add_to_table_int(all->args, all->sor_table);
		bubblesort(all->sor_table, all->len_sort);
		half_main(all);
	}
	return (0);
}
