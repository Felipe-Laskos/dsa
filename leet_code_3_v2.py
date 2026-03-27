
def lengthOfLongestSubstring(s: str) -> int:
    sett = set()

    left = 0
    right = 0

    longest = 0
    
    w = 0

    arrLength = len(s)

    while(left != arrLength and right != arrLength):
        if(s[right] in sett):
            sett.remove(s[left])

            left = left + 1
        else:
            sett.add(s[right])

            w = (right - left) + 1

            if(w > longest):
                longest = w

            right = right + 1
    return longest

print(lengthOfLongestSubstring("pwwkew"))
