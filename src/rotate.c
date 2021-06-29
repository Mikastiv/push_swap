/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleblanc <mleblanc@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 23:57:14 by mleblanc          #+#    #+#             */
/*   Updated: 2021/06/29 00:30:27 by mleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"
#include "libft.h"

static void	rotate(t_stack *a)
{
	size_t	i;
	int		tmp;

	if (a->size < 2)
		return ;
	i = a->size - 1;
	tmp = a->data[i];
	while (i > 0)
	{
		a->data[i] = a->data[i - 1];
		--i;
	}
	a->data[0] = tmp;
}

void	rotate_a(t_stack *a)
{
	rotate(a);
	ft_putstr_fd("ra\n", 1);
}

void	rotate_b(t_stack *b)
{
	rotate(b);
	ft_putstr_fd("rb\n", 1);
}

void	rotate_ab(t_stack *a, t_stack *b)
{
	rotate(a);
	rotate(b);
	ft_putstr_fd("rr\n", 1);
}
