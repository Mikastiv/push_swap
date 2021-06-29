#include "libft.h"
#include "stack.h"
#include "parse.h"
#include <stdlib.h>

void	clean_and_exit(t_stack *a, t_stack *b)
{
	delete_stack(a);
	delete_stack(b);
	exit(0);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	if (argc < 2)
		return (0);
	a = new_stack(argc - 1);
	b = new_stack(argc - 1);
	if (!a || !b)
		clean_and_exit(a, b);
	if (!parse_args(argc, argv, a))
		clean_and_exit(a, b);
	clean_and_exit(a, b);
}
