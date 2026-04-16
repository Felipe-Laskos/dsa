def execute(intervals):
    intervals.sort(key = lambda interval: interval[0])

    merged = []

    for interval in intervals:
        if not merged or merged[-1][1] < interval[0]:
            merged.append(interval)
        else:
            merged[-1] = [merged[-1][0], max(merged[-1][1], interval[1])]

    return merged

intervals = [[2,3],[4,5],[6,7],[8,9],[1,10]]

print(execute(intervals))