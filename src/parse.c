/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleblanc <mleblanc@student.42quebec>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 13:52:33 by mleblanc          #+#    #+#             */
/*   Updated: 2021/07/09 14:06:14 by mleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "stack.h"
#include <limits.h>
#include <stdlib.h>

bool	is_not_digit(char c)
{
	return (!ft_isdigit(c));
}

int	*lst_find(t_list *lst, int n)
{
	int	*ptr;

	while (lst)
	{
		ptr = (int *)lst->content;
		if (*ptr == n)
			return (ptr);
		lst = lst->next;
	}
	return (NULL);
}

bool	add_elem(t_stack *s, t_list **lst, char *num)
{
	t_list	*tmp;
	long	*n;

	n = (long *)ft_calloc(1, sizeof(long));
	if (!n)
		return (false);
	*n = ft_atol(num);
	if (num[0] == '-' || num[0] == '+')
		num++;
	if (lst_find(*lst, (int)*n) || ft_str_any(num, is_not_digit)
		|| *n > (long)INT_MAX || *n < (long)INT_MIN)
	{
		free(n);
		return (false);
	}
	tmp = ft_lstnew(n);
	if (!tmp)
	{
		free(n);
		return (false);
	}
	ft_lstadd_front(lst, tmp);
	push_back(s, *n);
	return (true);
}

bool	parse_args(int argc, char **argv, t_stack *a)
{
	t_list	*lst;
	int		i;

	lst = NULL;
	i = 1;
	while (i < argc)
	{
		if (!add_elem(a, &lst, argv[i]))
		{
			ft_lstclear(&lst, free);
			ft_putendl_fd("Error", 2);
			return (false);
		}
		++i;
	}
	ft_lstclear(&lst, free);
	return (true);
}
