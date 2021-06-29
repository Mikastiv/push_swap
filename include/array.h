/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleblanc <mleblanc@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 22:30:41 by mleblanc          #+#    #+#             */
/*   Updated: 2021/06/29 00:22:35 by mleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_H
# define ARRAY_H

# include <stddef.h>

typedef struct s_array
{
	int		*data;
	size_t	size;
}	t_array;

t_array	*new_array(size_t size);
void	delete_array(t_array *array);
void	print_array(t_array *array);

void	swap_a(t_array *a);
void	swap_b(t_array *b);
void	swap_ab(t_array *a, t_array *b);

void	push(t_array *a, int n);
void	push_a(t_array *a, t_array *b);
void	push_b(t_array *b, t_array *a);

void	rotate_a(t_array *a);
void	rotate_b(t_array *b);
void	rotate_ab(t_array *a, t_array *b);

void	rev_rotate_a(t_array *a);
void	rev_rotate_b(t_array *b);
void	rev_rotate_ab(t_array *a, t_array *b);

#endif
