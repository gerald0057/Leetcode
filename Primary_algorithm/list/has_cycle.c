#include <stdio.h>
#include <stdbool.h>
#include "list.h"

bool hasCycle(struct ListNode *head) {
    struct ListNode *fast = head, *slow = head;
    if (head == NULL) return false;
    while (fast && fast->next)
    {
        fast = fast->next->next;
        slow = slow->next;
        if (fast == slow) return true;
    }
    return false;
}

bool hasCycle_1(struct ListNode *head) {
    while (head)
    {
        if (head->val == 10e5 + 1) return true;
        head->val = 10e5 + 1;
        head = head->next;
    }
    return false;
}
