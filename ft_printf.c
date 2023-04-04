/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcharnec <jcharnec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 15:54:07 by areverte          #+#    #+#             */
/*   Updated: 2023/04/04 18:10:41 by jcharnec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_type(va_list lst, char c)
{
	if (c == 'c')
		return (ft_print_char(va_arg(lst, int)));
	else if (c == 's')
		return (ft_print_s(va_arg(lst, char *)));
	else if (c == 'p')
		return (ft_print_ptr(va_arg(lst, void *)));
	else if (c == 'd' || c == 'i')
		return (ft_print_bsten(va_arg(lst, int)));
	else if (c == 'u')
		return (ft_print_decu(va_arg(lst, unsigned int)));
	else if (c == 'x')
		return (ft_print_hex(va_arg(lst, unsigned int)));
	else if (c == 'X')
		return (ft_print_hexmay(va_arg(lst, unsigned int)));
	else if (c == '%')
	{
		if (write (1, "%", 1) == -1)
			return (-1);
		return (1);
	}
	return (0);
}

// function support to printf
static int	ft_printing(char const *s, va_list lst, int cont, int totalc)
{
	int	sub_count;

	while (s[cont])
	{
		if (s[cont] == '%' && s[cont + 1])
		{
			sub_count = ft_type(lst, s[cont + 1]);
			if (sub_count == -1)
				return (-1);
			totalc = totalc + sub_count;
			cont = cont + 2;
		}
		else
		{
			if (write (1, &s[cont], 1) == -1)
				return (-1);
		totalc++;
		cont++;
		}
	}
	return (totalc);
}

int	ft_printf(char const *s, ...)
{
	va_list	lst;
	int		cont;
	int		totalc;

	va_start(lst, s);
	cont = 0;
	totalc = 0;
	totalc = ft_printing(s, lst, cont, totalc);
	va_end(lst);
	return (totalc);
}
