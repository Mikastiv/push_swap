/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleblanc <mleblanc@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 22:48:35 by mleblanc          #+#    #+#             */
/*   Updated: 2021/06/29 00:30:27 by mleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"
#include "libft.h"

t_stack	*new_stack(size_t size)
{
	t_stack	*arr;

	arr = ft_calloc(1, sizeof(t_stack));
	if (!arr)
		return (NULL);
	arr->data = ft_calloc(size, sizeof(int));
	if (!arr->data)
		return (ft_free(arr));
	arr->size = 0;
	return (arr);
}

void	delete_stack(t_stack *stack)
{
	ft_free(stack->data);
	ft_free(stack);
}

void	print_stack(t_stack *stack)
{
	size_t	i;

	i = stack->size;
	while (i > 0)
	{
		ft_putnbr_fd(stack->data[--i], 1);
		ft_putchar_fd('\n', 1);
	}
}
