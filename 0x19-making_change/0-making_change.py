#!/usr/bin/python3
"""Making Change problem
"""


def makeChange(coins, total):
    """Returns the fewest number of coins needed to meet a given total
    Args:
        coins: array of integers representing the coin values
        total: the total to find coins for
    """
    if total <= 0:
        return 0

    placeholder = total + 1

    memory = {0: 0}

    for i in range(1, total + 1):
        memory[i] = placeholder

        for coin in coins:
            current = i - coin
            if current < 0:
                continue

            memory[i] = min(memory[current] + 1, memory[i])

    if memory[total] == total + 1:
        return -1

    return memory[total]
