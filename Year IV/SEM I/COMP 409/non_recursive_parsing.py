'''
Non recursive predictive parsing
Dec 3, 2018

Given Grammar:
  A -> CB
  B -> +CB | epsilon
  C -> ED
  D -> *ED | epsilon
  E -> (A) | x
'''

V = ['A', 'B', 'C', 'D', 'E']
T = ['+', '*', '(', ')', 'x']

parse_table = {
  'A': {
    'x': 'CB',
    '(': 'CB'
  },
  'B': {
    '+': '+CB',
    ')': '',
    '$': '',
  },
  'C': {
    'x': 'ED',
    '(': 'ED'
  },
  'D': {
    ')': '',
    '+': '',
    '*': '*ED',
    '$': ''
  },
  'E': {
    'x': 'x',
    '(': '(A)',
  }
}

string = "x+x*x$"
stack = ['$', 'A']
iptr = 0
while True:
  current_input = string[iptr]
  print("\nTop of stack = {} && Current input = {}".format(stack[len(stack) - 1], current_input))

  if stack[len(stack) - 1] == '$' and current_input == '$':
    print('\n\n** Accepted **')
    break

  if stack[len(stack) - 1 ] in V:
    v = stack.pop()
    production_of_v = parse_table[v][current_input]
    rev_production_of_v = list(production_of_v)
    rev_production_of_v.reverse()
    print('Replacing {} ==> {}'.format(v, production_of_v))
    for p in rev_production_of_v:
      stack.append(p)
  else:
    if current_input == stack[len(stack) - 1]:
      iptr += 1
      stack.pop()
      print('Matched {} and {}'.format(current_input, current_input))
    else: 
      print("\n\n**Rejected")
      break
