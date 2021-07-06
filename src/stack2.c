/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleblanc <mleblanc@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/04 20:24:45 by mleblanc          #+#    #+#             */
/*   Updated: 2021/07/05 22:51:34 by mleblanc         ###   ########.fr       */
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
