import java.io.*;
import java.util.*;
import crio.ds.List.ListNode;

// DON'T TOUCH THIS FILE. ASSESSMENT WILL REPLACE THIS FILE


class LinkedListRandomReversal {

    public static void main(String[] args) {


        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        ArrayList<Integer> list = new ArrayList<Integer>();
        for(int i = 0 ; i < n ; ++i) {
            list.add(scanner.nextInt());
        }
        int k = scanner.nextInt();
        int[] nums = new int[k];
        for(int i = 0 ; i < k ; ++i) {
            nums[i] = scanner.nextInt();
        }
        scanner.close();

        ListNode head = ListNode.createList(list);
        ListNode result = new Solution().performRandomReversal(head, nums);

        List<Integer> resultList = ListNode.extractList(result);
        System.out.println(resultList.size());
        for(int x: resultList) {
            System.out.print(x + " ");
        }
        System.out.println();
    }
}
