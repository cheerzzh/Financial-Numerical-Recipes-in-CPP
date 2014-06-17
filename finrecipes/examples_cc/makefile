ZIPFILE = examples_cc.zip
ALLFILES = run_all_examples.cc

CXX = gcc
CXXFLAGS = -c -O2
 %.o : %.cc
	$(CXX) $(CXXFLAGS) $*.cc

fin_recipes.h:
	cp ../all_cc_progs/fin_recipes.h .
normdist.h:
	cp ../all_cc_progs/normdist.h .


LIB = librecipes.a 
librecipes.a: 
	cd ../all_cc_progs; make lib
	cp ../all_cc_progs/librecipes.a .

################################################
## IF NEWMAT IS AVAILABLE, UNCOMMENT
# may need to set path here, change to reflect your setup
#### CXXFLAGS += -I/home/bernt/include 
#### LIBS +=  -L/home/bernt/lib 
# CXXFLAGS += -D_HAVE_NEWMAT_ 
# LIBS +=  -lnewmat

################################################
## IF IT++ IS AVAILABLE, UNCOMMENT
# CXXFLAGS += -D_HAVE_ITPP_ 
# LIBS +=  -litpp -lcblas -latlas


################################################
## IF GSL IS AVAILABLE, UNCOMMENT
# CXXFLAGS += -D_HAVE_GSL_
# LIBS += -lgsl 

run_all_examples.o: librecipes.a fin_recipes.h normdist.h  $(LIB) 
run_all_examples: librecipes.a fin_recipes.h run_all_examples.o 
	g++ run_all_examples.o  $(LIBS) -L. -lrecipes  -o run_all_examples 
run: run_all_examples
	./run_all_examples


TO_CLEAN_FILES += $(LIB) run_all_examples *~
TO_CLEAN_FILES += *.o
TO_CLEAN_FILES += example*.cc *.h  

clean:
	rm -f $(TO_CLEAN_FILES) 
pack:
	zip -u $(ZIPFILE) makefile $(ALLFILES)
crunch: clean
	zip -m -u $(ZIPFILE) $(ALLFILES) 
unpack:
	unzip -u -o $(ZIPFILE)
realclean: clean
install-h:
install-lib:
install-www:

