/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssamadi <ssamadi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/06 12:46:14 by ssamadi           #+#    #+#             */
/*   Updated: 2021/06/15 14:05:55 by ssamadi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include "libft1/libft.h"

# define  LONG_L long long

typedef struct s_all
{
	LONG_L	len_a;
	LONG_L	len_b;
	LONG_L	len_c;
	LONG_L	len_min;
	long	group;
	LONG_L	*table_a;
	LONG_L	*table_b;
	LONG_L	*table_min;
	LONG_L	*sor_table;
	LONG_L	len_sort;
	LONG_L	*table_c;
	char	**args;
	int		c;
	int		c2;
	int		ac;
	char	**tmp;
	char	**sp_line;
	int		j;
	LONG_L	d;
	LONG_L	i;
	LONG_L	jj;
}	t_all;

LONG_L	ft_my_atoi(const char *str);
LONG_L	max_number(LONG_L *av, LONG_L len);
LONG_L	min_number(LONG_L *av, LONG_L len);
void	swap_first_two(LONG_L table[], char o);
void	add_to_table_int(char *av[], LONG_L table[]);
void	rotate(LONG_L table_a[], LONG_L len);
void	reverce_rotate(LONG_L table_a[], LONG_L len);
void	push_b(LONG_L table_a[], LONG_L table_b[]);
LONG_L	get_index(LONG_L ta[], LONG_L len, LONG_L min);
void	ss_first_two(LONG_L table_a[], LONG_L table_b[]);
void	loop_rra(LONG_L	index, LONG_L ta[]);
void	half_sort_five(LONG_L ta[], LONG_L tb[]);
void	loop_rra(LONG_L	index, LONG_L ta[]);
int		half_sort_three(LONG_L	min, LONG_L	max, LONG_L *ta);
void	push_a(LONG_L ta[], LONG_L tb[]);
void	sort_three(LONG_L *ta);
void	sort_five(LONG_L ta[], LONG_L tb[]);
void	sort_two(LONG_L ta[]);
void	half_sort_four(LONG_L ta[], LONG_L tb[]);
void	sort_four(LONG_L ta[], LONG_L tb[]);
void	sort_twenty(LONG_L ta[], LONG_L tb[]);
void	half_addmin(LONG_L table_c[], LONG_L table_min[], LONG_L k);
void	add_min(LONG_L table_c[], LONG_L table_min[], LONG_L k);
int		check_ith_range(LONG_L table_min[], LONG_L ta);
int		check_max_int(void);
t_all	*all_t(void);
void	start_sort_hundred(LONG_L table_a[], LONG_L table_b[],
			LONG_L table_min[]);
void	sort_hundred(LONG_L table_a[], LONG_L table_b[],
			LONG_L table_c[], LONG_L table_min[]);
void	half_twenty(LONG_L ta[], LONG_L tb[]);
void	push_max_t_a(LONG_L table_a[], LONG_L table_b[]);
void	start(void);
void	norm_list(char **ar);
void	add_in_list(char **ar);
void	rem_args(char **av);
void	swap(LONG_L *xp, LONG_L *yp);
int		check_table_sort(void);
int		t_isdigit(char number);
void	bubblesort(LONG_L arr[], LONG_L n);
void	half_main(t_all *all);
int		check_double(void);
int		check_erros(char **av);

#endif
