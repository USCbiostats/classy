#include <Rcpp.h>
#include "classy3.h"

/*
 An explicit instantiation declaration (an extern template) skips implicit
 instantiation step: the code that would otherwise cause an implicit instantiation
 instead uses the explicit instantiation definition provided elsewhere (resulting
 in link errors if no such instantiation exists). This can be used to reduce
 compilation times by explicitly declaring a template instantiation in all but
 one of the source files using it, and explicitly defining it in the remaining
 file.
 source: https://en.cppreference.com/w/cpp/language/class_template
 */
template class classy3<Rcpp::NumericVector>;
// template class classy<std::vector<double>>;


// Counts the number of elements in x
template <class T> int classy3< T >::count() {
  return x->size();
}

// Sums the vector x
template <class T> double classy3< T >::sum() {
  return std::accumulate(x->begin(), x->end(), 0.0);
}

// Counting if less than y
template<> int classy3< Rcpp::NumericVector >::count_if_less(double y) {

  int ans = 0;
  for (Rcpp::NumericVector::const_iterator it = x->begin(); it != x->end(); ++it)
    if (*it <= y)
      ans++;

  return ans;

}

// Returning the vector `x`. We don't actually need to use the `this->` part,
// but is a nice example of `this->` :).
template<class T> T classy3< T >::get() {
  return *x;
}

