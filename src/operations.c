#include "push_swap.h"

void ft_swap(t_stack *stack)
{
    int tmp;

    if (stack->len < 2)
        return;
    tmp = stack->arr[0];
    stack->arr[0] = stack->arr[1];
    stack->arr[1] = tmp;
    printf("s%c\n", stack->name);
}

void ft_push(t_stack *src, t_stack *dst)
{
    int i;

    if (src->len == 0)
        return;
    i = dst->len;
    while (i > 0)
    {
        dst->arr[i] = dst->arr[i - 1];
        i--;
    }
    dst->arr[0] = src->arr[0];
    dst->len += 1;
    src->len -= 1;
    while (i < src->len)
    {
        src->arr[i] = src->arr[i + 1];
        i++;
    }
    printf("p%c\n", dst->name);
}

void ft_rot(t_stack *stack, char print)
{
    int tmp;
    int i;

    tmp = stack->arr[0];
    i = 0;
    while (i < stack->len - 1)
    {
        stack->arr[i] = stack->arr[i + 1];
        i++;
    }
    stack->arr[i] = tmp;
    if (print != 0)
        printf("r%c\n", stack->name);
}

void ft_rrot(t_stack *stack, char print)
{
    int tmp;
    int i;

    tmp = stack->arr[stack->len - 1];
    i = stack->len - 1;
    while (i > 0)
    {
        stack->arr[i] = stack->arr[i - 1];
        i--;
    }
    stack->arr[i] = tmp;
    if (print != 0)
        printf("rr%c\n", stack->name);
}

void ft_rotboth(t_stack *a, t_stack *b, char direction)
{
    if (direction == 'f')
    {
        ft_rot(a, 0);
        ft_rot(b, 0);
        printf("rr\n");
    }
    if (direction == 'r')
    {
        ft_rrot(a, 0);
        ft_rrot(b, 0);
        printf("rrr\n");
    }
}
