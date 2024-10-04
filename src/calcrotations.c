#include "push_swap.h"

int ft_calctotops(int i, int j)
{
    int v[2];

    v[0] = i;
    v[1] = j;
    if (i >=  0 && j >= 0)
        return (ft_max(v, 2));
    if (i < 0 && j < 0)
        return (ft_abs(ft_min(v, 2)));
    return (ft_abs(i) + ft_abs(j));
}

int ft_minmaxcase(t_stack *b)
{
    int i;
    int j;


    i = 0;
    j = b->len - 1;
    while (b->arr[j] != b->min && b->arr[i] != b->max)
    {
        j = i;
        i++;
    }
    if (i <= b->len - i)
        return (i);
    return (-1 * (b->len - i));
}

int ft_convtry(t_stack *b, int n)
{
    int i;
    int j;

    i = 0;
    j = b->len - 1;
    if (n < b->min || n > b->max)
        return(ft_minmaxcase(b));
    while (i < b->len)
    {
        if (b->arr[i] == b->max && b->arr[j] == b->min)
        {
            j = i;
            i++;
        }
        if (n < b->arr[j] && n > b->arr[i])
            break;
        j = i;
        i++;
    }
    if (i <= b->len - i)
        return (i);
    return (-1 * (b->len - i));
}

void ft_calcrotations(t_stack *a, t_stack *b, t_ops *ops)
{
    int i;
    int j;
    int tot_ops;
    int act_ops;

    act_ops = INT_MAX;
    i = 0;
    while (i < a->len)
    {
        j = ft_convtry(b, a->arr[i]);
        tot_ops = ft_calctotops(i, j);
        if (tot_ops < act_ops)
        {
            ops->ra = i;
            ops->rb = j;
            act_ops = tot_ops;
        }
        tot_ops = ft_calctotops(i - a->len, j);
        if (tot_ops < act_ops)
        {
            ops->ra = i - a->len;
            ops->rb = j;
            act_ops = tot_ops;
        }
        i++;
    }
}
