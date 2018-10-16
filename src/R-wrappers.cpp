#include <Rcpp.h>
#include "classy.h"

using namespace Rcpp;

//' The `classy` C++ class
//' @param x A numeric vector.
//' @return
//' The `new_classy` function creates an object of C++ class `classy`. This is
//' an object of class [externalptr-class] in the R side.
//'
//' `classy_sum` and `classy_count` return the sum and the count of elements
//' in the `x` vector passed to `new_classy`.
//'
//' `classy_count_if` returns the count of elements in `x` if these are less
//' than `y`.
//'
//' `classy_get` returns the original vector `x` passed to `new_classy`.
//' @export
//' @aliases classy classy-class
//' @examples
//'
//' # Creating a new object
//' set.seed(1)
//' obj <- new_classy(runif(10))
//'
//' # Getting the sum
//' classy_sum(obj)
//'
//' # Counting
//' classy_count(obj)
//'
//' # Conditional count
//' classy_count_if_less(obj, 0.5)
//'
//' # The object
//' classy_get(obj)
//'
//' # Removing
//' rm(obj)
//'
//' # If we call the garbage collector, you can see the destructor been called
//' gc()
// [[Rcpp::export]]
SEXP new_classy(std::vector< double > x_) {

  return wrap(Rcpp::XPtr< classy >(new classy(x_), true));

}

//' @export
//' @rdname new_classy
// [[Rcpp::export]]
SEXP classy_get(SEXP p_) {

  Rcpp::XPtr< classy > p(p_);

  return wrap(p->get());

}

//' @export
//' @rdname new_classy
// [[Rcpp::export]]
int classy_count(SEXP p_) {

  Rcpp::XPtr< classy > p(p_);

  return p->count();

}

//' @export
//' @rdname new_classy
// [[Rcpp::export]]
double classy_sum(SEXP p_) {

  Rcpp::XPtr< classy > p(p_);

  return p->sum();

}

//' @export
//' @rdname new_classy
// [[Rcpp::export]]
double classy_count_if_less(SEXP p_, double y) {

  Rcpp::XPtr< classy > p(p_);

  return p->count_if_less(y);

}

