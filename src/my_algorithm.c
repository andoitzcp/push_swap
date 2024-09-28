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
