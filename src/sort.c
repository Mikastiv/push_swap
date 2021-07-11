/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleblanc <mleblanc@student.42quebec>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 22:49:09 by mleblanc          #+#    #+#             */
/*   Updated: 2021/07/11 18:08:31 by mleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pswap.h"
#include "libft.h"

static bool	front_a_is_next(t_pswap *s)
{
	return (front(s->a) == 0 || front(s->a) == back(s->a) + 1);
}

static void	sort_big_recurse(t_pswap *s)
{
	if (s->b->size == 0)
		return ;
	split_b_higher(s, average(s->b));
	while (front_a_is_next(s))
		rotate_a(s->a);
	sort_big_recurse(s);
}

void	sort_big(t_pswap *s)
{
	int	mid;

	mid = average(s->a);
	split_a_lower(s, mid);
	sort_big_recurse(s);
}
