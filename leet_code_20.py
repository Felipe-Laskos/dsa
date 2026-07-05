def isValid(s):
    stack = []

    pairs = {
        ")": "(",
        "]": "[",
        "}": "{"
    }

    for c in s:
        if c in pairs:
            if len(stack) == 0 or stack.pop() != pairs[c]:
                return False
        else:
            stack.append(c)

    return len(stack) == 0


s = "()[]{}"

print(isValid(s))
