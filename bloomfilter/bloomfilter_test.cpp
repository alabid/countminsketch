# include <iostream>
# include <algorithm>
# include <vector>
# include <cstdlib>
# include <cmath>
# include "bloomfilter.hpp"
using namespace std;

// run basic tests on BloomFilter
int main(int argc, char **argv) {
  vector<const char *> vec_str;
  vector<const char*>::iterator it;
  BloomFilter::BloomFilter b(0.01, 0.1);
  unsigned int i;

  const char *ar_str[] = {
    "hello", "some", "one", "hello", "alice",
    "one", "lady", "let", "us", "lady",
    "alice", "in", "wonderland", "us", "lady",
    "lady", "some", "hello", "none", "pie"
  };
  for (i = 0; i < 20; i++) {
    if (find(vec_str.begin(), vec_str.end(), ar_str[i]) == vec_str.end()) {
      vec_str.push_back(ar_str[i]);
    }
    b.add(ar_str[i]);
  }
  
  // 1. test for items in ar_str
  // note: since probablistic (and not deterministic)
  // might not be accurate sometimes 
  for (it = vec_str.begin(); it != vec_str.end(); it++) {
    if (!b.contains(*it)) {
      cout << "Incorrect";
    } else {
      cout << "Correct";
    }
    cout << " answer for '" << *it << "'" << endl;
  }

  // 2. print out total number of items inserted into BloomFilter
  cout << "Total number of items inserted: " << b.totalcount() << endl;
  
  // 3. test for items not in ar_str
  cout << "Testing for strings not in ar_str..." << endl;
  cout << "Contains 'blabla'? " <<  (b.contains("blabla") ? "True" : "False") << endl;
  cout << "Contains 'yoyo!'? " << (b.contains("yoyo!") ? "True" : "False") << endl;

  return 0;
}


