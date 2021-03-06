if [ ! -e .passed_mergesort ] ;
then
    echo "Must pass \`make test_mergesort\` before queueing jobs"
    exit 1
fi

qsub -q mamba -d $(pwd) -l walltime=4:00:00,nodes=1:ppn=16 util/bench_mergesort.sh
echo "----------------------"
echo
echo "Once the job COMPLETES, plot with \`make plot_mergesort\`"
