CC=gcc
LDFLAGS=

binaries:memSim

all: $(binaries)

memSim: driver.c prcsADT.c ramADT.c 
	$(CC) $^ -o $@ $(LDFLAGS)

clean:
	$(RM) -f $(binaries) *.o