/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarash <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 11:24:58 by pmarash           #+#    #+#             */
/*   Updated: 2020/11/09 13:03:28 by pmarash          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*fill_str(char *str_nb, int len, int n)
{
	if (n == 0)
		str_nb[0] = '0';
	else if (n - 1 == 2147483647)
	{
		str_nb[1] = '2';
		n = 147483648;
	}
	while (n != 0)
	{
		str_nb[len] = n % 10 + '0';
		n /= 10;
		len--;
	}
	return (str_nb);
}

static int	len_nb(int nb)
{
	int		len;

	len = 1;
	if (nb < 0)
		while (nb != 0)
		{
			nb /= 10;
			len++;
		}
	else
		while (nb > 9)
		{
			nb /= 10;
			len++;
		}
	return (len);
}

char		*ft_itoa(int n)
{
	int		sign;
	int		len;
	char	*str_nb;

	sign = 1;
	if (n < 0)
		sign = -1;
	len = len_nb(n);
	if (!(str_nb = (char*)malloc(sizeof(char) * (len + 1))))
		return (0);
	if (n == -2147483647 - 1)
	{
		ft_strlcpy(str_nb, "-2147483648", sizeof("-2147483648"));
		return (str_nb);
	}
	str_nb[len] = '\0';
	if (sign == -1)
		str_nb[0] = '-';
	n *= sign;
	len--;
	str_nb = fill_str(str_nb, len, n);
	return (str_nb);
}
