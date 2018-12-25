'''
Dec 25, 2018
Cycle Detection algorithm - using depth first search
'''


class Node:
  def __init__(self, id):
    self.id = id
    self.adjacent_nodes = []

  def addAdjacentNode(self, nodes):
    for node in nodes:
      self.adjacent_nodes.append(node)


visited = []


def checkCycle(parent, node):
  global visited

  print("{} ==> {} [{}]".format(parent.id, node.id, visited))
  if node.id in visited and parent.id != node.id:
    return True

  visited.append(node.id)

  for adj_node in node.adjacent_nodes:
    if adj_node.id != parent.id:
      return checkCycle(node, adj_node)

  return False


if __name__ == "__main__":
  v1 = Node('1')
  v2 = Node('2')
  v3 = Node('3')
  v4 = Node('4')
  v5 = Node('5')
  v6 = Node('6')

  v1.addAdjacentNode([v2, v3, v4])
  v2.addAdjacentNode([v1, v5])
  v3.addAdjacentNode([v1, v5])
  v4.addAdjacentNode([v1])
  v5.addAdjacentNode([v2, v3, v6])
  v6.addAdjacentNode([v5])

  has_cycle = checkCycle(v2, v1)
  print(has_cycle)
