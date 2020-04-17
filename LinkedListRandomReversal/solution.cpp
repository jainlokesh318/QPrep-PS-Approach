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





// TODO: CRIO_TASK_MODULE_LINKED_LIST_RANDOM_REVERSAL
// Input:
//      1. singly linked list
//      2. list of numbers
//
// Task:
//      for every `k` in numbers
//          reverse next k elements of the linked list (for first k start from head)
//          append the reversed list to result linked list
//
// Output:
//      Return the result list
//

ListNode * performRandomReversals(ListNode * head, const vector<int> & numbers)
{
}

