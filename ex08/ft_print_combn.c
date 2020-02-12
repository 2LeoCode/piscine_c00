/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsuardi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 17:32:19 by lsuardi           #+#    #+#             */
/*   Updated: 2020/02/12 12:10:22 by lsuardi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_tab(int tab[], int size, int z)
{
	int		i;
	char	c;

	i = 0;
	if (z == 1 || size != 1)
	{
		while (i < size)
		{
			c = (char)tab[i] + 48;
			write(1, &c, 1);
			i++;
		}
		if (tab[0] < 10 - size)
			write(1, ", ", 2);
	}
}

int		*ft_init(int *tab, int s)
{
	int i;

	i = 0;
	if (s == 1)
	{
		write(1, "0, ", 3);
	}
	while (i < s)
	{
		tab[i] = i;
		i++;
	}
	return (tab);
}

int		*ft_last_case(int *tab, int s)
{
	while (tab[s - 1] < 9)
	{
		tab[s - 1]++;
		ft_print_tab(tab, s, 1);
	}
	if (s >= 2)
	{
		tab[s - 2]++;
		tab[s - 1] = tab[s - 2] + 1;
	}
	if (s != 1)
		ft_print_tab(tab, s, 1);
	return (tab);
}

int		ft_check(int t[], int nb)
{
	int i;

	i = nb - 1;
	while (t[i] == 10 - (nb - i))
	{
		i--;
	}
	return (i);
}

void	ft_print_combn(int n)
{
	int tab[100];

	ft_init(tab, n);
	if (n == 1)
		ft_last_case(tab, n);
	tab[n] = n - 1;
	ft_print_tab(tab, n, 0);
	while (tab[0] < 10 - n && n != 1)
	{
		tab[n] = ft_check(tab, n);
		if (tab[n] == n - 1)
		{
			ft_last_case(tab, n);
			tab[n] = ft_check(tab, n);
		}
		else
		{
			tab[tab[n]]++;
			while (++tab[n] <= n)
			{
				tab[tab[n]] = tab[tab[n] - 1] + 1;
			}
			ft_print_tab(tab, n, 1);
		}
	}
}
