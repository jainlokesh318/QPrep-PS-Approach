#include <algorithm>
#include "../crio/cpp/ds/ListNode/ListNode.hpp"


// TODO: CRIO_TASK_MODULE_LINKED_LIST_RANDOM_REVERSAL_WITH_BREAKDOWN
// Input:
//      Given a list head
// Task:
//      1. reverse the given list inplace
//
// return:
//      return reversed_list_head
//
// Edge Cases:
//      What do you do when there are less than k elements ?
//

vector<ListNode*> reverse_linked_list(ListNode* head)
{
    vector<ListNode*> res;

    //base case i.e if empty linked list
    if(head == NULL){
        res.push_back(head);
        return res;
    }

    ListNode* prev = NULL, *next = NULL, *curr = head;

    while(curr != NULL)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    head = prev;

    //storing the nodes in a vector
    int i = 0;
    while(head != NULL){
        res.push_back(head);
        head = head->next;
    }
    return res;
}
// TODO: CRIO_TASK_MODULE_LINKED_LIST_RANDOM_REVERSAL_WITH_BREAKDOWN
//
// Input:
//      Given a list head and k
// Task:
//      1. split that given list into two lists
//           list1  -- first k elements
//           list2  -- all elements after k
//
// return:
//      return (list1_head, list2_head)
//
//
// Edge Cases:
//      What do you do when there are less than k elements ?
vector<ListNode*> split_list(ListNode* head, int k)
{
    //to calculate no. of elements in the linked list
    ListNode* list2 = head;
    int n = 0;
    while(list2 != NULL)
    {
        list2 = list2->next;
        n++;
    }

    //first handle the base/edge cases then the generalized
    vector<ListNode*> res(2);
    if(k == 0){
        res[0] = NULL;
        res[1] = head;
    }

    else if(k >= n){
        res[0] = head;
        res[1] = NULL;
    }
    else
    {
        res[0] = head;
        for(int i = 0; i < k; i++)
            head = head->next;
        head = head->next; //to make the new list from the new element;
        res[1] = head;
    }

    return res;
}

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

// TODO: CRIO_TASK_MODULE_LINKED_LIST_RANDOM_REVERSAL_WITH_BREAKDOWN
// Input:
//      1. given pointer to result list head
//      2. given pointer to result list tail
//      3. given head and tail of list to be appended
//
// Task:
//      append the given list to the result list
//

void append_reversed_list_to_result(ListNode* &result_head, ListNode* &result_tail, ListNode* append_head, ListNode* append_tail)
{
    if(result_head == NULL && result_tail == NULL){
        result_head = append_head;
        result_tail = append_tail;
    }
    else
        result_tail = append_tail;
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
