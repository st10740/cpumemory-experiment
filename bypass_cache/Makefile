CC = gcc
CFLAGS = -O0 -g -Wall
EXEC = bypass_cache
OBJS = main.o write.o
STACK_SIZE = ulimit -s unlimited

.PHONY: all run clean

all: $(EXEC)

$(EXEC): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $@

%.o: %.c
	$(CC) $(CFLAGS) -c $<

run: $(EXEC)
	@$(STACK_SIZE) && taskset --cpu-list 0 ./$(EXEC)

clean:
	rm -f *.o $(EXEC)