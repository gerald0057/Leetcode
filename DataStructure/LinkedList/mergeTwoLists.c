#include <stdio.h>
#include "MyList.h"

struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {
    if (l1 == NULL) return l2;
    if (l2 == NULL) return l1;

    ListNode *mergeHead = NULL;
    if (l1->val >= l2->val) {
        mergeHead = l2;
        mergeHead->next = mergeTwoLists(l1, l2->next);
    }
    if (l1->val < l2->val) {
        mergeHead = l1;
        mergeHead->next = mergeTwoLists(l1->next, l2);
    }
    return mergeHead;
}

int main(void) {
    int val_l1[] = {1, 2, 3};
    int val_l2[] = {1, 3, 4};
    MyLinkedList *obj_1 = myLinkedListCreate();
    MyLinkedList *obj_2 = myLinkedListCreate();

    int i = 0;
    for (i = 0; i < sizeof(val_l1) / sizeof(int); ++i)
        myLinkedListAddAtTail(obj_1, val_l1[i]);        
    for (i = 0; i < sizeof(val_l2) / sizeof(int); ++i)
        myLinkedListAddAtTail(obj_2, val_l2[i]);

    ShowList_DONOT_Have_Cycle(obj_1->head, "obj_1");
    ShowList_DONOT_Have_Cycle(obj_2->head, "obj_2");

    ListNode *mergedList = mergeTwoLists(obj_1->head, obj_2->head);
    ShowList_DONOT_Have_Cycle(mergedList, "mergedList");

    return 0;
}