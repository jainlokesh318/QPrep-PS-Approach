import sys
from ds.List.ListNode import ListNode, createList, extractList
from solution import *

# DON'T TOUCH THIS FILE. ASSESSMENT WILL REPLACE THIS FILE



n = int(sys.stdin.readline())
lst = list(map(int , sys.stdin.readline().strip().split()))

k = int(sys.stdin.readline().strip())
nums = list(map(int , sys.stdin.readline().strip().split()))

head = createList(lst)

result_head = Solution().performRandomReversal(head, nums)
result_list = extractList(result_head)

sys.stdout.write('{}\n'.format(len(result_list)))
sys.stdout.write('{}\n'.format(' '.join([str(x) for x in result_list])))

