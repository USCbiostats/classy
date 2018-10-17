#include <Rcpp.h>
#include "classy1.h"

using namespace Rcpp;

//' The `classy1` C++ class (copies R objects)
//' @param x A numeric vector.
//' @return
//' The `new_classy1` function creates an object of C++ class `classy`. This is
//' an object of class [externalptr-class] in the R side.
//'
//' `classy_sum1` and `classy_count` return the sum and the count of elements
//' in the `x` vector passed to `new_classy`.
//'
//' `classy_count_if1` returns the count of elements in `x` if these are less
//' than `y`.
//'
//' `classy_get1` returns the original vector `x` passed to `new_classy`.
//' @export
//' @aliases classy1 classy1-class
//' @examples
//'
//' # Creating a new object
//' set.seed(1)
//' obj <- new_classy1(runif(10))
//'
//' # Getting the sum
//' classy_sum1(obj)
//'
//' # Counting
//' classy_count1(obj)
//'
//' # Conditional count
//' classy_count_if_less1(obj, 0.5)
//'
//' # The object
//' classy_get1(obj)
//'
//' # Removing
//' rm(obj)
//'
//' # If we call the garbage collector, you can see the destructor been called
//' gc()
// [[Rcpp::export]]
SEXP new_classy1(std::vector< double > x_) {

  return wrap(Rcpp::XPtr< classy1 >(new classy1(x_), true));

}

//' @export
//' @rdname new_classy
// [[Rcpp::export]]
SEXP classy_get1(SEXP p_) {

  Rcpp::XPtr< classy1 > p(p_);

  return wrap(p->get());

}

//' @export
//' @rdname new_classy
// [[Rcpp::export]]
int classy_count1(SEXP p_) {

  Rcpp::XPtr< classy1 > p(p_);

  return p->count();

}

//' @export
//' @rdname new_classy
// [[Rcpp::export]]
double classy_sum1(SEXP p_) {

  Rcpp::XPtr< classy1 > p(p_);

  return p->sum();

}

//' @export
//' @rdname new_classy
// [[Rcpp::export]]
double classy_count_if_less1(SEXP p_, double y) {

  Rcpp::XPtr< classy1 > p(p_);

  return p->count_if_less(y);

}

