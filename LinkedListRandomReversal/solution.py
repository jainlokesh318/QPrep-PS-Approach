from ds.List.ListNode import ListNode

class Solution:








    def print_list(self, head):
        print("List : ", end=' ')

        while head:
            print(head.val, end= ' ')
            head = head.next

        print()


    def performRandomReversal(self, head, nums):
