/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleblanc <mleblanc@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/04 20:24:45 by mleblanc          #+#    #+#             */
/*   Updated: 2021/07/04 23:58:07 by mleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

int	find_number(t_stack *stack, int n)
{
	int	i;

	i = 0;
	while (i < stack->size)
	{
		if (stack->data[i] == n)
			return (i);
		++i;
	}
	return (-1);
}
