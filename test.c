/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zramahaz <zramahaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 11:59:35 by zramahaz          #+#    #+#             */
/*   Updated: 2024/05/19 14:18:12 by zramahaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    test(t_list **a, t_list **b)
{
    t_list *current_a;
    t_list *last_a;
    t_list *current_b;
    t_list *last_b;

    current_a = *a;
    last_a = ft_get_last_list(*a);
	printf("a(tete): ");
	while (current_a)
	{
		printf("%d ->", current_a->content);
		current_a = current_a->next;
	}
    printf("%p", current_a);
    printf("\n");
    printf("a(queue): ");
	while (last_a)
	{
		printf("%d ->", last_a->content);
		last_a = last_a->prev;
	}
    printf("%p", last_a);
    printf("\n");
    /*move*/ ra(a, 1);
    current_a = *a;
    last_a = ft_get_last_list(*a);
	printf("a(tete): ");
	while (current_a)
	{
		printf("%d ->", current_a->content);
		current_a = current_a->next;
	}
    printf("%p", current_a);
    printf("\n");
    printf("a(queue): ");
	while (last_a)
	{
		printf("%d ->", last_a->content);
		last_a = last_a->prev;
	}
    printf("%p", last_a);
    printf("\n");
    
    // current_b = *b;
    // last_b = ft_get_last_list(*b);
	// printf("b(queue): ");
	// while (current_b)
	// {
	// 	printf("%d ->", current_b->content);
	// 	current_b = current_b->next;
	// }
    // printf("%p ->", current_b);
    // printf("\n");
    // printf("b(queue): ");
	// while (last_b)
	// {
	// 	printf("%d <-", last_b->content);
	// 	last_b = last_b->prev;
	// }
    // printf("%p", last_b);
    // printf("\n");
}