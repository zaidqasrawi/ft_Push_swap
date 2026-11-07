#include "push_swap.h"

static int	ft_sqrt(int size)
{
	int	i;

	i = 1;
	while (i * i < size)
		i++;
	return (i);
}

static int	find_max_pos(t_stack *b)
{
	int	max;
	int	pos;
	int	i;

	max = b->index;
	pos = 0;
	i = 0;
	while (b)
	{
		if (b->index > max)
		{
			max = b->index;
			pos = i;
		}
		b = b->next;
		i++;
	}
	return (pos);
}

static void	push_chunks_to_b(t_stack **a, t_stack **b, int size, int *ops)
{
	int	chunk;
	int	pushed;

	chunk = ft_sqrt(size) * 3 / 2;
	pushed = 0;
	while (*a)
	{
		if ((*a)->index <= pushed)
		{
			push_b(a, b, ops);
			rotate(b, 'b', ops);
			pushed++;
		}
		else if ((*a)->index <= pushed + chunk)
		{
			push_b(a, b, ops);
			pushed++;
		}
		else
			rotate(a, 'a', ops);
	}
}

static void	push_back_to_a(t_stack **a, t_stack **b, int *ops)
{
	while (*b)
	{
		rotate_to_top(b, 'b', find_max_pos(*b), ops);
		push_a(a, b, ops);
	}
}

void	sort_medium(t_stack **a, int size, int bench_flag)
{
	int		*ops;
	int		disorder;
	t_stack	*b;

	b = NULL;
	ops = init_ops();
	disorder = compute_disorder(*a) * 10000;
	if (disorder != 0)
	{
		index_stack(a);
		push_chunks_to_b(a, &b, size, ops);
		push_back_to_a(a, &b, ops);
	}
	end_sort(ops, disorder, bench_flag, "Medium / O(n*sqrt(n))");
}
