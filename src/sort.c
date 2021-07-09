/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleblanc <mleblanc@student.42quebec>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 22:49:09 by mleblanc          #+#    #+#             */
/*   Updated: 2021/07/09 16:21:46 by mleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pswap.h"
#include "libft.h"

static void	sort_big_recurse(t_pswap *stacks, int index, int last_count)
{
	int	i;
	int	mid;
	int	count;

	if (stacks->b->size <= 5)
	{
		sort_5_b(stacks);
		sort_5_a(stacks, stacks->a->size - last_count);
		return ;
	}
	i = index + (stacks->c->size - index) / 2;
	mid = stacks->c->data[i];
	count = split_b_higher(stacks, mid);
	sort_big_recurse(stacks, i, count);
}

void	sort_big(t_pswap *stacks)
{
	int	i;
	int	mid;

	i = stacks->c->size / 2;
	mid = stacks->c->data[i];
	split_a_lower(stacks, mid);
	sort_big_recurse(stacks, i, 0);
}

static int	smallest_index(t_stack *s, int start)
{
	int	index;
	int	i;

	index = start;
	i = start + 1;
	while (i < s->size)
	{
		if (s->data[i] < s->data[index])
			index = i;
		++i;
	}
	return (index);
}

void	sort_5_b(t_pswap *stacks)
{
	int	index;

	while (stacks->b->size > 1)
	{
		index = smallest_index(stacks->b, 0);
		if (index < stacks->b->size / 2)
			while (index-- != -1)
				rev_rotate_b(stacks->b);
		else
			while (index++ < stacks->b->size - 1)
				rotate_b(stacks->b);
		push_a(stacks->a, stacks->b);
		rotate_a(stacks->a);
	}
	push_a(stacks->a, stacks->b);
	rotate_a(stacks->a);
}

void	sort_5_a(t_pswap *stacks, int start)
{
	int	index;
	int	pushes;

	pushes = 0;
	while (start < stacks->a->size - 1)
	{
		index = smallest_index(stacks->a, start);
		while (index < stacks->a->size - 2)
		{
			push_b(stacks->b, stacks->a);
			++pushes;
		}
		if (index == stacks->a->size - 2)
		{
			swap_a(stacks->a);
			++index;
		}
		rotate_a(stacks->a);
		while (pushes-- > 0)
			push_a(stacks->a, stacks->b);
		++start;
	}
	rotate_a(stacks->a);
}
