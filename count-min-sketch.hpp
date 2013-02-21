class CountMinSketch {
  // width, depth 
  int w,d;
  
  // eps (for error), 0.01 < eps < 1
  // the smaller the better
  float eps;
  
  // gamma (probability for accuracy), 0 < gamma < 1
  // the bigger the better
  float gamma;
  
  // p_gen (prime generator)
  // use in generation of hash function
  int p_gen;

  // aj, bj \in Z_p
  // both elements of fild Z_p used in generation of hash
  // function
  int aj, bj;

  // total count so far
  int total; 

  // array of arrays of counters
  int** C;

  // array of hash functions
  // int *hashes
public:
  // update item i by count c
  void update(int i, int c);
  // estimate count of item i and return count
  int estimate(int i);
}
