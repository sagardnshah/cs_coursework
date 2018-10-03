#!/bin/sh

RESULTDIR=result/

if [ ! -d ${RESULTDIR} ];
then
    mkdir ${RESULTDIR}
fi

P=${PBS_NP}

mpirun ./mpi_matmul 216000 2 2> ${RESULTDIR}/big-${P}

