Count-Min Sketch
================

Count-Min Sketch is a probabilistic sub-linear space streaming algorithm
 which can be used to summarize a data stream in different ways. It's 
mostly used to find **Heavy Hiiters** in a data set. This data structure
is pretty recent, as it was introduce in 2003. Sine then, it has inspired
many applications, extensions, and variations.

This probabilistic data structure was first proposed by Muthukrishnan
and Cormode (see references below for more details).

Count-Min Sketch Internals
--------------------------

The data structure primarily consists of a fixed array of counters, of 
width *w* and depth *d*. Every entry is called a counter.
 The counters are initialized to all zeros.
Each row of counters is associated with a different hash function (out
of k-pairwise independent hash functions). The hash function maps items
uniformly onto the range {1,2,...,w}. The hash functions do not need to be 
particularly strong or as complex as cryptographic hash functions. So you
can just use a linear hash. But is important that the hash function 
for each row be distinct.

There are two main operations: UPDATE(i,c), ESTIMATE(i). UPDATE(i,c)
updates (incremenets) the count associated with the item *i*. On the other 
hand, ESTIMATE(i) returns an estimate of the count associated with an 
item *i*.

For more details on the data structure internals, see the summary in this
repository.

References
----------
* [Count-Min Sketch and its Applications](https://sites.google.com/site/countminsketch)

* [Count-Min Sketch on Wikipedia] (https://en.wikipedia.org/wiki/Count-Min_sketch)

* [Approximating Data with the Count-Min Data Structure] (http://dimacs.rutgers.edu/graham/pubs/papers/cmsoft.pdf)

* [An improved Data Stream Summary: the Count-Min Sketch and its Applications] (http://www.research.att.com/people/Cormode.Graham/library/publicationsCormodeMuthukrishnan)