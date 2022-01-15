#include <stdio.h>
#include <math.h>
#define M_PI 3.14159265358979323846
#define MAX_INTER_COUNT 128

float my_func(float x)
{
    return sin(x / 2);
}

int main()
{
    float l, r, c;
    float val;
    float prec;
    float tmp;
    int i;

    printf("Please enter left and right border of search area: ");
    scanf("%f %f", &l, &r);

    printf("Enter search value: ");
    scanf("%f", &val);

    printf("Enter serach precision: ");
    scanf("%f", &prec);

    float eps = prec / 100.0f;

    for (i = 0; i < MAX_INTER_COUNT; i++)
    {
        c = (l + r) / 2.0f;
        tmp = my_func(c);
        if (fabs(tmp - val) <= prec)
            break;

        if (tmp > val)
            r = c + eps;
        else
            l = c - eps;
    }
    printf("\n");
    if (i < MAX_INTER_COUNT)
        printf("Values with given precision was found at: %.4f\nItterations before result: %d\nFound value: %.4f\nGiven value: %.4f\nError: %.4f\n", c, i + 1, tmp, val, fabs(tmp - val));
    else
        printf("Given values was not found with given precision\n");

    return 0;
}