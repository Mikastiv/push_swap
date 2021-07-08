/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pswap.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleblanc <mleblanc@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 23:02:46 by mleblanc          #+#    #+#             */
/*   Updated: 2021/07/08 15:53:18 by mleblanc         ###   ########.fr       */
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

void	split_a_lower(t_pswap *stacks, int mid);
int		split_b_higher(t_pswap *stacks, int mid);
void	sort_big(t_pswap *stacks);
void	sort_5(t_pswap *stacks);

#endif