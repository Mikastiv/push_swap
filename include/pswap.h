/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pswap.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleblanc <mleblanc@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 23:02:46 by mleblanc          #+#    #+#             */
/*   Updated: 2021/07/06 00:43:24 by mleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PSWAP_H
# define PSWAP_H

# include "stack.h"

typedef struct s_pswap
{
	t_stack	*a;
	t_stack	*b;
	t_stack	*c;
}	t_pswap;

void	split_a_lower(t_pswap *stacks, int min, int max);
void	split_b_higher(t_pswap *stacks, int min, int max);
void	sort_big(t_pswap *stacks);

#endif