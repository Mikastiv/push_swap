#include "libft.h"
#include "stack.h"
#include "parse.h"

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	if (argc < 2)
		return (0);
	a = new_stack(argc - 1);
	b = new_stack(argc - 1);
	parse_args(argc, argv, a);
	ft_putstr_fd("a:\n", 1);
	print_stack(a);
	ft_putstr_fd("b:\n", 1);
	print_stack(b);
	ft_putnbr_fd(is_sorted(a), 1);
	delete_stack(a);
	delete_stack(b);
}
