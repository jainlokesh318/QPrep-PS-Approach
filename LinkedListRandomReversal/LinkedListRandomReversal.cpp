#include <iostream>
#include "solution.cpp"
using namespace std;



int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);


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
