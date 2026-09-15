
#include "leapfrog.h"

// function to compute a single leapfrog-step
 
LeapfrogState leapfrog_step( const Eigen::VectorXd& theta, const Eigen::VectorXd& r,
    const ModelFn& model_fn, const Eigen::VectorXd& invM,  double epsilon, int direction )
{
    // first half kick:
    ModelResult res0 = model_fn( theta );
    Eigen::VectorXd r_new = r - direction * (epsilon / 2.0) * res0.gr;
 
    // drift
    Eigen::VectorXd theta_new = theta + direction * epsilon * ( invM.array() * r_new.array() ).matrix();
 
    // second half kick
    ModelResult res1 = model_fn( theta_new );
    r_new = r_new - direction * (epsilon / 2.0) * res1.gr;
 
    // make output:
    LeapfrogState out;
    out.theta = theta_new;
    out.r     = r_new;
    out.fn    = res1.fn;
    out.gr    = res1.gr;
    return out;
}
 
// make L leapfrog-steps (in case of hmc ) 
 
LeapfrogState leapfrog( Eigen::VectorXd& theta, Eigen::VectorXd& r,
    const ModelFn& model_fn, const Eigen::VectorXd& invM, double epsilon, int L )
{
    LeapfrogState state;
    for ( int i = 0; i < L; i++ ) {
        state = leapfrog_step( theta, r, model_fn, invM, epsilon, 1 );
        theta = state.theta;
        r     = state.r;
    }
    return state;
}