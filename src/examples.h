
# pragma once

//// File Name: examples.h
//// File Version: 0.01

// [[Rcpp::depends(RcppEigen)]]
#include <RcppEigen.h>
#include <cppad/cppad.hpp>
#include <memory>
#include <functional>
#include "model_types.h"
#include "regression.h"
#include "ddm4.h"

ModelFn make_regression_model(const Eigen::VectorXd& y, const Eigen::MatrixXd& X,
    double lambda2, double a, double b);

ModelFn make_regression_model_cppad( const Eigen::VectorXd& theta_init,
    const Eigen::VectorXd& y, const Eigen::MatrixXd& X,
    double lambda2, double a, double b);

ModelFn make_ddm4_cppad( const Eigen::VectorXd& theta_init,
    const Eigen::VectorXd& rts, const Eigen::VectorXd& xs,
    const Eigen::VectorXd& muPrior_sp, const Eigen::VectorXd& sdPrior_sp,
    const double min_rt, const double s2, const int kmax );