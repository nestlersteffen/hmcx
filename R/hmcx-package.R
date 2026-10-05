#' hmcx: Collection of functions for HMC- and NUTS-sampling
#'
#' @description Provides functions implementing a HMC-sampler and a NUTS-Sampler in R and C++. 
#'              Define your own functions in R and C++ with CppAD to obtain Bayesian estimates 
#'              with HMC or NUTS
#'
#' @keywords internal
#' @useDynLib hmcx, .registration = TRUE
#' @import Rcpp
#' @import RcppEigen
#' @import stats
#' @import utils
"_PACKAGE"