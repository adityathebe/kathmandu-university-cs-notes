"""Stochastic Gradient Descent to make a Perceptron learn AND Gate"""


import math
from random import random


def sgn(x):
	return 1 if x > 0 else 0


def predict(inputs, weights):
	sum_total = weights[0]
	for i in range(len(weights) - 1):
		sum_total += weights[i + 1] * inputs[i]
	return sgn(sum_total)


def sgd(train, l_rate, n_epoch):
	weights = [random() for i in range(len(train[0]))]

	for epoch in range(n_epoch):
		sum_error = 0
		for row in train:
			output = predict(row, weights)
			target = row[-1]
			error = target - output
			sum_error += error**2

			# Update delta weights and bias
			weights[0] += l_rate * error
			for i in range(len(row) - 1):
				weights[i + 1] += l_rate * error * row[i]

		if epoch % 20 is 0:
			print('> epoch=%d, lrate=%.3f, error=%.3f' % (epoch, l_rate, sum_error))
	return weights


if __name__ == "__main__":
	dataset = [[1, 1, 1], [1, 0, 0], [0, 1, 0], [0, 0, 0]]
	l_rate = 0.001
	n_epoch = 1000
	weights = sgd(dataset, l_rate, n_epoch)

	# Test
	for data in dataset:
		print('Input = {} Output = {}'.format(data[:2], predict(data, weights)))
