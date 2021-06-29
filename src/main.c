#include "libft.h"
#include "stack.h"

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	(void)argv;
	a = new_stack(argc - 1);
	b = new_stack(argc - 1);
	push(a, 0);
	push(a, 1);
	push(a, 2);
	push(a, 3);
	push(a, 4);
	swap_a(a);
	ft_putstr_fd("a: \n", 1);
	print_stack(a);
	ft_putstr_fd("b: \n", 1);
	print_stack(b);
}
