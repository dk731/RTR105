#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define VAL_DEF_SIZE 16

char type;

char add_fact(void *val, int i)
{
    char cmp_res;

    if (type == 'c')
    {
        char val_before = *((char *)val);
        *((char *)val) *= i;
        cmp_res = *((char *)val) > val_before;
    }
    else if (type == 'i')
    {
        int val_before = *((int *)val);
        *((int *)val) *= i;
        cmp_res = *((int *)val) > val_before;
    }
    else
    {
        long long val_before = *((long long *)val);
        *((long long *)val) *= i;
        cmp_res = *((long long *)val) > val_before;
    }
    
    return cmp_res;
}

int main()
{
    int d;
    printf("Please eneter number: ");
    scanf(" %d", &d);

    printf("Select data type(c - char, i - int, l - long): ");
    scanf(" %c", &type);

    if (type != 'c' && type != 'i' && type != 'l')
    {
        printf("Invalid data type!\n");
        return 1;
    }

    char my_val[VAL_DEF_SIZE];
    memset(my_val, 0, VAL_DEF_SIZE);
    my_val[0] = 1;
    int i = 2;
    char last_res;

    while (i <= d && (last_res = add_fact(my_val, i++)))
        ;
    
    if ((i != d + 1 && d > 0) || !last_res)
    {
        printf("Choosen data type too small!\n");
        return 1;
    }

    switch (type)
    {
        case 'c':
            printf("Res: %d\n", *((char *)my_val));
            break;
        case 'i':
            printf("Res: %d\n", *((int *)my_val));
            break;
        case 'l':
            printf("Res: %lld\n", *((long long *)my_val));
            break;
    }

    return 0;
}