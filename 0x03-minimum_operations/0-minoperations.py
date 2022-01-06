#!/usr/bin/python3
"""Min operations required"""


def min_operations(n):
    """Minimun operations required"""
    if n <= 1:
        return 0
    count = copy = 0
    num = 1
    while True:
        if n % num == 0:
            count += 1
            copy = num
        num += copy
        count += 1
        if num == n:
            return count
    return 0


minOperations = min_operations
