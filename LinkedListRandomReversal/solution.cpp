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


void append(ListNode** head, int new_data)
{
    ListNode* new_node = new ListNode();
    ListNode* last = *head;

    new_node->val = new_data;
    new_node->next = NULL;

    if(*head == NULL){
        *head = new_node;
        return;
    }

    while(last->next != NULL)
        last = last->next;

    last->next = new_node;
    return;
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

ListNode * performRandomReversals(ListNode * head, const vector<int> & v)
{
    ListNode* new_head = new ListNode();
    ListNode* current = head;

    for(int i = 0; i < v.size(); i++)
    {
        stack<int> st;
        int x = v[i];
        while(x-- && current != NULL){
            st.push(current->val);
            current = current->next;
        }

        while(!st.empty())
        {
            append(&new_head, st.top());
            st.pop();
        }
    }

    while(current != NULL)
    {
        append(&new_head, current->val);
        current = current->next;
    }

    return new_head->next;
}

