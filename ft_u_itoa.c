/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_u_itoa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcharnec <jcharnec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 15:55:39 by areverte          #+#    #+#             */
/*   Updated: 2023/04/05 19:10:34 by jcharnec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

//función que cuenta la cantidad de dígitos en un número entero
static int	ft_dgt(long nb)
{
	int	dgt;

	dgt = 0;
	while (nb > 0)
	{
		nb = nb / 10;
		dgt++;
	}
	return (dgt);
}

//función que convierte un número entero en una cadena de caracteres
static char	*ft_tostring(char *s, int dgt, long i)
{
	while (i > 0)
	{
		s[dgt] = '0' + (i % 10);
		i = i / 10;
		dgt--;
	}
	return (s);
}

//convierte un entero sin signo en una cadena de caracteres
char	*ft_u_itoa(unsigned int n)
{
	char	*s;
	int		dgt;

	dgt = ft_dgt(n);
	if (n == 0)
	{
		s = malloc(sizeof(char) * 2);
		if (!s)
			return (NULL);
		s[0] = '0';
		s[1] = '\0';
		return (s);
	}
	s = malloc(sizeof(char) * (dgt + 1));
	if (!s)
		return (NULL);
	s[dgt] = '\0';
	dgt--;
	s = ft_tostring(s, dgt, n);
	return (s);
}
