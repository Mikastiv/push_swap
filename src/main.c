#include "libft.h"
#include "array.h"

int	main(int argc, char **argv)
{
	t_array	*a;
	t_array	*b;

	(void)argv;
	a = new_array(argc - 1);
	b = new_array(argc - 1);
	push(a, 0);
	push(a, 1);
	push(a, 2);
	push(a, 3);
	push(a, 4);
	swap_a(a);
	ft_putstr_fd("a: \n", 1);
	print_array(a);
	ft_putstr_fd("b: \n", 1);
	print_array(b);
}
