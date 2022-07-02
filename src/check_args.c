/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrafik <mrafik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 17:51:49 by mrafik            #+#    #+#             */
/*   Updated: 2022/06/24 13:40:02 by mrafik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../push_swap.h"

int	check(char *str)
{
	int	i;

	i = 0;
	if (ft_atoi(str) < INT_MIN
		|| ft_atoi(str) > INT_MAX)
		return (0);
	if (str[0] == '-' || str[0] == '+')
		i++;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (ft_isdigit(str[i]))
			i++;
		else
			return (0);
	}
	return (1);
}

int	*stack(t_stack *a)
{
	int	*b;
	int	i;

	i = 0;
	if (a)
	{
		b = (int *) malloc ((ft_lstsize(a)) * sizeof(int));
		while (a)
		{
			b[i] = a->content;
			a = a->next;
			i++;
		}
		return (b);
	}
	return (0);
}

int	duplicate(t_stack *a)
{
	t_stack	*s;

	s = a;
	while (s)
	{
		a = s->next;
		while (a)
		{
			if (s->content == a->content)
				return (0);
			a = a->next;
		}
		s = s->next;
	}
	return (1);
}

void	sort(int *str, int size)
{
	int	i;
	int	x;
	int	save;

	i = 0;
	while (i < size)
	{
		x = 0;
		while ((x + i) < size)
		{
			if (str[i] > str[i + x])
			{
				save = str[i];
				str[i] = str[i + x];
				str[i + x] = save;
			}
			x++;
		}
		i++;
	}
}

int	check_sorted(t_stack *a)
{
	while (a->next)
	{
		if (a->content > a->next->content)
			return (1);
		a = a->next;
	}
	return (0);
}
