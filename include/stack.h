/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleblanc <mleblanc@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 22:30:41 by mleblanc          #+#    #+#             */
/*   Updated: 2021/06/29 19:05:56 by mleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H

# include <stddef.h>
# include <stdbool.h>

typedef struct s_stack
{
	int		*data;
	size_t	size;
}	t_stack;

t_stack	*new_stack(size_t size);
void	delete_stack(t_stack *stack);
void	print_stack(t_stack *stack);
bool	is_sorted(t_stack *stack);

void	swap_a(t_stack *a);
void	swap_b(t_stack *b);
void	swap_ab(t_stack *a, t_stack *b);

void	push(t_stack *a, int n);
void	push_a(t_stack *a, t_stack *b);
void	push_b(t_stack *b, t_stack *a);

void	rotate_a(t_stack *a);
void	rotate_b(t_stack *b);
void	rotate_ab(t_stack *a, t_stack *b);

void	rev_rotate_a(t_stack *a);
void	rev_rotate_b(t_stack *b);
void	rev_rotate_ab(t_stack *a, t_stack *b);

#endif
