def subsets(nums):
    result = []

    def bt_dfs(index=0, path=None):
        if path is None:
            path = []

        if index == len(nums):
            result.append(path.copy())
            return

        path.append(nums[index])
        bt_dfs(index + 1, path)

        path.pop()
        bt_dfs(index + 1, path)

    bt_dfs()
    return result


print(subsets([1, 2, 3]))
