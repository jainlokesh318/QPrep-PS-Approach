from ds.List.ListNode import ListNode

class Solution:

# TODO: CRIO_TASK_MODULE_LINKED_LIST_RANDOM_REVERSAL_WITH_BREAKDOWN
# Input:
#      Given a list head
# Task:
#      1. reverse the given list inplace
#
# return:
#      return reversed_list_head
#
# Edge Cases:
#      What do you do when there are less than k elements ?
#

# TODO: CRIO_TASK_MODULE_LINKED_LIST_RANDOM_REVERSAL_WITH_BREAKDOWN
#
# Input:
#      Given a list head and k
# Task:
#      1. split that given list into two lists
#           list1  -- first k elements
#           list2  -- all elements after k
#
# return:
#      return (list1_head, list2_head)
#
#
# Edge Cases:
#      What do you do when there are less than k elements ?




# TODO: CRIO_TASK_MODULE_LINKED_LIST_RANDOM_REVERSAL_WITH_BREAKDOWN
# Input:
#      1. given pointer to result list head
#      2. given pointer to result list tail
#      3. given head and tail of list to be appended
#
# Task:
#      append the given list to the result list
#







    def print_list(self, head):
        print("List : ", end=' ')

        while head:
            print(head.val, end= ' ')
            head = head.next

        print()


    def performRandomReversal(self, head, nums):
