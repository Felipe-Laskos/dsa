def execute(intervals):

    intervals.sort(key = lambda interval: interval[0])

    x = -1
    m = list()

    m.append(intervals[0]) 
    x += 1

    for a in range(1, len(intervals)):
        first = intervals[a][0]
        second = intervals[a][1]

        if first > m[x][1]:
            m.append(intervals[a])
            x += 1
        elif second > m[x][1]:
            m[x][1] = second

        if first < m[x][0] and second >= m[x][0]:
            m[x][0] = first
        elif second < m[x][0]:
            m.insert(0, intervals[a])
            x += 1

    return m


intervals = [[2,3],[4,5],[6,7],[8,9],[1,10]]

print(execute(intervals))