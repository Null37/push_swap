/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   norm_file_8.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssamadi <ssamadi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 17:30:11 by ssamadi           #+#    #+#             */
/*   Updated: 2021/06/15 17:33:46 by ssamadi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	add_in_list(char **ar)
{
	LONG_L	i;
	t_all	*all;

	all = all_t();
	all->c = 0;
	all->c2 = 0;
	i = -1;
	if (!ar)
		return ;
	while (ar[++i])
		all->c++;
	i = -1;
	while (all->args && all->args[++i])
		all->c2++;
	all->tmp = malloc(sizeof(char *) * (all->c + all->c2 + 1));
	norm_list(ar);
}

void	rem_args(char **av)
{
	int			i;
	char		**ar;
	LONG_L		c;
	t_all		*all;

	all = all_t();
	i = 0;
	c = 0;
	while (av[++i])
	{
		ar = ft_split(av[i], ' ');
		add_in_list(ar);
		free(ar);
	}
	i = -1;
	while (all->args[++i])
		c++;
	all->ac = c;
}

void	swap(LONG_L *xp, LONG_L *yp)
{
	LONG_L	temp;

	temp = *xp;
	*xp = *yp;
	*yp = temp;
}

int	check_table_sort(void)
{
	t_all	*all;
	LONG_L	i;

	all = all_t();
	i = 0;
	while (i < all->len_sort)
	{
		if (all->sor_table[i] == all->table_a[i])
			i++;
		else
			return (1);
	}
	return (0);
}

int	t_isdigit(char number)
{
	if ((number >= '0' && number <= '9'))
	{
		return (1);
	}
	else
		return (0);
}
