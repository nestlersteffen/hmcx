
# pragma once

//// File Name: hmc.h
//// File Version: 0.01

// [[Rcpp::depends(RcppEigen)]]
#include <RcppEigen.h>
#include <hmcx/model_types.h>
#include "leapfrog.h"
#include "helpers.h"

struct HmcState {
    Eigen::VectorXd theta;
    double alpha;
    int accept;
    bool divergent;
};

HmcState hmc_step( Eigen::VectorXd current_theta, const ModelFn& model_fn,
    const Eigen::VectorXd& M, const Eigen::VectorXd& invM, double epsilon, int L );