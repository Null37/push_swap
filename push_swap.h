/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssamadi <ssamadi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/06 12:46:14 by ssamadi           #+#    #+#             */
/*   Updated: 2021/06/09 19:26:56 by ssamadi          ###   ########.fr       */
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
	int	*table_c;
}   t_all;

#endif
