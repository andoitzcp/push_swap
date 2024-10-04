#include "push_swap.h"

int ft_calcoptops(t_ops *ops, int act_ops, int i, int j)
{
    int v[2];
    int tmp_ops;

    v[0] = i;
    v[1] = j;
    if (i >=  0 && j >= 0)
        tmp_ops = ft_max(v, 2);
    else if (i < 0 && j < 0)
        tmp_ops = ft_abs(ft_min(v, 2));
    else
        tmp_ops = ft_abs(i) + ft_abs(j);
    if (act_ops <= tmp_ops)
        return (act_ops);
    ops->ra = i;
    ops->rb = j;
    return (tmp_ops);
}

char ft_isbetweenminmax(t_stack *stack, int i, int j)
{
    int n;
    int m;
    char c;

    n = stack->arr[i];
    m = stack->arr[j];
    c = stack->name;
    if (n == stack->max && m == stack->min && c == 'b')
        return (1);
    if (n == stack->min && m == stack->max && c == 'a')
        return (1);
    return (0);

}

char ft_ispostoinsert(t_stack *s, int n, int i, int j)
{
    if ((n < s->min || n > s->max) && ft_isbetweenminmax(s, i, j))
        return (1);
    if (n > s->min && n < s->max && !ft_isbetweenminmax(s, i, j))
    {
        if (s->name == 'a' && s->arr[j] < n && s->arr[i] > n)
            return (1);
        if (s->name == 'b' && s->arr[j] > n && s->arr[i] < n)
            return (1);
    }
    return (0);
}

int ft_convtry(t_stack *s, int n)
{
    int i;
    int j;

    i = 0;
    j = s->len - 1;
    while (i < s->len)
    {
        if (ft_ispostoinsert(s, n, i, j))
            break;
        j = i;
        i++;
    }
    if (i <= s->len - i)
        return (i);
    return (-1 * (s->len - i));
}

void ft_calcrotations(t_stack *a, t_stack *b, t_ops *ops)
{
    int i;
    int j;
    int tot_ops;

    tot_ops = INT_MAX;
    i = 0;
    while (i < a->len)
    {
        j = ft_convtry(b, a->arr[i]);
        tot_ops = ft_calcoptops(ops, tot_ops, i, j);
        tot_ops = ft_calcoptops(ops, tot_ops, i - a->len, j);
        i++;
    }
}
