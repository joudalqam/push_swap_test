/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalqam <jalqam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 14:44:09 by jalqam            #+#    #+#             */
/*   Updated: 2024/12/21 19:09:06 by jalqam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "../libft/libft.h"
# include <limits.h>
# include <stdio.h>
# include <unistd.h>

typedef struct s_node
{
	struct s_node	*next;
	int				data;
	int				count;
	int				index;
}					t_node;

int					stack_len(t_node *stack);
int					sort_check(t_node **stack_a, t_node **stack_b);
int					malloc_size(int size, char **str, char *sep);
int					is_right(int num, char *s);
int					checkdouble(t_node **stack);
void				freestack(t_node **stack);
int					initialize_stacks(char **argv, t_node **stack_a, int argc);
char				*str_join(char **str, char *sep, int size);
char				**free_split(char **split);
int					is_sorted(t_node *stack_a);
void				give_index(t_node *stack_a);
int					get_max_bits(t_node **stack);
int					sort_check(t_node **stack_a, t_node **stack_b);
void				radix_pass(t_node **stack_a, t_node **stack_b, int cur_bit,
						int size);
void				radix_sort(t_node **stack_a, t_node **stack_b);
int					push(t_node **stack, int value);
int					errorcheck(void);
int					swap(t_node **stack);
int					sa(t_node **stack);
int					sb(t_node **stack);
int					ss(t_node **stack_a, t_node **stack_b);
int					rotate(t_node **stack);
int					ra(t_node **stack);
int					rb(t_node **stack);
int					reverse_rotate(t_node **stack);
int					rra(t_node **stack);
int					rrb(t_node **stack);
void				sort_two(t_node **stack);
void				sort_three(t_node **stack);
void				sort_four(t_node **stack_a, t_node **stack_b);
void				sort_five(t_node **stack_a, t_node **stack_b);
int					pa(t_node **stack_a, t_node **stack_b);
int					pb(t_node **stack_a, t_node **stack_b);
int					find_position(t_node **stack, int value);
int					initialize_and_prepare(int argc, char **argv,
						t_node **stack_a, t_node **stack_b);
void				process_and_cleanup(t_node **stack_a, t_node **stack_b);
#endif