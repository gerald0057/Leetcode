#include <stdio.h>
#include <stdlib.h>
#include "MyList.h"

struct ListNode* removeElements(struct ListNode* head, int val) {
    if (head == NULL)
        return NULL;
    
    ListNode *pDel = NULL;
    while (head)
    {
        if (head->val == val) {
            pDel = head;
            head = head->next;
            free(pDel);
            pDel = NULL;
        }
        else
            break;
    }
    if (head == NULL)
        return NULL;
    
    ListNode *pA = head;
    ListNode *pB = pA->next;
    while (pB)
    {
        if (pB->val == val) {
            pDel = pB;
            pB = pB->next;
            pA->next = pB;
            free(pDel);
            pDel = NULL;
        }
        if (pB && (pB->val != val)) {
            pA = pB;
            pB = pB->next;
        }        
    }
    
    return head;
}

int main(void) {
    int val[] = {1, 2, 2, 1};
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

    obj->head = removeElements(obj->head, 2);

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