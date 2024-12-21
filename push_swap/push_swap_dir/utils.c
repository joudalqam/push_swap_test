/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalqam <jalqam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 14:51:20 by jalqam            #+#    #+#             */
/*   Updated: 2024/12/21 19:05:40 by jalqam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*str_join(char **str, char *sep, int size)
{
	char	*mal;
	int		i;
	int		j;
	int		k;

	mal = malloc(10000);
	if (!mal)
		return (NULL);
	i = 1;
	k = 0;
	while (i < size)
	{
		j = 0;
		while (str[i][j])
			mal[k++] = str[i][j++];
		j = 0;
		while (sep[j] && i < size - 1)
			mal[k++] = sep[j++];
		i++;
	}
	mal[k] = '\0';
	return (mal);
}

int	malloc_size(int size, char **str, char *sep)
{
	int	i;
	int	len;
	int	sep_len;

	sep_len = ft_strlen(sep);
	len = 0;
	i = 0;
	while (i < size)
		len += ft_strlen(str[i++]);
	len += (size - 2) * sep_len + 1;
	return (len);
}

int	stack_len(t_node *stack)
{
	int	size;

	size = 0;
	while (stack)
	{
		size++;
		stack = stack->next;
	}
	return (size);
}

void	freestack(t_node **stack)
{
	t_node	*temp;

	if (!*stack || !stack)
		return ;
	while (*stack)
	{
		temp = *stack;
		*stack = (*stack)->next;
		free(temp);
	}
}

char	**free_split(char **split)
{
	char	**temp;

	temp = split;
	if (split)
	{
		while (*temp)
		{
			free(*temp);
			temp++;
		}
		free(split);
	}
	return (NULL);
}
