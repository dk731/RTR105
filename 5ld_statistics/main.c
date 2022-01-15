#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_STRING_SIZE 512

char lookup[256];

int comp(const void *elem1, const void *elem2)
{
    char f = *((char *)elem1);
    char s = *((char *)elem2);
    if (f > s)
        return 1;
    if (f < s)
        return -1;
    return 0;
}

int main()
{
    memset(lookup, 0, 256);
    char in_str[MAX_STRING_SIZE];

    fgets(in_str, MAX_STRING_SIZE, stdin);

    int str_len = strlen(in_str) - 1;
    in_str[str_len] = 0;
    qsort(in_str, str_len, sizeof(char), comp);
    printf("MIN value: '%c' (%d)\n", in_str[0], in_str[0]);
    printf("MAX value: '%c' (%d)\n", in_str[str_len - 1], in_str[str_len - 1]);
    int sum = 0;
    for (int i = 0; i < str_len; i++)
    {
        sum += in_str[i];
        lookup[in_str[i]]++;
    }
    printf("Median value: '%c' (%d)\n", in_str[str_len / 2], in_str[str_len / 2]);

    int max = -1;
    char max_symb;
    for (int i = 0; i < 256; i++)
        if (lookup[i] > max)
        {
            max_symb = i;
            max = lookup[max_symb];
        }

    printf("Mode value: '%c' (%d times)\n\n", max_symb, max);
    printf("Sorted string: \"%s\"\n", in_str);
    printf("Sorted numbers: ");
    for (int i = 0; i < str_len; i++)
        printf("%d; ", in_str[i]);

    printf("\n");

    return 0;
}