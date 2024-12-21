/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalqam <jalqam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 18:02:54 by jalqam            #+#    #+#             */
/*   Updated: 2024/12/21 14:50:23 by jalqam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	reverse_rotate(t_node **stack)
{
	t_node	*last;
	t_node	*prev;

	if (stack_len(*stack) < 2)
		return (-1);
	last = *stack;
	while (last->next)
	{
		prev = last;
		last = last->next;
	}
	prev->next = NULL;
	last->next = *stack;
	*stack = last;
	return (0);
}

int	rra(t_node **stack)
{
	if (reverse_rotate(stack) == 0)
		ft_putstr_fd("rra\n", 1);
	return (0);
}

int	rrb(t_node **stack)
{
	if (reverse_rotate(stack) == 0)
		ft_putstr_fd("rrb\n", 1);
	return (0);
}
