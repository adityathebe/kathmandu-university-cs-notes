# Implementation of algorithm as discussed in class

def swap(arr, x, y):
	(arr[x], arr[y]) = (arr[y], arr[x])

def settlePivotElement(elements, lower_range, upper_range):
	pivotElement = elements[lower_range]
	left_pointer = lower_range + 1
	right_pointer = upper_range
	while True:
		while left_pointer <= right_pointer and elements[left_pointer] < pivotElement:
			left_pointer += 1
		while left_pointer <= right_pointer and elements[right_pointer] > pivotElement: 
			right_pointer -= 1
		if left_pointer > right_pointer: break
    
		swap(elements, left_pointer, right_pointer)

	swap(elements, lower_range, right_pointer)
	return right_pointer

def quickSort(elements, lower_range, upper_range):
	index_of_pivot_element = settlePivotElement(elements, lower_range, upper_range)
	
	if lower_range <= index_of_pivot_element - 1:
		quickSort(elements, lower_range, index_of_pivot_element - 1)

	if index_of_pivot_element + 1 <= upper_range:
		quickSort(elements, index_of_pivot_element + 1 , upper_range)

if __name__ == "__main__":
	inputs = [11, 32, 99, 5, 206, 258, 111, 25, 252, 82, 434, 23, 477, 1111, 1]
	print("Unsorted Input :: ", inputs)
	lower_range = 0
	upper_range = len(inputs) - 1
	quickSort(inputs, lower_range, upper_range)
	print("Sorted Output  :: ",inputs)
