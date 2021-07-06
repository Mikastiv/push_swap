#include "libft.h"
#include "stack.h"
#include "parse.h"
#include <stdlib.h>

void	clean_and_exit(t_stack *a, t_stack *b, t_stack *c)
{
	delete_stack(a);
	delete_stack(b);
	delete_stack(c);
	exit(0);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	t_stack	*c;

	if (argc < 2)
		return (0);
	a = new_stack(argc - 1);
	b = new_stack(argc - 1);
	c = new_stack(argc - 1);
	if (!a || !b || !c)
		clean_and_exit(a, b, c);
	if (!parse_args(argc, argv, a))
		clean_and_exit(a, b, c);
	copy_stack(c, a);
	quicksort(c);
	sort_big(a, b, c);
	clean_and_exit(a, b, c);
}
