
# pragma once

//// File Name: leapfrog.h
//// File Version: 0.01

// [[Rcpp::depends(RcppEigen)]]
#include <RcppEigen.h>
#include "model_types.h"

struct LeapfrogState {
    Eigen::VectorXd theta;
    Eigen::VectorXd r;
    double fn;
    Eigen::VectorXd gr;
};

LeapfrogState leapfrog_step( const Eigen::VectorXd& theta, const Eigen::VectorXd& r,
    const ModelFn& model_fn, const Eigen::VectorXd& invM, double epsilon,
    int direction = 1 );
 
LeapfrogState leapfrog( Eigen::VectorXd& theta, Eigen::VectorXd& r, const ModelFn& model_fn,
    const Eigen::VectorXd& invM, double epsilon, int L );