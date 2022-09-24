main : main.o libconfiguration.so libsite.so
	g++ -Og -std=c++20 main.o -o main -L. -lconfiguration -lsite
main.o : main.cpp
	g++ -Og -std=c++20 -c main.cpp -o main.o
libconfiguration.so : configuration.o libsite.so
	g++ -Og -std=c++20 -shared configuration.o -o libconfiguration.so -L. -lsite
configuration.o : configuration.cpp
	g++ -Og -std=c++20 -fpic -c configuration.cpp -o configuration.o
libsite.so : site.o
	g++ -Og -std=c++20 -shared site.o -o libsite.so
libsite.o : site.cpp
	g++ -Og -std=c++20 -fpic -c site.cpp -o site.o

.PHONY: clean
clean : 
	rm -r main *.o *.so