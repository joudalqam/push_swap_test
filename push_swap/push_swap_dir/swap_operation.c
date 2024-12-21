/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_operation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 18:03:39 by jalqam            #+#    #+#             */
/*   Updated: 2024/12/15 21:44:23 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	swap(t_node **stack)
{
	t_node	*first;
	t_node	*sec;
	int		cur;

	if (stack_len(*stack) < 2)
		return (-1);
	first = *stack;
	sec = first->next;
	cur = first->data;
	first->data = sec->data;
	sec->data = cur;
	return (0);
}

int	sa(t_node **stack)
{
	if (swap(stack) == 0)
		ft_putstr_fd("sa\n", 1);
	return (0);
}

int	sb(t_node **stack)
{
	if (swap(stack) == 0)
		ft_putstr_fd("sa\n", 1);
	return (0);
}

int	ss(t_node **stack_a, t_node **stack_b)
{
	int	swap_a;
	int	swap_b;

	swap_a = swap(stack_a);
	swap_b = swap(stack_b);
	if (swap_a == 0 && swap_b == 0)
		ft_putstr_fd("ss\n", 1);
	return (0);
}
