/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalqam <jalqam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 19:11:34 by jalqam            #+#    #+#             */
/*   Updated: 2024/12/21 16:48:43 by jalqam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	sort_two(t_node **stack)
{
	if (!stack || !*stack || !(*stack)->next)
		return ;
	if ((*stack)->data > (*stack)->next->data)
		swap(stack);
}

void	sort_three(t_node **stack)
{
	int	a;
	int	b;
	int	c;

	a = (*stack)->data;
	b = (*stack)->next->data;
	c = (*stack)->next->next->data;
	if (a < b && b > c && c > a)
	{
		sa(stack);
		ra(stack);
	}
	else if (b < a && a < c && b < c)
		sa(stack);
	else if (b < c && c < a && a > b)
		ra(stack);
	else if (c < a && a > b && b > c)
	{
		sa(stack);
		rra(stack);
	}
	else if (c < b && b > a && a > c)
		rra(stack);
}

int	is_sorted(t_node *stack_a)
{
	t_node	*current;

	current = stack_a;
	while (current->next)
	{
		if (current->data > current->next->data)
			return (0);
		current = current->next;
	}
	return (1);
}

void	sort_four(t_node **stack_a, t_node **stack_b)
{
	t_node	*cur;
	int		min;

	cur = *stack_a;
	min = cur->data;
	while (cur)
	{
		if (min > cur->data)
			min = cur->data;
		cur = cur->next;
	}
	while ((*stack_a)->data != min)
	{
		if (find_position(stack_a, min) <= 2)
			ra(stack_a);
		else
			rra(stack_a);
	}
	pb(stack_b, stack_a);
	sort_three(stack_a);
	pa(stack_a, stack_b);
}

void	sort_five(t_node **stack_a, t_node **stack_b)
{
	t_node	*cur;
	int		min;

	cur = *stack_a;
	min = cur->data;
	while (cur)
	{
		if (min > cur->data)
			min = cur->data;
		cur = cur->next;
	}
	while ((*stack_a)->data != min)
	{
		if (find_position(stack_a, min) <= 2)
			ra(stack_a);
		else
			rra(stack_a);
	}
	pb(stack_b, stack_a);
	sort_four(stack_a, stack_b);
	pa(stack_a, stack_b);
}
