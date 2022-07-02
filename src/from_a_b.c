/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   from_a_b.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrafik <mrafik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 11:45:12 by mrafik            #+#    #+#             */
/*   Updated: 2022/06/24 20:52:31 by mrafik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../push_swap.h"

void	calcul2(t_push_swap *push_swap)
{
	if ((push_swap->m + push_swap->c) >= (push_swap->len)
		|| (push_swap->n - push_swap->c) <= 0)
	{
		push_swap->m = push_swap->len - 1;
		push_swap->n = 0;
	}
	else
	{
		push_swap->m = push_swap->m + push_swap->c;
		push_swap->n = push_swap->n - push_swap->c;
	}
}

void	calcul(t_stack **a, t_push_swap *push_swap)
{
	if (ft_lstsize((*a)) >= 150)
		push_swap->c = ft_lstsize(*a) / 18;
	else
		push_swap->c = ft_lstsize(*a) / 8;
	push_swap->x = ft_lstsize(*a) / 2 ;
	push_swap->len = ft_lstsize(*a);
	push_swap->m = push_swap->x + push_swap->c;
	push_swap->n = push_swap->x - push_swap->c;
	push_swap->k = 0;
	push_swap->i = 0;
}

void	from_a_b(t_stack **a, t_stack **b, t_push_swap *push_swap)
{
	while (push_swap->len != ft_lstsize((*b)))
	{
		while (push_swap->i < (push_swap->m - push_swap->n + 1))
		{
			if (push_swap->str[push_swap->n] <= (*a)->content
				&& (*a)->content <= push_swap->str[push_swap->m])
			{
				ft_push(a, b, "pb\n");
				if ((*b)->content <= push_swap->str[push_swap->x])
					rotate(b, "rb\n");
				push_swap->i++;
			}
			else
				rotate(a, "ra\n");
		}
		calcul2(push_swap);
	}
}
