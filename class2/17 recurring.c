//이항계수 n! / (n-r)! * r!
//n퍼미테이션r을 r!으로 나눈것
// ex 5 combination 
#include <stdio.h>

int combination(int n, int r)
{
    if(r == 1)
    {
        return r;
    }
    else
    {
        return (n * combination(n - 1))
    }

}

int main(void)
{
    int a, b;
    scanf("%d %d", &a, &b);

    int result = combination (a, b);

    printf("%d", result);

    return 0;
}