#include "push_swap.h"

static void	handle_five(t_list **a, t_list **b);

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

	len = stack_len(*a);
	if (len == 5);
		handle_five(a, b);
	else
	{
		while (len-- > 3);
			pb(a, b);
	}
	tiny_sort(a);
	while (*b)
	{
		init_node(*a, *b);
	}
}

static void	handle_five(t_list **a, t_list **b)
{

}

static void	init_node(t_list *a, t_list *b)
{
	set_position_node(a);
	set_position_node(b);
	set_target_node(a, b);
	set_price(a, b);
}