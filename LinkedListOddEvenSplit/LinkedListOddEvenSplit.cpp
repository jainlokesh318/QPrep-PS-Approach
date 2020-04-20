#include <iostream>
#include <cassert>
#include "solution.cpp"
using namespace std;

// DON'T TOUCH THIS FILE. ASSESSMENT WILL REPLACE THIS FILE



int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);


    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i)
        cin >> arr[i];

    ListNode node;
    ListNode * head = node.createListWithLoop(arr, k);
    vector<ListNode *> result = split_list_by_odd_or_even(head);

    printlist(result[0]);
    printlist(result[1]);
}
