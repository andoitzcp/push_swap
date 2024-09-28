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
	// Aqui hay que crear una funcion estilo leftpad o extender ft_printf con la
	// opcion de padding y que sea ft_sprintf
	// En caso de ser string "3" entra erroneamente el en if por que
	// strncmp("214...7", "3", 11) < 0
	/*
    if (ft_strncmp(INT_MAX, s, 10) < 0)
	{
	//ft_printf("Flag01.1: HERE\n");
      //return (write(2, "Error\n",6), 0);
	}
	ft_printf("Flag02: HERE\n");
    if (ft_strncmp(INT_MIN, s, 11) < 0 && *s == '-')
	{
      //return (write(2, "Error\n",6), 0);
	}
	*/
    return(1);
}

int ft_isrepeated(char **array, char *s)
{
    int i;

    i = 0;
	if (!array)
		return (0);
    while (array[i])
    {
        if (ft_strncmp(array[i], s, 11) == 0)
            return (write(2, "Error\n",6), 1);
        i++;
    }
    return (0);


}
int ft_check_argv(int argc, char **argv)
{
    int i;

    i = 1;
    while (i < argc)
    {
        if (ft_isinteger(argv[i]) == 0)
            return (0);
        if (ft_isrepeated(argv + i + 1, argv[i]) == 1)
            return (0);
        i++;
    }
    return (1);
}

void ft_buildstack(t_stack *stack, int sz, char **content, char name)
{
    int i;

    stack->arr = calloc(sz - 1, sizeof(int));
	if (!stack->arr)
	{
		write(2, "Error\n",6);
		exit(EXIT_FAILURE);
	}
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

static void ft_free(t_stack *stack)
{
	int *array;

	array = stack->arr;
	free(array);
}

int main(int argc, char **argv)
{
    t_stack a;
    t_stack b;

    if (argc < 2)
        return(0);
    if (ft_check_argv(argc, argv) == 0)
	{
        return (1);
	}
    ft_buildstack(&a, argc, argv, 'a');
    ft_buildstack(&b, argc, NULL, 'b');
	ft_printstack(&a);
	//ft_printstack(&a);
	//ft_swap(&a);
	//ft_printstack(&a);
	//ft_rot(&a);
	//ft_printstack(&a);
	//ft_rrot(&a);
	//ft_printstack(&a);
	//ft_push(&a, &b);
	//ft_printstack(&a);
	//ft_printstack(&b);
	ft_buildinstructions(&a, &b);
	ft_printstack(&a);
	ft_free(&a);
	free(b.arr);
}
