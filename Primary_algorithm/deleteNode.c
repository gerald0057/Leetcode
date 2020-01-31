#include <stdio.h>
#include <stdlib.h>
#include "..\Data_Structure\MyList.h"

void deleteNode(struct ListNode* node) {
    node->val = node->next->val;
    struct ListNode *pDel = node->next;
    node->next = node->next->next;
    free(pDel);
    pDel = NULL;
}

int main(void) {
    MyLinkedList *obj = myLinkedListCreatRandomList(5);
    ShowList_DONOT_Have_Cycle(obj->head, "Original");
    ListNode *cur = obj->head->next->next;
    deleteNode(cur);
    ShowList_DONOT_Have_Cycle(obj->head, "Current");

    return 0;
}