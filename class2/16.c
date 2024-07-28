#include <stdio.h>

/*int sum(int n)
{
    if(n == 1) 
    return 1;
    else
    return (n + sum(n-1));
}*/
// 1~n까지 더하는 함수

int main(void)
{
    int n;
    scanf("%d", &n);

    int sum = 0;
    
    for(int i = 1; i <= n; i++)
    {
        sum += i;
    }

    printf("%d", sum);

    return 0;
}