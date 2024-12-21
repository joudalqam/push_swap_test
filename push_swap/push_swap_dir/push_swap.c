/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalqam <jalqam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 18:03:27 by jalqam            #+#    #+#             */
/*   Updated: 2024/12/21 20:19:34 by jalqam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sort_check(t_node **stack_a, t_node **stack_b)
{
	int	len;

	len = stack_len(*stack_a);
	if (!stack_a || !stack_b)
	{
		errorcheck();
		return (0);
	}
	if (len == 0)
	{
		errorcheck();
		return (0);
	}
	else if (len == 2)
		sort_two(stack_a);
	else if (len == 3)
		sort_three(stack_a);
	else if (len == 4)
		sort_four(stack_a, stack_b);
	else if (len == 5)
		sort_five(stack_a, stack_b);
	else
		radix_sort(stack_a, stack_b);
	return (1);
}

int	initialize_stacks(char **argv, t_node **stack_a, int argc)
{
	int	num;
	int	i;

	i = argc - 1;
	while (i > 0)
	{
		if (!is_right(ft_atoi(argv[i]), argv[i]))
		{
			freestack(stack_a);
			return (0);
		}
		num = ft_atoi(argv[i]);
		push(stack_a, num);
		i--;
	}
	if (!checkdouble(stack_a))
	{
		freestack(stack_a);
		return (0);
	}
	return (1);
}

int	initialize_and_prepare(int argc, char **argv, t_node **stack_a,
		t_node **stack_b)
{
	*stack_b = NULL;
	*stack_a = NULL;
	if (argc == 1)
		return (0);
	if (!initialize_stacks(argv, stack_a, argc))
	{
		return (0);
	}
	if (is_sorted(*stack_a))
		return (0);
	return (1);
}

void	process_and_cleanup(t_node **stack_a, t_node **stack_b)
{
	give_index(*stack_a);
	sort_check(stack_a, stack_b);
	freestack(stack_a);
	freestack(stack_b);
}

int	main(int argc, char **argv)
{
	t_node	*stack_a;
	t_node	*stack_b;

	if (!initialize_and_prepare(argc, argv, &stack_a, &stack_b))
	{
		freestack(&stack_a);
		freestack(&stack_b);
		return (0);
	}
	process_and_cleanup(&stack_a, &stack_b);
	return (0);
}
