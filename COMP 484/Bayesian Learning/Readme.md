# Bayesian Learning

Bayesian reasoning provides a probabilistic approach to inference. It is based on the assumption that the quantities of interest are governed by probability distributions and that optimal decisions can be made by reasoning about these probabilities together with observed data.

### Why study Bayesian Learning ?
- Bayesian learning algorithms such as naive bayes classifier are among the most practical approaches to certain types of learning problems. Their results are comparable to other learning algorithms like decision tree & neural networks and in some cases even better.
- They provide a useful perspective for understanding many learning algorithms that do not explicitly manipulate probabilities.

### Issues
- In practice, it is difficult to know the probabilities, required by Bayesian Algorithms, in advance.
- Significant computational cost is required to determine the Bayes optimal hypothesis in the general case

* * *

# Bayes Theorem

Bayes theorem provides a way to calculate the probability of a hypothesis based on its prior probability, the probabilities of observing various data given the hypothesis, and the observed data itself. Bayes theorem is the cornerstone of Bayesian learning methods because it provides a way to calculate the posterior probability p(*H*|E), from P(*H*) together with P(E) and P(E|*H*). 

Generally, we consider a set of candidate hypotheses *H* and then try to find the most probable hypothesis *h* ∈ H given the observed data D. The best hypothesis *h* is called a *maximum a posteriori* (MAP) hypothesis. We can determine MAP hypothesis (*h*<sub>MAP</sub>) by using Bayes theorem to calculate the posterior probability of each candidate hypothesis.

![](http://i.imgur.com/bAUE6ZF.png)

We dropped the term P(D) in the final step because it is a constant and contributes equally to each candidate hypothesis' posterior probability. If we consider that all candidate hypotheses are equally probable then P(*h*) will also be a constant and can be dropped off the equation. In this case, only P(D|h) contributes to the posterior probability. Any hypothesis that maximizes P(D|*h*) is called a *maximum likelihood* (ML) hypothesis, *h*<sub>ML</sub>.

#### MAP vs ML ?

### Notations

![](https://images.deepai.org/glossary-terms/f2066cfd2c954d739ae0d2bdfe8e614a/posterior.png)

- P(*H*): The initial probability that hypothesis *H* holds, before we have observed the training data
- P(E): Prior probability that evidence E will be observed (i.e., the probability of E given no knowledge about which hypothesis holds)
- P(E|*H*): Probability of observing evidence E given some world in which hypothesis *H* holds
- P(*H*|E): Probability that *H* holds given the observed training data E. It is called **Posterior probability of h** and in machine learning problems this is what we are interested in.

* * *

## Probabilistic Models vs Non-Probabilistic Models

## Discriminative Models vs Generative Models

- Given an input data x and labels y - A generative model learns the joint probability distribution p(x,y) and a discriminative model learns the conditional probability distribution p(y|x).
- Discriminative models generally outperform generative models in classification tasks.

![](https://i.stack.imgur.com/Xrmqg.png)

* * *

# Bayes Theorem & Concept Learning

Since Bayes Theorem provides a principled way to calculate the posterior probability of each hypothesis given the training data, we can use it as the basis for a straightforward learning algorithm that calculates the probability for each possible hypothesis, then outputs the most probable.
