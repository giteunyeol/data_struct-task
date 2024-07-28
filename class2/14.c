//입력 : n, 1 + 1/2 + ... 1/n >> float형으로받음

#include <stdio.h>

float half(float n)
{
    if(n == 1)
    {
        return 1.0;
    }
    else
    {
        return 1.0 / n + half(n-1);
    }
}

int main(void)
{
    float n;
    scanf("%f", &n);

    float result = half(n);
    printf("%f", result);

    return 0;
}