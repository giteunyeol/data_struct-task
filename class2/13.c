// 1부터 n까지 더하는 순환 프로그램
#include <stdio.h>

int add(int n) // i = 1 부터 , n까지 더하는 함수를 짜야함
{
    if(n == 1)
    {
        return 1;
    }
    else
    {
        return n + add(n-1);
    }
}

int main(void)
{
    int n;
    scanf("%d", &n);
    int result = add(n);

    printf("%d", result);

    return 0;
}