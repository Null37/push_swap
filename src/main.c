/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssamadi <ssamadi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/06 12:34:52 by ssamadi           #+#    #+#             */
/*   Updated: 2021/06/14 17:49:12 by ssamadi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_all	*all_t(void)
{
	static t_all	all;

	return (&all);
}

int	err_message(int ac)
{
	if (check_max_int() == -1)
	{
		write(2, "Error\n", 6);
		return (-1);
	}
	if (check_double(ac) == -1)
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
	if (ac > 1)
	{
		start(ac);
		rem_args(av);
		if (check_erros(all->args) == -1)
		{
			write(2, "Error\n", 6);
			return (-1);
		}
		add_to_table_int(all->args, all->table_a);
		if (err_message(ac) == -1)
			return (-1);
		add_to_table_int(all->args, all->table_c);
		add_to_table_int(all->args, all->sor_table);
		bubblesort(all->sor_table, all->len_sort);
		half_main(all);
	}
	return (0);
}
