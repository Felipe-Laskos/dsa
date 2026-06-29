from collections import Counter

def tokKFrequent(nums, k):
    n = len(nums)
    counter = Counter(nums)

    arr: list[int | list[int]] = [0] * (n + 1)

    for num, freq in counter.items():
        bucket = arr[freq]
        if isinstance(bucket, list):
            bucket.append(num)
        else:
            arr[freq] = [num]

    re = []
    for i in range(n, -1, -1):
        bucket = arr[i]
        if isinstance(bucket, list):
            re.extend(bucket)
        if len(re) == k:
            break

    return re
