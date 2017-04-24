/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpinson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/24 17:22:23 by mpinson           #+#    #+#             */
/*   Updated: 2017/04/24 17:22:54 by mpinson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <limits.h>
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int	main(int argc, char **argv)
{
	char	c;
	char	*yolo;
	int		fd;
	int		i;

	i = INT_MIN;
	setlocale(LC_ALL, "");
//	while (i < INT_MAX)
//	{
		printf("%d\n", ft_printf("ft_printf : @main_ftprintf: %####0000 33..1..#00d", 256));
		printf("%d\n", printf("no_printf : @main_ftprintf: %####0000 33..1..#00d", 256));
		i++;
//	}
	return (0);
}
