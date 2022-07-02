/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrafik <mrafik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 15:13:56 by mrafik            #+#    #+#             */
/*   Updated: 2022/06/23 12:27:04 by mrafik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../push_swap.h"

long int	ft_atoi(const char *ptr)
{
	int			signe;
	int			i;
	long int	stock;

	i = 0;
	signe = 1;
	stock = 0;
	while (ptr[i] == ' ' || ptr[i] == '\n' || ptr[i] == '\t'
		|| ptr[i] == '\v' || ptr[i] == '\r' || ptr[i] == '\f')
		i++;
	if (ptr[i] == '+' || ptr[i] == '-')
	{
		if (ptr[i] == '-')
			signe = -1;
		i++;
	}
	while (ptr[i] >= '0' && ptr[i] <= '9')
	{
		stock = (stock * 10) + (ptr[i] - '0');
		i++;
	}
	return (stock * signe);
}
