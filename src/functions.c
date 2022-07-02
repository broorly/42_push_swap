/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrafik <mrafik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 16:50:21 by mrafik            #+#    #+#             */
/*   Updated: 2022/06/23 00:14:07 by mrafik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../push_swap.h"

void	swap(t_stack **a, char *str)
{
	t_stack	*s;
	int		save;

	if (*a && ft_lstsize(*a) >= 2)
	{
		s = (*a)->next;
		save = (*a)->content;
		(*a)->content = s->content;
		s->content = save;
		ft_printf("%s", str);
	}
}

void	rotate(t_stack **a, char *str)
{
	t_stack	*s;

	if (*a && ft_lstsize(*a) >= 2)
	{
		s = *a;
		*a = (*a)->next;
		s->next = NULL;
		ft_lstaddback(a, s);
		ft_printf("%s", str);
	}
}

void	reverse_rotate(t_stack **a, char *str)
{
	t_stack	*s;
	t_stack	*b;

	if (*a && ft_lstsize(*a) >= 2)
	{
		s = *a;
		while (s->next->next)
			s = s->next;
		b = s->next;
		s->next = NULL;
		ft_lstaddfront(a, b);
		ft_printf("%s", str);
	}
}

void	ft_push(t_stack **a, t_stack **b, char *str)
{
	t_stack	*tmp;

	if (*a)
	{
		tmp = *a;
		*a = (*a)->next;
		tmp->next = NULL;
		if (!(*b))
			*b = tmp;
		else
			ft_lstaddfront(b, tmp);
		ft_printf("%s", str);
	}
}

void	ft_pushb(t_stack **a, t_stack **b, char *str)
{
	t_stack	*tmp;

	if (*a)
	{
		tmp = *a;
		*a = (*a)->next;
		tmp->next = NULL;
		if (!(*b))
			*b = tmp;
		else
			ft_lstaddback(b, tmp);
		ft_printf("%s", str);
	}
}
