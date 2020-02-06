/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsuardi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 14:47:13 by lsuardi           #+#    #+#             */
/*   Updated: 2020/02/05 14:47:17 by lsuardi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_final(int i, int j)
{
	char tab_num[4];

	tab_num[0] = (char)(i / 10) + 48;
	tab_num[1] = (char)(i % 10) + 48;
	tab_num[2] = (char)(j / 10) + 48;
	tab_num[3] = (char)(j % 10) + 48;
	write(1, &tab_num, 2);
	write(1, " ", 1);
	write(1, &tab_num[2], 2);
	write(1, "\n", 1);
}

void	ft_print(int i, int j)
{
	char tab_num[4];

	tab_num[0] = (char)(i / 10) + 48;
	tab_num[1] = (char)(i % 10) + 48;
	tab_num[2] = (char)(j / 10) + 48;
	tab_num[3] = (char)(j % 10) + 48;
	write(1, &tab_num, 2);
	write(1, " ", 1);
	write(1, &tab_num[2], 2);
	if(!(tab_num[0] == '9' && tab_num[1] == '8' && tab_num[2] == '9' && tab_num[3] == '9'))
		write(1, ", ", 2);
}

void	ft_print_comb2(void)
{
	int a;
	int b;

	a = 0;
	b = 1;
	while (a < 98)
	{
		while (b < 99)
		{
			ft_print(a, b);
			b++;
		}
		ft_print(a, b);
		a++;
		b = a + 1;
	}
	ft_print(a, b);
}
