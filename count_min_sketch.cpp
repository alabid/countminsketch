# include <iostream>
# include <cmath>
# include <cstdlib>
# include <ctime>
# include <limits>
# include "count_min_sketch.hpp"

using namespace std;

/**
   Class definition for CountMinSketch.
   todos:
   C++ destructors
   Comments!
   optimize data structures (unsigned!)
   use standard C++ style!
   Lots of tests!
   Code to handle strings, int, floats, all pre-specified.
   Update documentation!
**/
CountMinSketch::CountMinSketch(float ep, float gamm) {
  eps = ep;
  gamma = gamm;
  w = ceil(exp(1)/eps);
  d = ceil(log(1/gamma));
  total = 0;

  // initialize counter array of arrays, C
  C = new int* [d];
  unsigned int i, j;
  for (i = 0; i < d; i++) {
    C[i] = new int[w];
    for (j = 0; j < w; j++) {
      C[i][j] = 0;
    }
  }
  // initialize d pairwise independent hashes
  srand(time(NULL));
  hashes = new int*[d];
  for (i = 0; i < d; i++) {
    hashes[i] = new int[2];
    genajbj(hashes, i);
  }
}

void CountMinSketch::update(int i, int c) {
  total = total + c;
  unsigned int hashval = NULL;
  for (unsigned int j = 0; j < d; j++) {
    hashval = (hashes[j][0]*i+hashes[j][1])%w;
    C[j][hashval] = C[j][hashval] + c;
  }
}

unsigned int CountMinSketch::estimate(int i) {
  int minval = numeric_limits<int>::max();
  unsigned int hashval = NULL;
  for (unsigned int j = 0; j < d; j++) {
    hashval = (hashes[j][0]*i+hashes[j][1])%w;
    minval = MIN(minval, C[j][hashval]);
  }
  return minval;
}

void CountMinSketch::genajbj(int** hashes, int i) {
  hashes[i][0] = float(rand())*float(LONG_PRIME)/float(RAND_MAX) + 1;
  hashes[i][1] = float(rand())*float(LONG_PRIME)/float(RAND_MAX) + 1;  
}

int main(int argc, char **argv) {
  CountMinSketch sketch(0.1, 0.01);
  sketch.update(1, 3);
  sketch.update(50, 6);
  sketch.update(2, 5);
  sketch.update(1, 3);
  cout << "there are " << sketch.estimate(1) << " 1's" << endl;
  cout << "there are " << sketch.estimate(50) << " 50's" << endl;
  cout << "there are " << sketch.estimate(2) << " 2's" << endl;
  cout << "there are " << sketch.estimate(5) << " 5's" << endl;
  return 0;
}

