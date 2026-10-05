# pragma once

//// File Name: nuts.h
//// File Version: 0.01

// [[Rcpp::depends(RcppEigen)]]
#include <RcppEigen.h>
#include <cppad/cppad.hpp>
#include <hmcx/model_types.h>

inline constexpr double DDM_PI = 3.14159265358979323846;

CppAD::AD<double> ddm4_dstand( const CppAD::AD<double>& t, const CppAD::AD<double>& a, 
    const CppAD::AD<double>& w, const CppAD::AD<double>& v, const double& s2, 
    const int& kmax );

CppAD::ADFun<double> ddm4_tape( const Eigen::VectorXd& theta, const Eigen::VectorXd& rts, 
    const Eigen::VectorXd& xs, const Eigen::VectorXd& muPrior_sp, const Eigen::VectorXd& sdPrior_sp,
    const double min_rt, const double s2, const int kmax );