/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: areverte <areverte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 15:51:14 by areverte          #+#    #+#             */
/*   Updated: 2023/02/11 15:51:15 by areverte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

//returns the number of digits of a number
static int	ft_digits(long nb)
{
	int	digits;

	digits = 0;
	if (nb < 0)
	{
		nb = nb * -1;
		digits++;
	}
	while (nb > 0)
	{
		nb = nb / 10;
		digits++;
	}
	return (digits);
}

//this function fills up the string
static char	*ft_tostring(char *s, int digits, long i)
{
	if (i < 0)
	{
		s[0] = '-';
		i = i * -1;
	}
	while (i > 0)
	{
		s[digits] = '0' + (i % 10);
		i = i / 10;
		digits--;
	}
	return (s);
}

//itoa normal, int to String
char	*ft_itoa(int n)
{
	char	*s;
	int		digits;

	digits = ft_digits(n);
	if (n == 0)
	{
		s = malloc(sizeof(char) * 2);
		if (!s)
			return (NULL);
		s[0] = '0';
		s[1] = '\0';
		return (s);
	}
	s = malloc(sizeof(char) * (digits + 1));
	if (!s)
		return (NULL);
	s[digits] = '\0';
	digits--;
	s = ft_tostring(s, digits, n);
	return (s);
}
