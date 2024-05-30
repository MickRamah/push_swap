/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stash_manipulation.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zramahaz <zramahaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 15:12:10 by zramahaz          #+#    #+#             */
/*   Updated: 2024/05/30 15:27:59 by zramahaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list  *ft_get_last_list(t_list *stash)
{
    if (stash == NULL)
        return (NULL);
    while (stash->next)
        stash = stash->next;
    return (stash);
}

int	ft_sorted_stash(t_list *a)
{
	while (a->next)
	{
		if (a->content > a->next->content)
			return (0);
		a = a->next;
	}
	return (1);
}

size_t	ft_stash_len(t_list *a)
{
	int	count;

	count = 0;
	while (a)
	{
		count++;
		a = a->next;
	}
	return (count);
}

t_list	*ft_find_highest_node(t_list *a)
{
	int		max;
	t_list	*highest_node;

	max = INT_MIN;
	while (a)
	{
		if (max < a->content)
		{
			max = a->content;
			highest_node = a;
		}
		a = a->next;
	}
	return (highest_node);
}

t_list	*ft_find_smallest_node(t_list *a)
{
	int	min;
	t_list	*smallest_node;

	min = INT_MAX;
	while (a)
	{
		if (a->content < min)
		{
			min = a->content;
			smallest_node = a;
		}
		a = a->next;
	}
	return (smallest_node);
}

void	ft_set_current_position(t_list *stash)
{
	int	i;
	int	mediane;

	i = 0;
	mediane = ft_stash_len(stash) / 2;
	while (stash)
	{
		stash->current_position = i;
		if (i <= mediane)
			stash->above_mediane = true;
		else
			stash->above_mediane = false;
		i++;
		stash = stash->next;
	}
}

void	ft_set_target_node(t_list *a, t_list *b)
{
	int		max;
	t_list	*current_a;
	
	while (b)
	{
		max = INT_MAX;
		current_a = a;
		while (current_a)
		{
			if ((current_a->content > b->content) && (max > current_a->content))
			{
				max = current_a->content;
				b->target_node = current_a;
			}
			current_a = current_a->next;
		}
		if (max == INT_MAX)
			b->target_node = ft_find_smallest_node(a);
		b = b->next;
	}
}

void	ft_set_path_lenght(t_list *a, t_list *b)
{
	int	len_a;
	int	len_b;

	len_a = ft_stash_len(a);
	len_b = ft_stash_len(b);
	while (b)
	{
		b->path_lenght = b->current_position;
		if (b->above_mediane == false)
			b->path_lenght = len_b - b->path_lenght;
		if (b->target_node->above_mediane == true)
			b->path_lenght += b->target_node->current_position;
		else
			b->path_lenght += len_a - b->target_node->current_position;
		b = b->next;
	}
}

void	ft_set_shortest_path(t_list *b)
{
	int		min;
	t_list	*pos;

	if (b == NULL)
		return ;
	min = INT_MAX;
	while (b)
	{
		if (b->path_lenght < min)
		{
			min = b->path_lenght;
			pos = b;
		}
		b->shortest_path = false;
		b = b->next;
	}
	pos->shortest_path = true;
}