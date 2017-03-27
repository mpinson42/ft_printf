/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpinson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/24 17:40:46 by mpinson           #+#    #+#             */
/*   Updated: 2017/03/24 17:40:48 by mpinson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int		ft_largeur(int i, t_glob *g, char c)
{
	int tmp;

	i = g->flag_largeur - i - 1;
	if (g->flag_more == 1)
		i--;
	tmp = i;
	while (i >= 0)
	{
		ft_putchar(c);
		i--;
	}
	return (tmp);
}

int		ft_pourcent(t_glob *g)
{
	int i;

	i = 1;
	if ((g->flag_largeur != 0 && g->flag_neg == 0 && g->flag_0 == 0) ||
			(g->presision > -1 && g->flag_0 == 0 && g->flag_neg == 0))
		i = i + ft_largeur(i, g, '0');
	if ((g->flag_largeur != 0 && g->flag_neg == 0 && g->flag_0 == 1) ||
			(g->presision > -1 && g->flag_0 == 1 && g->flag_neg == 0))
	{
		i = i + ft_largeur(i, g, ' ');
	}
	ft_putchar('%');
	if (g->flag_largeur != 0 && g->flag_neg == 1)
		i = i + ft_largeur(i, g, ' ');
	if (i == 1 || i == 0 || i == -1)
		return (1);
	else
		return (i + 1);
}

char	*ft_largeur_ptr(char *ptr, int tmp, char *str, t_glob *g)
{
	int i;

	if ((int)ft_strlen(ptr) < g->flag_largeur && g->flag_neg)
	{
		str = (char *)malloc(sizeof(char) * (1 + g->flag_largeur));
		i = ft_absolut(ft_strlen(ptr) - g->flag_largeur);
		tmp = -1;
		while (ptr[++tmp])
			str[tmp] = ptr[tmp];
		i = -1;
		while (++i < ft_absolut(ft_strlen(ptr) - g->flag_largeur))
			str[tmp++] = ' ';
	}
	return (str);
}

int		ft_pointeur(va_list *ap, t_glob *g)
{
	char	*ptr;
	char	*str;
	int		i;
	int		tmp;

	tmp = 0;
	ptr = ft_strjoin("0x", ft_itoa_base((uintmax_t)va_arg(ap[0], void *), 16));
	str = ptr;
	if ((int)ft_strlen(ptr) < g->flag_largeur && !g->flag_neg)
	{
		str = (char *)malloc(sizeof(char) * (1 + g->flag_largeur));
		i = ft_absolut(ft_strlen(ptr) - g->flag_largeur);
		tmp = -1;
		while (++tmp < i)
			str[tmp] = ' ';
		i = 0;
		while (tmp < g->flag_largeur)
			str[tmp++] = ptr[i++];
	}
	str = ft_largeur_ptr(ptr, tmp, str, g);
	ft_putstr(str);
	return (ft_strlen(str));
}
