CC=g++
CFLAGS=-Wall -Wextra
SFILES=AMGraph.o ALGraph.o
HFILES=AMGraph.hh ALGraph.o
all: AMGraph
AMGraph.o: AMGraph.cc AMGraph.hh 
	$(CC) $(CFLAGS) -c AMGraph.cc 

ALGraph.o: ALGraph.cc ALGraph.hh 
	$(CC) $(CFLAGS) -c ALGraph.cc 

AMGraph: $(SFILES) $(HFILES) main.cc 
	$(CC) $(CFLAGS) $(SFILES) -o graph main.cc 

clean: 
	rm *.o graph