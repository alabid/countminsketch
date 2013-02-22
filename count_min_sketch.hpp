# define LONG_PRIME 32993
# define MIN(a,b)  (a < b ? a : b)

class CountMinSketch {
  // width, depth 
  unsigned int w,d;
  
  // eps (for error), 0.01 < eps < 1
  // the smaller the better
  float eps;
  
  // gamma (probability for accuracy), 0 < gamma < 1
  // the bigger the better
  float gamma;
  
  // aj, bj \in Z_p
  // both elements of fild Z_p used in generation of hash
  // function
  unsigned int aj, bj;

  // total count so far
  unsigned int total; 

  // array of arrays of counters
  int** C;

  // array of hash values for a particular item 
  // contains two element arrays {aj,bj}
  int **hashes;

  // generate "new" aj,bj
  void genajbj(int** hashes, int i);
public:
  // constructor
  CountMinSketch(float eps, float gamma);
  
  // update item i by count c
  void update(int i, int c);
  // estimate count of item i and return count
  unsigned int estimate(int i);
};

int main(int argc, char **argv);

