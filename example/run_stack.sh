#!/bin/sh
#PBS -l ncpus=1
#PBS -l nodes=1:hsca-05
#PBS -q default
#
cd $PBS_O_WORKDIR
#
setup -r /home/yasuda/temp/hscMosaic

python ./run_stack.py All
