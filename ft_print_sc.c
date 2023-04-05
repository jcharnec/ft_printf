/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_sc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcharnec <jcharnec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 15:53:33 by areverte          #+#    #+#             */
/*   Updated: 2023/04/05 18:00:12 by jcharnec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
//función que imprime una cadena de caracteres y 
//devuelve la cantidad de caracteres impresos.
int	ft_print_s(char *s)
{
	int	cont;

	cont = 0;
	if (!s)
	{
		if (write (1, "(null)", 6) == -1)
			return (-1);
		return (6);
	}
	while (s[cont])
	{
		if (write (1, &s[cont], 1) == -1)
			return (-1);
		cont++;
	}
	return (cont);
}

//función que imprime un carácter y devuelve un valor 
//booleano que indica si la operación fue exitosa o no.
int	ft_print_char(int c)
{
	if (write (1, &c, 1) == -1)
		return (-1);
	return (1);
}
