/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrafik <mrafik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 17:29:00 by mrafik            #+#    #+#             */
/*   Updated: 2022/06/24 17:46:34 by mrafik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../push_swap.h"

int	ft_find_bonus(char *s, char *str)
{
	int	i;

	i = 0;
	while (s[i] && str[i])
	{
		if (s[i] != str[i])
			return (0);
		i++;
	}
	return (1);
}

int	ft_help(char *str, t_stack **a, t_stack **b)
{
	if (ft_find_bonus(str, "pa\n"))
		ft_push(b, a, "");
	else if (ft_find_bonus(str, "rra\n"))
		reverse_rotate(a, "");
	else if (ft_find_bonus(str, "rrb\n"))
		reverse_rotate(b, "");
	else if (ft_find_bonus(str, "rb\n"))
		rotate(b, "");
	else if (ft_find_bonus(str, "ra\n"))
		rotate(a, "");
	else if (ft_find_bonus(str, "sa\n"))
		swap(a, "");
	else if (ft_find_bonus(str, "sb\n"))
		swap(b, "");
	else if (ft_find_bonus(str, "pb\n"))
		ft_push(a, b, "");
	else if (ft_find_bonus(str, "rrr\n"))
		rrr(a, b);
	else if (ft_find_bonus(str, "rr\n"))
		rr(a, b);
	else
		return (ft_error());
	return (1);
}

void	checker(t_stack **a, t_stack **b)
{
	char	*str;
	int		x;

	str = get_next_line(0);
	while (str)
	{
		x = ft_help(str, a, b);
		if (x == 0)
		{
			free(str);
			return ;
		}
		free(str);
		str = get_next_line(0);
	}
	if (check_sorted_bonus(*a) && ft_lstsize(*b) == 0)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
}

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;
	int		i;

	b = NULL;
	a = NULL;
	i = 1;
	if (ac >= 2)
	{
		while (i < ac)
		{
			if (!check(av[i]))
				return (ft_error());
			i++;
		}
		ft_stack_a (ac, av, &a);
		if (i == 2)
			return (0);
		if (!duplicate(a))
			return (ft_error());
		checker(&a, &b);
	}
}
