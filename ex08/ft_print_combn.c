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

int		ft_int_to_char(int i)
{
	char c;

	c = (char)i + 48;
	return (c);
}

void	ft_print_tab(int tab[], int size)
{
	int		i;
	char	c;

	i = 0;
	while (i < size)
	{
		c = ft_int_to_char(tab[i]);
		write(1, &c, 1);
		i++;
	}
	write(1, ", ", 2);
}

void	ft_print_tab_end(int tab[], int size)
{
	int		i;
	char	c;

	i = 0;
	while (i < size)
	{
		c = ft_int_to_char(tab[i]);
		write(1, &c, 1);
		i++;
	}
	write(1, "\n", 1);
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

	a = 0;
	while (a < n)
	{
		tab[a] = a;
		a++;
	}
	a = n - 1;
	ft_print_tab(tab, n);
	while (tab[0] < 10 - n)
	{
		a = ft_check(tab, n);
		if (a == n - 1)
		{
			while (tab[a] < 9)
			{
				tab[a]++;
				ft_print_tab(tab, n);
			}
			tab[a - 1]++;
			tab[a] = tab[a - 1] + 1;
			ft_print_tab(tab, n);
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
	ft_print_tab_end(tab, n);
}
