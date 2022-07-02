/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrafik <mrafik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 15:15:03 by mrafik            #+#    #+#             */
/*   Updated: 2022/06/22 23:11:51 by mrafik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../push_swap.h"

int	ft_find(int *s, int c, t_stack *a)
{
	int	i;

	i = 0;
	while (i < ft_lstsize(a))
	{
		if (s[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	ft_error(void)
{
	ft_printf("Error\n");
	return (0);
}
