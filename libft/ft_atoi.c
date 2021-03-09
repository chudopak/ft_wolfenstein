/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarash <pmarash@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 12:59:15 by pmarash           #+#    #+#             */
/*   Updated: 2020/12/09 16:15:34 by pmarash          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned long	auxiliary(char *str)
{
	unsigned long	i;

	i = 0;
	while (*str >= '0' && *str <= '9')
	{
		i = i * 10 + (*str - '0');
		str++;
	}
	return (i);
}

int						ft_atoi(char *str)
{
	int				znac;
	unsigned long	i;

	znac = 1;
	i = 0;
	while (*str == ' ' || *str == '\t' || *str == '\n' || *str == '\v'
		|| *str == '\b' || *str == '\a' || *str == '\f' || *str == '\r')
		str++;
	if (*str == '+')
		str++;
	else if (*str == '-')
	{
		znac = -1;
		str++;
	}
	if (*str < '0' || *str > '9')
		return (0);
	i = auxiliary(str);
	if (i > 9223372036854775807 && znac == 1)
		return (-1);
	if (i > 9223372036854775807 && znac == -1)
		return (0);
	return (znac * i);
}
