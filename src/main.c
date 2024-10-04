#include "push_swap.h"

void ft_buildstack(t_stack *stack, int sz, char **content, char name)
{
    int i;

    stack->arr = calloc(sz - 1, sizeof(int));
	if (!stack->arr)
        ft_returnwitherror();
	stack->name = name;
	stack->len = 0;
	stack->sz = sz - 1;
	if (!content)
		return ;
    i = 0;
    while (i < sz - 1)
    {
        stack->arr[i] = ft_atoi(content[i + 1]);
        i++;
    }
	stack->len = i;
}

char ft_isordered(t_stack *stack)
{
    int i;

    if (stack->len < 2)
        return (1);
    i = 0;
    while (i < stack->len - 1)
    {
        if (stack->arr[i] > stack->arr[i + 1])
            return (0);
        i++;
    }
    return (1);
}


int main(int argc, char **argv)
{
    t_stack a;
    t_stack b;

    if (argc < 2)
        return(0);
    if (ft_check_argv(argc, argv) == 0)
        return (1);
    ft_buildstack(&a, argc, argv, 'a');
    ft_buildstack(&b, argc, NULL, 'b');
    if (!ft_isordered(&a))
    {
        if (a.len == 2)
            ft_swap(&a);
        if (a.len == 3)
        {
            ft_rotuntilordered(&a);
            ft_order3elarray(&a);
            ft_rotuntilordered(&a);
        }
        else
            ft_buildinstructions(&a, &b);
    }
	free(a.arr);
	free(b.arr);
    return (0);
}
