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
    float l, r;
    float val;
    float prec;
    float tmp;

    printf("Please enter left and right border of search area: ");
    scanf("%f %f", &l, &r);

    printf("Enter search value: ");
    scanf("%f", &val);

    printf("Enter serach precision: ");
    scanf("%f", &prec);

    float eps = prec / 100.0f;

    float res_x = l;
    float res_val = my_func(l);

    while (l < r)
    {
        tmp = my_func(l);
        if (fabs(tmp - val) <= fabs(val - res_val))
        {
            res_val = tmp;
            res_x = l;
        }

        l += prec;
    }
    printf("\n");

    printf("Closes value found: %.2f at %.2f\nError: %.2f\n", res_val, res_x, fabs(val - res_val));

    return 0;
}