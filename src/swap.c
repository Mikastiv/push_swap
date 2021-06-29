/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleblanc <mleblanc@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 23:00:36 by mleblanc          #+#    #+#             */
/*   Updated: 2021/06/29 00:17:04 by mleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "array.h"
#include "libft.h"

static void	swap(t_array *arr)
{
	int	tmp;

	if (arr->size < 2)
		return ;
	tmp = arr->data[arr->size - 1];
	arr->data[arr->size - 1] = arr->data[arr->size - 2];
	arr->data[arr->size - 2] = tmp;
}

void	swap_a(t_array *a)
{
	swap(a);
	ft_putstr_fd("sa\n", 1);
}

void	swap_b(t_array *b)
{
	swap(b);
	ft_putstr_fd("sb\n", 1);
}

void	swap_ab(t_array *a, t_array *b)
{
	swap(a);
	swap(b);
	ft_putstr_fd("ss\n", 1);
}
