#!/bin/sh

RESULTDIR=result/

for i in 1 4 9 16 25 36;
do
    echo $i $(cat ${RESULTDIR}/${i})
done

