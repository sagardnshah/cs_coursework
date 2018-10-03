CXX=mpicxx
CC=mpicc
LD=mpicxx
CXXFLAGS=-std=c++11

mpi_matmul:

run: run_1x1 run_2x2 run_3x3 run_4x4 run_5x5 run_6x6
	echo

run_1x1: mpi_matmul
	qsub -q mamba -l walltime=00:10:00 -d $(shell pwd) -l nodes=1:ppn=1 -l mem=80GB ./run.sh

run_2x2: mpi_matmul
	qsub -q mamba -l walltime=00:10:00 -d $(shell pwd) -l nodes=2:ppn=2 -l mem=80GB ./run.sh

run_3x3: mpi_matmul
	qsub -q mamba -l walltime=00:10:00 -d $(shell pwd) -l nodes=3:ppn=3 -l mem=80GB ./run.sh

run_4x4: mpi_matmul
	qsub -q mamba -l walltime=00:10:00 -d $(shell pwd) -l nodes=4:ppn=4 -l mem=80GB ./run.sh

run_5x5: mpi_matmul
	qsub -q mamba -l walltime=00:10:00 -d $(shell pwd) -l nodes=5:ppn=5 -l mem=80GB ./run.sh

run_6x6: mpi_matmul
	qsub -q mamba -l walltime=00:10:00 -d $(shell pwd) -l nodes=6:ppn=6 -l mem=80GB ./run.sh

run_big: run_big-4x4 run_big-5x5 run_big-6x6
	echo

run_big-4x4: mpi_matmul
	qsub -q mamba -l walltime=01:00:00 -d $(shell pwd) -l nodes=4:ppn=4 -l mem=250GB ./run-big.sh

run_big-5x5: mpi_matmul
	qsub -q mamba -l walltime=01:00:00 -d $(shell pwd) -l nodes=5:ppn=5 -l mem=250GB ./run-big.sh

run_big-6x6: mpi_matmul
	qsub -q mamba -l walltime=01:00:00 -d $(shell pwd) -l nodes=6:ppn=6 -l mem=250GB ./run-big.sh

table:
	./table.sh

big-table:
	./big-table.sh
