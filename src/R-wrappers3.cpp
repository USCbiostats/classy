#include <Rcpp.h>
#include "classy3.h"

using namespace Rcpp;

//' The `classy3` C++ class (uses smart pointers)
//' @param x A numeric vector.
//' @return
//' The `new_classy3` function creates an object of C++ class `classy3`. This is
//' an object of class [externalptr-class] in the R side.
//'
//' `classy_sum3` and `classy_count3` return the sum and the count of elements
//' in the `x` vector passed to `new_classy`.
//'
//' `classy_count_if3` returns the count of elements in `x` if these are less
//' than `y`.
//'
//' `classy_get3` returns the original vector `x` passed to `new_classy`.
//' @export
//' @aliases classy3 classy3-class
//' @examples
//'
//' # Creating a new object
//' set.seed(1)
//' obj <- new_classy3(runif(10))
//'
//' # Getting the sum
//' classy_sum3(obj)
//'
//' # Counting
//' classy_count3(obj)
//'
//' # Conditional count
//' classy_count_if_less3(obj, 0.5)
//'
//' # The object
//' classy_get3(obj)
//'
//' # Removing
//' rm(obj)
//'
//' # If we call the garbage collector, you can see the destructor been called
//' gc()
// [[Rcpp::export]]
SEXP new_classy3(NumericVector x_) {

  std::shared_ptr<NumericVector> x = std::make_shared<NumericVector>(x_);

  return wrap(Rcpp::XPtr< classy3<NumericVector> >(new classy3<NumericVector>(x) , true));

}

//' @export
//' @rdname new_classy
// [[Rcpp::export]]
SEXP classy_get3(SEXP p_) {

  Rcpp::XPtr< classy3<NumericVector> > p(p_);

  return wrap(p->get());

}

//' @export
//' @rdname new_classy
// [[Rcpp::export]]
int classy_count3(SEXP p_) {

  Rcpp::XPtr< classy3<NumericVector> > p(p_);

  return p->count();

}

//' @export
//' @rdname new_classy
// [[Rcpp::export]]
double classy_sum3(SEXP p_) {

  Rcpp::XPtr< classy3<NumericVector> > p(p_);

  return p->sum();

}

//' @export
//' @rdname new_classy
// [[Rcpp::export]]
double classy_count_if_less3(SEXP p_, double y) {

  Rcpp::XPtr< classy3<NumericVector> > p(p_);

  return p->count_if_less(y);

}

