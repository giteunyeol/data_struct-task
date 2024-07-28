/*
int poly_eval(ListType* plist, int x)
{
    ListNode* p = plist->head;
    int eval = 0;
    
    for (; p; p = p->link)
    {
        int result = 1;
        for (int i = 0; i < p->expon; i++) // 지수번만큼 x를 곱하기
        {
            result *= x;
        }
        result *= p->coef; // 계수 곱하기
        eval += result; 
    }
    return eval;
}
*/