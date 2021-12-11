#!/usr/bin/python3
"""Lock boxes"""


def can_unlock_all(boxes):
    """Check if all of boxes can be opened"""
    num_boxes = len(boxes)
    keys = set()
    for idx, box in enumerate(boxes, start=1):
        for key in box:
            if key < num_boxes:
                keys.add(key)
                keys.update(boxes[key])
            if len(keys) >= num_boxes-1:
                return True
        if idx not in keys:
            return False


canUnlockAll = can_unlock_all
