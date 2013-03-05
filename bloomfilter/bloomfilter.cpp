# include <iostream>
# include <cmath>
# include <cstdlib>
# include <ctime>
# include "bloomfilter.hpp"
using namespace std;

/**
   Class definition for BloomFilter.
   public operations:
   // overloaded add
   void add(int item);
   void add(char *item);
   // overloaded contains
   unsigned int contains(int item);
   unsigned int contains(char *item);
**/


// BloomFilter constructor
// ep -> error 0.01 < ep < 1 (the smaller the better)
// gamma -> probability for error (the smaller the better) 0 < gamm < 1
BloomFilter::BloomFilter(float ep, float gamm) {
  if (!(0.009 <= ep && ep < 1)) {
    cout << "eps must be in this range: [0.01, 1)" << endl;
    exit(EXIT_FAILURE);
  } else if (!(0 < gamm && gamm < 1)) {
    cout << "gamma must be in this range: (0,1)" << endl;
    exit(EXIT_FAILURE);
  }
  eps = ep;
  gamma = gamm;
  w = ceil(exp(1)/eps);
  d = ceil(log(1/gamma));
  total = 0;
  // initialize counter array of arrays, C
  C = new bool *[d];
  unsigned int i, j;
  for (i = 0; i < d; i++) {
    C[i] = new bool[w];
    for (j = 0; j < w; j++) {
      C[i][j] = false;
    }
  }
  // initialize d pairwise independent hashes
  srand(time(NULL));
  hashes = new int* [d];
  for (i = 0; i < d; i++) {
    hashes[i] = new int[2];
    genajbj(hashes, i);
  }
}

// BloomFilter destructor
BloomFilter::~BloomFilter() {
  // free array of counters, C
  unsigned int i;
  for (i = 0; i < d; i++) {
    delete[] C[i];
  }
  delete[] C;
  
  // free array of hash values
  for (i = 0; i < d; i++) {
    delete[] hashes[i];
  }
  delete[] hashes;
}

// add item (int) to filter
void BloomFilter::add(int item) {
  total = total + 1;
  unsigned int hashval = NULL;
  for (unsigned int j = 0; j < d; j++) {
    hashval = (hashes[j][0]*item+hashes[j][1])%w;
    C[j][hashval] = true;
  }
}

// add item (string) to filter
void BloomFilter::add(const char *str) {
  int hashval = hashstr(str);
  add(hashval);
}

// returns True if item (int) is probably in the bloom filter
// returns False if item (int) is definitely not in the bloom filter
bool BloomFilter::contains(int item) {
  unsigned int hashval = NULL;
  for (unsigned int j = 0; j < d; j++) {
    hashval = (hashes[j][0]*item+hashes[j][1])%w;
    if (!C[j][hashval]) {
      return false;
    }
  }
  return true;
}

// returns True if item (string) is probably in the bloom filter
// returns False if item (string) is definitely not in the bloom filter
bool BloomFilter::contains(const char *str) {
  int hashval = hashstr(str);
  return contains(hashval);
}

// returns the total count of items added to bloom filter
unsigned int BloomFilter::totalcount() {
  return total;
}

// generates aj,bj from field Z_p for use in hashing
void BloomFilter::genajbj(int** hashes, int i) {
  hashes[i][0] = int(float(rand())*float(LONG_PRIME)/float(RAND_MAX) + 1);
  hashes[i][1] = int(float(rand())*float(LONG_PRIME)/float(RAND_MAX) + 1);
}

// generates a hash value for a sting
// same as djb2 hash function
unsigned int BloomFilter::hashstr(const char *str) {
  unsigned long hash = 5381;
  int c;
  while (c = *str++) {
    hash = ((hash << 5) + hash) + c; /* hash * 33 + c */
  }
  return hash;
}


