/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleblanc <mleblanc@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 22:49:09 by mleblanc          #+#    #+#             */
/*   Updated: 2021/07/08 16:18:08 by mleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pswap.h"
#include "libft.h"

static void	sort_big_recurse(t_pswap *stacks, int index)
{
	int	i;
	int	mid;
	int	count;

	if (stacks->b->size <= 5)
	{
		sort_5(stacks);
		return ;
	}
	i = index + (stacks->c->size - index) / 2;
	mid = stacks->c->data[i];
	count = split_b_higher(stacks, mid);
	sort_big_recurse(stacks, i);
}

void	sort_big(t_pswap *stacks)
{
	int	i;
	int	mid;

	i = stacks->c->size / 2;
	mid = stacks->c->data[i];
	split_a_lower(stacks, mid);
	sort_big_recurse(stacks, i);
}

static int	smallest_index(t_stack *s)
{
	int	index;
	int	i;

	index = 0;
	i = 1;
	while (i < s->size)
	{
		if (s->data[i] < s->data[index])
			index = i;
		++i;
	}
	return (index);
}

void	sort_5(t_pswap *stacks)
{
	int	index;

	while (stacks->b->size > 1)
	{
		index = smallest_index(stacks->b);
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
