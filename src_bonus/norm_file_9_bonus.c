/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   norm_file_9_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssamadi <ssamadi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 17:35:25 by ssamadi           #+#    #+#             */
/*   Updated: 2021/06/20 17:29:57 by ssamadi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	bubblesort(LONG_L arr[], LONG_L n)
{
	int	i;
	int	j;

	i = 0;
	while (i < (n - 1))
	{
		j = 0;
		while (j < (n - i - 1))
		{
			if (arr[j] > arr[j + 1])
				swap(&arr[j], &arr[j + 1]);
			j++;
		}
		i++;
	}
}

int	check_erros(char **av)
{
	t_all	*all;
	int		i;
	int		j;

	all = all_t();
	i = 0;
	while (av[i])
	{
		j = 0;
		if (av[i][j] == '-' || av[i][j] == '+')
			j++;
		if (av[i][j] == '\0')
			return (-1);
		while (av[i][j])
		{
			if (t_isdigit(av[i][j]) != 1)
				return (-1);
			j++;
		}
		i++;
	}
	return (0);
}

int	check_double(void)
{
	LONG_L	i;
	LONG_L	j;
	t_all	*all;

	j = 0;
	i = 0;
	all = all_t();
	while (i < all->ac)
	{
		j = 0;
		while (j < all->ac)
		{
			if (i != j && all->table_a[i] == all->table_a[j])
				return (-1);
			j++;
		}
		i++;
	}
	return (0);
}

char	*ft_strjoin12(char *s1, char *s2)
{
	size_t	size;
	char	*str;
	int		i;
	int		j;

	i = -1;
	j = 0;
	if (!s1)
		return ((str = ft_strdup(s2)));
	size = ft_strlen(s1) + ft_strlen(s2);
	str = (char *)malloc(sizeof(char) * size + 1);
	if (!str)
		return (NULL);
	while (s1[++i] != '\0')
		str[i] = s1[i];
	while (s2[j] != '\0')
		str[i++] = s2[j++];
	str[i] = '\0';
	free(s1);
	return (str);
}

int	half_errr(t_all	*all)
{
	if (check_erros(all->args) == -1)
	{
		free(all->aplc);
		free(all->line);
		free_all();
		write(2, "Error\n", 6);
		return (-1);
	}
	add_to_table_int(all->args, all->table_a);
	if (err_message() == -1)
	{
		free(all->aplc);
		free(all->line);
		free_all();
		return (-1);
	}
	return (0);
}
