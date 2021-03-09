/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarash <pmarash@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 16:15:33 by pmarash           #+#    #+#             */
/*   Updated: 2020/12/23 16:15:59 by pmarash          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_puthex(unsigned int nb, int registr)
{
	if (nb / 16 != 0)
		ft_puthex(nb / 16, registr);
	if (nb % 16 < 10)
		ft_putchar(nb % 16 + '0');
	else
	{
		if (registr == 0)
			ft_putchar('a' + (nb % 16) % 10);
		else
			ft_putchar('A' + (nb % 16) % 10);
	}
}
