.PHONY: all clean

all: bin/phonebook

bin/phonebook: build/src/main.o build/src/phonebook.o build/src/interface.o src/interface.h src/phonebook.h src/user.h
	mkdir bin -p
	gcc -Wall build/src/main.o build/src/interface.o build/src/phonebook.o -o bin/phonebook 

build/src/main.o: src/main.c src/interface.h src/phonebook.h src/user.h
	mkdir build/src -p
	gcc -Wall -c src/main.c -o build/src/main.o 

build/src/interface.o: src/interface.c src/interface.h
	mkdir build/src -p
	gcc -Wall -c src/interface.c -o build/src/interface.o 

build/src/phonebook.o: src/phonebook.c src/interface.h src/phonebook.h src/user.h
	mkdir build/src -p
	gcc -Wall -c src/phonebook.c -o build/src/phonebook.o

clean:
	rm -rf build/* bin/*