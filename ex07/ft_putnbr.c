/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsuardi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 16:16:39 by lsuardi           #+#    #+#             */
/*   Updated: 2020/02/05 16:16:45 by lsuardi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_nbchiffres(int i)
{
	int n;

	n = 0;
	while (i > 0)
	{
		i /= 10;
		n++;
	}
	return(n);
}

void	ft_putnbr(int nb)
{
	int cpt;
	int index;
	char tab_ch[10];

	cpt = ft_nbchiffres(nb);
	index = 1;
	while (cpt > 1)
	{
		index *= 10;
		cpt--;
	}
	cpt--;
	while (index > 0)
	{
		tab_ch[cpt] = (char)(nb / index) + 48;
		write(1, &tab_ch[cpt], 1);
		nb %= index;
		index /= 10;
		cpt++;
	}
}
