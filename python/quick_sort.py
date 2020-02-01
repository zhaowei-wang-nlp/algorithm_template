# 数组排序
def quick_sort_array(q, l, r):
    if l >= r:
        return
    i, j = l-1, r+1
    x = q[l]
    while i < j:
        i += 1
        while q[i] < x:
            i += 1
        j -= 1
        while q[j] > x:
            j -= 1
        if i < j:
            temp, q[i] = q[i], q[j]
            q[j] = temp
    quick_sort(q, l, j)
    quick_sort(q, j+1, r)


#  链表排序
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None
def quick_sort_list(head, end):
    if head is end:
        return
    x = head.val
    # 此处i和j都可能到达end，和数组排序不一样
    i, j = head, head.next
    while j is not end:
        while j is not end and j.val > x:
            j = j.next
        if j is not end:
            i = i.next
            temp, i.val = i.val, j.val
            j.val = temp
            j = j.next
    temp, head.val = head.val, i.val
    i.val = temp
    self.quick_sort(head, i)
    self.quick_sort(i.next, end)


def sort_list(head: ListNode) -> ListNode:
        self.quick_sort(head, None)
        return head


if __name__ == "__main__":
    N = 1e6+10
    n = int(input())
    q = [int(e) for e in input().split()]
    quick_sort(q, 0, n-1)
    for i in range(n):
        print(str(q[i])+" ", end="")