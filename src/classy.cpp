#include "classy.h"


// Counts the number of elements in x
int classy::count() {
  return x.size();
}


// Sums the vector x
double classy::sum() {
  return std::accumulate(x.begin(), x.end(), 0.0);
}

// Counting if less than y
int classy::count_if_less(double y) {

  int ans = 0;
  for (std::vector< double >::const_iterator it = x.begin(); it != x.end(); ++it)
    if (*it <= y)
      ans++;

  return ans;

}

// Returning the vector `x`. We don't actually need to use the `this->` part,
// but is a nice example of `this->` :).
std::vector< double > classy::get() {
  return this->x;
}
