'''
Date : Dec 24, 2018
Duration : ~1 hr
'''

class TreeNode:
  def __init__(self, value, frequency):
    self.left = None
    self.right = None
    self.value = value
    self.frequency = frequency

def getFrequencyFromText(txt):
  '''
  Returns a dictionary 
    key = character
    value = frequency
  '''
  frequency = {}
  for char in txt:
    if char in frequency:
      frequency[char] += 1
    else:
      frequency[char] = 1

  return frequency


def getListOfNode(frequency):
  '''
  Provide a frequency dictionary
  Returns a list of TreeNode
  '''
  nodes = []
  for char in frequency:
    node = TreeNode(char, frequency[char])
    nodes.append(node)

  return nodes


def mergeNodes(nodes):
  '''
  Merge the first two nodes from a list of sorted nodes
  '''
  first_node = nodes[0]
  second_node = nodes[1]
  new_node = TreeNode(None, first_node.frequency + second_node.frequency)
  new_node.left = first_node
  new_node.right = second_node
  nodes = [new_node] + nodes[2:]
  return nodes


def sort(nodes):
  '''
  Sort nodes using Insertion sort based on frequency  
  '''

  sorted_nodes = []
  for node in nodes:
    if len(sorted_nodes) == 0:
      sorted_nodes.append(node)
    else:
      index = len(sorted_nodes) - 1
      while(index >= 0 and sorted_nodes[index].frequency > node.frequency):
        index -= 1
      sorted_nodes = sorted_nodes[:index + 1] + [node] + sorted_nodes[index + 1:]
  return sorted_nodes


def generateHuffmanTree(frequency):
  '''
  Provide a frequency dictionary
  Returns a Huffman Tree
  '''
  nodes = getListOfNode(frequency)
  while len(nodes) > 1:
    sorted_nodes = sort(nodes)
    nodes = mergeNodes(sorted_nodes)
  return nodes[0]


def generateEncodingValues(node, code = "", values = {}):
  '''
  Returns a dictionary with encoded value mappings
  '''
  if node is not None:
    if node.value:
      values[node.value] = code
    generateEncodingValues(node.left, code + '0', values)
    generateEncodingValues(node.right, code + '1', values)
  return values


def huffmanEncode(text, encoding_dict):

  compressed_txt = ''
  for char in text:
    compressed_txt += encoding_dict[char]

  return compressed_txt


def huffmanDecode(encoded_bits, encoding_dict):
  current_code = ""
  decoded_text = ""

  reverse_dict = {v: k for k, v in encoding_dict.items()}

  for bit in encoded_bits:
    current_code += bit
    if current_code in reverse_dict:
      character = reverse_dict[current_code]
      decoded_text += character
      current_code = ""

  return decoded_text


if __name__ == "__main__":
  # Read File
  f = open("input.txt", "r")
  text = f.read()
  if len(text) == 0: raise Exception('Empty input')

  # Count Frequency
  frequency = getFrequencyFromText(text)
  print("Frequency ::", frequency, '\n')

  # Generate Huffman tree and encoding maps
  huffman_tree = generateHuffmanTree(frequency)
  encoding_dict = generateEncodingValues(huffman_tree)
  if len(encoding_dict) < 2:
    for key in encoding_dict: encoding_dict[key] = '0'
  print("Encoding map ::", encoding_dict, '\n')

  # Encode and decode text 
  encoded_bits = huffmanEncode(text, encoding_dict)
  wf = open("encoded.txt", "w")
  wf.write(encoded_bits)
  decoded_text = huffmanDecode(encoded_bits, encoding_dict)
  wf = open("decoded.txt", "w")
  wf.write(decoded_text)

  # Measure compression ratio
  uncompressed_size = 0
  for char in text:
    uncompressed_size += 8

  compressed_size = 0
  for char in encoded_bits:
    compressed_size += 1

  compression_ratio = uncompressed_size / compressed_size
  print("Compression Ratio = {}".format(round(compression_ratio, 2)))
