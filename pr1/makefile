CC=gcc
LDFLAGS=

binaries:pr1

all: $(binaries)

pr1: driver.c prcsADT.c ramADT.c 
	$(CC) $^ -o $@ $(LDFLAGS)

clean:
	$(RM) -f $(binaries) *.o