
<!-- README.md is generated from README.Rmd. Please edit that file -->

# classy

[![Travis build
status](https://travis-ci.org/USCbiostats/classy.svg?branch=master)](https://travis-ci.org/USCbiostats/classy)
[![AppVeyor build
status](https://ci.appveyor.com/api/projects/status/github/USCbiostats/classy?branch=master&svg=true)](https://ci.appveyor.com/project/USCbiostats/classy)
[![lifecycle](https://img.shields.io/badge/lifecycle-experimental-orange.svg)](https://www.tidyverse.org/lifecycle/#experimental)
[![CRAN
status](https://www.r-pkg.org/badges/version/classy)](https://cran.r-project.org/package=classy)

This R package illustrates how to work with classes and `Rcpp::XPtr`
objects in R and Rcpp.

The R package includes documentation using
[roxygen2](https://cran.r-project.org/package=roxygen2), so the `Rd`
files in the `man` folder were generated automatically by it.

## Two types of examples

By default, all the `Rcpp::` objects that are mapped to R objects
provide pointers instead of *deep copies*, which translates in efficient
memory management and speed. The problem is that whenever you start
using objects other than `NumericMatrix`, `NumericVector`,
`IntegerMatrix`, etc. Rcpp generates copies of these objects.

The `classy` R package provides two different approaches when working
with C++ classes. The first approach, `classy1`, more simple but
inefficient, uses `std::vector< double >` member objects, which makes
`Rcpp` duplicate the object that you are passing when creating the
class. This should be OK whenever you don’t care about memory usage,
otherwise, if you are dealing with large memory objects (i.e. something
that occupies a couple of gigs in your computer).

You can take a look at the source of the files:

  - Header [classy1.h](src/classy1.h)
  - Implementation [classy1.cpp](src/classy1.cpp)
  - R wrappers (with Rcpp::XPtr) [R-wrappers1.cpp](src/R-wrappers1.cpp)

The second method provided, `classy3` (there will be an intermediate),
uses `NumericVector` wrapped around smart pointers, in particular,
[`std::shared_ptr`](https://en.cppreference.com/w/cpp/memory/shared_ptr)
instead, but it is also implemented using [class
templates](https://en.wikipedia.org/wiki/Template_\(C%2B%2B\)#Class_templates).
This is a more appropiate approach when dealing with large objects since
data is never duplicated.

You can take a look at the source of the files:

  - Header [classy3.h](src/classy3.h)
  - Implementation [classy3.cpp](src/classy3.cpp)
  - R wrappers (with Rcpp::XPtr) [R-wrappers3.cpp](src/R-wrappers3.cpp)

## Installation

``` r
devtools::install_github("USCbiostats/classy")
```

## Example 1: Using `classy1` (i.e. duplicating memory)

``` r

# loading the package
library(classy)

set.seed(1)
obj <- new_classy1(runif(10))

# Getting the sum
classy_sum1(obj)
#> [1] 5.515139

# Counting
classy_count1(obj)
#> [1] 10

# Conditional count
classy_count_if_less1(obj, 0.5)
#> [1] 4

# The object
classy_get1(obj)
#>  [1] 0.26550866 0.37212390 0.57285336 0.90820779 0.20168193 0.89838968
#>  [7] 0.94467527 0.66079779 0.62911404 0.06178627
```

## Example 2: Using `classy3` (i.e. using smart pointers)

``` r

# loading the package
library(classy)

set.seed(1)
obj <- new_classy3(runif(10))

# Getting the sum
classy_sum3(obj)
#> [1] 5.515139

# Counting
classy_count3(obj)
#> [1] 10

# Conditional count
classy_count_if_less3(obj, 0.5)
#> [1] 4

# The object
classy_get3(obj)
#>  [1] 0.26550866 0.37212390 0.57285336 0.90820779 0.20168193 0.89838968
#>  [7] 0.94467527 0.66079779 0.62911404 0.06178627
```
