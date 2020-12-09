#!/bin/bash

echo "##############################################################################################################"
echo "# Title      : test_batch_sgemm                                                                              #"
echo "# CPU        : FT2000+ (246)                                                                                 #"
echo "# Tester     : LWC                                                                                           #"
echo "# Time       : 2020.07.04                                                                                    #"
echo "# Description: Test performance of batch_sgemm for different {count}, {M}, {N}, {K}.                         #"
echo "#              To run the script, one should check environment variables.                                    #"
echo "##############################################################################################################"


echo "---------------------------------------------------------- 1 ----------------------------------------------------------------"
#### set threads ####
echo "export OMP_NUM_THREADS=1"
export OMP_NUM_THREADS=1

#### clean ####
echo "rm testbatch"
rm testbatch

#### compile ####
echo "gcc -g test_batchblas.c  -I ../.. -L ../.. -static -lopenblas -fopenmp -o testbatch"
gcc -g verify.c  -I ../.. -L ../.. -static -lopenblas -fopenmp -o testbatch
echo "-----------------------------------------------------------------------------------------------------------------------------"


echo "---------------------------------------------------------- 2 ----------------------------------------------------------------"
#### run test ####
# testbatch count M N K

# numbers of matrix
# count="1 8 16 32 64 128 256"
count="1"
# sizes of a matrix
#m="10 20 40 80 160 320 640 1280"
#n="10 20 40 80 160 320 640 1280" 
#k="10 20 40 80 160 320 640 1280"
#m="3"
#n="3"
#k="3"

#p=(R R R R C C C C)
#q=(R C R C C R C R)
#r=(R R C C C C R R)
# run
for i in $count
do
    echo " "
    echo "%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%"
    taskset -c 1 ./testbatch 1 3 3 3 C C C
    #for j in $m
    #do
    #    echo "*************************************************************************************************"
    #    #echo "./testbatch count=${i} m=${j} m=${j} k=${j}"
    #		for t in {0..7};
    #		do
    #		    echo "------count = ${i}-------count=${i} m=${j} m=${j} k=${j}------layoutA=${p[$t]} layoutB=${q[$t]} layoutC=${r[$t]}-------------------------------------------------------------"
    #        taskset -c 1 ./testbatch $i $j $j $j ${p[$t]} ${q[$t]} ${r[$t]}
    #			echo "----------------------------------------------------------------------------------------------------------------------------"
    #		done	
    #    echo "********************************************************************************************************************"
    #done
    echo "%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%"
    echo " "
done
echo "-----------------------------------------------------------------------------------------------------------------------------"
