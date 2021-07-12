/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleblanc <mleblanc@student.42quebec>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 22:49:09 by mleblanc          #+#    #+#             */
/*   Updated: 2021/07/12 16:52:54 by mleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pswap.h"
#include "libft.h"

static void	sort_big_recurse(t_pswap *s);

static bool	front_a_is_next(t_pswap *s)
{
	return (front(s->a) == 0 || front(s->a) == back(s->a) + 1);
}

void	push_a_top(t_pswap *s, int max)
{
	while (front(s->a) <= max)
	{
		if (front_a_is_next(s))
			rotate_a(s->a);
		else
			push_b(s->b, s->a);
	}
	if (stack_min(s->b) == back(s->a) + 1)
		sort_big_recurse(s);
}

static void	sort_big_recurse(t_pswap *s)
{
	int	b_max;

	if (s->b->size == 0)
		return ;
	b_max = stack_max(s->b);
	split_b_higher(s, average(s->b));
	while (front_a_is_next(s))
		rotate_a(s->a);
	sort_big_recurse(s);
	push_a_top(s, b_max);
}

void	sort_big(t_pswap *s)
{
	int	mid;

	mid = average(s->a);
	split_a_lower(s, mid);
	sort_big_recurse(s);
	push_a_top(s, stack_max(s->a));
}
