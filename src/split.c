/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleblanc <mleblanc@student.42quebec>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 22:50:02 by mleblanc          #+#    #+#             */
/*   Updated: 2021/07/13 15:36:42 by mleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pswap.h"

void	split_a_lower(t_pswap *s, int mid)
{
	while (contains_smaller(s->a, mid))
	{
		while (front(s->a) > mid)
			rotate_a(s->a);
		push_b(s->b, s->a);
	}
}

static bool	front_b_is_next(t_pswap *s)
{
	return (front(s->b) == 0 || front(s->b) == back(s->a) + 1);
}

static void	max_to_front(t_pswap *s)
{
	int	i;
	int	max;

	max = stack_max(s->b);
	if (front(s->b) == max)
	{
		push_a(s->a, s->b);
		return ;
	}
	i = find_number(s->b, max);
	if (i < s->b->size / 2)
		rev_rotate_b(s->b);
	else
		rotate_b(s->b);
}

void	split_b_higher(t_pswap *s, int mid)
{
	int	count;

	count = s->b->size;
	while (count-- > 0)
	{
		if (front_b_is_next(s))
		{
			push_a(s->a, s->b);
			rotate_a(s->a);
		}
		else if (s->b->size < 13)
			max_to_front(s);
		else if (mid <= front(s->b))
			push_a(s->a, s->b);
		else
			rotate_b(s->b);
	}
}

void	split_a_top(t_pswap *s, int max)
{
	int	rotations;
	int	mid;
	int	i;

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
	i = rotations;
	while (rotations--)
		rev_rotate_a(s->a);
	if (should_sort_b(s) && i > 0)
		sort_b_recurse(s);
}
