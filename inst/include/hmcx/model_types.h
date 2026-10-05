
# pragma once

//// File Name: model_types.h
//// File Version: 0.01

// [[Rcpp::depends(RcppEigen)]]
#include <RcppEigen.h>
#include <functional>

struct ModelResult {
	double fn;
	Eigen::VectorXd gr;
};

using ModelFn = std::function<ModelResult(const Eigen::VectorXd&)>;