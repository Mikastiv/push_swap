/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleblanc <mleblanc@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 23:00:36 by mleblanc          #+#    #+#             */
/*   Updated: 2021/06/29 00:30:27 by mleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"
#include "libft.h"

static void	swap(t_stack *arr)
{
	int	tmp;

	if (arr->size < 2)
		return ;
	tmp = arr->data[arr->size - 1];
	arr->data[arr->size - 1] = arr->data[arr->size - 2];
	arr->data[arr->size - 2] = tmp;
}

void	swap_a(t_stack *a)
{
	swap(a);
	ft_putstr_fd("sa\n", 1);
}

void	swap_b(t_stack *b)
{
	swap(b);
	ft_putstr_fd("sb\n", 1);
}

void	swap_ab(t_stack *a, t_stack *b)
{
	swap(a);
	swap(b);
	ft_putstr_fd("ss\n", 1);
}
