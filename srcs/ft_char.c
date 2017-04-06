/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_char.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpinson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/22 19:47:35 by mpinson           #+#    #+#             */
/*   Updated: 2017/03/23 18:47:00 by mpinson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	ft_unichar(va_list *ap, t_glob *g)
{
	wchar_t	str;
	wchar_t	*s;
	int		i;

	i = 0;
	str = va_arg(ap[0], wchar_t);
	if (g->flag_largeur < 2)
		return (ft_uni_putchar(str));
	if (!(s = (wchar_t *)malloc(sizeof(wchar_t) * 2)))
		return (-1);
	while (g->flag_largeur-- - 1 && !g->flag_neg)
		s[i++] = ' ';
	if (!g->flag_neg)
		s[i] = str;
	while (g->flag_largeur-- - 1 && g->flag_neg)
	{
		s[0] = str;
		s[i++ + 1] = ' ';
	}
	return (ft_uni_putstr(s));
}

int	ft_char(va_list *ap, t_glob *g)
{
	unsigned char	str;
	char			*s;
	int				i;

	i = 0;
	if (g->flagl == 1)
		return (ft_unichar(ap, g));
	str = va_arg(ap[0], int);
	g->flag_largeur < 2 ? ft_putchar(str) : 0;
	if (g->flag_largeur < 2)
		return (1);
	if (!(s = (char *)malloc(sizeof(char) * 2)))
		return (-1);
	while (g->flag_largeur-- - 1 && !g->flag_neg)
		s[i++] = ' ';
	!g->flag_neg ? s[i] = str : 0;
	while (g->flag_largeur-- && g->flag_neg)
	{
		s[0] = str;
		s[i++ + 1] = ' ';
	}
	if (str != 0)
		return (write(1, s, ft_strlen(s)));
	return (write(1, s, ft_strlen(s) + 1));
}
