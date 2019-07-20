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
- Distance is calculated base on *all* attributes of the instances. Due to this many irrelevant attributes might be considered which affects the distance eventually leading to decrease in the accuracy. This difficulty, which arises when many irrelevant attributes are present, is sometimes referred to as the **curse of dimensionality**.
- Doesn't prioritize nearer neighbors

## Remarks on kNN

### Inductive bias of kNN

The inductive bias corresponds to an assumption that the classification of an instance x<sub>q</sub> will be most similar to the classification of other instances that are nearby in Euclidean distance.


### Curse of dimensionality

When an instance is described by a large set of attributes the accuracy and the speed of the algorithm is affected. 

Consider applying kNN to a problem in which each instance is described by 20 attributes, but where only 2 of these attributes are relevant to determine the class of the an instance. In this case, instances that have identical values for the 2 relevant attributes may nevertheless be distant from one another in the 20-dimensional instance space. We can also think of situations where the 2 relevant attributes may differ vastly but then the remaining 18 attributes add up to to lower down the distance between the query instance and the irrelevant training instance.

One approach to overcome this problem is to weight each attribute differently when calculating the distance between two instances. This corresopnds to stretching the axes in the Euclidean space, shortening the axes that correspond to less relevant attributes, and lengthening the axes that correspond to more relevant attributes. Another approach would be to completely eliminate the least relevant attributes from the instance space

### Efficient memory indexing

Because kNN delays all processing until a new query is received, significant computation can be requried to process each new query. Various methods have been developed for indexing the stored training examples so that the nearest neighbors can be identified more efficiently at some additional cost in memory. One such indexing method is the **kd-tree** in which instances are stored at the leaves of a tree with nearby instances stored at the same or nearby nodes.

* * *

## Distance-Weighted Nearest Neighbor Algorithm

- It is a refinement of kNN.
- The distance to the query point from each of the k neighbors are weighted. Greater weight is given to closer neighbors.
- The weight can be taken as the inverse of the square of the distance.
- Since the neighbors are weighted we can consider the entire training instances instead of just *k* of them. However, the algorithm will become much slower. 
- When all the training instances are considered the algorithm is called a **gobal method** and When only *k* training instances are considered the algorithm is called a **local method**.

### Advantages 

- Robust to noisy training data. Since the impact of neighbors are weighted the impact of some isolated noisy training examples are smoothened out.
- Very effective when provided with a sufficiently large set of training data.