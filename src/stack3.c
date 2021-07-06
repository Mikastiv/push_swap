/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleblanc <mleblanc@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 20:19:23 by mleblanc          #+#    #+#             */
/*   Updated: 2021/07/05 21:01:38 by mleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

bool	is_sorted_rev(t_stack *stack)
{
	int	i;
	int	prev;

	if (stack->size < 2)
		return (true);
	i = 1;
	prev = stack->data[0];
	while (i < stack->size)
	{
		if (stack->data[i] < prev)
			return (false);
		prev = stack->data[i++];
	}
	return (true);
}

bool	contains_bigger(t_stack *s, int min)
{
	int	i;

	i = 0;
	while (i < s->size)
	{
		if (s->data[i] > min)
			return (true);
		++i;
	}
	return (false);
}

void	split_b_higher(t_stack *b, t_stack *a, int mid)
{
	while (contains_bigger(b, mid))
	{
		while (front(b) <= mid)
			rotate_b(b);
		push_a(a, b);
	}
}
