from ds.List.ListNode import ListNode

def print_list(head):
    while head:
        print(head.val, end='->')
        head = head.next
    print('null')

# TODO: CRIO_TASK_MODULE_LINKED_LIST_ODD_EVEN_SPLIT
# Input:
#      1. head of linked list
# Task:
#      1. if linked list has no loop just split odd position and even position elements
#      2. if linked list has loop then return all odd position elements in the loop
#          and even positions elements in the loop
#  Output:
#      1. head of linked list of all nodes in odd positions
#      2. head of linked list of all nodes in even positions

def split_list_by_odd_or_even(head):

