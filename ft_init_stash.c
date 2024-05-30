/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_stash.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zramahaz <zramahaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 11:00:25 by zramahaz          #+#    #+#             */
/*   Updated: 2024/05/30 15:28:10 by zramahaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int  ft_syntax_error(char *argv_i);
static void ft_free_and_exit(int argc, char **argv, t_list **a);
static int  ft_check_repetition_and_stash(t_list **a, int nb);
static int  ft_check_repetition(t_list *a, int nb);

void	ft_init_stash(int argc, char **argv, t_list **a)
{
    int     i;
    long    nb;

    i = 0;
    while (argv[i])
    {
        if (ft_syntax_error(argv[i]))
            ft_free_and_exit(argc, argv, a);
        nb = ft_atoi(argv[i]);
        if (nb > INT_MAX || nb < INT_MIN)
            ft_free_and_exit(argc, argv, a); 
        if (ft_check_repetition_and_stash(a, (int)nb))
            ft_free_and_exit(argc, argv, a);            
        i++;
    }
    if (argc == 2)
    {
        i = 0;
        while (argv[i])
        {
            free(argv[i]);
            i++;
        }
        free(argv);
    }
}

static int  ft_syntax_error(char *argv_i)
{
    int j;

    j = 0;
    if (!(argv_i[j] == '+' || argv_i[j] == '-'
            || (argv_i[j] >= '0' && argv_i[j] <= '9')))
        return (1);
    if (argv_i[j] == '-' || argv_i[j] == '+')
        j++;
    while ((argv_i[j] >= '0' && argv_i[j] <= '9') && argv_i[j])
        j++;
    if ((argv_i[j - 1] == '-' || argv_i[j -1] == '+') && !argv_i[j])
        return (1);
    if (!argv_i[j])
        return (0);
    return (1);
}

static void ft_free_and_exit(int argc, char **argv, t_list **a)
{
    int i;
    t_list  *tmp;
    t_list  *current;

    i = 0;
    if (argc == 2)
    {
        while (argv[i])
        {
            free(argv[i]);
            i++;
        }
    }
    current = *a;
    while (current)
    {
        tmp = current->next;
        free(current);
        current = tmp;
    }
    *a = NULL;
    write(2, "error\n", 6);
    exit(1);
}

static int  ft_check_repetition_and_stash(t_list **a, int nb)
{
    t_list  *new;
    t_list  *last;
    
    if (ft_check_repetition(*a, nb))
        return (1);
    new = malloc(sizeof(t_list));
    if (new == NULL)
        return (1);
    new->content = nb;
    new->next = NULL;
    if (*a == NULL)
    {
        *a = new;
        new->prev = NULL;
    }
    else
    {
        last = ft_get_last_list(*a);
        last->next = new;
        new->prev = last;
    }
    return (0);
}

static int  ft_check_repetition(t_list *a, int nb)
{
    if (a == NULL)
        return (0);
    while (a)
    {
        if (a->content == nb)
            return (1);
        a = a->next;
    }
    return (0);
}