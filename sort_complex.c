#include "push_swap.h"

void	index_stack(t_stack **a)
{
	t_stack	*cur;
	t_stack	*cmp;
	int		rank;

	cur = *a;
	while (cur)
	{
		rank = 0;
		cmp = *a;
		while (cmp)
		{
			if (cur->value > cmp->value)
				rank++;
			cmp = cmp->next;
		}
		cur->index = rank;
		cur = cur->next;
	}
}

static int	count_bits(int n)
{
	int	bits;

	bits = 0;
	while (n > 0)
	{
		bits++;
		n >>= 1;
	}
	return (bits);
}

static void	radix_pass(t_stack **a, t_stack **b, int bit, int *ops)
{
	int	i;
	int	size;

	i = 0;
	size = stack_size(*a);
	while (i < size)
	{
		if ((((*a)->index >> bit) & 1) == 0)
			push_b(a, b, ops);
		else
			rotate(a, 'a', ops);
		i++;
	}
	while (*b)
		push_a(a, b, ops);
}

void	sort_complex(t_stack **a, int size, int bench_flag)
{
	int		*ops;
	int		disorder;
	int		bit;
	int		max_bits;
	t_stack	*b;

	b = NULL;
	ops = init_ops();
	disorder = compute_disorder(*a) * 10000;
	if (disorder != 0)
	{
		index_stack(a);
		max_bits = count_bits(size - 1);
		bit = 0;
		while (bit < max_bits)
			radix_pass(a, &b, bit++, ops);
	}
	end_sort(ops, disorder, bench_flag, "Complex / O(nlog(n))");
}
