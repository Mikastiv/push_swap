/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleblanc <mleblanc@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 22:49:09 by mleblanc          #+#    #+#             */
/*   Updated: 2021/07/05 23:13:06 by mleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort.h"

void	sort_big_recurse(t_sort *stacks, int index)
{
	int	i;
	int	mid;

	if (stacks->b->size <= 3)
		return ;
	i = index + (stacks->c->size - index) / 2;
	mid = stacks->c->data[i];
	split_b_higher(stacks->b, stacks->a, mid);
	sort_big_recurse(stacks, i);
}

void	sort_big(t_stack *a, t_stack *b, t_stack *c)
{
	t_sort	s;
	int		i;
	int		mid;

	s.a = a;
	s.b = b;
	s.c = c;
	i = c->size / 2;
	mid = c->data[i];
	split_a_lower(a, b, mid);
	sort_big_recurse(&s, i);
}
