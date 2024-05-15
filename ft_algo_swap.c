/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algo_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zramahaz <zramahaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 10:11:18 by zramahaz          #+#    #+#             */
/*   Updated: 2024/05/15 16:19:09 by zramahaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ss(t_list *a, t_list *b)
{
	sa(a, 0);
	sb(b, 0);
	write(1, "ss\n", 3);
}

void	sa(t_list *a, int status)
{
	int	tmp;

	tmp = a->content;
	a->content = a->next->content;
	a->next->content = tmp;
	if (status)
		write(1, "sa\n", 3);
}

void	sb(t_list *b, int status)
{
	int	tmp;

	tmp = b->content;
	b->content = b->next->content;
	b->next->content = tmp;
	if (status)
		write(1, "sb\n", 3);
}

void	rr(t_list **a, t_list **b)
{
	ra(a, 0);
	rb(b, 0);
	write(1, "rr\n", 3);
}

void	ra(t_list **a, int status)
{
	t_list	*current;
	t_list	*last;

	current = *a;
	last = ft_get_last_list(current);
	last->next = current;
	*a = current->next;
	current->next = NULL;
	if (status)
		write(1, "ra\n", 3);
}

void	rb(t_list **b, int status)
{
	t_list	*current;
	t_list	*last;

	current = *b;
	last = ft_get_last_list(current);
	last->next = current;
	*b = current->next;
	current->next = NULL;
	if (status)
		write(1, "rb\n", 3);
}

void	rrr(t_list **a, t_list **b)
{
	rra(a, 0);
	rrb(b, 0);
	write(1, "rrr\n", 4);
}

void	rra(t_list **a, int status)
{
	t_list	*current;
	t_list	*last;

	current = *a;
	last = ft_get_last_list(*a);
	*a = last;
	last->next = current;
	current = current->next;
	current->next = NULL;
	write(1, "rra\n", 4);
}

void	rrb(t_list **b, int status)
{
	t_list	*current;
	t_list	*last;

	current = *b;
	last = ft_get_last_list(*b);
	*b = last;
	last->next = current;
	current = current->next;
	current->next = NULL;
	write(1, "rrb\n", 4);
}

void	pb(t_list **a, t_list **b)
{
	t_list	*tmp_1;
	t_list	*tmp_2;

	tmp_1 = *a;
	*a = (*a)->next;
	tmp_1->next = NULL;
	if ((*b) == NULL)
		*b = tmp_1;
	else
	{
		tmp_2 = *b;
		*b = tmp_1;
		tmp_1->next = tmp_2;
	}
	write(1, "pb\n", 3);
}

void	pa(t_list **b, t_list **a)
{
	t_list	*tmp_1;
	t_list	*tmp_2;

	tmp_1 = *b;
	*b = (*b)->next;
	tmp_1->next = NULL;
	if ((*a) == NULL)
		*a = tmp_1;
	else
	{
		tmp_2 = *a;
		*a = tmp_1;
		tmp_1->next = tmp_2;
	}
	write(1, "pa\n", 3);
}
