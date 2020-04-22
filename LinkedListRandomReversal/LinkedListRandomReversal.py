import sys
from ds.List.ListNode import ListNode, createList, extractList
from solution import *

# DON'T TOUCH THIS FILE. ASSESSMENT WILL REPLACE THIS FILE



def test_reverse_linked_list():
    # empty list test

    res = Solution().reverse_linked_list(None)
    assert res[0] == None

    # one element test
    arr = [1]
    head = createList(arr)
    res = Solution().reverse_linked_list(head)

    assert res[0] != None
    assert res[0].val == 1
    assert res[0].next == None

    # two element test

    arr = [1, 2]
    head = createList(arr)
    res = Solution().reverse_linked_list(head)

    assert res[0] != None
    assert res[0].val == 2
    assert res[0].next != None
    second = res[0].next
    assert second != None
    assert second.val == 1
    assert second.next == None


def test_split_list():
    # empty list test

    res = Solution().split_list(None, 1)

    assert res[0] == None
    assert res[1] == None


    # one element test [1, 0]

    arr = [1]

    head = createList(arr)
    res = Solution().split_list(head, 1)

    assert res[0] != None
    assert res[0].val == 1
    assert res[0].next == None
    assert res[1] == None


    # one element test, [0, 1]

    arr = [1]

    head = createList(arr)
    res = Solution().split_list(head, 0)

    assert res[1] != None
    assert res[1].val == 1
    assert res[1].next == None
    assert res[0] == None

    # two element test, [2, 0]

    arr = [1, 2]
    head = createList(arr)
    res = Solution().split_list(head, 2)

    assert res[0] != None
    assert res[0].val == 1
    assert res[0].next != None
    assert res[0].next.val == 2
    assert res[0].next.next == None
    assert res[1] == None

    # two element test, [1, 1]

    arr = [1, 2]

    head = createList(arr)
    res = Solution().split_list(head, 1)

    assert res[0] != None
    assert res[0].val == 1
    assert res[0].next == None
    assert res[1].val == 2
    assert res[1].next == None

    # two element test, [0, 2]

    arr = [1, 2]

    head = createList(arr)
    res = Solution().split_list(head, 0)

    assert res[1] != None
    assert res[1].val == 1
    assert res[1].next != None
    assert res[1].next.val == 2
    assert res[1].next.next == None
    assert res[0] == None

def test_append_reversed_list_to_result():
    result_head = None
    result_tail = None


    res = Solution().append_reversed_list_to_result(result_head, result_tail, None, None)
    result_head = res[0]
    result_tail = res[1]
    assert result_head == None
    assert result_tail == None

    arr1 = [1, 2, 3]

    list1 = createList(arr1)

    res = Solution().append_reversed_list_to_result(result_head, result_tail, list1, list1.next.next)
    result_head = res[0]
    result_tail = res[1]

    expected_arr1 = extractList(result_head)
    # now the lsit should look like 1->2->3->None
    assert expected_arr1[0] == arr1[0]
    assert expected_arr1[1] == arr1[1]
    assert expected_arr1[2] == arr1[2]

    arr2 = [4, 5]

    list2 = createList(arr2)
    res = Solution().append_reversed_list_to_result(result_head, result_tail, list2, list2.next)
    result_head = res[0]
    result_tail = res[1]

    expected_arr2 = extractList(result_head)
    # now the lsit should look like 1->2->3->4->5->None
    assert expected_arr1[0] == arr1[0]
    assert expected_arr1[1] == arr1[1]
    assert expected_arr1[2] == arr1[2]
    assert expected_arr2[3] == arr2[0]
    assert expected_arr2[4] == arr2[1]

    res = Solution().append_reversed_list_to_result(result_head, result_tail, None, None)
    result_head = res[0]
    result_tail = res[1]
    # now the lsit should look like 1->2->3->4->5->None
    assert expected_arr1[0] == arr1[0]
    assert expected_arr1[1] == arr1[1]
    assert expected_arr1[2] == arr1[2]
    assert expected_arr2[3] == arr2[0]
    assert expected_arr2[4] == arr2[1]

test_reverse_linked_list()
test_split_list()
test_append_reversed_list_to_result()


n = int(sys.stdin.readline())
lst = list(map(int , sys.stdin.readline().strip().split()))

k = int(sys.stdin.readline().strip())
nums = list(map(int , sys.stdin.readline().strip().split()))

head = createList(lst)

result_head = Solution().performRandomReversal(head, nums)
result_list = extractList(result_head)

sys.stdout.write('{}\n'.format(len(result_list)))
sys.stdout.write('{}\n'.format(' '.join([str(x) for x in result_list])))

