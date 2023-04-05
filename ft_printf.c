/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcharnec <jcharnec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 15:54:07 by areverte          #+#    #+#             */
/*   Updated: 2023/04/05 19:08:58 by jcharnec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_format(va_list lst, char s)
{
	if (s == 'c')
		return (ft_print_char(va_arg(lst, int)));
	else if (s == 's')
		return (ft_print_s(va_arg(lst, char *)));
	else if (s == 'p')
		return (ft_print_ptr(va_arg(lst, void *)));
	else if (s == 'd' || s == 'i')
		return (ft_print_bsten(va_arg(lst, int)));
	else if (s == 'u')
		return (ft_print_decu(va_arg(lst, unsigned int)));
	else if (s == 'x')
		return (ft_print_hex(va_arg(lst, unsigned int)));
	else if (s == 'X')
		return (ft_print_hexmay(va_arg(lst, unsigned int)));
	else if (s == '%')
	{
		if (write (1, "%", 1) == -1)
			return (-1);
		return (1);
	}
	return (0);
}

// funcion de soporte para printf
static int	ft_printing(char const *s, va_list lst, int i, int totalc)
{
	int	cnt;

	while (s[i])
	{
		if (s[i] == '%' && s[i + 1])
		{
			cnt = ft_format(lst, s[i + 1]);
			if (cnt == -1)
				return (-1);
			totalc = totalc + cnt;
			i = i + 2;
		}
		else
		{
			if (write (1, &s[i], 1) == -1)
				return (-1);
		totalc++;
		i++;
		}
	}
	return (totalc);
}

int	ft_printf(char const *s, ...)
{
	va_list	lst;
	int		cnt;
	int		totalc;

	va_start(lst, s);
	cnt = 0;
	totalc = 0;
	totalc = ft_printing(s, lst, cnt, totalc);
	va_end(lst);
	return (totalc);
}
/*
int	main(void)
{
	ft_printf("Hola %s\n", "mundo");
	printf("Hola %s\n", "mundo");
	ft_printf("El número %d en octal es %o\n", 42, 42);
	printf("El número %d en octal es %o\n", 42, 42);
	ft_printf("El número %d en hexadecimal es %x\n", 42, 42);
	printf("El número %d en hexadecimal es %x\n", 42, 42);
	ft_printf("El número %f con dos decimales es %.2f\n", 3.14159, 3.14159);
	printf("El número %f con dos decimales es %.2f\n", 3.14159, 3.14159);
	return (0);
}
*/