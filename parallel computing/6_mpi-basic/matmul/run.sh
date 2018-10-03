#!/bin/sh

RESULTDIR=result/

if [ ! -d ${RESULTDIR} ];
then
    mkdir ${RESULTDIR}
fi

P=${PBS_NP}

mpirun ./mpi_matmul 72000 2 2> ${RESULTDIR}/${P}

