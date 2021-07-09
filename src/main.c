#include "libft.h"
#include "pswap.h"
#include "parse.h"
#include <stdlib.h>

void	clean_and_exit(t_pswap *stacks)
{
	delete_stack(stacks->a);
	delete_stack(stacks->b);
	delete_stack(stacks->c);
	exit(0);
}

void	rank(t_stack *a, t_stack *c)
{
	int	i;

	i = 0;
	while (i < c->size)
	{
		a->data[i] = (c->size - 1) - find_number(c, a->data[i]);
		++i;
	}
}

int	main(int argc, char **argv)
{
	t_pswap	stacks;

	if (argc < 2)
		return (0);
	stacks.a = new_stack(argc - 1);
	stacks.b = new_stack(argc - 1);
	stacks.c = new_stack(argc - 1);
	if (!stacks.a || !stacks.b || !stacks.c)
		clean_and_exit(&stacks);
	if (!parse_args(argc, argv, stacks.a))
		clean_and_exit(&stacks);
	copy_stack(stacks.c, stacks.a);
	quicksort(stacks.c);
	rank(stacks.a, stacks.c);
	sort_big(&stacks);
	clean_and_exit(&stacks);
}
