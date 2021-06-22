/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssamadi <ssamadi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/20 15:40:29 by ssamadi           #+#    #+#             */
/*   Updated: 2021/06/20 16:39:19 by ssamadi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>

int	strleen(char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*strdup1(char *s)
{
	char	*str;
	int		i;
	int		len;

	i = 0;
	len = strleen(s);
	str = (char *)malloc(sizeof(char *) * (len + 1));
	while (s[i] != '\0')
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*strjoin1(char *s, char c)
{
	int		i;
	char	*str;
	int		len;

	i = 0;
	len = strleen(s);
	str = (char *)malloc(sizeof(char *) * (len + 1 + 1));
	while (s[i] != '\0')
	{
		str[i] = s[i];
		i++;
	}
	str[i] = c;
	str[i + 1] = '\0';
	return (str);
}

int	get_next_line(int fd, char **line)
{
	int		r;
	char	c;
	char	*tmp;

	c = '\0';
	*line = strdup1("");
	if (!*line)
		return (-1);
	r = 1;
	while (r > 0)
	{
		r = read(fd, &c, 1);
		if (r == 0)
			break ;
		if (c == '\0' || c == '\n')
		{
			c = '\0';
			break ;
		}
		tmp = *line;
		*line = strjoin1(*line, c);
		free(tmp);
	}
	return (r);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*r;
	char	*c1;
	char	*c2;
	size_t	i;

	r = (char *)malloc(strlen(s1) + strlen(s2) + 1);
	if (!s1 || !s2 || !r)
		return (NULL);
	c1 = (char *)s1;
	c2 = (char *)s2;
	i = 0;
	while (*c1)
		r[i++] = *(c1++);
	while (*c2)
		r[i++] = *(c2++);
	r[i] = '\0';
	return (r);
}
