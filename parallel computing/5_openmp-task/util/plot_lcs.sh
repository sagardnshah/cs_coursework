#!/bin/sh

RESULTDIR=result/
PLOTDIR=plot/
h=`hostname`


if [ ! -d ${RESULTDIR} ];
then
    echo "must run make bench_lcs"
    exit 1
fi

if [ ! -d ${PLOTDIR} ];
then
    mkdir ${PLOTDIR}
fi

NS="1000 100000" 
THREADS="2 8 12 16"

	     

# format output
for m in ${NS} ;
do
    for n in ${NS} ;
    do
        for t in ${THREADS} ;
        do
	    #output in format "thread seq par"
	    echo ${t} \
	         $(cat ${RESULTDIR}/lcs_seq_${m}_${n}) \
	         $(cat ${RESULTDIR}/lcs_${m}_${n}_${t})
        done   > ${RESULTDIR}/speedup_lcs_${m}_${n}
    done
done

for n in ${NS} ;
do
    for t in ${THREADS} ;
    do
	for m in ${NS} ;
	do
	    #output in format "m seq par"
	    echo ${m} \
	         $(cat ${RESULTDIR}/lcs_seq_${m}_${n}) \
	         $(cat ${RESULTDIR}/lcs_${m}_${n}_${t})
        done   > ${RESULTDIR}/speedup_lcs_thread_${n}_${t}
    done
done


# plot
GSP="${GSP} ; set title 'lcs'; plot "
for m in ${NS} ;
do
    c=1
    for n in ${NS} ;
    do 
        GSP="${GSP}  '${RESULTDIR}/speedup_lcs_${m}_${n}' u 1:(\$2/\$3) t 'm=${m} n=${n}' lc ${c} lw 3 , "
        c=`expr $c + 1`
    done
done


for n in ${NS} ;
do
    for t in ${THREADS} ; 
    do 
	echo ${t}
	
	GTSP="${GTSP} ; set title 'lcs-${t} threads, n=${n}'; \
                    set key top left; \
                    set xlabel 'M'; \
                    set ylabel 'speedup'; \
                    set xrange [*:*]; \
                    set yrange [0:20]; \
                    set logscale x 10; \
                    set ytics 2;"
    GTSP="${GTSP} plot '${RESULTDIR}/speedup_lcs_thread_${n}_${t}' u 1:(\$2/\$3) t 'threads=${t}: n=${n}' lc 1 lw 3 ; "
    done
done

#echo ${GTSP}


gnuplot <<EOF
set terminal pdf
set output '${PLOTDIR}lcs_speedup_n.pdf'
set style data linespoints
set key top left;
set xlabel 'threads'; 
set ylabel 'speedup';
set xrange [0:20];
set yrange [0:20];
set ytics 2;

${GSP}

EOF

gnuplot <<EOF
set terminal pdf
set output '${PLOTDIR}lcs_speedup_thread.pdf'
set style data linespoints

${GTSP}


EOF
