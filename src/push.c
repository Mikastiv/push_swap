/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleblanc <mleblanc@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 23:35:49 by mleblanc          #+#    #+#             */
/*   Updated: 2021/06/29 00:22:14 by mleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "array.h"
#include "libft.h"

static int	pop(t_array *a)
{
	int	n;

	n = a->data[a->size - 1];
	--a->size;
	return (n);
}

void	push(t_array *a, int n)
{
	a->data[a->size++] = n;
}

void	push_a(t_array *a, t_array *b)
{
	push(a, pop(b));
	ft_putstr_fd("pa\n", 1);
}

void	push_b(t_array *b, t_array *a)
{
	push(b, pop(a));
	ft_putstr_fd("pb\n", 1);
}
