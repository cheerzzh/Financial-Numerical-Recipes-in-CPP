#include "fin_recipes.h"

double option_price_american_put_approximated_bjerksund_stensland( const double& S, 
								   const double& X, 
								   const double& r, 
								   const double& q,
								   const double& sigma, 
								   const double& T ){
    return option_price_american_call_approximated_bjerksund_stensland(X,S,r-(r-q),r-q,sigma,T);
};

