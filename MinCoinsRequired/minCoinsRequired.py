#
# Created on Thu Sep 17 2020
#
# Copyright (c) 2020 SaiReddy
#


def minCoinsReqiuired(coins, number):
    coins_required = [float("inf") for i in range(number + 1)]
    coins_required[0] = 0
    for coin in coins:
        for i in range(number + 1):
            if i >= coin:
                coins_required[i] = min(coins_required[i], 1 + coins_required[i - coin])

    return coins_required[-1]


print(minCoinsReqiuired([1, 2, 4], 3))

print(minCoinsReqiuired([1, 2, 4, 5, 6, 10], 100))

print(minCoinsReqiuired([1, 2, 4, 5, 6, 10], 10))
print(minCoinsReqiuired([1, 2, 4, 5, 6, 10], 60))
print(minCoinsReqiuired([1, 2, 4, 5, 6, 10], 12))
print(minCoinsReqiuired([1, 2, 4, 5, 6, 10], 99))
print(minCoinsReqiuired([1, 2, 4, 5, 6, 10], 15))

# 2
# 10
# 1
# 6
# 2
# 11
# 2
