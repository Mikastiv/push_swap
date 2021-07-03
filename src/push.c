/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleblanc <mleblanc@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 23:35:49 by mleblanc          #+#    #+#             */
/*   Updated: 2021/07/03 14:24:40 by mleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"
#include "libft.h"

static int	pop(t_stack *a)
{
	int	n;

	n = a->data[a->size - 1];
	--a->size;
	return (n);
}

void	push(t_stack *s, int n)
{
	s->data[s->size++] = n;
}

void	push_a(t_stack *a, t_stack *b)
{
	if (b->size > 0)
		push(a, pop(b));
	ft_putstr_fd("pa\n", 1);
}

void	push_b(t_stack *b, t_stack *a)
{
	if (a->size > 0)
		push(b, pop(a));
	ft_putstr_fd("pb\n", 1);
}
