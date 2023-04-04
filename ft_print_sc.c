/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_sc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: areverte <areverte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 15:53:33 by areverte          #+#    #+#             */
/*   Updated: 2023/02/11 15:53:34 by areverte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
//prints a string and returns the amount of characters
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

//prints a char, the function returns as a boolean
int	ft_print_char(int c)
{
	if (write (1, &c, 1) == -1)
		return (-1);
	return (1);
}
