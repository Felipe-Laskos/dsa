result = []

n = 3

def bt_dfs(path=None):
    if path is None:
        path = []

    if len(path) == n:
        result.append("".join(path))
        return

    for char in ["A", "B"]:
        path.append(char)
        bt_dfs(path)
        path.pop()

bt_dfs()
print(result)