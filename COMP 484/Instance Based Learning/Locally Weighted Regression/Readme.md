# Locally Weighted Regression

- LWR is a generalization of nearest-neighbor algorithm
- Given a new query instance x<sub>*q*</sub>, LWR constructs an explicit approximation to f over a local region surrounding the query point x<sub>*q*</sub>
- The two issues of kNN are addressed in LWR. Distance are weighted and so are the attributes
- Just like traditional regression method, an approximation function F is evaluated. But F is different for each query point and is calculated only when a new query is encountered. The approximation function F can be linear function, a quadratic function, multilayer neural network, etc

## Locally Weighted Linear Regression

The approximation function is assumed to be a linear function. 

![](http://i.imgur.com/93FgIZL.png)

a<sub>*i*</sub>(x) denotes the value of the i<sup>*th*</sup> attribute of an instance (a<sub>*i*</sub> represents a dimension in the Euclidean space)

Traditionally, we defined an error function - generally Root Mean Square (RMS) value. Gradient descent was used to minimize the error by finding the coefficients w<sub>*i*</sub>.

![](http://i.imgur.com/EHfdzJs.png)

LWR follows similar approach with few simple modifications. Instead of evaluating the error against the entire training examples it is evaluated only for k nearest neighbors. Here are 3 possible ways to define the error function

1. Evaluate error over just k nearest neighbors
2. Evaluate over the entire training set D, while assigning weights to error for each training examples. The weight is assigned based on some decreasing function K of its distance from x<sub>*q*</sub>.
3. Evaluate error over just k nearest neighbors and also weight them.

![](http://i.imgur.com/O5fO8yA.png)

* * *

![](https://storage.googleapis.com/kaggle-competitions/kaggle/4207/logos/front_page.png)