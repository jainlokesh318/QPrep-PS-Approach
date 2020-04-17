from ds.List.ListNode import ListNode

class Solution:








    def print_list(self, head):
        print("List : ", end=' ')

        while head:
            print(head.val, end= ' ')
            head = head.next

        print()

# TODO: CRIO_TASK_MODULE_LINKED_LIST_RANDOM_REVERSAL
# Input:
#      1. singly linked list
#      2. list of numbers
#
# Task:
#      for every `k` in numbers
#          reverse next k elements of the linked list (for first k start from head)
#          append the reversed list to result linked list
#
# Output:
#      Return the result list
#

    def performRandomReversal(self, head, nums):
