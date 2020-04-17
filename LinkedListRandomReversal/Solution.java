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



    public ListNode performRandomReversal(ListNode head, int[] nums) {
    }
}
