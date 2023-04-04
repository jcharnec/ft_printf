/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: areverte <areverte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 15:52:32 by areverte          #+#    #+#             */
/*   Updated: 2023/02/11 15:52:33 by areverte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_hex(unsigned int nb)
{
	int		cont;
	int		sub_count;
	char	*s;

	cont = 0;
	sub_count = 0;
	s = "0123456789abcdef";
	if (nb >= 16)
	{
		sub_count = ft_print_hex(nb / 16);
		if (sub_count == -1)
			return (-1);
		cont = cont + sub_count;
		sub_count = ft_print_hex(nb % 16);
		if (sub_count == -1)
			return (-1);
		cont = cont + sub_count;
	}
	else
	{
		if (write (1, &s[nb], 1) == -1)
			return (-1);
		cont++;
	}
	return (cont);
}

int	ft_print_hexmay(unsigned int nb)
{
	int		cont;
	int		sub_count;
	char	*s;

	cont = 0;
	sub_count = 0;
	s = "0123456789ABCDEF";
	if (nb >= 16)
	{
		sub_count = ft_print_hexmay(nb / 16);
		if (sub_count == -1)
			return (-1);
		cont = cont + sub_count;
		sub_count = ft_print_hexmay(nb % 16);
		if (sub_count == -1)
			return (-1);
		cont = cont + sub_count;
	}
	else
	{
		if (write (1, &s[nb], 1) == -1)
			return (-1);
		cont++;
	}
	return (cont);
}
