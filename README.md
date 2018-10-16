
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

## Installation

``` r
devtools::install_github("USCbiostats/classy")
```

## Example

Here is a basic example.

``` r

# loading the package
library(classy)

set.seed(1)
obj <- new_classy(runif(10))

# Getting the sum
classy_sum(obj)
#> [1] 5.515139

# Counting
classy_count(obj)
#> [1] 10

# Conditional count
classy_count_if_less(obj, 0.5)
#> [1] 4

# The object
classy_get(obj)
#>  [1] 0.26550866 0.37212390 0.57285336 0.90820779 0.20168193 0.89838968
#>  [7] 0.94467527 0.66079779 0.62911404 0.06178627
```