/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssamadi <ssamadi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/06 12:46:14 by ssamadi           #+#    #+#             */
/*   Updated: 2021/06/10 11:45:59 by ssamadi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "libft1/libft.h"

typedef struct s_all
{
	int	len_a;
	int	len_b;
	int	len_c;
	int	len_min;
	int	group;
	int	*table_a;
	int	*table_b;
	int	*table_min;
	int	*sor_table;
	int	len_sort;
	int	*table_c;
	char **args;
	int	c;
	int	c2;
	int ac;
	char **tmp;
	int j;
}   t_all;

#endif
