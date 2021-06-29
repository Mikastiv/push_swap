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
	push(s, *n);
	return (true);
}

bool	parse_args(int argc, char **argv, t_stack *a)
{
	t_list	*lst;
	size_t	i;

	lst = NULL;
	i = 1;
	while ((int)i < argc)
	{
		if (!add_elem(a, &lst, argv[i]))
		{
			ft_lstclear(&lst, free);
			return (false);
		}
		++i;
	}
	ft_lstclear(&lst, free);
	return (true);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	if (argc < 2)
		return (0);
	a = new_stack(argc - 1);
	b = new_stack(argc - 1);
	parse_args(argc, argv, a);
	ft_putstr_fd("a: \n", 1);
	print_stack(a);
	ft_putstr_fd("b: \n", 1);
	print_stack(b);
	delete_stack(a);
	delete_stack(b);
}
