#include <stdio.h>
#include <string.h>

#define maxsize 100

typedef struct stack // value값과 top을 가지고 있는 stack형태 선언
{
    int value[maxsize];
    int top;

}stack;

void creatstack(stack * p) // top의 기본값을 -1로 선언(print할때 top보다 +1로)
{
    p -> top = -1;
}
void push(stack * p) // stack에서 push함수 구현, top을++ 해주고 value값을 올려야함
{
    p->value[++(p->top)] = p->top; // parenthesis의 value에 top과 같은 값 대입
    printf("%d", p->value[p->top+1]);
}
void simillarpop(stack * p)  // 우괄호가 들어왔을때 제일 위의 value를 pop하고 반환
{
    for(int i = p->top +1; i >= 0; i--)
    {
        if(p->value[i] != -1)
        {
            printf("%d", p->value[i]);
            p->value[i] = -1;
            break;
        }
    }
}
int main(void)
{
    stack parenthesis; // stack형태를 가지고 있는 parenthesis 선언
    creatstack(&parenthesis);
    char string[100];
    scanf("%s", string); // string이라는 문자열에 괄호를 입력받음
    for(int i = 0; i < strlen(string) ; i++) // 입력받은 문자열에 0부터 끝까지 검사
    {
        //좌괄호랑 우괄호인 case로 구분해서 할당
        if(string[i] == '(') // 좌괄호(push)
        {
            push(&parenthesis); // 함수에서 print
        }
        else if(string[i] == ')') // 우괄호(pop?)
        {
            simillarpop(&parenthesis);
        }
    }


    return 0;
}


