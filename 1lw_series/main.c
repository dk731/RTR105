#include <stdio.h>
#include <math.h>

const char *TAILOR_EXP = "\
                %d                       \n\
               _____                     \n\
              \\           k     2*k+1   \n\
               \\      (-1)  *  x        \n\
sin(%.2f/2) = >     ____________________ \n\
               /                 2*k+1   \n\
              /____  (2*k+1)! * 2        \n\
               k=%d                      \n\
";

const char *RECURRENCE_EXP = "\
                                         2    \n\
                               (-1)  *  x     \n\
Rekurences reizinajums:    ___________________\n\
                                              \n\
                                k*(2*k+1)     \n\
";

float factorial(int val)
{
    float res = 1.0f;
    for (int i = 2; i <= val; i++)
        res *= i;
    return res;
}

float taylor_exp(float x, int k)
{
    return (pow(-1, k) * pow(x, 2 * k + 1)) / (factorial(2 * k + 1) * pow(2, 2 * k + 1));
}

int main()
{
    float x;

    printf("y(x) = sin(x / 2) calculation: \nPlease enter x value: ");
    scanf("%f", &x);

    printf("sin(%.2f / 2) = %.2f\n", x, sin(x / 2));

    float s = taylor_exp(x, 0);

    printf("a0    = %.2f    S0    = %.2f\n", s, s);

    for (int i = 1; i < 1000; i++)
        s += taylor_exp(x, i);

    // taylor_exp(1, 999)  = -1.050553356E-6334
    // taylor_exp(1, 1000) =  6.562677134E-6342

    printf("a999  = %.2f   S999  = %.2f\n", taylor_exp(x, 999), s);
    s += taylor_exp(x, 1000);
    printf("a1000 = %.2f   S1000 = %.2f\n", taylor_exp(x, 1000), s);

    printf("sin(%.2f / 2) caur summu = %.2f\n", x, s);

    printf(TAILOR_EXP, 0, x, 1000);
    printf("\n\n");
    printf(RECURRENCE_EXP);
    return 0;
}