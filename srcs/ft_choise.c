/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpinson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/23 14:27:32 by mpinson           #+#    #+#             */
/*   Updated: 2017/04/15 14:32:16 by mpinson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

char	*ft_largeur_no2(char *str, t_glob *g)
{
	while (g->flag_largeur - 1 && !g->flag_neg && g->flag_0)
	{
		str = ft_strjoin("0", str);
		g->flag_largeur--;
	}
	while (g->flag_largeur - 1 && g->flag_neg)
	{
		str = ft_strjoin(str, " ");
		g->flag_largeur--;
	}
	return (str);
}

int		ft_largeur_no(char c, t_glob *g)
{
	char *str;

	if (!(str = (char *)malloc(sizeof(char) * 2)))
		return (-1);
	str[0] = c;
	str[1] = 0;
	!g->flag_largeur ? ft_putchar(c) : 0;
	if (!g->flag_largeur)
		return (1);
	while (g->flag_largeur - 1 && !g->flag_neg && !g->flag_0)
	{
		str = ft_strjoin(" ", str);
		g->flag_largeur--;
	}
	str = ft_largeur_no2(str, g);
	ft_putstr(str);
	return (ft_strlen(str));
}

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
	return (ft_largeur_no(g->type, g));
}
