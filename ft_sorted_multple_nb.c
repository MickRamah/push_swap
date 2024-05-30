/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorted_multple_nb.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zramahaz <zramahaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 14:38:25 by zramahaz          #+#    #+#             */
/*   Updated: 2024/05/30 16:57:06 by zramahaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void     ft_init_nodes(t_list *a, t_list *b);
static void     ft_move_node(t_list **a, t_list **b);
static t_list   *ft_return_shortest_path(t_list *b);
static void     ft_sorted_5_nb(t_list **a, t_list **b);

void	ft_sorted_3_nb(t_list **a)
{
	t_list	*highest_node;

	highest_node = ft_find_highest_node(*a);
	if (*a == highest_node)
		ra(a, 1);
	else if ((*a)->next == highest_node)
		rra(a, 1);
	if ((*a)->content > (*a)->next->content)
		sa(*a, 1);
}

void    ft_sorted_multiple_nbs(t_list **a, t_list **b)
{
    int     len_a;
    t_list  *smallest_node;

    len_a = ft_stash_len(*a);
    if (len_a == 5)
        ft_sorted_5_nb(a, b);
    else
    {
        while (len_a > 3)
        {
            pb(a, b);
            len_a--;
        }
    }
    ft_sorted_3_nb(a);
    while (*b)
    {
        ft_init_nodes(*a, *b);
        ft_move_node(a, b);
    }
    ft_set_current_position(*a);
    smallest_node = ft_find_smallest_node(*a);
    while (*a != smallest_node)
    {
        if (smallest_node->above_mediane)
            ra(a, 1);
        else
            rra(a, 1);
    }    
}

static void ft_init_nodes(t_list *a, t_list *b)
{
    ft_set_current_position(a);
    ft_set_current_position(b);
    ft_set_target_node(a, b);
    ft_set_path_lenght(a, b);
    ft_set_shortest_path(b);
}

static void ft_move_node(t_list **a, t_list **b)
{
    t_list  *shortest_path;

    shortest_path = ft_return_shortest_path(*b);
    if (shortest_path->above_mediane && shortest_path->target_node->above_mediane)
        ft_rotation(a, b, shortest_path);
    if (!(shortest_path->above_mediane) && !(shortest_path->target_node->above_mediane))
        ft_reverse_rotation(a, b, shortest_path);
    ft_finish_rotation_b(b, shortest_path);
    ft_finish_rotation_a(a, shortest_path->target_node);
    pa(a, b);
}

static t_list   *ft_return_shortest_path(t_list *b)
{
    while (b)
    {
        if (b->shortest_path == true)
            return (b);
        b = b->next;
    }
}

static void ft_sorted_5_nb(t_list **a, t_list **b)
{
    ft_init_nodes(*a, *b);
    ft_finish_rotation_a(a, ft_find_smallest_node(*a));
    pb(a, b);
    ft_init_nodes(*a, *b);
    ft_finish_rotation_a(a, ft_find_smallest_node(*a));
    pb(a, b);
}