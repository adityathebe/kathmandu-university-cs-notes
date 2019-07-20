# *k*-Nearest Neighbor

- Is the most basic instance-based learning method
- Assumes all instances correspond to points in the n-dimensional Euclidean space
- Nearest neighbors of an instance are defined in terms of the Euclidean distance
- The target function can be either discrete-valued or real-valued

### Voronoi Tesselation

- The entire instance space is partitioned. Each partition is a convex polyhedra. 
- For each training instance there's a corresponding partition.
- Every partition  indicates the set of query points whose classification will be completely determined by that training example.
- the Voronoi diagram is different for a different values of k for a given training set.