/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfurmane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/18 14:04:49 by vfurmane          #+#    #+#             */
/*   Updated: 2020/09/20 11:27:12 by vfurmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "put.h"

void	ft_merge(int *tab, int *left, int *right, int size)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i + j < size)
	{
		if (i < size / 2 && j < size / 2 + size % 2)
		{
			tab[i + j] = (left[i] < right[j]) ? left[i] : right[j];
			if (left[i] < right[j])
				i++;
			else
				j++;
		}
		else
		{
			tab[i + j] = (i < size / 2) ? left[i] : right[j];
			if (i < size / 2)
				i++;
			else
				j++;
		}
	}
}

void	ft_sort(int *tab, int size)
{
	int	i;
	int	*tmp_tab;

	if (!(tmp_tab = malloc(sizeof(*tmp_tab) * size)))
		return ;
	i = -1;
	while (++i < size)
		tmp_tab[i] = tab[i];
	if (size / 2 > 1)
		ft_sort(tmp_tab, size / 2);
	if (size / 2 + size % 2 > 1)
		ft_sort(&tmp_tab[size / 2], size / 2 + size % 2);
	ft_merge(tab, tmp_tab, &tmp_tab[size / 2], size);
	free(tmp_tab);
}

void	ft_aff_tab(int *tab, int size)
{
	int	i;

	i = 0;
	while (i < size - 1)
	{
		ft_putnbr(tab[i++]);
		ft_putchar(1, ' ');
	}
	ft_putnbr(tab[i++]);
	ft_putchar(1, '\n');
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
