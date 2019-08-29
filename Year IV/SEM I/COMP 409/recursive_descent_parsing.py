###########
# Grammar #
###########

# Symbols
T = ['x', 'y', 'b']
V = ['S', 'A', 'B', 'C', 'D' ]
START = 'S'

# Production Rule
RULE = {
	'S': ['A', 'B'],
	'A': ['C', 'D'],
	'B': ['b'],
	'C': ['x'],
	'D': ['y']
}

##################
# Initialization #
##################
input_str = 'xx'
stack = []
output = START
iptr = optr = 0
production_index = 0

def replace_variable_in_output():
	global output, input_str, iptr, optr, production_index
	while output[optr] in V:
		# Push to stack
		stack.append({ 'output': output, 'iptr': iptr, 'optr': optr, 'p_index': production_index })
		
		# Replace
		variable = output[optr]
		productions = RULE[variable]
		production = productions[production_index]
		output = output[:optr] + production + output[optr + 1:]
		print('Replaced {} by {}. New Output = {}'.format(variable, production, output))

		# Reset Production Index 
		production_index = 0

def revert():
	global output, input_str, iptr, optr, production_index
	stack_top = stack.pop()
	iptr = stack_top['iptr']
	optr = stack_top['optr']
	output = stack_top['output']
	production_index = stack_top['p_index'] + 1
	print("Reverted to output = {}, iptr = {}, optr = {} & pIndex = {}".format(
		output, iptr, optr, production_index
	))

# Returns True if end of stack is reached
def backtrack():
	global output, input_str, iptr, optr, production_index

	if len(stack) == 0 :
		return True
	revert()
	if production_index == len(RULE[output[optr]]):
		print("No more production for {}".format(output[optr]))
		return backtrack()
	
def match_terminals():
	global output, input_str, iptr, optr, production_index
	
	if input_str[iptr] == output[optr]:
		print("Matched {} and {}. New iptr = {} and optr = {}".format(input_str[iptr], output[optr], iptr, optr))
		iptr += 1
		optr += 1
		return True
	else:
		return False

while True:
	print('\n***************************')

	if len(input_str) == iptr and len(output) == optr:
		print("Accepted")
		break
	
	if len(output) == optr:
		if len(stack) == 0:
			print("Rejected")
			break
		else:

	replace_variable_in_output()
	matched = match_terminals()
