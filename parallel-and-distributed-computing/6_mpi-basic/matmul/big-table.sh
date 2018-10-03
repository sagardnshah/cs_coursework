#!/bin/sh

RESULTDIR=result/

for i in 16 25 36;
do
    echo $i $(cat ${RESULTDIR}/big-${i})
done
