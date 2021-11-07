#include <stdio.h>

void no_arg_no_return()
{
    printf("Function without arguments and return value\n");
}

void arg_no_return(int arg1, char arg2, char * arg3)
{
    printf("Function with arguments but without return value\n");
}

int no_arg_return()
{
    printf("Function without arguments but with return value\n");
    return 1;
}

int arg_return(int arg1, char arg2, char * arg3)
{
    printf("Function with arguments and return value\n");
    return 1;
}

int main()
{
    no_arg_no_return();
    arg_no_return(1, 2, NULL);
    no_arg_return();
    arg_return(1, 2, NULL);
}