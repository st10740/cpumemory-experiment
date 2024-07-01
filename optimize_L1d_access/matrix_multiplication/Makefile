CC = gcc
CFLAGS = -O0 -g -Wall -DN=1000
EXEC = matrix_mult_origin matrix_mult_tr matrix_mult_subm matrix_mult_vec
STACK_SIZE = ulimit -s unlimited
PERF_SET = sudo sysctl kernel.perf_event_paranoid=2
PERF = perf stat --repeat 10 -e cycles

.PHONY: all run clean

all: $(EXEC)

$(EXEC): %: %.c
	$(CC) $(CFLAGS) -o $@ $<

run: $(EXEC)
	@$(STACK_SIZE)
	@$(PERF_SET)
	$(PERF) taskset --cpu-list 0 ./matrix_mult_origin
	$(PERF) taskset --cpu-list 0 ./matrix_mult_tr
	$(PERF) taskset --cpu-list 0 ./matrix_mult_subm
	$(PERF) taskset --cpu-list 0 ./matrix_mult_vec

clean:
	rm -f *.o $(EXEC)