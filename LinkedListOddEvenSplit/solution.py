from ds.List.ListNode import ListNode

def print_list(head):
    while head:
        print(head.val, end='->')
        head = head.next
    print('null')


def split_list_by_odd_or_even(head):

