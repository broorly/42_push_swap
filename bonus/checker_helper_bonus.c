/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_helper_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrafik <mrafik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 21:35:26 by mrafik            #+#    #+#             */
/*   Updated: 2022/06/24 17:46:04 by mrafik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../push_swap.h"

int	check_sorted_bonus(t_stack *a)
{
	t_stack	*tmp;
	t_stack	*s;

	if (!a)
		return (0);
	s = a->next;
	tmp = a;
	while (tmp->next)
	{
		if (tmp->content > s->content)
			return (0);
		tmp = tmp->next;
		s = s->next;
	}
	return (1);
}

void	ft_stack_a(int ac, char **av, t_stack **a)
{
	int	i;

	i = 1;
	while (i < ac)
	{
		ft_lstaddback(a, ft_lstnew(ft_atoi(av[i])));
		i++;
	}
}

void	ft_printf_stack(t_stack *a)
{
	while (a)
	{
		ft_printf("%d ", a->content);
		a = a->next;
	}
	ft_printf("\n");
}

void	rr(t_stack **a, t_stack **b)
{
	rotate(a, "");
	rotate(b, "");
}

void	rrr(t_stack **a, t_stack **b)
{
	reverse_rotate(a, "");
	reverse_rotate(b, "");
}
