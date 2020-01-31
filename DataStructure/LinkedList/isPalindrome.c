#include <stdio.h>
#include <stdbool.h>
#include "MyList.h"

void myShowList_DONOT_Have_Cycle(ListNode *head) {
    if (head == NULL)
        return;
    ListNode *cur = head;
    int param = 0;
    printf("[List obj]: ");
    while (cur)
    {
        param = cur->val;
        cur = cur->next;
        printf("%d->", param);
    }
    printf("NULL\n");
}

struct ListNode* reverseList(struct ListNode* head) {
    if (head == NULL) return NULL;
    if (head->next == NULL) return head;
    ListNode *pA = head;
    ListNode *pB = pA->next;
    ListNode *pC = pB->next;

    while (pC) {
        pB->next = pA;
        pA = pB;
        pB = pC;
        pC = pC->next;        
    }
    pB->next = pA;
    head->next = NULL;
    head = pB;

    return head;
}

bool isPalindrome(struct ListNode* head) {
    if (head == NULL)
        return true;

//double points get the middle pos (pslow)
    ListNode *pSlow = head;
    ListNode *pFast = head;
    while (pFast->next && pFast->next->next) {
        pFast = pFast->next->next;
        pSlow = pSlow->next;
    }

//reverse the latter list
    ListNode *revList = reverseList(pSlow->next);
    ListNode *Node2Join = pSlow; //save pSlow for recovery
    Node2Join->next = revList;
    // ShowList_DONOT_Have_Cycle(head);

//matching
    Node2Join = Node2Join->next;
    ListNode *pFromHead = head;
    while (Node2Join)
    {
        if (pFromHead->val != Node2Join->val)
            return false;
        pFromHead = pFromHead->next;
        Node2Join = Node2Join->next;
    }

//recovery the latter list
    revList = reverseList(pSlow->next);
    pSlow->next = revList;
    
    return true;
}

int main(void) {
    MyLinkedList *obj = myLinkedListCreate();
    ListNode *cur = NULL;

    int i = 0;
    int val[] = {1, 2, 2, 1};
    for (i = 0 ; i < sizeof(val) / sizeof(int); ++i) {
        myLinkedListAddAtTail(obj, val[i]);
    }

    printf("%s\n", isPalindrome(obj->head) ? "True" : "False");

    myShowList_DONOT_Have_Cycle(obj->head);

    return 0;
}