/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algo_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zramahaz <zramahaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 10:11:18 by zramahaz          #+#    #+#             */
/*   Updated: 2024/05/19 14:13:36 by zramahaz         ###   ########.fr       */
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
	/*napiana*/
	current->next->prev = NULL;
	*a = current->next;
	current->next = NULL;
	/*napiana*/
	current->prev = last;
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
	current->next->prev = NULL;
	*b = current->next;
	current->next = NULL;
	current->prev = last;
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
	t_list	*last;
	int				len;

	len = ft_stash_len(*a);
	if (NULL == *a || NULL == a || 1 == len)
		return ;
	last = ft_get_last_list(*a);
	last->prev->next = NULL;
	last->next = *a;
	last->prev = NULL;
	*a = last;
	last->next->prev = last;
	if (status)
		write(1, "rra\n", 4);
}

void	rrb(t_list **b, int status)
{
	t_list	*last;
	int				len;

	len = ft_stash_len(*b);
	if (NULL == *b || NULL == b || 1 == len)
		return ;
	last = ft_get_last_list(*b);
	last->prev->next = NULL;
	last->next = *b;
	last->prev = NULL;
	*b = last;
	last->next->prev = last;
	if (status)
		write(1, "rrb\n", 4);
}

void	pb(t_list **a, t_list **b)
{

	t_list	*node_to_push;

	if (NULL == *a)
		return ;
	node_to_push = *a;
	*a = (*a)->next;
	if (*a)
		(*a)->prev = NULL;
	node_to_push->prev = NULL;
	if (NULL == *b)
	{
		*b = node_to_push;
		node_to_push->next = NULL;
	}
	else
	{
		node_to_push->next = *b;
		node_to_push->next->prev = node_to_push;
		*b = node_to_push;
	}
	
	// t_list	*tmp_1;
	// t_list	*tmp_2;

	// tmp_1 = *a;
	// *a = (*a)->next;
	// tmp_1->next = NULL;
	// (*a)->prev = NULL;
	// if ((*b) == NULL)
	// 	*b = tmp_1;
	// else
	// {
	// 	tmp_2 = *b;
	// 	*b = tmp_1;
	// 	tmp_1->next = tmp_2;
	// }
	write(1, "pb\n", 3);
}

void	pa(t_list **a, t_list **b)
{
	t_list	*node_to_push;

	if (NULL == *b)
	{
		printf("b(tete): %p\n", *b);
		return ;		
	}
	node_to_push = *b;
	*b = (*b)->next;
	if (*b)
		(*b)->prev = NULL;
	node_to_push->prev = NULL;
	if (NULL == *a)
	{
		*a = node_to_push;
		node_to_push->next = NULL;
	}
	else
	{
		node_to_push->next = *a;
		node_to_push->next->prev = node_to_push;
		*a = node_to_push;
	}
	
	// t_list	*tmp_1;
	// t_list	*tmp_2;

	// tmp_1 = *b;
	// *b = (*b)->next;
	// tmp_1->next = NULL;
	// if ((*a) == NULL)
	// 	*a = tmp_1;
	// else
	// {
	// 	tmp_2 = *a;
	// 	*a = tmp_1;
	// 	tmp_1->next = tmp_2;
	// }
	write(1, "pa\n", 3);
}