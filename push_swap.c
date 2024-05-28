#include "push_swap.h"

static void	handle_five(t_list **a, t_list **b);
static void	init_nodes(t_list *a, t_list *b);
static void	move_nodes(t_list **a, t_list **b);

void	tiny_sort(t_list **stack)
{
	t_list	*highest_node;

	highest_node = find_highest(*stack);
	if (*stack == highest_node)
		ra(stack, 1);
	else if ((*stack)->next == highest_node)
		rra(stack, 1);
	if ((*stack)->value > (*stack)->next->value)
		sa(*stack, 1);
}

void	push_swap(t_list **a, t_list **b)
{
	int	len;
	t_list *min_node;

	len = stack_len(*a);
	if (len == 5)
		handle_five(a, b);
	else
	{
		while (len-- > 3)
			pb(a, b);
	}
	tiny_sort(a);
	while (*b)
	{
		init_nodes(*a, *b);
		move_nodes(a, b);
	}
	set_position_node(*a);
	min_node = find_smallest(*a);
	if (min_node->above_mediane)
		while (min_node != *a)
			ra(a, 1);
	else
		while (min_node != *a)
			rra(a, 1);
}

static void	handle_five(t_list **a, t_list **b)
{
	while (stack_len(*a) > 3)
	{
		init_nodes(*a, *b);
		finish_rotation_a(a, find_smallest(*a));
		pb(a, b);
	}
}

static void	init_nodes(t_list *a, t_list *b)
{
	set_position_node(a);
	set_position_node(b);
	set_target_node(a, b);
	set_price(a, b);
	set_cheapest(b);
}

static void	move_nodes(t_list **a, t_list **b)
{
	t_list *cheapest_node;

	cheapest_node = return_cheapest(*b);
	// printf("cheapest_node->content = %d\n", cheapest_node->value);
	if (cheapest_node->above_mediane && cheapest_node->target_node->above_mediane)
		rotate(a, b, cheapest_node);
	else if (!(cheapest_node->above_mediane) && !(cheapest_node->target_node->above_mediane))
		reverse_rotate(a, b, cheapest_node);
	finish_rotation_a(a, cheapest_node->target_node);
	finish_rotation_b(b, cheapest_node);
	pa(a, b);
}