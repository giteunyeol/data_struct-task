// 삭제함수
// how ? 
/*
ex) 지우고 싶은 value의 값이 3인 경우
curnode를 이용해서 헤드가 가리키는 처음 노드부터 NULL이 나올때까지 돌아준다.
돌아주며 curnode가 가리키는 value의 값이 3일때, curnode의 next(다음 노드를 가리키는 포인터)를 value의갑이 3인 노드의 다음 노드로 바꾼다.
free함수로 할당된 메모리를 지워준다.
*/

/*
void delete(int number)
{
    node *prevnode = NULL;
    node *curnode = head;
    while (curnode != NULL)
    {
        if (curnode->value == number)
        {
            if (prevnode != NULL)
            {
                prevnode->next = curnode->next; // 이전 노드의 next를 현재 노드의 다음 노드로 설정
                free(curnode); // 현재 노드를 해제
                return; // 함수 종료
            }
            else // 삭제하려는 노드가 헤드 노드일 때
            {
                head = curnode->next; // 헤드 노드를 현재 노드의 다음 노드로 설정
                free(curnode); // 현재 노드를 해제
                return; // 함수 종료
            }
        }
        prevnode = curnode;
        curnode = curnode->next;
    }
}

*/