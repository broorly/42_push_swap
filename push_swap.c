/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrafik <mrafik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 13:07:06 by mrafik            #+#    #+#             */
/*   Updated: 2022/06/24 23:19:27 by mrafik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

void	ft_printf_stack(t_stack *a)
{
	while (a)
	{
		ft_printf("%d ", a->content);
		a = a->next;
	}
	ft_printf("\n");
}

void	ft_fct_norm(t_stack **a, t_stack **b, t_push_swap *push_swap)
{
	push_swap->str = stack(*a);
	sort(push_swap->str, ft_lstsize(*a));
	calcul(a, push_swap);
	from_a_b(a, b, push_swap);
	ft_b_to_a(a, b, push_swap);
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

int	main(int ac, char **av)
{
	t_stack		*a;
	t_stack		*b;
	t_push_swap	push_swap;

	a = NULL;
	b = NULL;
	push_swap.i = 1;
	if (ac >= 2)
	{
		while (push_swap.i < ac)
		{
			if (!check(av[push_swap.i]))
				return (ft_error());
			push_swap.i++;
		}
		ft_stack_a (ac, av, &a);
		if (push_swap.i == 2 || !check_sorted(a))
			return (0);
		if (!duplicate(a))
			return (ft_error());
		if (ft_lstsize(a) <= 15)
			sor_10(&b, &a, &push_swap);
		else
			ft_fct_norm(&a, &b, &push_swap);
	}
}
