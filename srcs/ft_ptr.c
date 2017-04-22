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
	int		i;
	char	*str;

	i = 0;
	str = ft_strdup("%");
	while (g->flag_0 == 0 && g->flag_neg == 0 && g->presision == -1
		&& ++i < g->flag_largeur)
		str = ft_strjoin(" ", str);
	while (g->flag_0 == 0 && g->flag_neg == 0 && g->presision > -1
		&& ++i < g->flag_largeur)
		str = ft_strjoin("0", str);
	while (g->flag_0 == 1 && g->flag_neg == 0 && ++i < g->flag_largeur)
		str = ft_strjoin("0", str);
	while (++i < g->flag_largeur && g->flag_neg == 1)
		str = ft_strjoin(str, " ");
	return (write(1, str, ft_strlen(str)));
}

char *ft_pressison(t_glob *g, char *str)
{
	int i;
	int y;
	char *tmp;

	i = 2;
	y = 0;
	tmp = malloc(sizeof(char) * (g->presision + 1));
	ft_bzero(tmp, ft_strlen(str) + 1);
	if(g->presision != -1)
	{
		while(y < g->presision - (int)ft_strlen(str) + 2)
		{
			tmp[y] = '0';
			y++;
		}
		while(str[i] && i < g->presision)
		{
			tmp[y] = str[i];
			y++; 
			i++;
		}
		
		//printf("--->%s   %d\n", tmp, i);
		str = ft_strjoin("0x", tmp);
	}
	return(str);
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
	str = ft_pressison(g, str);
	if ((int)ft_strlen(ptr) < g->flag_largeur && !g->flag_neg && !g->flag_0)
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
	if ((int)ft_strlen(ptr) < g->flag_largeur && !g->flag_neg && g->flag_0)
	{
		str = (char *)malloc(sizeof(char) * (1 + g->flag_largeur));
		i = ft_absolut(ft_strlen(ptr) - g->flag_largeur);
		i = -1;
		while (++i < (int)ft_strlen(ptr))
			str[i] = ptr[i];
		//printf("%s\n", str);
		while (i < g->flag_largeur)
			str[i++] = '0';
	}
	if ((int)ft_strlen(ptr) < g->flag_largeur && g->flag_neg && !g->flag_0)
	{
		str = (char *)malloc(sizeof(char) * (1 + g->flag_largeur));
		i = ft_absolut(ft_strlen(ptr) - g->flag_largeur);
		i = -1;
		while (++i < (int)ft_strlen(ptr))
			str[i] = ptr[i];
		//ft_printf("%s", str);
		while (i < g->flag_largeur)
		{
		//	ft_putchar(' ');
			str[i++] = ' ';
		}
	}
	//str = ft_largeur_ptr(ptr, tmp, str, g);
	ft_putstr(str);
	return (ft_strlen(str));
}
