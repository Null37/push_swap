/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssamadi <ssamadi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/06 12:34:52 by ssamadi           #+#    #+#             */
/*   Updated: 2021/06/08 19:16:09 by ssamadi          ###   ########.fr       */
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
	all->len_a--;
	i = all->len_b;
	while (i > 0)
	{
		table_b[i] = table_b[i - 1];
		i--;
	}
	table_b[0] = tmp;
	all->len_b++;
}

int get_index(int ta[], int len, int min)
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
	//printf("min == %d | index == %d | size == %d\n", min, index, size);
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
	// int  i = 0;
	// while(i < all->len_a)
	// {
	// 	printf("%da == %d\n", ta[i], all->len_a);
	// 	i++;
	// }
	write(1, "pb\n", 3);
	push_b(ta, tb);
	// i = 0;
	// while(i < all->len_a)
	// {
	// 	printf("%da == %d\n", ta[i], all->len_a);
	// 	i++;
	// }
	// write(1, "pb\n", 3);
	// //push_b(ta, tb);
	// i = 0;
	// while(i < all->len_b)
	// {
	// 	printf("%db\n", tb[i]);
	// 	i++;
	// }
	// i = 0;
	// while(i < all->len_a)
	// {
	// 	printf("%da == %d\n", ta[i], all->len_a);
	// 	i++;
	// }
	// i = 0;
	// while(i < all->len_b)
	// {
	// 	printf("%db\n", tb[i]);
	// 	i++;
	// }
}

void	sort_twenty(int ta[], int tb[])
{
	t_all *all;

	all = all_t();
	int i = all->len_a;
	while (i)
	{
		half_twenty(ta, tb);
		i--;
	}
	//printf("len == > |%d|\n", all->len_a);
	//push_a(ta, tb);
	// push_a(ta, tb);
	// push_a(ta, tb);
	// push_a(ta, tb);
	// printf("=======> %d\n", all->len_b);
	int b = all->len_b;
	while (b > 0)
	{
		write(1, "pa\n", 3);
		push_a(ta, tb);
		b--;
	}
	
	// push_a(ta, tb);
	// push_a(ta, tb);
	// push_a(ta, tb);
	// i = 0;
	// while (i < all->len_b)
	// {
	// 	write(1, "pa\n", 3);
	// 	push_a(ta, tb);
	// 	i++;
	// }
	
}



void	half_addmin(int table_c[], int table_min[], int k)
{
	t_all *all;

	all = all_t();
	int min = min_number(table_c, all->len_c);
	int index = get_index(table_c, all->len_c, min);
	//printf("index == %d | min == %d\n", index, min);
	int  i = 0;
	table_min[k] = table_c[index];
	table_c[index] = table_c[index + 1];
	all->len_c--;
}

void	add_min(int table_c[], int table_min[], int k)
{
	t_all *all;

	all = all_t();
	int i = 0;
	while (i < k)
	{
		half_addmin(table_c, table_min, i);
		i++;
	}
}

int	check_ith_range(int table_min[], int ta)
{
	int i = 0;
	t_all *all;

	all = all_t();
	while (i < all->len_min)
	{
		if (table_min[i] == ta)
			return (2);
		i++;
	}
	return (-1);
}

void	start_sort_hundred(int table_a[], int table_b[], int table_c[], int table_min[])
{
	t_all *all;

	all = all_t();
	all->len_min = 4;
	int i = 0;
	int j = all->len_a;
	while (i < all->len_a)
	{
		if (check_ith_range(table_min, table_a[0]) == 2)
		{
			write(1, "pb\n", 3);
			push_b(table_a, table_b);
			continue ;
		}
		if (i < j && check_ith_range(table_min, table_a[++i]) == 2)
		{
			write(1, "ra\n", 3);
			rotate(table_a, all->len_a);
			i = 0;
		}
		else if (i < j && check_ith_range(table_min, table_a[--j]) == 2)
		{
			write(1, "rra\n", 4);
			reverce_rotate(table_a, all->len_a);
			j = all->len_a;
		}
	}
}

void	half_sor_hundred(int table_a[], int table_b[], int table_c[], int table_min[])
{
	t_all *all;

	all = all_t();
}

void	sort_hundred(int table_a[], int table_b[], int table_c[], int table_min[])
{
	t_all *all;

	all = all_t();
	
	int i = 0;
	// while(i < 4)
	// {
	// 	printf("\nmin ==> %dm\n", table_min[i]);
	// 	i++;
	// }
	
	// while(i < 4)
	// {
		add_min(table_c, table_min, 4);
		i = 0;
		while(i < 4)
		{
			printf("\nmin ==> %dm\n", table_min[i]);
			i++;
		}
		// start_sort_hundred(table_a, table_b, table_c, table_min);
		// add_min(table_c, table_min, 4);
		// i = 0;
		// while(i < 2)
		// {
		// 	printf("\nmin ==> %dm\n", table_min[i]);
		// 	i++;
		// }
	// 	i++;
	// }
	// if(all->len_a < 4)
	// {
	// 	int min = 
	// }
	// i = 0;
	// while(i < all->len_a)
	// {
	// 	printf("%da\n", table_a[i]);
	// 	i++;
	// }
	// i = 0;
	// while(i < all->len_b)
	// {
	// 	printf("%db\n", table_b[i]);
	// 	i++;
	// }
	// add_min(table_c, table_min, all->len_a);
	
}


int	main(int ac, char *av[])
{
	int	check;
	int	i;
	int len;
	int table_a[ac];
	int table_b[ac];
	int table_c[ac];
	int table_min[ac];
	int	max;
	int	min;

	t_all *all;
	
	all = all_t();
	all->len_a = ac - 1;
	all->len_c = ac - 1;
	all->len_b = 0;
	add_to_table_int(av, table_a);
	add_to_table_int(av, table_c);
	//add_min(table_c, table_min, 4);
	//swap_first_two(table_a, len, 'a');
	//ss_first_two(table_a, table_b);
	//rotate(table_a, len);
	//reverce_rotate(table_a, len);
	//push_b(table_a, table_b, &len);
	// printf("ac === %d\n", ac);///*
	//printf("%d", all->len_b);
	// if (all->len_a == 2)
	// 	sort_two(table_a);
	// else if (all->len_a == 3)
	// 	sort_three(table_a);
	// else if (all->len_a == 4)
	// 	sort_four(table_a, table_b);
	// else if (all->len_a == 5)
	// 	sort_five(table_a, table_b);
	// else if (all->len_a >= 6 && all->len_a <= 20)
	// 	sort_twenty(table_a, table_b);
	// else if (all->len_a > 20 && all->len_a <= 150)
		sort_hundred(table_a, table_b, table_c, table_min);
	// i = 0;
	// while(i < all->len_c)
	// {
	// 	printf("%dc == %d\n", table_c[i], all->len_c);
	// 	i++;
	// }
	// i = 0;
	// while(i < 4)
	// {
	// 	printf("\nmin ==> %dm == %d\n", table_min[i], all->len_c);
	// 	i++;
	// }
	return (0);
}