/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalqam <jalqam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 12:33:44 by jalqam            #+#    #+#             */
/*   Updated: 2024/12/21 20:17:53 by jalqam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_right(int num, char *s)
{
	int	i;

	i = 0;
	if (!s || !*s)
		return (0);
	if (s[i] == '+' || s[i] == '-')
		i++;
	while (s[i])
	{
		if (!ft_isdigit(s[i]))
		{
			errorcheck();
			return (0);
		}
		i++;
	}
	if (s[0] == '+')
		return (1);
	if (ft_strlen(s) != lenst(num))
	{
		errorcheck();
		return (0);
	}
	return (1);
}

int	checkdouble(t_node **stack)
{
	t_node	*cur;
	t_node	*check;

	cur = *stack;
	while (cur != NULL)
	{
		check = cur->next;
		while (check != NULL)
		{
			if (cur->data == check->data)
			{
				errorcheck();
				return (0);
			}
			check = check->next;
		}
		cur = cur->next;
	}
	return (1);
}

int	errorcheck(void)
{
	ft_putstr_fd("Error", 2);
	return (0);
}
