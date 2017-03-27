/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_presision_uni.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpinson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/24 17:40:38 by mpinson           #+#    #+#             */
/*   Updated: 2017/03/24 17:40:40 by mpinson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

wchar_t	*ft_presision_uni1(wchar_t *str, t_glob *g, int bol)
{
	int		i;
	wchar_t	*tmp;

	if (g->presision == 0)
		str = L"";
	if (g->presision != -1 && g->presision > 0 && !bol)
	{
		i = -1;
		if (!(tmp = (wchar_t *)malloc(sizeof(wchar_t) * (g->presision + 1))))
			return (NULL);
		while (++i < g->presision)
			tmp[i] = str[i];
		tmp[i] = 0;
		str = tmp;
	}
	return (str);
}

wchar_t	*ft_presision_uni2(wchar_t *str, t_glob *g, int bol)
{
	int		i;
	int		test;
	wchar_t	*tmp;

	if (g->presision != -1 && g->presision >= (int)ft_uni_strlen(str) && bol)
	{
		if (!(tmp = (wchar_t *)malloc(sizeof(wchar_t) * (g->presision + 2))))
			return (NULL);
		i = -2;
		test = 1;
		tmp[0] = '-';
		while (++i < ft_absolut((g->presision - (int)ft_uni_strlen(str))))
			tmp[i] = '0';
		i = 1;
		while (str[i])
			tmp[test++] = str[i++];
		tmp[test] = 0;
		free(str);
		str = tmp;
		free(tmp);
	}
	return (str);
}

wchar_t	*ft_flag_more_space_uni1(wchar_t *str, t_glob *g, int bol)
{
	int		i;
	wchar_t	*tmp;

	if (g->flag_more && bol == 0)
	{
		if (!(tmp = (wchar_t *)malloc(sizeof(wchar_t) *
						(ft_uni_strlen(str) + 2))))
			return (NULL);
		tmp[0] = '+';
		i = 0;
		while (str[++i - 1])
			tmp[i] = str[i - 1];
		tmp[i] = 0;
		str = tmp;
		free(tmp);
	}
	return (str);
}

wchar_t	*ft_flag_more_space_uni2(wchar_t *str, t_glob *g, int bol)
{
	int		i;
	wchar_t	*tmp;

	if (g->flag_space && bol == 0)
	{
		if (!(tmp = (wchar_t *)malloc(sizeof(wchar_t) *
						(ft_uni_strlen(str) + 2))))
			return (NULL);
		tmp[0] = ' ';
		i = 0;
		while (str[i++ - 1])
			tmp[i] = str[i - 1];
		tmp[i] = 0;
		str = tmp;
		free(tmp);
	}
	return (str);
}
