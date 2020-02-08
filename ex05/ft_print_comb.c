/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsuardi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 13:27:16 by lsuardi           #+#    #+#             */
/*   Updated: 2020/02/05 13:27:21 by lsuardi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print(char i, char j, char k)
{
	unsigned char s;

	s = 0;
	write(1, &i, 1);
	write(1, &j, 1);
	write(1, &k, 1);
	if (i == '7' && j == '8' && k == '9')
		s = 1;
	if (!s)
		write(1, ", ", 2);
}

void	ft_print_comb(void)
{
	char a;
	char b;
	char c;

	a = '0';
	b = '1';
	c = '2';
	while (a < 55)
	{
		while (b < 56)
		{
			while (c < 57)
			{
				ft_print(a, b, c);
				c++;
			}
			ft_print(a, b, c);
			b++;
			c = b + 1;
		}
		ft_print(a, b, c);
		a++;
		b = a + 1;
		c = b + 1;
	}
	ft_print(a, b, c);
}

int main(){
	ft_print_comb();
	return 0;
}