/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfurmane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/18 14:48:05 by vfurmane          #+#    #+#             */
/*   Updated: 2020/09/18 18:21:29 by vfurmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "put.h"

void	ft_putchar(int fd, char c)
{
	write(fd, &c, 1);
}

void	ft_putstr(int fd, char *str)
{
	while (*str)
		ft_putchar(fd, *(str++));
}

int		ft_error(char *msg, int ret)
{
	ft_putstr(2, msg);
	ft_putchar(2, '\n');
	return (ret);
}

void	*ft_null_error(char *msg)
{
	ft_putstr(2, msg);
	ft_putchar(2, '\n');
	return (NULL);
}

void		ft_putnbr(int nb)
{
	unsigned int	n;

	if (nb < 0)
		ft_putchar(1, '-');
	n = (nb < 0) ? -nb : nb;
	if (n < 10)
		ft_putchar(1, n + '0');
	else
	{
		ft_putnbr(n / 10);
		ft_putchar(1, n % 10 + '0');
	}
}
