/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcharnec <jcharnec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 15:54:29 by areverte          #+#    #+#             */
/*   Updated: 2023/04/04 14:04:02 by jcharnec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdio.h>
# include <stdarg.h>
# include <stdlib.h>

int		ft_printf(char const *s, ...);
int		ft_print_s(char *s);
int		ft_print_char(int c);
int		ft_print_hex(unsigned int nb);
int		ft_print_hexmay(unsigned int nb);
int		ft_print_ptr(void *p);
int		ft_print_bsten(int nb);
int		ft_print_decu(unsigned int nb);
char	*ft_itoa(int n);
char	*ft_u_itoa(unsigned int n);

#endif
