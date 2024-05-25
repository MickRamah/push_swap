#include "push_swap.h"

static int  syntax_error(char *argv_i);
static void ft_free_and_exit(int argc, char **argv, t_list **stack);
static int  check_repetition(t_list *a, int nb);
static void append_node(t_list **a, int nb);

void    stack_init(int argc, char **argv, t_list **a)
{
    int     i;
    int    nb;

    i = 0;
    nb = 0;
    while (argv[i])
    {
        if (syntax_error(argv[i]))
            ft_free_and_exit(argc, argv, a);
        nb = ft_atoi(argv[i]);
        if (check_repetition(*a, nb))
            ft_free_and_exit(argc, argv, a);
        append_node(a, nb);
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

static int  syntax_error(char *argv_i)
{
    int	j;

	j = 0;
	if (!(argv_i[j] == '+' || argv_i[j] == '-'
			|| (argv_i[j] >= '0' && argv_i[j] <= '9')))
		return (1);
	if (argv_i[j] == '+' || argv_i[j] == '-')
		j++;
	while ((argv_i[j] >= '0' && argv_i[j] <= '9') && argv_i[j])
		j++;
	if ((argv_i[j - 1] == '+' || argv_i[j - 1] == '-') && !argv_i[j])
		return (1);
	if (!argv_i[j])
		return (0);
	return (1);
}

static void ft_free_and_exit(int argc, char **argv, t_list **stack)
{
    t_list	*current;
	t_list	*tmp;
	int		i;

	i = 0;
	current = *stack;
	if (argc == 2)
	{
		while (argv[i])
		{
			free(argv[i]);
			i++;
		}
		free(argv);
	}
	while (current)
	{
		tmp = current->next;
		free(current);
		current = tmp;
	}
	*stack = NULL;
	write(2, "error\n", 6);
	exit(1);
}

static int  check_repetition(t_list *a, int nb)
{
    if (a == NULL)
        return (0);
    while (a)
	{
		if (a->value == nb)
			return (1);
		a = a->next;
	}
	return (0);
}

static void append_node(t_list **a, int nb)
{
    t_list	*new;
	t_list	*last;

    new = malloc(sizeof(t_list));
	if (new == NULL)
		exit(1);
	new->value = nb;
	new->next = NULL;
	if (*a == NULL)
	{
		*a = new;
		new->prev = NULL;
        return ;
    }
	last = ft_get_last_list(*a);
	last->next = new;
	new->prev = last;
}