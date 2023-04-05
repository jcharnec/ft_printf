/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcharnec <jcharnec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 15:52:32 by areverte          #+#    #+#             */
/*   Updated: 2023/04/05 17:45:44 by jcharnec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

//función recursiva que imprime un número en hexadecimal 
//y devuelve la cantidad de números que se imprimieron.
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

//función recursiva que imprime un número en hexadecimal en
//mayusculas y devuelve la cantidad de números que se imprimieron.
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
