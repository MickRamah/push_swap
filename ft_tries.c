/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tries.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zramahaz <zramahaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 14:38:25 by zramahaz          #+#    #+#             */
/*   Updated: 2024/05/19 15:34:01 by zramahaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void    ft_search_min_and_swap(t_list **a);

void	ft_swap(t_list **a, t_list **b)
{
	if (ft_stash_len(*a) == 5)
		ft_trie_cinq_nb(a, b);
}

void	ft_trie_cinq_nb(t_list **a, t_list **b)
{
	while (ft_stash_len(*a) > 3)
    {
        ft_search_min_and_swap(a);
        pb(a, b);
    }
    if (!ft_stash_sorted(*a))
        tiny_sort(a);
    pa(a, b);
    pa(a, b);
}

static void    ft_search_min_and_swap(t_list **a)
{
    int min;
    t_list  *pos;
    t_list  *current;
    t_list  *last;

    current = (*a);
    pos = *a;
    min = INT_MAX;
    last = ft_get_last_list(*a);
    while (current)
    {
        if (min > current->content)
        {
            min = current->content;
            pos = current;
        }
        current = current->next;
    }
    if (pos == *a)
        return ;
    else if (pos == (*a)->next)
        sa(*a, 1);
    else if (pos == last->prev)
    {
        rra(a, 1);
        rra(a, 1);
    }
    else if (pos == last)
        rra(a, 1);
    else
    {
        ra(a, 1);
        sa(*a, 1);
    }
}