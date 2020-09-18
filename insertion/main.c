/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfurmane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/18 14:04:49 by vfurmane          #+#    #+#             */
/*   Updated: 2020/09/18 19:37:58 by vfurmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "put.h"

void	ft_sort(int *tab, int size)
{
	int	i;
	int	tmp;
	int	start;

	start = 1;
	while (start < size)
	{
		i = start;
		while (i > 0 && tab[i - 1] > tab[i])
		{
			tmp = tab[i - 1];
			tab[i - 1] = tab[i];
			tab[i--] = tmp;
		}
		start++;
	}
}

void	ft_aff_tab(int *tab, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		ft_putnbr(tab[i++]);
		ft_putchar(1, '\n');
	}
}

int		main(int argc, char **argv)
{
	int	size;
	int	*numbers;

	if (argc != 2)
		return (0);
	numbers = NULL;
	size = ft_get_num(argv[1], &numbers);
	if (!numbers)
		return (0);
	ft_sort(numbers, size);
	ft_aff_tab(numbers, size);
	free(numbers);
	return (0);
}
