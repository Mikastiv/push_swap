/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleblanc <mleblanc@student.42quebec>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 20:19:23 by mleblanc          #+#    #+#             */
/*   Updated: 2021/07/12 14:51:22 by mleblanc         ###   ########.fr       */
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

int	stack_max(t_stack *s)
{
	int	i;
	int	max;

	max = back(s);
	i = 1;
	while (i < s->size)
	{
		if (max < s->data[i])
			max = s->data[i];
		++i;
	}
	return (max);
}

int	stack_min(t_stack *s)
{
	int	i;
	int	min;

	min = back(s);
	i = 1;
	while (i < s->size)
	{
		if (min > s->data[i])
			min = s->data[i];
		++i;
	}
	return (min);
}
