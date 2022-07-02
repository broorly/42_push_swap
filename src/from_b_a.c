/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   from_b_a.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrafik <mrafik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 14:56:26 by mrafik            #+#    #+#             */
/*   Updated: 2022/06/24 21:05:08 by mrafik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../push_swap.h"

int	is_here(t_stack *b, int t)
{
	int		i;
	t_stack	*tmp;

	tmp = b;
	i = 0;
	while (tmp)
	{
		if (tmp->content == t)
		{
			if (i > (ft_lstsize(b) / 2))
				return (1);
			else
				return (0);
		}
		i++;
		tmp = tmp->next;
	}
	return (0);
}

void	ft_norm(t_stack **a, t_stack **b, t_push_swap *push_swap)
{
	if ((*b)->content == push_swap->str[push_swap->x])
	{
		ft_push(b, a, "pa\n");
		push_swap->x--;
	}
	else
	{
		if (push_swap->down == 0 || (*b)->content > push_swap->ta->content)
		{
			ft_push(b, a, "pa\n");
			rotate(a, "ra\n");
			push_swap->down++;
		}
		else
		{
			if (is_here((*b), push_swap->str[push_swap->x]))
				reverse_rotate(b, "rrb\n");
			else
				rotate(b, "rb\n");
		}
	}
}

void	last_a(t_stack **a, t_push_swap *push_swap)
{
	if ((*a))
	{
		push_swap->ta = *a;
		while (push_swap->ta->next)
			push_swap->ta = push_swap->ta->next;
	}
}

void	ft_b_to_a(t_stack **a, t_stack **b, t_push_swap *push_swap)
{
	int	*save;

	push_swap->down = 0;
	push_swap->x = push_swap->len - 1;
	while (push_swap->len != ft_lstsize((*a)))
	{
		last_a(a, push_swap);
		save = stack(*b);
		if (ft_find(save, push_swap->str[push_swap->x], *b))
			ft_norm(a, b, push_swap);
		else
		{
			reverse_rotate(a, "rra\n");
			push_swap->x--;
			push_swap->down--;
		}
		free(save);
	}
	while (push_swap->down > 0)
	{
		reverse_rotate(a, "rra\n");
		push_swap->down--;
	}
}
