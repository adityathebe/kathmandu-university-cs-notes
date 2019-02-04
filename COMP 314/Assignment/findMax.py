"""
Date: Mon Feb 4, 2019
Duration: 5 minutes

#2. http://ku.edu.np/cse/faculty/manoj/2018/comp314/assignments.php
"""

input = [1, 4, 7, 8, 6, 3, 0]

def findMax(arr, left, right):
  mid = (left + right) // 2
  if arr[mid] >= arr[mid - 1] and arr[mid] >= arr[mid + 1]:
    return arr[mid]

  findMax(arr, left, mid - 1)
  findMax(arr, mid + 1, right)

print(findMax(input, 0, len(input) - 1))
