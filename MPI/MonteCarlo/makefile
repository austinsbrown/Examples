default:
	make MonteCarlo
	make MonteCarloReduction

MonteCarloReduction: main_better.c
	mpicc -lm main_better.c -o MonteCarloReduction

MonteCarlo: main.c
	mpicc -lm main.c -o MonteCarlo

clean:
	rm MonteCarlo MonteCarloReduction

run_MonteCarlo:
	mpiexec -n 2 ./MonteCarlo

run_MonteCarloBetter:
	mpiexec -n 2 ./MonteCarlo