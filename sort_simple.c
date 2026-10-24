static int	find_min_position(t_stack *stack)
{
	t_node	*current;
	int		min_val;
	int		min_pos;
	int		i;

	current = stack->top;
	min_val = current->value;
	min_pos = 0;
	i = 0;
	while (i < stack->size)
	{
		if (current->value < min_val)
		{
			min_val = current->value;
			min_pos = i;
		}
		current = current->next;
		i++;
	}
	return (min_pos);
}

static void	rotate_min_to_top(t_stack *a, int pos, t_bench *bench)
{
	if (pos <= a->size / 2)
	{
		while (pos > 0)
		{
			op_ra(a, bench);
			pos--;
		}
	}
	else
	{
		pos = a->size - pos;
		while (pos > 0)
		{
			op_rra(a, bench);
			pos--;
		}
	}
}

static void	sort_two(t_stack *a, t_bench *bench)
{
	if (a->size == 2 && a->top->value > a->top->next->value)
		op_sa(a, bench);
}

static void	sort_three(t_stack *a, t_bench *bench)
{
	int	first;
	int	second;
	int	third;

	first = a->top->value;
	second = a->top->next->value;
	third = a->top->next->next->value;
	if (first > second && second < third && first < third)
		op_sa(a, bench);
	else if (first > second && second > third)
	{
		op_sa(a, bench);
		op_rra(a, bench);
	}
	else if (first > second && second < third && first > third)
		op_ra(a, bench);
	else if (first < second && second > third && first < third)
	{
		op_sa(a, bench);
		op_ra(a, bench);
	}
	else if (first < second && second > third && first > third)
		op_rra(a, bench);
}

void	sort_simple(t_stack *a, t_stack *b, t_bench *bench)
{
	int	pos;
	int	push_count;

	if (stack_is_sorted(a))
		return ;
	if (a->size == 2)
	{
		sort_two(a, bench);
		return ;
	}
	if (a->size == 3)
	{
		sort_three(a, bench);
		return ;
	}
	push_count = a->size - 3;
	while (push_count > 0)
	{
		pos = find_min_position(a);
		rotate_min_to_top(a, pos, bench);
		op_pb(a, b, bench);
		push_count--;
	}
	sort_three(a, bench);
	while (b->size > 0)
		op_pa(a, b, bench);
}
