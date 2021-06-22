/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   norm_file_3_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssamadi <ssamadi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 15:01:54 by ssamadi           #+#    #+#             */
/*   Updated: 2021/06/20 17:08:55 by ssamadi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

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
		if (i + 1 >= all->len_b)
			break ;
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

void	half_main_bonus(t_all *all, char *line)
{
	char	**sp;
	int		i;

	sp = ft_split(line, '\n');
	i = -1;
	while (sp[++i])
	{
		if (ft_strncmp(sp[i], "ra", 3) == 0)
			 rotate(all->table_a, all->len_a);
		else if (ft_strncmp(sp[i], "rb", 3) == 0)
			rotate(all->table_b, all->len_b);
		else if (ft_strncmp(sp[i], "rr", 3) == 0)
		{
			rotate(all->table_a, all->len_a);
			rotate(all->table_b, all->len_b);
		}
		half_loop_bonus(all, sp, i);
	}
	free_args(sp);
	check_is_a_sorted();
}

void	free_all(void)
{
	t_all	*all;

	all = all_t();
	free(all->table_a);
	free(all->table_b);
	free(all->sor_table);
}

void	check_is_a_sorted(void)
{
	t_all	*all;
	LONG_L	i;

	all = all_t();
	i = 0;
	if (all->len_b != 0)
	{
		write(1, "KO\n", 3);
		return ;
	}
	while (i < all->len_sort)
	{
		if (all->sor_table[i] == all->table_a[i])
			i++;
		else
		{
			write(1, "KO\n", 3);
			return ;
		}
	}
	write(1, "OK\n", 3);
}
