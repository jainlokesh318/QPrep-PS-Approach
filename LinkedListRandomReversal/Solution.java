import crio.ds.List.ListNode;

class Solution {



    public static void print_list(ListNode head) {
        System.out.print("List : ");
        while(head != null) {
            System.out.print(head.val + " ");
            head = head.next;
        }
        System.out.println();
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

    public ListNode performRandomReversal(ListNode head, int[] nums) {
    }
}
