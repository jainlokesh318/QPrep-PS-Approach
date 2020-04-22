#include <iostream>
#include "solution.cpp"
using namespace std;

// DON'T TOUCH THIS FILE. ASSESSMENT WILL REPLACE THIS FILE



void test_reverse_linked_list(void)
{
    // empty list test

    {
        vector<ListNode *> res = reverse_linked_list(NULL);
        assert(res[0] == NULL);
    }

    // one element test
    {
        vector<int> arr = {1};
        ListNode node;
        ListNode * head = node.createList(arr);
        // one element test
        vector<ListNode *> res = reverse_linked_list(head);
        assert(res[0] != NULL);
        assert(res[0]->val == 1);
        assert(res[0]->next == NULL);
    }

    // two element test
    {
        vector<int> arr = {1, 2};
        ListNode node;
        ListNode * head = node.createList(arr);
        // one element test
        vector<ListNode *> res = reverse_linked_list(head);
        assert(res[0] != NULL);
        assert(res[0]->val == 2);
        ListNode * second = res[0]->next;
        assert(second != NULL);
        assert(second->val == 1);
        assert(second->next == NULL);
    }
}


void test_split_list()
{
    // split empty list
    {
        vector<ListNode *> res = split_list(NULL, 1);

        assert(res[0] == NULL);
        assert(res[1] == NULL);
    }

    //split 1 element list [1, rest]
    {
        vector<int> arr = {1};
        ListNode node;
        ListNode * head = node.createList(arr);
        // one element test
        vector<ListNode *> res = split_list(head, 1);

        assert(res[0]->val == 1);
        assert(res[1] == NULL);
    }

    //split 1 element list [0, rest]
    {
        vector<int> arr = {1};
        ListNode node;
        ListNode * head = node.createList(arr);
        // one element test
        vector<ListNode *> res = split_list(head, 0);

        assert(res[0] == NULL);
        assert(res[1]->val == 1);
    }


    //split 2 element list [1, rest]
    {
        vector<int> arr = {1, 2};
        ListNode node;
        ListNode * head = node.createList(arr);
        // one element test
        vector<ListNode *> res = split_list(head, 1);

        assert(res[0]->val == 1);
        assert(res[1]->val == 2);
    }

    //split 2 element list [2, 0]
    {
        vector<int> arr = {1, 2};
        ListNode node;
        ListNode * head = node.createList(arr);
        // one element test
        vector<ListNode *> res = split_list(head, 2);

        assert(res[0]->val == 1);
        assert(res[0]->next->val == 2);
        assert(res[1] == NULL);
    }

    //split 2 element list [0, 2]
    {
        vector<int> arr = {1, 2};
        ListNode node;
        ListNode * head = node.createList(arr);
        // one element test
        vector<ListNode *> res = split_list(head, 0);

        assert(res[1]->val == 1);
        assert(res[1]->next->val == 2);
        assert(res[0] == NULL);
    }
}

void test_append_reversed_list_to_result()
{
    ListNode * result_head = NULL;
    ListNode * result_tail = NULL;

    {
        append_reversed_list_to_result(result_head, result_tail, NULL, NULL);

        assert(result_head == NULL);
        assert(result_tail == NULL);

        ListNode node;
        vector<int> arr1 = {1, 2, 3};
        ListNode * list1 = node.createList(arr1);
        append_reversed_list_to_result(result_head, result_tail, list1, list1->next->next);
        vector<int> expected_arr1 = node.extractList(result_head);
        // now the list should look like 1->2->3->NULL
        assert(expected_arr1[0] == arr1[0]);
        assert(expected_arr1[1] == arr1[1]);
        assert(expected_arr1[2] == arr1[2]);

        vector<int> arr2 = {4, 5};
        ListNode * list2 = node.createList(arr2);
        append_reversed_list_to_result(result_head, result_tail, list2, list2->next);
        vector<int> expected_arr2 = node.extractList(result_head);
        // now the list should look like 1->2->3->4->5->NULL
        assert(expected_arr1[0] == arr1[0]);
        assert(expected_arr1[1] == arr1[1]);
        assert(expected_arr1[2] == arr1[2]);
        assert(expected_arr2[3] == arr2[0]);
        assert(expected_arr2[4] == arr2[1]);

        append_reversed_list_to_result(result_head, result_tail, NULL, NULL);
    }
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    test_reverse_linked_list();
    test_split_list();
    test_append_reversed_list_to_result();

    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i)
        cin >> arr[i];

    int k;
    cin >> k;
    vector<int> nums(k);
    for (int i = 0; i < k; ++i) {
        cin >> nums[i];
    }

    ListNode node;
    ListNode * head = node.createList(arr);
    ListNode * result = performRandomReversals(head, nums);

    vector<int> res = node.extractList(result);
    cout << res.size() << "\n";
    for (size_t i = 0; i < res.size(); ++i) {
        cout << res[i] << " ";
    }
    cout << "\n";

}
