#
# Created on Tue Sep 15 2020
#
# Copyright (c) 2020 SaiReddy
#

def maximumSumSubArray(arr):
    high=arr[0]
    result=arr[0]
    for number in arr[1:]:
        high=max(number,number+high)
        result=max(result,high)
    
    return result


print(maximumSumSubArray([3, 4, -6, 7, 8]))