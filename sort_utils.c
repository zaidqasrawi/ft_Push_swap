#include "push_swap.h"

int	*init_ops(void)
{
	int	*ops;

	ops = malloc(11 * sizeof(int));
	if (!ops)
		exit(1);
	ft_bzero(ops, 11 * sizeof(int));
	return (ops);
}

void	end_sort(int *ops, int disorder, int bench_flag, char *name)
{
	if (bench_flag)
		bench(ops, disorder, name);
	free(ops);
}

int	stack_size(t_stack *s)
{
	int	n;

	n = 0;
	while (s)
	{
		n++;
		s = s->next;
	}
	return (n);
}

void	rotate_to_top(t_stack **s, char c, int pos, int *ops)
{
	int	size;

	size = stack_size(*s);
	if (pos <= size / 2)
	{
		while (pos-- > 0)
			rotate(s, c, ops);
	}
	else
	{
		while (pos++ < size)
			reverse_rotate(s, c, ops);
	}
}
