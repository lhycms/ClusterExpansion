g++ -std=c++20 -Og -fpic -c site.cpp -o site.o;
g++ -std=c++20 -Og -fpic -c configuration.cpp -o configuration.o;
g++ -std=c++20 -shared site.o -o libsite.so;
g++ -std=c++20 -shared configuration.o -o libconfiguration.so -L. -lsite;
g++ -Wall -std=c++20 -c main.cpp -o main.o;
g++ -Og -std=c++20 main.o -o main -L. -lconfiguration -lsite;


rm *.so *.o main test