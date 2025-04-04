/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcharnec <jcharnec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 15:53:06 by areverte          #+#    #+#             */
/*   Updated: 2023/04/05 17:36:13 by jcharnec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

//función recursiva que imprime un número en hexadecimal
//y devuelve la cantidad de números que se imprimieron
static int	ft_print_hexp(unsigned long long nb)
{
	int		cont;
	int		sub_ret;
	char	*s;

	cont = 0;
	sub_ret = 0;
	s = "0123456789abcdef";
	if (nb >= 16)
	{
		sub_ret = ft_print_hexp(nb / 16);
		if (sub_ret == -1)
			return (-1);
		cont = cont + sub_ret;
		sub_ret = ft_print_hexp(nb % 16);
		if (sub_ret == -1)
			return (-1);
		cont = cont + sub_ret;
	}
	else
	{
		if (write (1, &s[nb], 1) == -1)
			return (-1);
		cont++;
	}
	return (cont);
}

//función que imprime un puntero en hexadecimal 
//y devuelve la cantidad de números que se imprimieron.
int	ft_print_ptr(void *p)
{
	if (!p)
		return (ft_print_s("0x0"));
	if (write (1, "0x", 2) == -1)
		return (-1);
	return (ft_print_hexp((unsigned long long) p) + 2);
}
