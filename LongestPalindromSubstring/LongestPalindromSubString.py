#
# Created on Wed Sep 16 2020
#
# Copyright (c) 2020 SaiReddy
#


def checkPalindrome(str, start, end):
    while start >= 0 and end < len(str):
        if str[start] != str[end]:
            break
        start -= 1
        end += 1
    return [start + 1, end - 1]


def longestPalindromSubString(str):
    indices = [0, 0]
    for i in range(1, len(str)):
        # x y x
        one = checkPalindrome(str, i - 1, i + 1)
        # x x y
        two = checkPalindrome(str, i - 1, i)

        # print(one,two)

        indices = max(
            indices, max(one, two, key=lambda x: x[1] - x[0]), key=lambda x: x[1] - x[0]
        )

    # print(indices)
    return str[indices[0] : indices[1] + 1]


print(longestPalindromSubString("abaxyzzyxf"))

print(longestPalindromSubString("SaiReddyddeRiasuman"))

print(longestPalindromSubString("nandarcra"))

