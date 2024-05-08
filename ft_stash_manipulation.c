/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stash_manipulation.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zramahaz <zramahaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 15:12:10 by zramahaz          #+#    #+#             */
/*   Updated: 2024/05/08 15:16:57 by zramahaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int stash_sorted(t_list *a)
{
    while (a->next)
    {
        if (a->content > a->next->content)
            return (0);
        a = a->next;
    }
    return (1);
}

int ft_stash_len(t_list *a)
{
    int count;

    count = 0;
    while (a)
    {
        count++;
        a = a->next;       
    }
    return (count);
}