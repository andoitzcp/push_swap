#include "push_swap.h"

void ft_printstack(t_stack *stack)
{
    int i;

    ft_printf("Stack %c [%d/%d]: %p\n", stack->name, stack->len, stack->sz, stack);
    ft_printf("Array: [");
    i = 0;
    while (i < (stack->len - 1))
    {
        ft_printf("%d,", stack->arr[i]);
        i++;
    }
    if (stack->len > 0)
        ft_printf("%d", stack->arr[i]);
    ft_printf("]\n");
}