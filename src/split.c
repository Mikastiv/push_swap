/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleblanc <mleblanc@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 22:50:02 by mleblanc          #+#    #+#             */
/*   Updated: 2021/07/07 18:45:14 by mleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pswap.h"

void	split_a_lower(t_pswap *stacks, int mid)
{
	while (contains_smaller(stacks->a, mid))
	{
		while (front(stacks->a) > mid)
			rotate_a(stacks->a);
		push_b(stacks->b, stacks->a);
	}
}

int	split_b_higher(t_pswap *stacks, int mid)
{
	int	push_count;

	push_count = 0;
	while (contains_bigger(stacks->b, mid))
	{
		while (front(stacks->b) <= mid)
			rotate_b(stacks->b);
		push_a(stacks->a, stacks->b);
		++push_count;
	}
	return (push_count);
}
