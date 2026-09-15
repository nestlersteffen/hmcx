# pragma once

//// File Name: nuts.h
//// File Version: 0.01

// [[Rcpp::depends(RcppEigen)]]
#include <RcppEigen.h>
#include "model_types.h"
#include "leapfrog.h"
#include "helpers.h"

struct NutsState {
    Eigen::VectorXd theta;
    double alpha;
    int j;
    int n_steps;
    bool divergent;
    Eigen::VectorXd divergent_theta;
};

NutsState nuts_step( Eigen::VectorXd current_theta, const ModelFn& model_fn,
    const Eigen::VectorXd& M, const Eigen::VectorXd& invM, double epsilon, int max_depth );
