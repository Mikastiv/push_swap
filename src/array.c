/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleblanc <mleblanc@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 22:48:35 by mleblanc          #+#    #+#             */
/*   Updated: 2021/06/29 00:20:40 by mleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "array.h"
#include "libft.h"

t_array	*new_array(size_t size)
{
	t_array	*arr;

	arr = ft_calloc(1, sizeof(t_array));
	if (!arr)
		return (NULL);
	arr->data = ft_calloc(size, sizeof(int));
	if (!arr->data)
		return (ft_free(arr));
	arr->size = 0;
	return (arr);
}

void	delete_array(t_array *array)
{
	ft_free(array->data);
	ft_free(array);
}

void	print_array(t_array *array)
{
	size_t	i;

	i = array->size;
	while (i > 0)
	{
		ft_putnbr_fd(array->data[--i], 1);
		ft_putchar_fd('\n', 1);
	}
}
