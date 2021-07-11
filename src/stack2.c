/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleblanc <mleblanc@student.42quebec>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/04 20:24:45 by mleblanc          #+#    #+#             */
/*   Updated: 2021/07/11 17:05:31 by mleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

int	find_number(t_stack *stack, int n)
{
	int	i;

	i = 0;
	while (i < stack->size)
	{
		if (stack->data[i] == n)
			return (i);
		++i;
	}
	return (-1);
}

int	average(t_stack *stack)
{
	int	i;
	int	sum;

	i = 0;
	sum = 0;
	while (i < stack->size)
	{
		sum += stack->data[i];
		++i;
	}
	return ((float)(sum) / (int)(stack->size + 0.5f));
}

int	front(t_stack *s)
{
	return (s->data[s->size - 1]);
}

int	back(t_stack *s)
{
	return (s->data[0]);
}

bool	contains_smaller(t_stack *s, int max)
{
	int	i;

	i = 0;
	while (i < s->size)
	{
		if (s->data[i] <= max)
			return (true);
		++i;
	}
	return (false);
}
