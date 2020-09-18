/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfurmane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/18 14:15:48 by vfurmane          #+#    #+#             */
/*   Updated: 2020/09/18 19:18:29 by vfurmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include  <stdio.h> /* ===== DELETE ===== */

static char	*ft_strcat(char *dest, char *src)
{
	char			*res;
	unsigned long	i;
	unsigned long	dest_start;
	unsigned long	src_size;

	i = 0;
	dest_start = 0;
	while (dest[i++])
		dest_start++;
	i = 0;
	src_size = 0;
	while (src[i++])
		src_size++;
	i = -1;
	if (!(res = malloc(sizeof(*res) * (dest_start + src_size + 1))))
		exit(0);
	while (dest[++i])
		res[i] = dest[i];
	i = -1;
	while (src[++i])
		res[dest_start + i] = src[i];
	free(dest);
	res[dest_start + i] = '\0';
	return (res);
}

static char	*ft_strfile(char *path)
{
	int			fd;
	int			ret;
	char		buffer[BUF_SIZE];
	char		*str;
	extern int	errno;

	if (!(str = malloc(sizeof(*str) * (BUF_SIZE + 1))))
		return (ft_null_error("Memory error"));
	if ((fd = open(path, O_RDONLY)) == -1)
		return (ft_null_error(strerror(errno)));
	while ((ret = read(fd, buffer, BUF_SIZE)))
	{
		if (ret == -1)
			return (ft_null_error(strerror(errno)));
		buffer[ret] = '\0';
		str = ft_strcat(str, buffer);
	}
	return (str);
}

static int	ft_count_num(char *str)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (i >= 0 && str[i])
	{
		while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
			i++;
		i = (str[i] == '-') ? i + 1 : i;
		if (str[i] && (str[i] < '0' || str[i] > '9'))
			return (ft_error("Unknown character", 0));
		if (!str[i])
			return (count);
		count++;
		if (count < 0)
			return (ft_error("Too much numbers", 0));
		while (str[i] >= '0' && str[i] <= '9')
			i++;
	}
	if (i < 0)
		return (ft_error("File too big", 0));
	if (!count)
		return (ft_error("No number", 0));
	return (count);
}

static int	ft_atoi(char *str)
{
	int	neg;
	int index;
	int result;

	index = 0;
	result = 0;
	if (str[index] == '-')
	{
		neg = -1;
		index++;
	}
	else
		neg = 1;
	while (str[index] >= '0' && str[index] <= '9')
	{
		if (result >= 214748364 && str[index] > '7')
			ft_putstr(1, "Warning: Number too big\n");
		result = result * 10 + str[index++] - '0';
	}
	return (result * neg);
}

int 		ft_get_num(char *path, int **tab)
{
	int		i;
	int		size;
	int		tab_index;
	char	*str;

	if (!(str = ft_strfile(path)))
			return (0);
	if (!(size = ft_count_num(str)))
		return (0);
	if (!(*tab = malloc(sizeof(**tab) * size)))
		return (ft_error("Memory error", 0));
	i = 0;
	tab_index = 0;
	while (tab_index < size)
	{
		while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
			i++;
		(*tab)[tab_index++] = ft_atoi(&str[i]);
		i = (str[i] == '-') ? i + 1 : i;
		while (str[i] >= '0' && str[i] <= '9')
			i++;
	}
	return (size);
}
