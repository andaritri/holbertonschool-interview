#!/usr/bin/python3
"""Lock boxes"""


def can_unlock_all(boxes):
    """Check if all of boxes can be opened"""
    keys = set()
    for idx, box in enumerate(boxes, start=1):
        for key in box:
            if key < len(boxes):
                keys.add(key)
                keys.update(boxes[key])
        if idx not in keys:
            return False
    return True


canUnlockAll = can_unlock_all
