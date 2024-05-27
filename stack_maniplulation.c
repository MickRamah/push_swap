#include "push_swap.h"

t_list	*ft_get_last_list(t_list *stash)
{
	t_list	*last;

	last = stash;
	while (last->next)
		last = last->next;
	return (last);
}

int  stack_sorted(t_list *stack)
{
    while (stack->next)
	{
		if (stack->value > stack->next->value)
			return (0);
		stack = stack->next;
	}
	return (1);
}

int  stack_len(t_list *stack)
{
    int count;

    count = 0;
    if (stack == NULL)
        return (0);
    while (stack)
    {
        count++;
        stack = stack->next;
    }
    return (count);
}

t_list	*find_highest(t_list *stack)
{
	int				highest;
	t_list	*highest_node;

	if (NULL == stack)
		return (NULL);
	highest = INT_MIN;
	while (stack)
	{
		if (stack->value > highest)
		{
			highest = stack->value;
			highest_node = stack;
		}
		stack = stack->next;
	}
	return (highest_node);
}

t_list	*find_smallest(t_list *stack)
{
	int				smallest;
	t_list	*smallest_node;

	if (stack == NULL)
		return (NULL);
	smallest = INT_MAX;
	while (stack)
	{
		if (stack->value < smallest)
		{
			smallest = stack->value;
			smallest_node = stack;
		}
		stack = stack->next;
	}
	return (smallest_node);
}

void	set_target_node(t_list *a, t_list *b)
{
	t_list	*target_node;
	t_list	*current_a;
	long	max;

	while (b)
	{
		max = LONG_MAX;
		current_a = a;
		while (current_a)
		{
			if ((current_a->value > b->value) && (max > current_a->value))
			{
				max = current_a->value;
				target_node = current_a;
			}
			current_a = current_a->next;
		}
		if (max == LONG_MAX)
			b->target_node = find_smallest(a);
		else
			b->target_node = target_node;
		b = b->next;
	}
}

void	set_position_node(t_list *stack)
{
	int	i;
	int	center;

	if (stack == NULL)
		return ;
	i = 0;
	center = (stack_len(stack)) / 2;
	while (stack)
	{
		stack->current_position = i;
		if (stack->current_position <= center)
			stack->above_mediane = true;
		else
			stack->above_mediane = false;
		i++;
		stack = stack->next;
	}
}

void	set_price(t_list *a, t_list *b)
{
	while (b)
	{
		b->push_price = b->current_position;
		if (b->above_mediane == false)
			b->push_price = stack_len(b) - b->current_position;
		if (b->target_node->above_mediane == true)
			b->push_price += b->target_node->current_position;
		else
			b->push_price += stack_len(a) -  b->target_node->current_position;
		b = b->next;
	}
}

void	set_cheapest(t_list *stack)
{
	int		min;
	t_list	*pos_node;

	if (stack  == NULL)
		return ;
	pos_node = NULL;
	min = INT_MAX;
	while (stack)
	{
		if (stack->push_price < min)
		{
			min = stack->push_price;
			pos_node = stack;
		}
		stack->cheapest = false;
		stack = stack->next;
	}
	pos_node->cheapest = true;
}

t_list	*return_cheapest(t_list *stack)
{
	t_list	*cheapest_node;

	if (stack == NULL)
		return (NULL);
	cheapest_node = NULL;
	while (stack)
	{
		if (stack->cheapest == true)
			return (stack);
		stack = stack->next;
	}
	return (NULL);
}