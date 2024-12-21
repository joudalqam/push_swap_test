/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_operation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalqam <jalqam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 18:03:04 by jalqam            #+#    #+#             */
/*   Updated: 2024/12/21 14:48:22 by jalqam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	rotate(t_node **stack)
{
	t_node	*first;
	t_node	*last;

	if (stack_len(*stack) < 2)
		return (-1);
	first = *stack;
	last = *stack;
	while (last->next)
		last = last->next;
	*stack = first->next;
	first->next = NULL;
	last->next = first;
	return (0);
}

int	ra(t_node **stack)
{
	if (rotate(stack) == 0)
		ft_putstr_fd("ra\n", 1);
	return (0);
}

int	rb(t_node **stack)
{
	if (rotate(stack) == 0)
		write(1, "rb\n", 3);
	return (0);
}
