/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_operation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalqam <jalqam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 18:03:15 by jalqam            #+#    #+#             */
/*   Updated: 2024/12/21 14:55:16 by jalqam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	push(t_node **stack, int value)
{
	t_node	*new_node;

	new_node = malloc(sizeof(t_node));
	if (!new_node)
		return (errorcheck());
	new_node->next = *stack;
	new_node->data = value;
	*stack = new_node;
	return (0);
}

int	pa(t_node **stack_a, t_node **stack_b)
{
	t_node	*temp;

	if (!stack_b || !*stack_b)
		return (0);
	temp = *stack_b;
	*stack_b = temp->next;
	temp->next = *stack_a;
	*stack_a = temp;
	ft_putstr_fd("pa\n", 1);
	return (1);
}

int	pb(t_node **stack_a, t_node **stack_b)
{
	t_node	*temp;

	if (!stack_b || !*stack_b)
		return (0);
	temp = *stack_b;
	*stack_b = temp->next;
	temp->next = *stack_a;
	*stack_a = temp;
	ft_putstr_fd("pb\n", 1);
	return (1);
}
