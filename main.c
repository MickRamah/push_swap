#include "push_swap.h"

static void ft_free_stash(t_list **stack);

void    affichage(t_list **stack)
{
    t_list *current;
    t_list *last;

    current = *stack;
    last = ft_get_last_list(*stack);
    printf("-----------------------------------------\n");
    printf("tete  :");
    while (current)
    {
        printf("%d -> ", current->value);
        current = current->next;
    }
    printf("%p", current);
    printf("\n");
    printf("queue :");
    while (last)
    {
        printf("%d -> ", last->value);
        last = last->prev;
    }
    printf("%p", last);
    printf("\n");
    printf("-----------------------------------------\n");

}

int main(int argc, char **argv)
{
    t_list  *a;
    t_list  *b;

    a = NULL;
    b = NULL;
    if (argc == 1 || (argc == 2 && argv[1][0] == '\0'))
    {
        write(2, "error\n", 6);
        return (1);
    }
    if (argc == 2)
        argv = ft_split(argv[1], ' ');
    else
        argv = argv + 1;
    stack_init(argc, argv, &a);
    if (!stack_sorted(a))
    {
        if (stack_len(a) == 2)
            sa(a, 1);
        else if (stack_len(a) == 3)
            tiny_sort(&a);
        else
            push_swap(&a, &b);
    }
    affichage(&a);
    ft_free_stash(&a);
    return (0);
}

static void ft_free_stash(t_list **stack)
{
    t_list  *current;
    t_list  *tmp;

    current = *stack;
    while (current)
    {
        tmp = current->next;
        free(current);
        current = tmp;
    }
    *stack = NULL;
}