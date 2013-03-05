/** 
    Daniel Alabi
    Bloom filter implementation based on paper
    by Almeida et al
**/

// define some constants
# define LONG_PRIME 32993
# define MIN(a,b)  (a < b ? a : b)

/** BloomFilter class definition here **/
class  BloomFilter{
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

  // total count of items added so far
  unsigned int total; 

  // array of arrays of counters
  bool **C;

  // array of hash values for a particular item 
  // contains two element arrays {aj,bj}
  int **hashes;

  // generate "new" aj,bj
  void genajbj(int **hashes, int i);

public:
  // constructor
  BloomFilter(float eps, float gamma);
  
  // adds item (int) to the bloomfilter
  void add(int item);
  // adds item (string) to the bloom filter
  void add(const char *item);

  // returns True if item is probably in the filter
  // might return a false positive; never a false negative
  bool contains(int item);
  bool contains(const char *item);

  // returns the number of items stored in bloomfilter
  unsigned int totalcount();

  // generates a hash value for a string
  // same as djb2 hash function
  unsigned int hashstr(const char *str);

  // destructor
  ~BloomFilter();
};


