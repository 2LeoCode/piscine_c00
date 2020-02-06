/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsuardi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 17:32:19 by lsuardi           #+#    #+#             */
/*   Updated: 2020/02/05 17:32:25 by lsuardi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void	ft_print_tab(int tab[], int size)
{
	int		i;
	char	c;

	i = 0;
	while (i < size)
	{
		c = (char)tab[i] + 48;
		write(1, &c, 1);
		i++;
	}
	if (tab[0] == 10 - size)
	{
		write(1, "\n", 1);
	}
	else
	{
		write(1, ", ", 2);
	}
}

void	ft_init(int *tab, int s)
{
	int i;

	i = 0;
	while (i < s)
	{
		tab[i] = i;
		i++;
	}
}

void	ft_last_case(int *tab, int s)
{
	while (tab[s - 1] < 9)
	{
		tab[s - 1]++;
		ft_print_tab(tab, s);
	}
	tab[s - 2]++;
	tab[s - 1] = tab[s - 2] + 1;
	ft_print_tab(tab, s);
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
	int tab[n];
	int a;

	ft_init(tab, n);
	a = n - 1;
	ft_print_tab(tab, n);
	while (tab[0] < 10 - n)
	{
		a = ft_check(tab, n);
		if (a == n - 1)
		{
			ft_last_case(tab, n);
			a = ft_check(tab, n);
		}
		else
		{
			tab[a]++;
			while (a < n)
			{
				a++;
				tab[a] = tab[a - 1] + 1;
			}
			ft_print_tab(tab, n);
		}
	}
}
