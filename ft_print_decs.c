/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_decs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: areverte <areverte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 15:51:40 by areverte          #+#    #+#             */
/*   Updated: 2023/02/11 15:51:41 by areverte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
//this func prints a number a frees the memory
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

//this function prints a positive number and frees the memory
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
