/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleblanc <mleblanc@student.42quebec>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/04 20:24:45 by mleblanc          #+#    #+#             */
/*   Updated: 2021/07/12 17:19:06 by mleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

int	find_number(t_stack *s, int n)
{
	int	i;

	i = 0;
	while (i < s->size)
	{
		if (s->data[i] == n)
			return (i);
		++i;
	}
	return (-1);
}

int	average(t_stack *s)
{
	int	i;
	int	sum;

	i = 0;
	sum = 0;
	while (i < s->size)
	{
		sum += s->data[i];
		++i;
	}
	return ((float)(sum) / (int)(s->size + 0.5f));
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
