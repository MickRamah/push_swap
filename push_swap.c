/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zramahaz <zramahaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 11:00:41 by zramahaz          #+#    #+#             */
/*   Updated: 2024/05/08 16:30:54 by zramahaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void    sa(t_list *a);

void    push_swap(int argc, char **argv)
{
    t_list  *a;
    t_list  *b;
    t_list  *current;
    int     i = 0;

    a = NULL;
    b = NULL;
    if (argc == 1 || (argc == 2 && argv[1][0] == '\0'))
        exit(1);
    if (argc == 2)
        argv = ft_split(argv[1], ' '); // deja reglE (malloc et free)
    else
        argv = argv + 1;
    ft_test_and_stash(argc, &a, argv); // malloc a
    // while (a)
    // {
    //     printf("a->prev =      %p\n", a->prev);
    //     printf("a(addresse) =  %p\n", a);
    //     printf("a->content =  |%d|\n", a->content);
    //     printf("a->next =      %p\n", a->next);
    //     printf("------------------------------------------------\n");
    //     a = a->next;
    // }

    //ra mbola tsy trie ilay liste
    if (!stash_sorted(a))
    {
        // current = a;
        // while (current)
        // {
        //     printf("%d\n", current->content);
        //     current = current->next;
        // }
        // printf("a |\n");
        //  printf("------------------------------\n");
        if (ft_stash_len(a) == 2)
            sa(a);
    }
    else
        printf("triE\n");
    while (a)
        {
            printf("%d\n", a->content);
            a = a->next;
        }
        printf("a |\n");
        printf("------------------------------\n");
}

void ft_test_and_stash(int argc, t_list **a, char **argv)
{
    int     i;
    long    nb;

    i = 0;
    while (argv[i])
    {
        if (ft_error(argv[i]))
            ft_free_and_exit(a, argv, argc); // en cas d'erreur, free a argv
        nb = ft_atoi(argv[i]);
        if (ft_stash_and_check_repetition(a, nb)) // malloc a
            ft_free_and_exit(a, argv, argc); // en cas d'erreur, free a argv
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
    }
}

static void    sa(t_list *a)
{
    int tmp;

    tmp = a->content;
    a->content = a->next->content;
    a->next->content = tmp;
    write(1, "sa\n", 3);
    printf("---------------------------------\n");
}

static void    sb(t_list *a)
{
    int tmp;

    tmp = b->content;
    b->content = b->next->content;
    b->next->content = tmp;
    write(1, "sb\n", 3);
    printf("---------------------------------\n");
}