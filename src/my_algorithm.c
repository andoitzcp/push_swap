#include "push_swap.h"

//int ft_calcrotations(t_stack *b, int n)
//{
    //int i;
    //int k;
   //
    //i = 0;
    //k = b->len - 1;
    //if (n < b->min || n > b->max)
    //{
        //while (b->arr[i] != b->max)
        //{
            //i++;
        //}
        //if (n < b->min)
            //b->min = n;
        //else
            //b->max = n;
    //}
    //else
    //{
        //while (n < b->arr[i] || n > b->arr[k])
        //{
            //k = i;
            //i++;
        //}
        //// aqui se podria meter n > b->arr[(b-len - 1 + i) % b->len] mirar despues a
        //// ver si merece la pena
    //}
    //if (i <= b->len - i)
        //return (i);
    //return (-1 * (b->len - i));
//}

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

int ft_convtry(t_stack *a, t_stack *b, int i)
{
    int j;
    int k;

    j = 0;
    k = b->len - 1;
    if (a->arr[i] < b->min || a->arr[i] > b->max)
    {
        while (b->arr[j] != b->max)
            j++;
        if (a->arr[i] < b->min)
            b->min = a->arr[i];
        else
            b->max = a->arr[i];
    }
    else
    {
        while (a->arr[i] < b->arr[j] || a->arr[i] > b->arr[k])
        {
            k = j;
            j++;
        }
    }
    if (j <= b->len - j)
        return (j);
    return (-1 * (b->len - j));
}

int ft_calcrotations(t_stack *a, t_stack *b, t_ops *ops)
{
    //iterar i e ir guardando en *ops las instrucciones si son mas pequeñas que
    //la anterior

    int i;
    int j;
    int tot_ops;
    int act_ops;

    act_ops = INT_MAX;
    i = 0;
    while (i < a->len)
    {
        j = ft_convtry(a, b, i);
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


void ft_buildinstructions(t_stack *a, t_stack *b)
{
    int i;

    i = 3;
    while (i-- > 0)
        ft_push(a, b);
    b->min = ft_min(b->arr, b->len);
    b->max = ft_max(b->arr, b->len);
    while (a->len > 0)
    {
        i = ft_calcrotations(b, a->arr[0]);
        while (i > 0)
        {
            ft_rot(b);
            i--;
        }
        while (i++ < 0)
            ft_rrot(b);
        ft_push(a, b);
    }
    i = ft_calcrotations(b, b->max + 1);
    while (i-- > 0)
        ft_rot(b);
    i += 1;
    while (i++ < 0)
        ft_rrot(b);
    while (b->len > 0)
        ft_push(b, a);
}
