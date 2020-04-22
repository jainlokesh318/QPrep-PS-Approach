import sys

from ds.List.ListNode import *
from solution import *

# DON'T TOUCH THIS FILE. ASSESSMENT WILL REPLACE THIS FILE


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
