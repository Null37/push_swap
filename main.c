/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssamadi <ssamadi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/06 12:34:52 by ssamadi           #+#    #+#             */
/*   Updated: 2021/06/07 19:00:26 by ssamadi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_is_number(int ac, char **av)
{
	int	i;

	i = ac;
	return (i - 1);
}

t_all	*all_t(void)
{
	static t_all	all;

	return (&all);
}

int	max_number(int *av, int len)
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

int	min_number(int *av, int len)
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

void	swap_first_two(int table[], int len, char o)
{
	int tmp;
	t_all *all;
	
	all = all_t();
	tmp = table[0];
	table[0] = table[1];
	table[1] = tmp;
	if (o == 'a')
		write(1, "sa\n", 3);
	else if (o == 'b')
		write(1, "sb\n", 3);
}

void	add_to_table_int(char *av[], int table[])
{
	int		i;
	t_all	*all;
	
	i = 1;
	all = all_t();
	while (i <= all->len_a)
	{
		table[i - 1] = atoi(av[i]);
		i++;
	}
}

void	rotate(int table_a[], int len)
{
	int	tmp;
	int	i;

	i = 0;
	tmp = table_a[0];
	while (i < len)
	{
		table_a[i] = table_a[i + 1];
		i++;
	}
	table_a[len - 1] = tmp;
}

void	reverce_rotate(int table_a[], int len)
{
	int	tmp;
	int	i;

	i = len;
	tmp = table_a[len - 1];
	while (i > 0)
	{
		table_a[i] = table_a[i - 1];
		i--;
	}
	table_a[0] = tmp; 
}

void	push_b(int table_a[], int table_b[])
{
	int tmp;
	int	i;

	t_all *all;

	all = all_t();
	tmp = table_a[0];
	i = 0;
	while (i < all->len_a)
	{
		table_a[i] = table_a[i + 1];
		i++;
	}
	all->len_a = all->len_a-1;
	i = 0;
	while (i < all->len_b)
	{
		table_b[i + 1] = table_b[i];
		i++;
	}
	table_b[0] = tmp;
	all->len_b++;
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

void	ss_first_two(int table_a[], int table_b[])
{
	t_all *all;
	
	all = all_t();
	swap_first_two(table_a, all->len_a, 'a');
	swap_first_two(table_b, all->len_b, 'b');
}

void half_sort_five(int ta[], int tb[])
{
	t_all *all;
	
	all = all_t();
	int min = min_number(ta, all->len_a);
	int index = get_index(ta, all->len_a, min);
	//printf("min = %d || index = %d\n", min, index);
	if (index <= 2)
	{
		while (index > 0)
		{
			write(1, "ra\n", 3);
			rotate(ta, all->len_a);
			index--;
		}
	}
	else if (index > 2)
	{
		while (index < all->len_a)
		{
			write(1, "rra\n", 4);
			reverce_rotate(ta, all->len_a);
			index++;
		}
	}
	write(1, "pb\n", 3);
	// push_stack(len, ta, len_b, tb);
	
	push_b(ta, tb);
	// 	int i = 0;
	// while(i < all->len_a)
	// {
	// 	printf("%da == %d\n", ta[i], all->len_a);
	// 	i++;
	// }
}

void sort_three(int *ta)
{
	t_all *all;

	all = all_t();
	int min = min_number(ta, all->len_a);
	int max = max_number(ta, all->len_a);

	// printf("mx = %d | mn = %d\n", max, min);
	if (ta[0] == max && ta[2] == min)
	{
		write(1, "ra\n", 3);
		rotate(ta, all->len_a);
		swap_first_two(ta, all->len_a, 'a');
		return ;
	}
	if (ta[1] == min && ta[2] == max)
	{
		swap_first_two(ta, all->len_a, 'a');
		return ;
	}
	if (ta[1] == max && ta[2] == min)
	{
		write(1, "rra\n", 4);
		reverce_rotate(ta, all->len_a);
		return ;
	}
	if (ta[0] == max && ta[1] == min)
	{
		write(1, "ra\n", 3);
		rotate(ta, all->len_a);
		return ;
	}
	if (ta[0] == min && ta[1] == max)
	{
		write(1, "rra\n", 4);
		reverce_rotate(ta, all->len_a);
		swap_first_two(ta, all->len_a, 'a');
		return ;
	}
}

void	push_a(int ta[], int tb[])
{
	int tmp;
	int	i;

	t_all *all;

	all = all_t();
	tmp = tb[0];
	i = 0;
	while (i < all->len_b)
	{
		tb[i] = tb[i + 1];
		all->len_b--;
		i++;
	}
	i = all->len_a;
	while (i > 0)
	{
		ta[i] = ta[i - 1];
		i--;
	}
	ta[0] = tmp;
	all->len_a++;
}

void sort_five(int ta[], int tb[])
{
	t_all *all;
	
	all = all_t();
	half_sort_five(ta, tb);
	half_sort_five(ta, tb);
	
	if (all->len_a == 3)
		sort_three(ta);
	push_a(ta, tb);
	push_a(ta, tb);
	//push_stack(len_b, tb, len, ta);
		// printf("%d =\n", *len_b);

	
	//push_stack(len_b, tb, len, ta);
	write(1, "pa\npa\n", 6);
}

void	sort_two(int ta[])
{
	t_all *all;
	
	all = all_t();
	int max = max_number(ta, all->len_a);
	if(max == ta[0])
		swap_first_two(ta, all->len_a, 'a');
}

void	sort_four(int ta[], int tb[])
{
	t_all *all;
	
	all = all_t();
	int max = max_number(ta, all->len_a);
	int index = get_index(ta, all->len_a, max);
	// printf("%d\n", index);
	if (index == 3)
	{
		reverce_rotate(ta, all->len_a);
		write(1, "rra\n", 4);
	}
	else
	{
		while(index > 0)
		{
			rotate(ta, all->len_a);
			write(1, "ra\n", 3);
			index--;
		}
	}
	push_b(ta, tb);
	write(1, "pb\n", 3);
	sort_three(ta);
	push_a(ta, tb);
	write(1, "pa\n", 3);
	rotate(ta, all->len_a);
	write(1, "ra\n", 3);
	// int i = 0;
	// while (i < all->len_a)
	// {
	// 	printf("%d\n", ta[i]);
	// 	i++;
	// }
	
	
}

void	half_twenty(int ta[], int tb[])
{
	t_all *all;

	all = all_t();
	int min = min_number(ta, all->len_a);
	int index = get_index(ta, all->len_a, min);

	int size = all->len_a / 2;
	printf("min == %d | index == %d | size == %d\n", min, index, size);
	if (index <= size)
	{
		while (index > 0)
		{
			write(1, "ra\n", 3);
			rotate(ta, all->len_a);
			index--;
		}
	}
	else if (index > size)
	{
		while (index < all->len_a)
		{
			write(1, "rra\n", 4);
			reverce_rotate(ta, all->len_a);
			index++;
		}
	}
	int i = 0;
	while(i < all->len_a)
	{
		printf("%da == %d\n", ta[i], all->len_a);
		i++;
	}
	write(1, "pb\n", 3);
	push_b(ta, tb);
	i = 0;
	while(i < all->len_b)
	{
		printf("%db\n", tb[i]);
		i++;
	}
}

void	sort_twenty(int ta[], int tb[])
{
	t_all *all;

	all = all_t();
	int i = 0;
	while(i < all->len_a)
	{
		half_twenty(ta, tb);
		i++;
	}
	i = 0;
	// while (i < all->len_b)
	// {
	// 	write(1, "pa\n", 3);
	// 	push_a(ta, tb);
	// 	i++;
	// }
	
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

	t_all *all;
	
	all = all_t();
	all->len_a = ac - 1;
	all->len_b = 0;
	add_to_table_int(av, table_a);
	//swap_first_two(table_a, len, 'a');
	//ss_first_two(table_a, table_b);
	//rotate(table_a, len);
	//reverce_rotate(table_a, len);
	//push_b(table_a, table_b, &len);
	// printf("ac === %d\n", ac);///*
	//printf("%d", all->len_b);
	if (all->len_a == 2)
		sort_two(table_a);
	else if (all->len_a == 3)
		sort_three(table_a);
	else if (all->len_a == 4)
		sort_four(table_a, table_b);
	else if (all->len_a == 5)
		sort_five(table_a, table_b);
	else if (all->len_a >= 6 && all->len_a <= 20)
		sort_twenty(table_a, table_a);
	i = 0;
	// while(i < all->len_a)
	// {
	// 	printf("%da == %d\n", table_a[i], all->len_a);
	// 	i++;
	// }
	// i = 0;
	// while(i < all->len_b)
	// {
	// 	printf("%db\n", table_b[i]);
	// 	i++;
	// }
	return (0);
}