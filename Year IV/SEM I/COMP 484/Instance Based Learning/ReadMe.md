# Instance-Based Learning
*(Memory-based learning)*

- Instance-based learning methods simply store the training examples *< x<sub>i</sub>, f(x<sub>i</sub>) >*
- Some instance-based learning methods are - Nearest Neighbor and Locally Weighted Regression
- Instances are assumed to be points in Euclidean Space. Or in case of case-based reasoning, which is another approach to instance-based learning, the instances are represented by complex logical descriptions rather than points in a Euclidean space.
- Can approximate both real-valued and discrete-valued target functions

## Advantages

- Instead of estimating the target function once for the entire instance space, instace-based learning methods can estimate it locally and differently for each new instance to be classified. This essentially means that these methods can construct a different approximation to the target function for each distinct query instace. This has significant advantages when the target function is very complex, but can still be described by a collection of less complex local approximations.

- It has the ability to adapt its model to previously unseen data. Instance-based learners may simply store a new instance or throw an old instance away. 

## Disadvantage

- Overfitting (*Instance reduction algorithms have been proposed to overcome this*)

- The cost of classifying new instances grows with the data. In the worst case, a hypothesis is a list of n training items and the computational complexity of classifying a single new instance is O(n).

- These methods consider **all** attributes of the instances when attempting to retrieve similar training examples from memory. If the target concept depends on only a few of the many available attributes, then the instances that are truly most "similar" may well be a large distance apart.

## How it works

- The training instances provided are simply stored.
- When a new query instance is encountered, a set of similar related instances is retrieved from memory and is used to classify the new query instance.

## Lazy Learning vs Eager Learning

**Lazy Learning**:
- Just store data set without learning from it
- Starts classifying data when it receives the test data
- Takes less time learning and more time classifying data
- Ex. k-nearest neighbor, Case-based reasoning

**Eager Learning**:
- Eager learners construct a classification model based on the given training data before receiving data for classification.
- Due to the model construction, eager learners take a long time for train and less time to predict.
- Ex. Decision Tree, Naive Bayes, Artificial Neural Networks