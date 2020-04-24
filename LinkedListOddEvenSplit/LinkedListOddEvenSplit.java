import java.util.*;
import java.io.*;
import crio.ds.List.ListNode;

// DON'T TOUCH THIS FILE. ASSESSMENT WILL REPLACE THIS FILE


class LinkedListOddEvenSplit {

    private static ListNode createListWithLoop(List<Integer> numbers, int k) {
        if(k == -1) {
            return ListNode.createList(numbers);
        }
        ListNode head = new ListNode(numbers.get(0));
        ListNode current = head;
        ListNode kth_node = null;

        --k;
        if(k == 0) {
            kth_node = current;
        }
        for(int i = 1 ; i < numbers.size() ; ++i) {
            current.next = new ListNode(numbers.get(i));
            current = current.next;
            --k;
            if(k == 0) {
                kth_node = current;
            }
        }
        current.next = kth_node;
        return head;
    }
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
