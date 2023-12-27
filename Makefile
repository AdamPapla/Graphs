CC=g++
CFLAGS=-Wall -Wextra
SFILES=graph.o
HFILES=graph.hh
all: AMGraph
graph.o: graph.cc graph.hh 
	$(CC) $(CFLAGS) -c graph.cc 

AMGraph: graph.o graph.hh main.cc 
	$(CC) $(CFLAGS) graph.o -o AMGraph main.cc 

clean: 
	rm AMGraph