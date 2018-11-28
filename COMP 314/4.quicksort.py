def swap(arr, x, y):
	(arr[x], arr[y]) = (arr[y], arr[x])

def settlePivotElement(elements, lower_range, upper_range):
	pivotElement = elements[lower_range];
	pL = lower_range + 1;
	pR = upper_range;
	while True:
		while pL <= pR and elements[pL] < pivotElement : pL += 1
		while pL <= pR and elements[pR] > pivotElement : pR -= 1
		if pL > pR: break
		swap(elements, pL, pR);

	swap(elements, lower_range, pR);
	return pR;

def quickSort(elements, lower_range, upper_range):
	index_of_pivot_element = settlePivotElement(elements, lower_range, upper_range)
	
	if lower_range <= index_of_pivot_element - 1:
		quickSort(elements, lower_range, index_of_pivot_element - 1);

	if index_of_pivot_element + 1 <= upper_range:
		quickSort(elements, index_of_pivot_element + 1 , upper_range);

if __name__ == "__main__":
	inputs = [11, 32, 99, 5, 206, 258, 111, 25, 252, 82, 434, 23, 477, 1111, 1]
	print("Unsorted Input :: ", inputs)
	lower_range = 0
	upper_range = len(inputs) - 1
	quickSort(inputs, lower_range, upper_range)
	print("Sorted Output  :: ",inputs)
