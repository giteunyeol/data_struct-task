#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct node
{
    element data;
    struct node* link;
} node;

void insert(node** phead, node* new_p)
{
    if (*phead == NULL)
    {
        new_p->link = NULL;
        *phead = new_p;
    }
    else
    {
        new_p->link = NULL;
        node* p = *phead;
        while (p->link != NULL)
            p = p->link;
        p->link = new_p;
    }
}

node* create_node(element data)
{
    node* new_p;
    new_p = (node*)malloc(sizeof(node));
    new_p->data = data;
    new_p->link = NULL;
    return new_p;
}

void print_list(node* head)
{
    for (node* p = head; p != NULL; p = p->link)
        printf("%d ", p->data);
}

node* alternate(node* A, node* B)
{
    node* p = A;
    node* q = B;
    node* r = NULL;

    while (p != NULL || q != NULL) {
        if (p != NULL) {
            insert(&r, create_node(p->data));
            p = p->link;
        }
        if (q != NULL) {
            insert(&r, create_node(q->data));
            q = q->link;
        }
    }
    return r;
}

int main(void)
{
    int count;
    int num;

    node* A = NULL;
    node* B = NULL;
    node* result = NULL;

    printf("리스트 A 데이터 개수: ");
    scanf("%d", &count);

    for (int i = 0; i < count; i++) 
    {
        printf("a%d 노드 데이터: ",i+1);
        scanf("%d", &num);
        insert(&A, create_node(num));
    }

    printf("리스트 B 데이터 개수: ");
    scanf("%d", &count);
    for (int i = 0; i < count; i++)
    {
        printf("b%d 노드 데이터: ",i+1);
        scanf("%d", &num);
        insert(&B, create_node(num));
    }
    
    printf("리스트 C : ");
    print_list(alternate(A, B));

    return 0;
}
