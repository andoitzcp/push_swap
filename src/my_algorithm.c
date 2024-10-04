#include "push_swap.h"

void ft_ordersmallarray(t_stack *a, t_stack *b)
{
    int i;

    i = 0;
    a->max = ft_min(b->arr, b->len);
    while (a->len > 3)
    {
        i++;

    }

}

void ft_buildinstructions(t_stack *a, t_stack *b)
{
    int i;
    t_ops ops;

    i = 3;
    while (i-- > 0)
        ft_push(a, b);
    b->min = ft_min(b->arr, b->len);
    b->max = ft_max(b->arr, b->len);
    while (b->arr[0] != b->max)
        ft_rot(b, 1);
    if (b->arr[0] < b->arr[1] || b->arr[1] < b->arr[2])
        ft_swap(b);
    while (a->len > 0)
    {
        ft_calcrotations(a, b, &ops);
        ft_doops(a, b, &ops);
        b->min = ft_min(b->arr, b->len);
        b->max = ft_max(b->arr, b->len);
    }
    while (b->arr[0] != b->max)
        ft_rot(b, 1);
    while (b->len > 0)
        ft_push(b, a);
}
