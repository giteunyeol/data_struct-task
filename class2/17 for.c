// n combination r >> n! / (n-r)! * r!
// for 형으로

#include <stdio.h>

int main(void)
{
    int n, r;
    scanf("%d %d", &n, &r);
    int up = 1; // 분자
    
    //팩토리얼
    for(int i = n; i >= r; i--)
    {
        int up = up * i ;
    }

    printf("%d", &up);
    

    



    return 0;
}