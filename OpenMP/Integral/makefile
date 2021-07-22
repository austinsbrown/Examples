default:
	make critical
	make atomic
	make serial

critical: integral_critical.c
	gcc integral_critical.c -fopenmp -o critical

atomic: integral_atomic.c
	gcc integral_atomic.c -fopenmp -o atomic

serial: integral_serial.c
	gcc integral_serial.c -fopenmp -o serial

clean:
	rm serial atomic critical