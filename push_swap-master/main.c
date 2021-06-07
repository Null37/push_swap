/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssamadi <ssamadi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 16:13:00 by fbouibao          #+#    #+#             */
/*   Updated: 2021/06/07 11:35:04 by ssamadi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <stdio.h>
# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include "libft1/libft.h"

typedef struct s_filerdr
{
	char				stack_a;
	int					stack_b;
	int					stack_c;
}					t_filerdr;

int	check_args(char **av)
{
	int i;
	int cpt;

	i = 0;
	while (av[++i])
	{
		cpt = -1;
		if (av[i][0] == '+' || av[i][0] == '-')
			cpt++;
		while (av[i][++cpt])
		{
			if (!ft_isdigit(av[i][cpt]))
			{
				return (1);
			}
		}		
	}
	return (0);
}


void	ft_allc(int **ta, int la)
{
	if (*ta)
		free(*ta);
	*ta = malloc(sizeof(int) * la);
}


void sort_swap(char *ta, char *tb)
{
	
}
void	rmp_t(char **av, int ac, int ta[ac])
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (++i < ac)
	{
		ta[j] = atoi(av[i]);
		j++;
	}
}

void	sort_tc(int len_tc, int tc[len_tc])
{
	int i;
	int j;
	int pos;
	int min;
	int swap;

	i = -1;	
	while (++i < len_tc)
	{
		
		j = i;
		min = tc[j];
		pos = j;
		while (j < len_tc)
		{
			if (tc[j] < min)
			{
				min = tc[j];
				pos = j;
			}
			j++;
		}
		if (pos != i)
		{
			swap = tc[i];
			tc[i] = tc[pos];
			tc[pos] = swap;
		}
	}
	
}

void	swap_stack(int len, int ta[len])
{
	int swap;

	swap = ta[0];
	ta[0] = ta[1];
	ta[1] = swap;
}

void	rotate_stack(int len, int ta[len])
{
	

	int swap;
	int i;

	swap = ta[0];
	i = -1;
	while (++i < len - 1)
	{
		ta[i] = ta[i + 1];
	}
	ta[len - 1] = swap;
	
}

void	reverse_rotate_stack(int len, int ta[len])
{
	int swap;
	int i;

	swap = ta[len - 1];
	i = len;
	while (--i > 0)
	{
		ta[i] = ta[i - 1];
	}
	ta[0] = swap;
}

void	push_stack(int *len, int ta[*len], int *lenb, int tb[*lenb])
{
	int push;
	int i;

	push = ta[0];
	i = -1;
	while (++i < *len - 1)
		ta[i] = ta[i + 1];
	(*len)--;
	i = *lenb + 1;
	while (--i > 0)
		tb[i] = tb[i - 1];
	tb[0] = push;
	(*lenb)++;
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

int	max_number1(int *av, int len)
{
	int	max;
	int	i;

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


int	min_number1(int *av, int len)
{
	int	min;
	int	i;

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
void sort_three(int *ta, int *len, char **av)
{
	int min = min_number1(ta, *len);
	int max = max_number1(ta, *len);

	// printf("mx = %d | mn = %d\n", max, min);
	if (ta[0] == max && ta[2] == min)
	{
		printf("ra\nsa\n");
		rotate_stack(*len, ta);
		swap_stack(*len, ta);
		return ;
	}
	if (ta[1] == min && ta[2] == max)
	{
		printf("sa\n");
		swap_stack(*len, ta);
		return ;
	}
	if (ta[1] == max && ta[2] == min)
	{
		printf("rra\n");
		reverse_rotate_stack(*len, ta);
		return ;
	}
	if (ta[0] == max && ta[1] == min)
	{
		printf("ra\n");
		rotate_stack(*len, ta);
		return ;
	}
	if (ta[0] == min && ta[1] == max)
	{
		printf("rra\nsa\n");
		rotate_stack(*len, ta);
		swap_stack(*len, ta);
		return ;
	}
}

int get_index(int *ta, int len, int min)
{
	int i = 0;
	while (i < len)
	{
		if (ta[i] == min)
			return (i);
		i++;	
	}
	return (-1);
}

void half_sort_five(int ta[], int tb[], int *len, int *len_b, char **av)
{
	int min = min_number1(ta, *len);
	int index = get_index(ta, *len, min);
	// printf("%d || %d\n", min, index);
	
	if (index <= 2)
	{
		while (index > 0)
		{
			printf("ra\n");
			rotate_stack(*len, ta);
			index--;
		}
	}
	else if (index > 2)
	{
		while (index < *len)
		{
			printf("rra\n");
			reverse_rotate_stack(*len, ta);
			index++;
		}
	}
	printf("pb\n");
	push_stack(len, ta, len_b, tb);
}

void sort_five(int ta[], int tb[], int *len, int *len_b, char **av)
{
	half_sort_five(ta, tb, len, len_b, av);
	half_sort_five(ta, tb, len, len_b, av);
	
	if (*len == 3)
		sort_three(ta, len, av);
		
	
	push_stack(len_b, tb, len, ta);
		// printf("%d =\n", *len_b);

	
	push_stack(len_b, tb, len, ta);
	printf("pa\npa\n");
	// int i = 0;
	// while (i < *len)
	// {
	// 		printf("|%d|", ta[i]);
	// 		i++;
	// }
	//  i = 0;
	// while (i < *len_b)
	// {
	// 		printf("\nBBB\n%d ", tb[i]);
	// 		i++;

	// }
	// printf("pb\n");
	



}


int	main(int ac, char *av[])
{
	int	i = -1;
	int	ta[ac];
	int	tb[ac];
	int	tc[ac];
	int len_ta;
	int len_tb;
	int len_tc;
	
	
	

	if (ac > 1)
	{
		len_ta = ac - 1;
		len_tb = 0;
		len_tc = ac - 1;
		rmp_t(av, ac, ta);
		// rmp_t(av, ac, tc);
		// sort_tc(len_tc, tc);


		// add *********
		if (len_ta == 3)
			sort_three(ta, &len_ta, av);
		else if (len_ta == 5)
			sort_five(ta, tb, &len_ta, &len_tb, av);


		
		//swap_stack(len_ta, ta);
		// rotate_stack(len_ta, ta);
		// reverse_rotate_stack(len_ta, ta);
		
		// push_stack(&len_ta, ta, &len_tb, tb);
		
		// printf("stack a\n");
		// while (++i < len_ta)
		// {
		// 	printf("%d\n", ta[i]);
		// }
		// printf("\nstack b\n");
		// i = -1;
		// while (++i < len_tb)
		// {
		// 	printf("%d\n", tb[i]);
		// }
		// push_stack(&len_tb, tb, &len_ta, ta);
		// printf("stack a\n");
		// i = -1;
		// while (++i < len_ta)
		// {
		// 	printf("%d\n", ta[i]);
		// }
		// printf("\nstack b\n");
		// i = -1;
		// while (++i < len_tb)
		// {
		// 	printf("%d\n", tb[i]);
		// }
	}
	else
	{
		ft_putstr_fd("Error\n", 1);
	}
	return (0);
}
