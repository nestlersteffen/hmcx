
# pragma once

//// File Name: helpers.h
//// File Version: 0.01

// [[Rcpp::depends(RcppEigen)]]
#include <RcppEigen.h>
#include "model_types.h"
#include "leapfrog.h"

double compute_H( const Eigen::VectorXd& theta, const Eigen::VectorXd& r,
    const ModelFn& model_fn, const Eigen::VectorXd& invM );

double compute_H( const Eigen::VectorXd& r, const Eigen::VectorXd& invM, double fn_val );

Eigen::VectorXd get_impulse(const Eigen::VectorXd& M);

double find_reasonable_epsilon( const Eigen::VectorXd& theta, const ModelFn& model_fn,
    const Eigen::VectorXd& M, const Eigen::VectorXd& invM );