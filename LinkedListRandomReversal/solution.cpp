#include <algorithm>
#include "../crio/cpp/ds/ListNode/ListNode.hpp"






/*
 * function useful for debugging
 */

void print_list(ListNode * head)
{
    printf("List : ");

    while (head) {
        printf("%d->", head->val);
        head = head->next;
    }
    printf("null\n");
}






ListNode * performRandomReversals(ListNode * head, const vector<int> & numbers)
{
}

