# *k*-Nearest Neighbor

- Is the most basic instance-based learning method
- Assumes all instances correspond to points in the n-dimensional Euclidean space
- Nearest neighbors of an instance are defined in terms of the Euclidean distance. *Manhattan distance* and *Cosine similarity* are other different methods to measure distance.
- The target function can be either discrete-valued or real-valued

### Voronoi Tesselation

![](http://i.imgur.com/OlkyQp0.png)

- The entire instance space is partitioned. Each partition is a convex polyhedra. 
- For each training instance there's a corresponding partition.
- Every partition  indicates the set of query points whose classification will be completely determined by that training example.
- For a given training set - the Voronoi diagram is different for a different values of k.

## Discrete-Valued Target Function

- V denotes the finite set of classes { v<sub>1</sub>, v<sub>2</sub>, ..., v<sub>s</sub> }

![](http://i.imgur.com/bfb4QBQ.png)

The first phase in the classification algorithm is simplified. The distance between the query instance x<sub>q</sub> and every training instance is evaluated. And then *k* training instances that are closest to x<sub>q</sub> is selected.

The second phase determines, among the selected *k* training examples, the most prevalent class.

## Real-Valued Target Function

The above algorithm can be modified easily to adapt to approximate continous-valued target functions. Instead of calculating argmax, we simply take the mean of the selected *k* training examples (*from the first phase of the classification algorithm*)

![](http://i.imgur.com/L6OMLOK.png)

## Issues with kNN

- Which distance function performs better ?
- How to find the closest points quickly ?
- Attributes of the instances are not weighted
- Doesn't prioritize nearer neighbors

* * *

## Distance-Weighted Nearest Neighbor Algorithm

- It is a refinement of kNN.
- The distance to the query point from each of the k neighbors are weighted. Greater weight is given to closer neighbors.
- The weight can be taken as the inverse of the square of the distance.
- Robust to noisy training data
- Since the neighbors are weighted we can consider the entire training instances instead of just *k* of them. However, the algorithm will become much slower. 
- When all the training instances are considered the algorithm is called a **gobal method** and When only *k* training instances are considered the algorithm is called a **local method**.