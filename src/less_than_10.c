/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   less_than_10.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrafik <mrafik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 11:47:13 by mrafik            #+#    #+#             */
/*   Updated: 2022/06/24 21:21:51 by mrafik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../push_swap.h"

int	bigger_than_3(int x, t_stack **b, t_stack **a, t_push_swap *push_swap)
{
	int	i;

	i = 0;
	push_swap->min = push_swap->str[0];
	while (i < ft_lstsize(*a))
	{
		if (push_swap->str[i] <= push_swap->min)
				push_swap->min = push_swap->str[i];
			i++;
	}
	while (push_swap->min != (*a)->content)
	{
		rotate(a, "ra\n");
	}
	ft_push(a, b, "pb\n");
	free (push_swap->str);
	push_swap->str = stack(*a);
	x--;
	return (x);
}

void	less_than_3(t_push_swap *push_swap, t_stack **a)
{
	if (push_swap->smin == 1 && push_swap->sm == 2)
		swap(a, "sa\n");
	else if (push_swap->smin == 2 && push_swap->sm == 0)
	{
		swap(a, "sa\n");
		reverse_rotate(a, "rra\n");
	}
	else if (push_swap->smin == 1 && push_swap->sm == 0)
		rotate(a, "ra\n");
	else if (push_swap->smin == 0 && push_swap->sm == 1)
	{
		swap(a, "sa\n");
		rotate(a, "ra\n");
	}
	else if (push_swap->smin == 2 && push_swap->sm == 1)
		reverse_rotate(a, "rra\n");
}

void	get_min_max(t_push_swap *push_swap)
{
	int	i;

	i = 0;
	while (i < 3)
	{
		if (push_swap->str[i] > push_swap->max)
		{
			push_swap->max = push_swap->str[i];
			push_swap->sm = i;
		}
		if (push_swap->str[i] < push_swap->min)
		{
			push_swap->min = push_swap->str[i];
			push_swap->smin = i;
		}
		i++;
	}
}

void	sor_10(t_stack **b, t_stack **a, t_push_swap *push_swap)
{
	int	x;

	push_swap->str = stack(*a);
	push_swap->min = push_swap->str[0];
	x = ft_lstsize(*a);
	while (x > 3)
		x = bigger_than_3(x, b, a, push_swap);
	push_swap->sm = 0;
	push_swap->smin = 0;
	push_swap->min = push_swap->str[0];
	push_swap->max = push_swap->str[0];
	get_min_max(push_swap);
	less_than_3(push_swap, a);
	while ((*b))
		ft_pushb(b, a, "pa\n");
}
