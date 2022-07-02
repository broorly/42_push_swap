/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrafik <mrafik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 13:07:00 by mrafik            #+#    #+#             */
/*   Updated: 2022/06/24 23:13:46 by mrafik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <limits.h>
# include <stdio.h>
# include <stdarg.h>
# include "bonus/get_next_line_bonus.h"

typedef struct s_stack
{
	int				content;
	struct s_stack	*next;
}	t_stack;

typedef struct push_swap
{
	t_stack	*ta;
	int		x;
	int		i;
	int		c;
	int		m;
	int		n;
	int		k;
	int		sm;
	int		smin;
	int		max;
	int		min;
	int		len;
	int		*str;
	int		down;
}	t_push_swap;

void		ft_b_to_a(t_stack **a, t_stack **b, t_push_swap *push_swap);
void		ft_printf_stack(t_stack *a);
int			ft_isdigit(int c);
t_stack		*ft_lstnew(int content);
void		ft_lstaddfront(t_stack **list, t_stack *new);
void		ft_lstaddback(t_stack **list, t_stack *new);
int			ft_lstsize(t_stack *a);
void		reverse_rotate(t_stack **a, char *str);
void		rotate(t_stack **a, char *str);
void		swap(t_stack **a, char *str);
int			duplicate(t_stack *a);
int			check(char *str);
int			*stack(t_stack *a);
void		sort(int *str, int size);
int			ft_strlen(int *s);
void		ft_push(t_stack **a, t_stack **b, char *str);
long int	ft_atoi(const char *ptr);
void		sor_10(t_stack **b, t_stack **a, t_push_swap *push_swap);
void		printf_stack(t_stack *a);
void		ft_pushb(t_stack **a, t_stack **b, char *str);
int			ft_printf(const char *s, ...);
int			ft_putchar(char c);
int			ft_putnbr(int nb);
int			ft_putstr(char *s);
int			ft_hexa(unsigned int nb, char *base, unsigned int b);
int			ft_p(unsigned long long nb);
int			ft_find(int *s, int c, t_stack *a);
int			check_sorted(t_stack *a);
void		from_a_b(t_stack **a, t_stack **b, t_push_swap *push_swap);
int			check_sorted_bonus(t_stack *a);
void		calcul(t_stack **a, t_push_swap *push_swap);
int			ft_find_bonus(char *s, char *str);
int			ft_error(void);
void		ft_stack_a(int ac, char **av, t_stack **a);
int			check_sorted_bonus(t_stack *a);
void		rrr(t_stack **a, t_stack **b);
void		rr(t_stack **a, t_stack **b);
#endif
