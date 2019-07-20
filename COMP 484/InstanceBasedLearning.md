# Instance-Based Learning
*(Memory-based learning or Lazy learning)*

- Instance-based learning methods simply store the training examples. 
- Some instance-based learning methods are - Nearest Neighbor and Locally Weighted Regression
- Instances are assumed to be points in Euclidean Space
- Can approximate both real-valued and discrete-valued target functions


## Advantages

- Instead of estimating the target function once for the entire instance space, instace-based learning methods can estimate it locally and differently for each new instance to be classified. This essentially means that these methods can construct a different approximation to the target function for each distinct query instace. This has significant advantages when the target function is very complex, but can still be described by a collection of less complex local approximations.

- It has the ability to adapt its model to previously unseen data. Instance-based learners may simply store a new instance or throw an old instance away. 

## Disadvantage

- Overfitting (Instance reduction algorithms have been proposed to overcome this)

- The cost of classifying new instances grows with the data. In the worst case, a hypothesis is a list of n training items and the computational complexity of classifying a single new instance is O(n).

- These methods consider **all** attributes of the instances when attempting to retrieve similar training examples from memory. If the target concept depends on only a few of the many available attributes, then the instances that are truly most "similar" may well be a large distance apart.

## How it works

- The training instances provided are simply store.
- When a new query instance is encountered, a set of similar related instances is retrieved from memory and used to classify the new query instance.