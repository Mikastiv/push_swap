/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleblanc <mleblanc@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 23:35:49 by mleblanc          #+#    #+#             */
/*   Updated: 2021/06/29 00:30:27 by mleblanc         ###   ########.fr       */
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

void	push(t_stack *a, int n)
{
	a->data[a->size++] = n;
}

void	push_a(t_stack *a, t_stack *b)
{
	push(a, pop(b));
	ft_putstr_fd("pa\n", 1);
}

void	push_b(t_stack *b, t_stack *a)
{
	push(b, pop(a));
	ft_putstr_fd("pb\n", 1);
}
