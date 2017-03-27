/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpinson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/23 14:27:32 by mpinson           #+#    #+#             */
/*   Updated: 2017/03/23 19:24:08 by mpinson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int		ft_time(va_list *ap, t_glob *g)
{
	if (g->type == '%')
		return (ft_pourcent(g));
	return (ft_printf("%.2s:%.2s:%-04.4s",
			ft_strsub(ft_itoa(va_arg(ap[0], int)), 0, 2),
					ft_strsub(ft_itoa(va_arg(ap[0], int)), 0, 2),
					ft_strsub(ft_itoa(va_arg(ap[0], int)), 0, 4)));
}

int		ft_choise(va_list *ap, t_glob *g)
{
	if (g->type == 0)
	{
		ft_putchar('%');
		return (1);
	}
	if (g->type == 'p')
		return (ft_pointeur(ap, g));
	if (g->type == 's')
		return (ft_string(ap, g));
	if (g->type == 'S')
		return (ft_uni_string(ap, g));
	if (g->type == 'd' || g->type == 'i' || g->type == 'u' || g->type == 'U'
		|| g->type == 'D' || g->type == 'f' || g->type == 'F')
		return (ft_int(ap, g));
	if (g->type == 'c')
		return (ft_char(ap, g));
	if (g->type == 'C')
		return (ft_unichar(ap, g));
	if (g->type == 'o' || g->type == 'O' || g->type == 'x' || g->type == 'X'
		|| g->type == 'b')
		return (ft_base(ap, g));
	if (g->type == 'k' || g->type == '%')
		return (ft_time(ap, g));
	return (0);
}
