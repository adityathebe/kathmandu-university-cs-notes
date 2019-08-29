"""
Date: Mon Feb 4, 2019
Duration: 40 minutes

# 2. http://ku.edu.np/cse/faculty/manoj/2018/comp314/assignments.php
"""

def findMax(arr, left, right):
  if left == right:
    return arr[left]

  if right - left == 1:
    if arr[right] > arr[left]:
      return arr[right]
    return arr[left]

  mid = (left + right) // 2
  if arr[mid] > arr[mid - 1] and arr[mid] > arr[mid + 1]:
    return arr[mid]

  if arr[mid] > arr[mid - 1]:
    return findMax(arr, mid + 1, right)
  else:
    return findMax(arr, left, mid - 1)

#############
# Unit Test #
#############
import random

def sequenceGenerator():
  size = random.randint(5, 15)
  mid = random.randint(0, size - 1)
  initial = random.randint(0, 100)
  arr = [initial]

  for x in range(size - 1):
    delta = random.randint(1, 25)
    if x >= mid: delta *= -1
    rand = arr[x] + delta
    arr.append(rand)

  return {
    "maxVal": arr[mid],
    "arr": arr
  }

def unitTest():
  counter = 200
  for _ in range(counter):
    seq = sequenceGenerator()
    max = seq.get('maxVal')
    arr = seq.get('arr')
    calculatedMax = findMax(arr, 0, len(arr) - 1)

    if max == calculatedMax: counter -= 1

  if counter == 0:
    print("100% Success")

unitTest()
