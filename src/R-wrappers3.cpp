#include <Rcpp.h>
#include "classy3.h"

using namespace Rcpp;

//' The `classy3` C++ class (uses smart pointers)
//' @param x A numeric vector.
//' @param p A pointer to a classy3 object.
//' @param y Numeric scalar.
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
//' @name classy3-class
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
SEXP new_classy3(NumericVector x) {

  std::shared_ptr<NumericVector> x_ = std::make_shared<NumericVector>(x);

  return wrap(Rcpp::XPtr< classy3<NumericVector> >(new classy3<NumericVector>(x_) , true));

}

//' @export
//' @rdname classy3-class
// [[Rcpp::export]]
SEXP classy_get3(SEXP p) {

  Rcpp::XPtr< classy3<NumericVector> > p_(p);

  return wrap(p_->get());

}

//' @export
//' @rdname classy3-class
// [[Rcpp::export]]
int classy_count3(SEXP p) {

  Rcpp::XPtr< classy3<NumericVector> > p_(p);

  return p_->count();

}

//' @export
//' @rdname classy3-class
// [[Rcpp::export]]
double classy_sum3(SEXP p) {

  Rcpp::XPtr< classy3<NumericVector> > p_(p);

  return p_->sum();

}

//' @export
//' @rdname classy3-class
// [[Rcpp::export]]
double classy_count_if_less3(SEXP p, double y) {

  Rcpp::XPtr< classy3<NumericVector> > p_(p);

  return p_->count_if_less(y);

}

//' @export
//' @rdname classy3-class
// [[Rcpp::export(invisible=true)]]
int classy_get_address3(SEXP p) {

  Rcpp::XPtr< classy3<NumericVector> > p_(p);
  p_->get_address();
  return 0;

}

//' Get the address of an R vector
//' @param x A numeric vector.
//' @export
// [[Rcpp::export(invisible = true)]]
int get_address(const NumericVector & x) {

  Rprintf("Address of x[1] (NumericVector): %p\n",  (void*) &(x[0u]) );
  return 0;

}
