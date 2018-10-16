// Generated by using Rcpp::compileAttributes() -> do not edit by hand
// Generator token: 10BE3573-1514-4C36-9D1C-5A225CD40393

#include <Rcpp.h>

using namespace Rcpp;

// new_classy
SEXP new_classy(std::vector< double > x_);
RcppExport SEXP _classy_new_classy(SEXP x_SEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< std::vector< double > >::type x_(x_SEXP);
    rcpp_result_gen = Rcpp::wrap(new_classy(x_));
    return rcpp_result_gen;
END_RCPP
}
// classy_get
SEXP classy_get(SEXP p_);
RcppExport SEXP _classy_classy_get(SEXP p_SEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< SEXP >::type p_(p_SEXP);
    rcpp_result_gen = Rcpp::wrap(classy_get(p_));
    return rcpp_result_gen;
END_RCPP
}
// classy_count
int classy_count(SEXP p_);
RcppExport SEXP _classy_classy_count(SEXP p_SEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< SEXP >::type p_(p_SEXP);
    rcpp_result_gen = Rcpp::wrap(classy_count(p_));
    return rcpp_result_gen;
END_RCPP
}
// classy_sum
double classy_sum(SEXP p_);
RcppExport SEXP _classy_classy_sum(SEXP p_SEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< SEXP >::type p_(p_SEXP);
    rcpp_result_gen = Rcpp::wrap(classy_sum(p_));
    return rcpp_result_gen;
END_RCPP
}
// classy_count_if_less
double classy_count_if_less(SEXP p_, double y);
RcppExport SEXP _classy_classy_count_if_less(SEXP p_SEXP, SEXP ySEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< SEXP >::type p_(p_SEXP);
    Rcpp::traits::input_parameter< double >::type y(ySEXP);
    rcpp_result_gen = Rcpp::wrap(classy_count_if_less(p_, y));
    return rcpp_result_gen;
END_RCPP
}

static const R_CallMethodDef CallEntries[] = {
    {"_classy_new_classy", (DL_FUNC) &_classy_new_classy, 1},
    {"_classy_classy_get", (DL_FUNC) &_classy_classy_get, 1},
    {"_classy_classy_count", (DL_FUNC) &_classy_classy_count, 1},
    {"_classy_classy_sum", (DL_FUNC) &_classy_classy_sum, 1},
    {"_classy_classy_count_if_less", (DL_FUNC) &_classy_classy_count_if_less, 2},
    {NULL, NULL, 0}
};

RcppExport void R_init_classy(DllInfo *dll) {
    R_registerRoutines(dll, NULL, CallEntries, NULL, NULL);
    R_useDynamicSymbols(dll, FALSE);
}
