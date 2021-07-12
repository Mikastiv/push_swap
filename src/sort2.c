/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleblanc <mleblanc@student.42quebec>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 17:13:33 by mleblanc          #+#    #+#             */
/*   Updated: 2021/07/12 17:46:13 by mleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pswap.h"

int	average_a_top(t_pswap *s, int max)
{
	int	i;
	int	sum;

	i = s->a->size - 1;
	sum = 0;
	while (s->a->data[i] != 0 && s->a->data[i] <= max)
	{
		sum += s->a->data[i];
		--i;
	}
	i = s->a->size - 1 - i;
	return ((float)(sum) / (int)(i + 0.5f));
}

void	split_a_top(t_pswap *s, int max)
{
	int	rotations;
	int	mid;
	// int	i;

	mid = average_a_top(s, max);
	rotations = 0;
	while (front(s->a) <= max && front(s->a) != 0)
	{
		if (front(s->a) >= mid)
		{
			rotate_a(s->a);
			++rotations;
		}
		else
			push_b(s->b, s->a);
	}
	while (rotations--)
		rev_rotate_a(s->a);
	if (should_sort_b(s))
		sort_b_recurse(s);
}
