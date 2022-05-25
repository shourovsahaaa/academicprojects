# Default target.
all: sort_driver

# Makes sort.o
sort: sort.cc sort.h
	g++ -c sort.cc

# Makes the main executable.
sort_driver: sort
	g++ -o sort_driver sort_driver.cc sort.o

# Cleans executable and object files.
clean:
	rm -f sort_driver sort.o
