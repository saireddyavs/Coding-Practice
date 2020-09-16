#
# Created on Wed Sep 16 2020
#
# Copyright (c) 2020 SaiReddy
#

# decreasing space complexity to O(min(len(str1),len(str2)))
def minimumEditDistance(str1, str2):
    str_big = str1 if len(str1) > len(str2) else str2
    str_small = str1 if len(str1) <= len(str2) else str2

    first_line = [i for i in range(0, len(str_small) + 1)]
    second_line = [i for i in range(0, len(str_small) + 1)]

    for i in range(1, len(str_big) + 1):
        if i % 2 == 0:
            current_line = first_line
            previous_line = second_line
        else:
            current_line = second_line
            previous_line = first_line
        current_line[0] = i
        for j in range(1, len(str_small) + 1):
            if str_small[j - 1] == str_big[i - 1]:
                current_line[j] = previous_line[j - 1]
            else:
                current_line[j] = 1 + min(
                    previous_line[j - 1], previous_line[j], current_line[j - 1]
                )

    print(second_line[-1] if len(str_big) % 2 == 1 else first_line[-1])


minimumEditDistance("abbbbbbbbb", "bbbbbbbbba")

minimumEditDistance("saireddy", "suman")

minimumEditDistance("RGUKT", "RGUKT-Basar")

minimumEditDistance("nandarc", "saireddy")

# 2
# 7
# 6
# 7
