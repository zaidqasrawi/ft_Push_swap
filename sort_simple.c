#include "push_swap.h"

static int	find_min_pos(t_stack *s)
{
	int	min;
	int	pos;
	int	i;

	min = s->value;
	pos = 0;
	i = 0;
	while (s)
	{
		if (s->value < min)
		{
			min = s->value;
			pos = i;
		}
		s = s->next;
		i++;
	}
	return (pos);
}

static void	sort_three(t_stack **a, int *ops)
{
	int	x;
	int	y;
	int	z;

	x = (*a)->value;
	y = (*a)->next->value;
	z = (*a)->next->next->value;
	if (x > y && x > z)
		rotate(a, 'a', ops);
	else if (y > x && y > z)
		reverse_rotate(a, 'a', ops);
	if ((*a)->value > (*a)->next->value)
		swap_a(a, ops);
}

static void	selection_sort(t_stack **a, t_stack **b, int size, int *ops)
{
	while (size > 3)
	{
		rotate_to_top(a, 'a', find_min_pos(*a), ops);
		push_b(a, b, ops);
		size--;
	}
	sort_three(a, ops);
	while (*b)
		push_a(a, b, ops);
}

void	sort_simple(t_stack **a, int size, int bench_flag)
{
	int		*ops;
	int		disorder;
	t_stack	*b;

	b = NULL;
	ops = init_ops();
	disorder = compute_disorder(*a) * 10000;
	if (disorder != 0 && size == 2)
		swap_a(a, ops);
	else if (disorder != 0)
		selection_sort(a, &b, size, ops);
	end_sort(ops, disorder, bench_flag, "Simple / O(n^2)");
}
