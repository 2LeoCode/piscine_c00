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

int ft_check(int t[], int nb)
{
	int i = nb - 1;
	while (t[i] == 10 - (nb - i))
	{
		i--;
	}
	return(i);
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
	for (int i = 0; i < n; i++)
	{
		printf("%d", tab[i]);
	}
	putchar(' ');
	while (tab[0] < 10 - n)
	{
		a = ft_check(tab, n);
		if (a == n - 1)
		{
			while (tab[a] < 9)
			{
				tab[a]++;
				for (int i = 0; i < n; i++)
				{
					printf("%d", tab[i]);
				}
				putchar(' ');
			}
			tab[a-1]++;
			tab[a] = tab[a - 1] + 1;
			for (int i = 0; i < n; i++)
			{
				printf("%d", tab[i]);
			}
			putchar(' ');
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
			for (int i = 0; i < n; i++)
			{
				printf("%d", tab[i]);
			}
			putchar(' ');
		}
	}
	for (int i = 0; i < n; i++)
	{
		printf("%d", tab[i]);
	}
	putchar('.');
}

int main()
{
	ft_print_combn(9);
	return(0);
}
