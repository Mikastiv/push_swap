/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleblanc <mleblanc@student.42quebec>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 17:13:33 by mleblanc          #+#    #+#             */
/*   Updated: 2021/07/13 15:35:52 by mleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pswap.h"

int	average_a_top(t_pswap *s, int max)
{
	int	i;
	int	sum;
	int	last;

	i = 0;
	sum = 0;
	last = s->a->size - 1;
	while (s->a->data[last - i] != 0 && s->a->data[last - i] <= max)
	{
		sum += s->a->data[last - i];
		++i;
	}
	return ((float)(sum) / (int)(i + 0.5f));
}
