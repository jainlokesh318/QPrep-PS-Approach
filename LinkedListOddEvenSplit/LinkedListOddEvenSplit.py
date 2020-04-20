import sys

from ds.List.ListNode import *
from solution import *

# DON'T TOUCH THIS FILE. ASSESSMENT WILL REPLACE THIS FILE


def test_do_odd_even_split():
    # empty list split
    res = do_odd_even_split(None, 1)
    assert res[0] == None
    assert res[1] == None


    # single element
    arr = [1]
    head = createList(arr)
    res = do_odd_even_split(head, 1)
    assert res[0] != None
    assert res[0].val == 1
    assert res[1] == None


    # two element
    arr = [1, 2]
    head = createList(arr)
    res = do_odd_even_split(head, 1)
    assert res[0] != None
    assert res[0].val == 1
    assert res[1] != None
    assert res[1].val == 2

    # 5 element split
    arr = [1, 2, 3, 4, 5]

    head = createList(arr)
    res = do_odd_even_split(head, 1)
    assert res[0] != None
    assert res[0].val == 1
    assert res[0].next.val == 3
    assert res[0].next.next.val == 5
    assert res[0].next.next.next == None
    assert res[1].val == 2
    assert res[1].next.val == 4
    assert res[1].next.next == None



def test_find_meeting_point():
    # empty list
    res = find_meeting_point(None)
    assert res == None

    # list with no loop
    arr = [1]
    head = createList(arr)
    assert None == find_meeting_point(head)

    # 1 -> 2 -> 3 -> {2}
    arr = [1, 2, 3]
    head = generateLinkedListWithCycle(arr, 1)
    res = find_meeting_point(head)
    assert res != None

def test_break_loop():
    arr = [1]
    head = generateLinkedListWithCycle(arr, 0)
    res = break_loop(head, head)

    assert res != None
    assert res.val == 1
    assert res.next == None


    arr = [1, 2, 3]
    head = generateLinkedListWithCycle(arr, 1)
    res = break_loop(head, head.next)
    assert res.next.next.next == None
    assert res.val == 1
    assert res.next.val == 2
    assert res.next.next.val == 3



def test_find_loop_start():
    # loop starts at node 1
    arr = [1, 2, 3]
    head = generateLinkedListWithCycle(arr, 0)

    meeting_point = head.next
    head.next = None
    res_index, res_node = find_loop_start(head, meeting_point)
    assert res_index == 1
    assert res_node != None
    assert res_node.val == 1


    # loop starts at node 2
    arr = [1, 2, 3]
    head = generateLinkedListWithCycle(arr, 1)

    meeting_point = head.next.next
    head.next.next = None
    res_index, res_node = find_loop_start(head, meeting_point)
    assert res_index == 2
    assert res_node != None
    assert res_node.val == 2


    # loop starts at node 3
    arr = [1, 2, 3]
    head = generateLinkedListWithCycle(arr, 2)

    meeting_point = head.next.next.next
    head.next.next.next = None

    res_index, res_node = find_loop_start(head, meeting_point)
    assert res_index == 3
    assert res_node != None
    assert res_node.val == 3

def print_list(head):
    lst = extractList(head)

    sys.stdout.write('{}\n'.format(len(lst)))
    sys.stdout.write(' '.join([str(x) for x in lst]) + '\n')

if __name__ == '__main__':

    n, k = map(int, sys.stdin.readline().strip().split())
    lst = list(map(int, sys.stdin.readline().strip().split()))

    head = generateLinkedListWithCycle(lst, k-1)

    head1, head2 = split_list_by_odd_or_even(head)
    print_list(head1)
    print_list(head2)
