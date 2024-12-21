/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalqam <jalqam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 12:21:39 by jalqam            #+#    #+#             */
/*   Updated: 2024/12/21 15:45:10 by jalqam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_position(t_node **stack, int value)
{
	int		pos;
	t_node	*current;

	pos = 0;
	current = *stack;
	while (current)
	{
		if (current->data == value)
			return (pos);
		current = current->next;
		pos++;
	}
	return (-1);
}

void	give_index(t_node *lsta)
{
	t_node	*tmp;
	t_node	*next;
	int		counter;

	if (!lsta)
		return ;
	next = lsta;
	while (next)
	{
		counter = 0;
		tmp = lsta;
		while (tmp->next)
		{
			if (tmp->data <= next->data)
				counter++;
			tmp = tmp->next;
		}
		next->index = counter;
		next = next->next;
	}
}

int	get_max_bits(t_node **stack)
{
	t_node	*head;
	int		max;
	int		max_bits;

	head = *stack;
	max = head->index;
	max_bits = 0;
	while (head)
	{
		if (head->index > max)
			max = head->index;
		head = head->next;
	}
	while ((max >> max_bits) != 0)
		max_bits++;
	return (max_bits);
}

void	radix_pass(t_node **stack_a, t_node **stack_b, int cur_bit, int size)
{
	t_node	*head_a;
	int		i;

	i = 0;
	while (i < size)
	{
		head_a = *stack_a;
		if (((head_a->index >> cur_bit) & 1) == 1)
			ra(stack_a);
		else
			pb(stack_b, stack_a);
		i++;
	}
	while (stack_len(*stack_b) != 0)
		pa(stack_a, stack_b);
}

void	radix_sort(t_node **stack_a, t_node **stack_b)
{
	int	i;
	int	size;
	int	max_bits;

	give_index(*stack_a);
	size = stack_len(*stack_a);
	max_bits = get_max_bits(stack_a);
	i = 0;
	while (i < max_bits)
	{
		radix_pass(stack_a, stack_b, i, size);
		i++;
		if (is_sorted(*stack_a))
			break ;
	}
}
