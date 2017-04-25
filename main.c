/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpinson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/25 20:24:46 by mpinson           #+#    #+#             */
/*   Updated: 2017/04/25 20:25:35 by mpinson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <locale.h>

int	main(void)
{
	setlocale(LC_ALL, "");
	printf("%d\n", ft_printf("ft_printf : %S", L"我是一只猫。"));
	printf("%d\n", printf("no_printf : %S", L"我是一只猫。"));
}
