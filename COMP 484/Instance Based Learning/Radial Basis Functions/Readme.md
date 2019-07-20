# Radial Basis Functions

- RBFN is a type of artificial neural network like Multilayer Perceptron. It has three layers : input layer, a single hidden layer and an output layer. 
- Each neuron in the input layer corresponds to a single attribute of an instance. If an instance as *n* attributes then the input layer has *n* neurons.
- Each neuron in the hidden layer consists a radial basis function (e.g. Gaussian function) centered on a point with the same dimensions as the instances(*n*).
- The output layer has a weighted sum of outputs from the hidden layer to form the network's output(s).
- Even though the approximated function F(x) is a global approximation to f(x), the contribution from each of the value of kernel function (K<sub>*u*</sub>) is localized to a region nearby he point x<sub>*u*</sub>. x<sub>*u*</sub> is one of the instances (training example).

![](http://i.imgur.com/joTqglL.png)

## Training

RBF networks are typically trained in a two-stage process. 

- First, the number k of hidden units is determined and each hidden unit *u* is defined by choosing the values of x<sub>*u*</sub> and variance that define its kernel function K.
- Second, the weights w<sub>*u*</sub> are trained to maximize the fit of the network to the training data, using the global error criterion. Backpropagation can be used in this step and it is more efficient for RBG than it is for MLP as  the kern functions are held fixed.

## How are the u hidden units selected ?

**Aproach 1:** Allocate a gaussian kernel function for each training example centering at themselves. Each kernel may be assigned the same width. This has an advantage that the RBFN can fit the training data exactly.

**Aproach 2:** Choose a set of kernel functions that is smaller than the number of training examples. The set of kernel functions may be distributed with centers spaced uniformly throughout the instance space X. Alternatively, we can choose to distribute the centers nonuniformly which may mean selecting in random fashion.

**Approach 3:** We can identify prototypical clusters of instances, then add a kernel function centerd at each cluster.