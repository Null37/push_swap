/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssamadi <ssamadi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/06 12:34:52 by ssamadi           #+#    #+#             */
/*   Updated: 2021/06/10 15:43:57 by ssamadi          ###   ########.fr       */
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
	
	i = 0;
	all = all_t();
	while (av[i] != NULL)
	{
		table[i] = atoi(av[i]);
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
	int  i = index;
	table_min[k] = table_c[index];
	while (i < all->len_c - 1)
	{
		table_c[i] = table_c[i + 1];
		i++;
	}
	
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
void	print_table(int len, int t[len])
{
	int i;

	i = -1;
	fprintf(stderr, "\n");
	while (++i<len)
	{
		fprintf(stderr, "%d ", t[i]);
	}
	
}
void	start_sort_hundred(int table_a[], int table_b[], int table_c[], int table_min[])
{
	t_all *all;

	all = all_t();
	int d = all->len_min;
	int i = 0;
	int j = all->len_a;
	while (1)
	{
		if (all->len_a <= 0 || d == 0)
			break ;
		if (check_ith_range(table_min, table_a[0]) == 2)
		{
			d--;
			write(1, "pb\n", 3);
			push_b(table_a, table_b);
			continue ;
		}
		if (i < j && check_ith_range(table_min, table_a[++i]) == 2)
		{
			write(1, "ra\n", 3);
			rotate(table_a, all->len_a);
			i = 0;
			j = all->len_a;
		}
		else if (i < j && check_ith_range(table_min, table_a[--j]) == 2)
		{
			write(1, "rra\n", 4);
			reverce_rotate(table_a, all->len_a);
			j = all->len_a;
			i = 0;
		}
	}
}

void	push_max_t_a(int table_a[], int table_b[])
{
	t_all *all;
	int	i;
	int max;
	int index;
	all = all_t();
	max = max_number(table_b, all->len_b);
	index = get_index(table_b, all->len_b, max);
	int size = all->len_b / 2;
	if (index <= size)
	{
		while (index > 0)
		{
			write(1, "rb\n", 3);
			rotate(table_b, all->len_b);
			index--;
		}
	}
	else if (index > size)
	{
		while (index < all->len_b)
		{
			write(1, "rrb\n", 4);
			reverce_rotate(table_b, all->len_b);
			index++;
		}
	}
	if (all->len_b > 0)
	{
		write(1, "pa\n", 3);
		push_a(table_a, table_b);
	}
}

void	sort_hundred(int table_a[], int table_b[], int table_c[], int table_min[])
{
	t_all *all;

	all = all_t();
	int i;
	// while(i < 4)
	// {
	// 	//printf("\nmin ==> %dm\n", table_min[i]);
	// 	i++;
	// }
	
	// while(i < 4)
	// {
		//add_min(table_c, table_min, 4);
		// i = 0;
		// while(i < 4)
		// {
		// 	printf("\nmin ==> %dm\n", table_min[i]);
		// 	i++;
		// }
		i = 0;
		//start_sort_hundred(table_a, table_b, table_c, table_min);
		while (all->len_a > 0)
		{
			if (all->len_a > all->group)
			{
				add_min(table_c, table_min, all->group);
				all->len_min = all->group;
			}
			else
			{
				add_min(table_c, table_min, all->len_a);
				all->len_min = all->len_a;
			}
			start_sort_hundred(table_a, table_b, table_c, table_min);
		}
		while (all->len_b > 0)
		{
			push_max_t_a(table_a, table_b);
		}
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
	// add_min(table_c, table_min, all->len_a);
	
}

void	start(int ac)
{
	t_all *all;

	all = all_t();
	all->len_a = ac - 1;
	all->len_c = ac - 1;
	all->len_sort = ac -1;
	all->len_b = 0;
	all->table_a = malloc(sizeof(int) * ac);
	all->table_b = malloc(sizeof(int) * ac);
	all->table_c = malloc(sizeof(int) * ac);
	all->table_min = malloc(sizeof(int) * ac);
	all->sor_table = malloc(sizeof(int) * ac);
}

void	norm_list(char **ar)
{
	int	i;

	t_all *all;
	
	all = all_t();
	i = 0;
	while (all->args && all->args[i])
	{
		all->tmp[i] = all->args[i];
		i++;
	}
	all->j = 0;
	while (ar[all->j])
	{
		all->tmp[i] = ar[all->j];
		i++;
		all->j++;
	}
	all->tmp[i] = NULL;
	all->args = all->tmp;
}

void    add_in_list(char **ar)
{
	int	i;
	t_all *all;
	
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
	all->tmp = malloc(sizeof(char *) * (all->c + all->c2) + 1);
	norm_list(ar);
}

void	rem_args(char **av)
{
	int		i;
	char	**ar;
	int		c;
	t_all *all;
	
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

void swap(int *xp, int *yp)
{
	int temp = *xp;
	*xp = *yp;
	*yp = temp;
}
 
// A function to implement bubble sort
void	bubblesort(int arr[], int n)
{
	int i, j;
	for (i = 0; i < n-1; i++)
 
	   // Last i elements are already in place  
	   for (j = 0; j < n-i-1; j++)
		   if (arr[j] > arr[j+1])
			  swap(&arr[j], &arr[j+1]);
}
 
/* Function to print an array */
void printArray(int arr[], int size)
{
	int i;
	for (i=0; i < size; i++)
		printf("%d ", arr[i]);
	printf("\n");
}

int	check_table_sort()
{
	t_all *all;

	all = all_t();
	int i = 0;
	while(i < all->len_sort)
	{
		if(all->sor_table[i] == all->table_a[i])
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

int	check_erros(char **av)
{
	t_all *all;

	all = all_t();
	int i = 0;
	int j;
	while(av[i])
	{
		if (*av[i] == '-' || *av[i] == '+')
			if (t_isdigit(av[i][1]) != 1)
				return (-1);
		if (t_isdigit(*av[i]) != 1 && *av[i] != '-' && *av[i] != '+')
			return (-1);
		i++;
	}
	return (0);
}

int	check_double(int ac)
{
	int	i;
	int j;

	j = 0;
	i = 0;
	t_all *all;
	
	all = all_t();
	while(i < ac - 1)
	{
		j = 0;
		while (j < ac -1)
		{
			if(i != j && all->table_a[i] == all->table_a[j])
				return (-1);
			j++;
		}
		i++;
	}
	return (0);
}

int	main(int ac, char *av[])
{
	t_all *all;

	all = all_t();
	char	*line;;
	char c;

	start(ac);
	rem_args(av);
	if (check_erros(all->args) == -1)
	{
		write(1, "Error\n", 6);
		return (-1);
	}
	add_to_table_int(all->args, all->table_a);
	if (check_double(ac) == -1)
	{
		write(1, "Error\n", 6);
		return (-1);
	}
	add_to_table_int(all->args, all->table_c);
	add_to_table_int(all->args, all->sor_table);
	bubblesort(all->sor_table, all->len_sort);
	if (check_table_sort() == 1)
	{
		if (all->len_a == 2)
			sort_two(all->table_a);
		else if (all->len_a == 3)
			sort_three(all->table_a);
		else if (all->len_a == 4)
			sort_four(all->table_a, all->table_b);
		else if (all->len_a == 5)
			sort_five(all->table_a, all->table_b);
		else if (all->len_a >= 6 && all->len_a <= 20)
			sort_twenty(all->table_a, all->table_b);
		else if (all->len_a > 20 && all->len_a <= 150)
		{
			all->group = all->len_c / 6;
			sort_hundred(all->table_a, all->table_b, all->table_c, all->table_min);
		}
		else if (all->len_a > 20 && all->len_a > 150)
		{
			all->group = all->len_c / 12;
			sort_hundred(all->table_a, all->table_b, all->table_c, all->table_min);
		}
	}
	return (0);
}