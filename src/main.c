#include "push_swap.h"

int ft_isinteger(char *s)
{
    int i;

    i = 0;
    while (s[i] != '\0')
    {
        if (!ft_isdigit(s[i]) && s[i] != '-' && s[i] != '+')
            return (write(2, "Error\n",6), 0);
        i++;
    }
    if (ft_strncmp(INT_MAX, s, 10) < 0)
        return (write(2, "Error\n",6), 0);
    if (ft_strncmp(INT_MIN, s, 11) < 0 && *s == '-')
        return (write(2, "Error\n",6), 0);
    return(1);
}

int ft_isrepeated(char **array, char *s)
{
    int i;

    i = 0;
    while (array[i])
    {
        if (ft_strncmp(array[i], s, 11) == 0)
            return (write(2, "Error\n",6), 0);
        i++;
    }
    return (1);


}
int ft_check_argv(int argc, char **argv)
{
    int i;

    i = 1;
    while (i < argc)
    {
        if (ft_isinteger(argv[i]) == 0)
            return (0);
        if (ft_isrepeated(argv + i + 1, argv[i]) == 0)
            return (0);
        i++;
    }
    return (1);
}

t_stack *ft_buildstack(int sz, char **content)
{
    t_stack *stack;
    int i;

    stack = malloc(sizeof(t_stack));
    i = 0;
    while (content[i])
    {
        stack->arr[i] = ft_atoi(content[i]);
        i++;
    }
    return (stack);

}

int main(int argc, char **argv)
{
    t_stack *a;
    t_stack *b;

    if (argc < 2)
        return(0);
    if (ft_check_argv(argc, argv) == 0)
        return (1);
    a = ft_buildstack(argc, argv);

}
