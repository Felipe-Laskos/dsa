import heapq

def findKthLargest(nums, k):
    heap = []

    for num in nums:
        if len(heap) < k:
            heapq.heappush(heap, num)
        else:
            heapq.heappushpop(heap, num)

    return heap[0]


nums = [3, 2, 1, 5, 6, 4]
k = 2

print(findKthLargest(nums, k))
