# pragma once

//// File Name: regression.h
//// File Version: 0.01

// [[Rcpp::depends(RcppEigen)]]
#include <RcppEigen.h>
#include <cppad/cppad.hpp>
#include "model_types.h"

ModelResult regression( const Eigen::VectorXd& theta, 
	const Eigen::VectorXd& y, const Eigen::MatrixXd& X,
	const double lambda2, const double a, const double b );

CppAD::ADFun<double> regression_tape(
    const Eigen::VectorXd& theta, 
    const Eigen::VectorXd& y, const Eigen::MatrixXd& X, 
    const double a, const double b, const double lambda2 );