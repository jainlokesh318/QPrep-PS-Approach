#include <algorithm>
#include "../crio/cpp/ds/ListNode/ListNode.hpp"

// TODO: CRIO_TASK_MODULE_LINKED_LIST_ODD_EVEN_SPLIT
// Input:
//      1. given linked list head pointer
//      2. node where loop starts
//
// Task:
//      break the loop
// TODO: CRIO_TASK_MODULE_LINKED_LIST_ODD_EVEN_SPLIT
// Input:
//      head of a singly linked list
// Task:
//      1. slow runner traverse the linked list one node at a time
//      2. fast runner traverse the linked list two node at a time
//      3. If slow runner and fast runner meet at some node then return that node
//      4. Else return null(they don't meet and linked list ends).
// Output:
//      return the node they both meet. null if the list has is null terminated
            //printf("step count = %d, slow ->data = %d\n", step_count, slow->val);
// TODO: CRIO_TASK_MODULE_LINKED_LIST_ODD_EVEN_SPLIT
// Input:
//      1. given pointer to result list head
//      2. given pointer to result list tail
//      3. given head and tail of list to be appended
//
// Task:
//      append the given list to the result list
//
// TODO: CRIO_TASK_MODULE_LINKED_LIST_ODD_EVEN_SPLIT
// Input:
//      1. given node in a the linked list
//      2. node position in given linked list(1 based indexing)
// Task:
//      split the elements in odd position and even position into two seperate list
//  Output:
//      1. head of linked list of all nodes in odd positions
//      2. head of linked list of all nodes in even positions

void printlist(ListNode * head)
{
    ListNode node;
    vector<int> res = node.extractList(head);

    cout << res.size() << "\n";
    for (size_t i = 0; i < res.size(); ++i) {
        cout << res[i] << " ";
    }
    cout << "\n";
}

// TODO: CRIO_TASK_MODULE_LINKED_LIST_ODD_EVEN_SPLIT
// Input:
//      1. head of linked list
// Task:
//      1. if linked list has no loop just split odd position and even position elements
//      2. if linked list has loop then return all odd position elements in the loop
//          and even positions elements in the loop
//  Output:
//      1. head of linked list of all nodes in odd positions
//      2. head of linked list of all nodes in even positions

vector<ListNode*> solve_without_loop(ListNode* head)
{
    vector<ListNode*> res(2);
    ListNode *temp = head, *even = NULL, *odd = NULL;
    ListNode* evenHead = NULL, *oddHead = NULL;
    int i = 1;

    while(temp != NULL)
    {
        if(i%2 == 0)
        {
            if(even == NULL){
                evenHead = temp;
                even = temp;
            }
            else
            {
                even->next = temp;
                even = temp;
            }
        }

        else
        {
            if(odd == NULL){
                odd = temp;
                oddHead = temp;
            }
            else
            {
                odd->next = temp;
                odd = temp;
            }
        }

        temp = temp->next;
        i++;
    }
    even->next = NULL;
    odd->next = NULL;

    res[0] = oddHead;
    res[1] = evenHead;

    return res;
}

vector<ListNode*> without_loop(ListNode *head)
{
    vector<ListNode*> res(2);
    if(head == NULL)
    {
        res[0] = NULL;
        res[1] = NULL;
        return res;
    }

    if(head->next == NULL)
    {
        res[0] = head;
        res[1] = NULL;
        return res;
    }

    res = solve_without_loop(head);
    return res;
}

vector<ListNode*> loop(ListNode *head, int loop_index)
{
    vector<ListNode*> res(2);
    res[0] = NULL;
    res[1] = NULL;

    ListNode *start = head, *temp;
    ListNode *even = NULL, *odd = NULL;
    ListNode* evenHead = NULL, *oddHead = NULL;

    int z = loop_index-1, chk = 0;

    while(z--)
        start = start->next;
    temp = start;

    z = loop_index-1;
    //cout << "The loop contains :- ";
    while(temp != start || chk == 0)
    {
        if(temp == start) chk = 1;

        if(z%2 == 1)
        {
            if(even == NULL){
                evenHead = temp;
                even = temp;
            }
            else
            {
                even->next = temp;
                even = temp;
            }
        }

        else
        {
            if(odd == NULL){
                odd = temp;
                oddHead = temp;
            }
            else
            {
                odd->next = temp;
                odd = temp;
            }
        }
        z++;
        temp = temp->next;
    }
    even->next = NULL;
    odd->next = NULL;

    res[0] = oddHead;
    res[1] = evenHead;

    return res;
}

vector<ListNode *> split_list_by_odd_or_even(ListNode * head, int loop_index)
{
    vector<ListNode*> res;
    if(loop_index == -1)
        res = without_loop(head);
    else
        res = loop(head, loop_index);
    return res;
}