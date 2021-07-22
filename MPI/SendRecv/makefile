default:
	make SendRecv
	make PingPong

SendRecv: SendRecv.c
	mpicc SendRecv.c -o SendRecv

PingPong: PingPong.c
	mpicc PingPong.c -o PingPong

run_SendRecv:
	mpiexec -n 2 ./SendRecv

run_PingPong:
	mpiexec -n 2 ./PingPong

clean:
	rm SendRecv PingPong