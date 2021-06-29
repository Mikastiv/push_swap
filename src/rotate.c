/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleblanc <mleblanc@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 23:57:14 by mleblanc          #+#    #+#             */
/*   Updated: 2021/06/29 00:17:00 by mleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "array.h"
#include "libft.h"

static void	rotate(t_array *a)
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

void	rotate_a(t_array *a)
{
	rotate(a);
	ft_putstr_fd("ra\n", 1);
}

void	rotate_b(t_array *b)
{
	rotate(b);
	ft_putstr_fd("rb\n", 1);
}

void	rotate_ab(t_array *a, t_array *b)
{
	rotate(a);
	rotate(b);
	ft_putstr_fd("rr\n", 1);
}
