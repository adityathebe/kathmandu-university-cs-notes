import math


def display(node, depth=0):
  print('     ' * depth + node.attr_name)
  depth += 1
  for child in node.children:
    display(child, depth)


class Node:
  def __init__(self):
    self.attr_name = None
    self.children = []

  def set_name(self, name):
    self.attr_name = name

  def add_child(self, child_node):
    self.children.append(child_node)

  def __str__(self):
    return self.attr_name


def lg2(num):
  return math.log(num, 2)


def getEntropy(s):
  total = sum(s)
  entropy = 0
  for x in s:
    if x == 0:
      continue
    proportion = x / total
    entropy += -proportion * lg2(proportion)

  return entropy


def id3(node, sample, attribute_set):

  # Calculate partition based on target value
  target_values = {"positive": 0, "negative": 0}
  for s in sample:
    if s['output'] == 1:
      target_values['positive'] += 1
    else:
      target_values['negative'] += 1
  partition = [val for key, val in target_values.items()]
  sample_entropy = getEntropy(partition)

  # Measure attribute with largest Information Gain
  best_attribute = None
  for attribute in attribute_set:
    second_part = 0
    for attr_value in attribute['values']:
      new_sample = [x for x in sample if x[attribute['name']] == attr_value]

      target_values = {"positive": 0, "negative": 0}
      for s in new_sample:
        if s['output'] == 1:
          target_values['positive'] += 1
        else:
          target_values['negative'] += 1
      partition = [val for key, val in target_values.items()]
      entropy = getEntropy(partition)
      second_part += (len(new_sample) / len(sample)) * entropy
    information_gain = sample_entropy - second_part
    attribute['information_gain'] = information_gain
    if best_attribute == None:
      best_attribute = attribute
    else:
      if information_gain > best_attribute['information_gain']:
        best_attribute = attribute
  node.set_name(best_attribute['name'])

  # Create descendant nodes
  new_attribute_set = [attr for attr in attribute_set if attr['name'] != best_attribute['name']]
  for attr_value in best_attribute['values']:
    best_attritbute_name = best_attribute['name']
    new_sample = [data for data in sample if data[best_attritbute_name] == attr_value]

    test = 0
    for s in new_sample:
      if s['output'] == 1:
        test += 1
      else:
        test -= 1

    child_node = Node()
    node.add_child(child_node)
    if abs(test) != len(new_sample) and len(new_attribute_set) != 0:
      id3(child_node, new_sample, new_attribute_set)
    else:
      child_node.set_name(attr_value)

if __name__ == "__main__":
  initial_sample = [
      {'outlook': 'sunny', 'temp': 'hot', 'humidity': 'high', 'wind': 'weak', 'output': 0},
      {'outlook': 'sunny', 'temp': 'hot', 'humidity': 'high', 'wind': 'strong', 'output': 0},
      {'outlook': 'overcast', 'temp': 'hot', 'humidity': 'high', 'wind': 'weak', 'output': 1},
      {'outlook': 'rain', 'temp': 'mild', 'humidity': 'high', 'wind': 'weak', 'output': 1},
      {'outlook': 'rain', 'temp': 'cool', 'humidity': 'normal', 'wind': 'weak', 'output': 1},
      {'outlook': 'rain', 'temp': 'cool', 'humidity': 'normal', 'wind': 'strong', 'output': 0},
      {'outlook': 'overcast', 'temp': 'cool', 'humidity': 'normal', 'wind': 'strong', 'output': 1},
      {'outlook': 'sunny', 'temp': 'mild', 'humidity': 'high', 'wind': 'weak', 'output': 0},
      {'outlook': 'sunny', 'temp': 'cool', 'humidity': 'normal', 'wind': 'weak', 'output': 1},
      {'outlook': 'rain', 'temp': 'mild', 'humidity': 'normal', 'wind': 'weak', 'output': 1},
      {'outlook': 'sunny', 'temp': 'mild', 'humidity': 'normal', 'wind': 'strong', 'output': 1},
      {'outlook': 'overcast', 'temp': 'mild', 'humidity': 'high', 'wind': 'strong', 'output': 1},
      {'outlook': 'overcast', 'temp': 'hot', 'humidity': 'normal', 'wind': 'weak', 'output': 1},
      {'outlook': 'rain', 'temp': 'mild', 'humidity': 'high', 'wind': 'strong', 'output': 0},
  ]

  attribute_set = [
      {'name': 'outlook', 'values': ['sunny', 'overcast', 'rain']},
      {'name': 'temp', 'values': ['hot', 'mild', 'cool']},
      {'name': 'humidity', 'values': ['high', 'normal']},
      {'name': 'wind', 'values': ['weak', 'strong']},
  ]

  head = Node()
  head.set_name('root')
  id3(head, initial_sample, attribute_set)
  display(head)
