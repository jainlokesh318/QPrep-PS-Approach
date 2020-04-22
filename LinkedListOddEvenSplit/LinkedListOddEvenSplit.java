import java.util.*;
import java.io.*;
import crio.ds.List.ListNode;

// DON'T TOUCH THIS FILE. ASSESSMENT WILL REPLACE THIS FILE


class LinkedListOddEvenSplit {
    private static void print_list(ListNode head) {
        List<Integer> list = ListNode.extractList(head);
        System.out.println(list.size());
        for(int x: list) {
            System.out.print(x + " ");
        }
        System.out.println();
    }
    public static void main(String[] args) {


        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int k = scanner.nextInt();
        ArrayList<Integer> list = new ArrayList<Integer>();
        for(int i = 0 ; i < n ; ++i) {
            list.add(scanner.nextInt());
        }
        scanner.close();

        ListNode head = createListWithLoop(list, k);
        ListNode[] result = new Solution().split_list_by_odd_or_even(head);

        print_list(result[0]);
        print_list(result[1]);
    }
}
