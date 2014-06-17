CXX= gcc
CXXFLAGS = -c -O2
 %.o : %.cc
	$(CXX) $(CXXFLAGS) $*.cc

LIBOBJS += cflow_irr.o cflow_irr_test_unique.o cflow_pv.o cflow_pv_discrete.o cflow_irr_discrete.o 

LIBOBJS += termstru_transforms.o termstru_yield_interpolated.o

LIBOBJS += bonds_price_discrete.o bonds_convexity_discrete.o \
           bonds_duration_discrete.o bonds_duration_macaulay_discrete.o bonds_yield_discrete.o

LIBOBJS += bonds_convexity.o bonds_duration.o bonds_duration_macaulay.o \
           bonds_duration_termstru.o bonds_convexity_termstru.o bonds_price_both.o bonds_price.o \
           bonds_price_termstru.o bonds_yield.o bonds_duration_modified.o

LIBOBJS += term_structure_class.o term_structure_class_flat.o term_structure_class_interpolated.o \

LIBOBJS += bin_eur_call_ud_one.o bin_eur_call_ud.o \
           binomial_tree_ud.o 

LIBOBJS += black_scholes_call.o black_scholes_call_div.o black_scholes_delta_call.o  \
           black_scholes_delta_put.o black_scholes_imp_vol_bisect.o black_scholes_imp_vol_newt.o \
           black_scholes_partials_call.o black_scholes_partials_put.o black_scholes_price_payout_call.o \
           black_scholes_price_payout_put.o black_scholes_put.o black_scholes_put_div.o 

LIBOBJS += warrant_price_black_scholes.o warrant_price_black_scholes_dividends.o 

LIBOBJS += bin_am_call.o bin_am_delta_call.o bin_am_delta_put.o bin_am_div_call.o \
           bin_am_div_put.o bin_am_partials_call.o bin_am_partials_put.o bin_am_prop_div_call.o \
           bin_am_prop_div_put.o bin_am_put.o bin_eur_call.o  bin_eur_put.o \
           bin_am_call_payout.o bin_am_put_payout.o

LIBOBJS += anal_price_am_call_div.o 

LIBOBJS += approx_am_call.o approx_am_put.o approx_am_put_johnson.o 


LIBOBJS += currency_opt_bin_call.o currency_opt_bin_put.o currency_opt_euro_call.o currency_opt_euro_put.o
LIBOBJS += futures_opt_call_black.o futures_opt_put_black.o futures_price.o
LIBOBJS += futures_opt_call_bin.o futures_opt_put_bin.o

LIBOBJS += findiff_exp_am_call.o findiff_exp_am_put.o findiff_exp_eur_call.o findiff_exp_eur_put.o

LIBOBJS += merton_jump_diff_call.o
LIBOBJS += exotics_lookback_call.o exotics_lookback_put.o
LIBOBJS += bermudan_call_option.o bermudan_put_option.o 
LIBOBJS += exotics_asian_price_call.o
LIBOBJS += option_price_american_perpetual_call.o option_price_american_perpetual_put.o
LIBOBJS += simulated_call_euro.o simulated_delta_call.o simulated_delta_put.o simulated_put_euro.o
LIBOBJS += simulate_lognormal_variable.o \
           simulate_lognormally_distributed_sequence.o \
           simulate_european_options_generic_routine_antithetic_variate.o \
           simulate_european_options_generic_routine.o \
           simulate_european_options_generic_routine_control_variate.o \
           simulate_european_options_generic_routine_price_sequence.o \
           simulate_european_options_generic_routine_price_sequence_control_variate.o \

LIBOBJS += payoff_average.o payoff_binary_options.o payoff_black_scholes_case.o payoff_lookback.o

LIBOBJS += binomial_generic.o binomial_generic_delta.o payoff_binary_put_call.o

LIBOBJS += opt_price_trinom_am_call.o opt_price_trinom_am_put.o

LIBOBJS += bondopt_call_bs.o bondopt_put_bs.o  \
           bondopt_call_coupon_bs.o bondopt_put_coupon_bs.o  \
           bondopt_call_binom_am.o bondopt_put_binom_am.o 

LIBOBJS += termstru_yield_nels_sie.o term_structure_class_nelson_siegel.o
LIBOBJS += termstru_discfact_cubic_spline.o term_structure_class_cubic_spline.o  
LIBOBJS += termstru_discfact_cir.o  term_structure_class_cir.o 
LIBOBJS += termstru_discfact_vasicek.o term_structure_class_vasicek.o 
LIBOBJS += term_structure_class_svensson.o termstru_yield_svensson.o

LIBOBJS += interest_rate_trees_gbm_build.o \
           interest_rate_trees_gbm_value_of_cashflows.o \
           interest_rate_trees_gbm_value_of_callable.o \

LIBOBJS +=  term_structure_class_ho_lee.o \
            term_structure_class_ho_lee_calc.o \
            term_structure_class_ho_lee_build_tree.o \
            term_structure_class_ho_lee_price_bond_option.o \

LIBOBJS += bondopt_call_vasicek.o  bondopt_put_vasicek.o \

LIBOBJS += bondopt_call_rend_bart.o 

LIBOBJS += normdist.o cum_normal_bivariate.o cum_normal.o \
           random_normal.o random_uniform.o

######################
### IF THE MATRIX LIBRARY NEMWMAT IS INSTALLED, UNCOMMENT BELOW
### may need to set path to where newmat is installed
###CXXFLAGS += -I/home/bernt/include
#LIBOBJS += mv_calc_newmat.o mv_calc_port_unconstrained_newmat.o
#LIBOBJS += findiff_imp_am_call_newmat.o findiff_imp_am_put_newmat.o \
#           findiff_imp_eur_call_newmat.o findiff_imp_eur_put_newmat.o \

######################
### IF THE MATRIX LIBRARY IT++ IS INSTALLED, UNCOMMENT BELOW
#LIBOBJS += mv_calc_itpp.o mv_calc_port_unconstrained_itpp.o 
#LIBOBJS += findiff_imp_am_put_itpp.o

######################
#### IF GSL IS INSTALLED, UNCOMMENT BELOW
#LIBOBJS += approx_am_put_geske_johnson.o
#LIBOBJS += heston_price.o
#LIBOBJS += N3.o


fin_recipes.h:
	cp ../h_files/fin_recipes*.h .
testing.o: fin_recipes.h
LIB = librecipes.a 
$(LIB): $(LIBOBJS)
	ar r $(LIB) $(LIBOBJS)
lib: fin_recipes.h $(LIB)


ZIPFILE = all_cc_progs.zip
TO_CLEAN_FILES += $(LIB) 
TO_CLEAN_FILES += *.o 
TO_CLEAN_FILES += *.cc *.h  *~

clean:
	rm -f $(TO_CLEAN_FILES) 
realclean: clean

ALLFILES = readme 

pack:
	zip -u $(ZIPFILE) makefile $(ALLFILES)
crunch: clean
	zip -m -u $(ZIPFILE) $(ALLFILES) 
unpack:
	unzip -u -o $(ZIPFILE)

install-h:
install-lib:
install-www:
