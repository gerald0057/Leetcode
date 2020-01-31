#include <stdio.h>
#include "MyList.h"

struct ListNode* oddEvenList(struct ListNode* head) {
    if (head == NULL)
        return NULL;
    else if (head->next == NULL || head->next->next == NULL)
        return head;
    struct ListNode *pEventHead = head->next;
    struct ListNode *pA = pEventHead->next;
    struct ListNode *pB = pA->next; //pB could be NULL

    head->next = pA;
    pEventHead->next = pB;
    int pos = 0;
    while (pA)
    {        
        if (pB == NULL) {
            pA->next = pEventHead;
            return head;
        }
        else if (pB->next == NULL) {
            if (!pos) {
                pA->next = pEventHead;
            }
            else {
                pB->next = pEventHead;
                pA->next = NULL;
            }
            return head;
        }
        else {
            pA->next = pB->next;
            pA = pB;
            pB = pB->next;
            pos = (pos + 1) % 2;
        }
    }
    
    return head;
}

int main(void) {
    int val[] = {2, 1, 3, 5, 6, 4, 7, 8};
    MyLinkedList *obj = myLinkedListCreate();
    ListNode *cur = NULL;
    
    int i = 0;
    for (i = 0; i < (sizeof(val) / sizeof(int)); ++i) {
        myLinkedListAddAtTail(obj, val[i]);
    }

    int param = 0;
    printf("[Original linked list]: ");
    cur = obj->head;
    while (cur)
    {
        param = cur->val;
        cur = cur->next;
        printf("%d->", param);
    }
    printf("NULL\n");

    obj->head = oddEvenList(obj->head);
    param = 0;
    printf("[Current linked list]: ");
    cur = obj->head;
    while (cur)
    {
        param = cur->val;
        cur = cur->next;
        printf("%d->", param);
    }
    printf("NULL\n");


    return 0;
}