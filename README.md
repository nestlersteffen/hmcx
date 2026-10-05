# hmcx

This package provides functions implementing a HMC-sampler and a NUTS-Sampler in R and C++. Define your own models in R and C++ with CppAD and then use hmc_chain (hmc_hain_cpp) or nuts_chain (nuts_chain_cpp) to obtain a single chain of the HMC or a NUTS-sampler. Both functions presume that your model is implemented in a function that provides the negative value of the log-posterior and the gradient of this function. 

Note that I implemented these functions to better understand STAN. You are free to use it, but there is no guarantee for correctness. See the examples on how to implement your model and to use the functions.

## Installation

``` r
# install.packages("devtools")
devtools::install_github("nestlersteffen/hmcx")
```

To update, simply rerun the installation command.

## Examples

We use the nuts_chain function to estimate a logistic regression model. To this end, we define a closure that provides the value of the negative log-posterior and the gradient for a parameter vector theta (where theta contains the regressions coefficients). Here is the function: 

``` r

make_logregression <- function( Y=NULL, X=NULL, m=NULL, M=NULL )
{
    function( theta ) {
        #- compute inverse of M:
        invM <- base::solve(M)
        #- compute linear predictor:
        mu <- X%*%theta
        pz <- plogis(mu)
        #- compute posterior components:
        ll <- sum( Y*log( pz ) + ( 1 - Y )*log( 1-pz ) ) 
        lp <- -0.5*( t( theta - m )%*%invM%*%( theta - m ) )
        #- compute gradient:
        gr_ll <- t(X)%*%(Y - pz)
        gr_lp <- invM%*%( theta - m )
        #- make output:
        res <- list( fn=-1*(ll + lp)[1,1], gr=-1*as.vector( gr_ll + gr_lp ) )
        return( res )
    }
}

```

Note that we used a multivariate normal prior for the regression coefficients. We now generate some data, initiale the closure, and then use it to obtain a chain of NUTS-samples. 

``` r

# make some data:

set.seed(1233)
n  <- 500
x  <- rnorm(n,0,1)
y  <- rbinom(n, 1, plogis( 0.5 + 0.2*x ) )

# initialize the closure (m and M are parameters of the prior)

logreg <- make_logregression(Y=y,X=cbind(1,x),m=rep(0,2),M=diag(1,2))

# some initial values for the chain (for the two regression coefficients) 

inits <- c(0, 0)

# define some arguments (see ?make_args):

args  <- make_args( biter=2000, burnin=1000 ) #biter = length of the chain

# do NUTS-sampling:

fit <- nuts_chain_r(model_fn=log_reg, args=args, verbose=TRUE, inits=inits )

# fit is a list, I use coda for the results

summary( coda::mcmc( fit$parms ) )

```

When you are interested in estimating the model with C++ or CppAD, just email me for the code or have a look at the regression.cpp, example.cpp, and exports.cpp file in the scr-folder. All three files contain the functions necessary to fit a linear regression model.

## Contributing

Issues and pull requests are not actively monitored. For questions, 
suggestions, or bug reports, please contact me directly via mail.

## Status

Work in progress.