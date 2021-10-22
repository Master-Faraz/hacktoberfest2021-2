#include <stdio.h>
#include <math.h>

float fun(float x) //.          For computing function
{
    return (x * x * x - 4 * x - 9);
}

void Bisection(float *x, float a, float b, int *itr)
{
    *x = (a + b) / 2;
    ++(*itr);
    printf("Iteration no .%3d \t x = %7.5f \n", *itr, *x);
}

void main()
{
    int itr = 0, max_itr;
    float x, a, b, all_error, x1; //.    all_err - how much error is allowed
    scanf("%f%f%f%d", &a, &b, &all_error, &max_itr);

    Bisection(&x1, a, b, &itr); //.  Mid point is coppied in x

    do
    {
        if (fun(a) * fun(x) < 0)
            b = x;
        else
            a = x;

        Bisection(&x1, a, b, &itr);

        if (fabs(x1 - x) < all_error)
        {
            printf("After %d iterations , root = %6.4f \n ", itr, x1);
            return 0;
        }
        x1 = x;
    } while (itr < max_itr);

    printf("No Solution \n");
    return -1;
}