/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssamadi <ssamadi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/06 12:34:52 by ssamadi           #+#    #+#             */
/*   Updated: 2021/06/20 17:25:44 by ssamadi          ###   ########.fr       */
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

void	free_args(char **ar)
{
	int	i;

	i = -1;
	while (ar[++i])
	{
		free(ar[i]);
	}
	free(ar);
}

int	check_oprtion(char *line)
{
	char	**s;
	int		i;

	s = ft_split(line, '\n');
	i = -1;
	while (s[++i])
	{
		if (ft_strncmp(s[i], "ra", 3) != 0
			&& ft_strncmp(s[i], "sa", 3) != 0
			&& ft_strncmp(s[i], "sb", 3) != 0
			&& ft_strncmp(s[i], "rb", 3) != 0
			&& ft_strncmp(s[i], "rr", 3) != 0
			&& ft_strncmp(s[i], "ss", 3) != 0
			&& ft_strncmp(s[i], "rra", 4) != 0
			&& ft_strncmp(s[i], "rrb", 4) != 0
			&& ft_strncmp(s[i], "rrr", 4) != 0
			&& ft_strncmp(s[i], "pa", 3) != 0
			&& ft_strncmp(s[i], "pb", 3) != 0)
		{
			free_args(s);
			return (-1);
		}
	}
	free_args(s);
	return (0);
}

int	main(int ac, char *av[])
{
	t_all	*all;

	all = all_t();
	all->args = NULL;
	all->ret = 1;
	if (ac > 1)
	{
		all->aplc = ft_strdup("");
		rem_args(av);
		start();
		if (half_errr(all) == -1)
			return (-1);
		loop_read(all);
		add_to_table_int(all->args, all->sor_table);
		bubblesort(all->sor_table, all->len_sort);
		half_main_bonus(all, all->aplc);
		free_all();
		free(all->line);
		free(all->aplc);
	}
	return (0);
}
