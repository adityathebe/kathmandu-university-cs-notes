# Radial Basis Functions

- RBFN is a type of artificial neural network like Multilayer Perceptron. It has three layers : input layer, a single hidden layer and an output layer. 
- RBFN is named so because it uses radial basis functions as the activation functions.
-The output of the network is a linear combination of radial basis functions of the inputs and neuron parameters.
- Even though the approximated function F(x) is a global approximation to f(x), the contribution from each of the value of kernel function (K<sub>*u*</sub>) is localized to a region nearby he point x<sub>*u*</sub>. x<sub>*u*</sub> is one of the instances (training example).
- Some of its uses are function approximation, classification, and time series prediction.

### MLP vs RBFN

An MLP would naturally separate the classes with hyper-planes in the input space (as
on the left). An alternative approach would be to model the separate class distributions
by localised radial basis functions (as on the right)

![MLP vs RBFN](http://i.imgur.com/4ZiAhgN.png)

## RBF Network Architecture

![](http://chrisjmccormick.files.wordpress.com/2013/08/architecture_simple2.png)

The above illustration shows the typical architecture of an RBF Network. It consists of an input vector, a layer of RBF neurons, and an output layer with one node per category or class of data.

**Input Layer:** Each neuron in the input layer corresponds to a single attribute of an instance. If an instance as *n* attributes then the input layer has *n* neurons.

**Hidden Layer (RBF Neurons):** Each neuron in the hidden layer consists a radial basis function (e.g. Gaussian function) centered on a point ( whose dimension is the same as the instances(*n*) ). Each RBF neuron stores a “prototype” vector which is just one of the vectors from the training set

**Output Layer:** The output layer consists of *C* nodes, one per category that we are trying to classify. Each output node computes a weighted sum of outputs from the hidden layer to form the network's output(s).

## Working Mechanism

### RBF Activation Functions:


Each RBF neuron computes a measure of the similarity between the input and its prototype vector (taken from the training set). Input vectors which are more similar to the prototype return a result closer to 1. There are different possible choices of similarity functions, but the most popular is based on the Gaussian.

![](http://i.imgur.com/joTqglL.png)

The term beta can be simplified as, β = 1 / (2 * σ^2). It controls the width of the bell curve. Higher the value of beta thiner the curve and vice versa.

![](http://chrisjmccormick.files.wordpress.com/2013/08/diff_variances_plot.png)


### How are the u hidden units selected ?

**Aproach 1:** Allocate a gaussian kernel function for each training example centering at themselves. Each kernel may be assigned the same width. This has an advantage that the RBFN can fit the training data exactly.

**Aproach 2:** Choose a set of kernel functions that is smaller than the number of training examples. The set of kernel functions may be distributed with centers spaced uniformly throughout the instance space X. Alternatively, we can choose to distribute the centers nonuniformly which may mean selecting in random fashion.

**Approach 3:** We can identify prototypical clusters of instances, then add a kernel function centerd at each cluster.

### Training

RBF networks are typically trained in a two-stage process. 

- First, the number k of hidden units is determined and each hidden unit *u* is defined by choosing the values of x<sub>*u*</sub> and variance that define its kernel function K.
- Second, the weights w<sub>*u*</sub> are trained to maximize the fit of the network to the training data, using the global error criterion. Backpropagation can be used in this step and it is more efficient for RBG than it is for MLP as the kernel functions are held fixed.

* * *

## Some good sources to learn RBFN

- https://www.youtube.com/watch?v=1Cw45yNm6VA
- https://mccormickml.com/2013/08/15/radial-basis-function-network-rbfn-tutorial/
-https://towardsdatascience.com/radial-basis-functions-neural-networks-all-we-need-to-know-9a88cc053448