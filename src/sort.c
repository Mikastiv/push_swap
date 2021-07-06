/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleblanc <mleblanc@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 22:49:09 by mleblanc          #+#    #+#             */
/*   Updated: 2021/07/06 18:42:05 by mleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pswap.h"

void	sort_big_recurse(t_pswap *stacks, int index)
{
	int	i;
	int	mid;

	if (stacks->b->size <= 3)
		return ;
	i = index + (stacks->c->size - index) / 2;
	mid = stacks->c->data[i];
	split_b_higher(stacks, mid);
	sort_big_recurse(stacks, i);
}

void	sort_big(t_pswap *stacks)
{
	int		i;
	int		mid;

	i = stacks->c->size / 2;
	mid = stacks->c->data[i];
	split_a_lower(stacks, mid);
	sort_big_recurse(stacks, i);
}
