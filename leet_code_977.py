def sortedSquares(nums):
        left = 0

        t = len(nums)

        right = t - 1
        
        nums_squared = []

        while right >= left:
            left_squared = nums[left] ** 2
            right_squared = nums[right] ** 2

            if right_squared > left_squared:
                nums_squared.append(right_squared)
                right = right - 1
            elif left_squared > right_squared:
                nums_squared.append(left_squared)
                left = left + 1
            else:
                nums_squared.append(nums[left] ** 2)
                left = left + 1
        
        return sorted(nums_squared)

print(sortedSquares([-4, -1, 0, 3, 10]))