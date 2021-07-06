/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleblanc <mleblanc@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 22:50:02 by mleblanc          #+#    #+#             */
/*   Updated: 2021/07/05 22:51:29 by mleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

void	split_a_lower(t_stack *a, t_stack *b, int mid)
{
	while (contains_smaller(a, mid))
	{
		while (front(a) > mid)
			rotate_a(a);
		push_b(b, a);
	}
}

void	split_b_higher(t_stack *b, t_stack *a, int mid)
{
	while (contains_bigger(b, mid))
	{
		while (front(b) <= mid)
			rotate_b(b);
		push_a(a, b);
	}
}
