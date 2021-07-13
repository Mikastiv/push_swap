/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleblanc <mleblanc@student.42quebec>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 20:19:23 by mleblanc          #+#    #+#             */
/*   Updated: 2021/07/13 15:25:47 by mleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

bool	is_sorted_rev(t_stack *s)
{
	int	i;
	int	prev;

	if (s->size < 2)
		return (true);
	i = 1;
	prev = s->data[0];
	while (i < s->size)
	{
		if (s->data[i] < prev)
			return (false);
		prev = s->data[i++];
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

int	stack_size(t_stack *s, int max)
{
	int	i;
	int	last;

	last = s->size - 1;
	i = 0;
	while (s->data[last - i] <= max && s->data[last - i] != 0)
		++i;
	return (i);
}
