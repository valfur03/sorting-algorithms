/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfurmane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/18 15:01:30 by vfurmane          #+#    #+#             */
/*   Updated: 2020/09/18 19:17:57 by vfurmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUT_H
# define PUT_H

# include <unistd.h>
# include <stdlib.h>

void	ft_putchar(int fd, char c);

void	ft_putstr(int fd, char *str);

int		ft_error(char *msg, int ret);

void	*ft_null_error(char *msg);

void	ft_putnbr(int nb);

#endif
