/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfurmane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/18 14:04:49 by vfurmane          #+#    #+#             */
/*   Updated: 2020/09/19 10:39:49 by vfurmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "put.h"

void	ft_swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	ft_sort(int *tab, int size)
{
	int	i;
	int	min;
	int	pivot;

	i = 0;
	min = 0;
	pivot = tab[size - 1];
	while (i < size - 1)
	{
		if (tab[i] <= pivot)
			ft_swap(&tab[i], &tab[min++]);
		i++;
	}
	ft_swap(&tab[i], &tab[min]);
	if (size > 2)
	{
		ft_sort(tab, min);
		ft_sort(&tab[min], size - min);
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
