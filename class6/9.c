#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int value;
    struct node * next;
}node;

node * head = NULL;

void makenode(int i) // node 생성 함수
{
    node * newnode;
    node * curnode;
    newnode = (node*)malloc(sizeof(node));
    printf("노드 #%d의 데이터 : " , i);
    scanf("%d", &(newnode->value));
    newnode -> next = NULL;

    if(head == NULL)
    {
        head = newnode;
        return;
    }
    curnode = head;
    while(curnode ->next != NULL)
    {
        curnode = curnode->next; 
    }
    curnode->next = newnode;
}

void display()
{
    node * curnode;
    curnode = head;
    while(curnode -> next != NULL)
    {
        printf("%d->", curnode->value);
        curnode = curnode->next;
    }
    printf("%d", curnode->value);
}

void free_memory() //메모리 릭 방지
{
    node *curnode = head;
    node *nextnode;
    while (curnode != NULL)
    {
        nextnode = curnode->next;
        free(curnode);
        curnode = nextnode;
    }
}

int main(void)
{
    printf("노드의 개수 : ");
    int n;
    scanf("%d", &n);

    for(int i = 1; i <= n; i++)
    {
        makenode(i);

        if(i == n)
        {
            display();
        }
    }
    free_memory();
    
    return 0; 
}