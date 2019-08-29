"""
Jan 30, 2019
Duration: 40 minutes

The Triangle
http://ku.edu.np/cse/faculty/manoj/2014/comp314/assignment3.pdf
"""


class Node:
  def __init__(self, value):
    self.left = None
    self.right = None
    self.value = value
    self.max = None

input = """
7
3 8
8 1 0
2 7 4 4
4 5 2 6 5
"""

nodes = []
def makeTree():
  lines = input.split('\n')
  lines = filter(lambda x: x is not "", lines)

  # Create Nodes
  for i, line in enumerate(lines):
    nodes.append([])
    numbers = line.split(' ')
    for j, number in enumerate(numbers):
      n = Node(int(number))
      nodes[i].append(n)

  # Connect Nodes
  row = 0
  col = 0
  for line in nodes:
    for j, node in enumerate(line):
      if (row < len(nodes) - 1):
        node.left = nodes[row+1][j]
        node.right = nodes[row+1][j+1]
    row += 1

def max(n1, n2):
  if n1.value > n2.value:
    return n1.value
  else:
    return n2.value

def findMax(root):
  # If max for this node has already been evaluated
  if root.max is not None: return root

  if root.left is not None and root.right is not None:
    new_val = root.value + max(findMax(root.left), findMax(root.right))
    root.max = new_val  # Memoization
    return Node(new_val)

  # Terminal Nodes
  if root.left is None and root.right is None:
    return root

  if root.left is None and root.right is not None:
    return findMax(root.right)

  if root.left is not None and root.right is None:
    return findMax(root.left)

if __name__ == "__main__":
  makeTree()
  root = nodes[0][0]
  ans = findMax(root)
  print(ans.value)
