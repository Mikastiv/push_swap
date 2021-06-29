/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleblanc <mleblanc@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 00:07:59 by mleblanc          #+#    #+#             */
/*   Updated: 2021/06/29 00:26:42 by mleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "array.h"
#include "libft.h"

static void	rev_rotate(t_array *a)
{
	size_t	i;
	int		tmp;

	if (a->size < 2)
		return ;
	i = 0;
	tmp = a->data[0];
	while (i < a->size - 1)
	{
		a->data[i] = a->data[i + 1];
		++i;
	}
	a->data[a->size - 1] = tmp;
}

void	rev_rotate_a(t_array *a)
{
	rev_rotate(a);
	ft_putstr_fd("rra\n", 1);
}

void	rev_rotate_b(t_array *b)
{
	rev_rotate(b);
	ft_putstr_fd("rrb\n", 1);
}

void	rev_rotate_ab(t_array *a, t_array *b)
{
	rev_rotate(a);
	rev_rotate(b);
	ft_putstr_fd("rrr\n", 1);
}
