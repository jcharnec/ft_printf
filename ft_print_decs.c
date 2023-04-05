/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_decs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcharnec <jcharnec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 15:51:40 by areverte          #+#    #+#             */
/*   Updated: 2023/04/05 17:50:59 by jcharnec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
//función que toma un número entero como entrada y lo convierte 
//en una cadena de caracteres utilizando la función ft_itoa
int	ft_print_bsten(int nb)
{
	int		cont;
	char	*s;

	cont = 0;
	s = ft_itoa(nb);
	cont = ft_print_s(s);
	free(s);
	return (cont);
}

//La función que toma un número entero sin signo como entrada y 
//lo convierte en una cadena de caracteres utilizando la función ft_u_itoa
int	ft_print_decu(unsigned int nb)
{
	int		cont;
	char	*s;

	cont = 0;
	s = ft_u_itoa(nb);
	cont = ft_print_s(s);
	free(s);
	return (cont);
}
