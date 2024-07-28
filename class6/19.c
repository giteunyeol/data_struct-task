/*
void split(node* head, node** A, node** B)
{
    node* current = head;
    int count = 1;

    *A = NULL;
    *B = NULL;

    while (current != NULL) {
        node* new_node = create_node(current->data); // 새로운 노드 생성

        if (count % 2 == 1) {
            
            insert(A, new_node);
        } else {
          
            insert(B, new_node);
        }

        // 리스트 C에 직접 노드 추가
        insert(&head, new_node);

        current = current->link; 
        count++;
    }
}
*/