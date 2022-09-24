CXX = g++ -Og -std=c++20

build_folder = build


main : ${build_folder}/main.o
	${CXX} ${build_folder}/main.o -o main -L${build_folder} -lconfiguration -lsite

${build_folder}/main.o : main.cpp ${build_folder}/libconfiguration.so ${build_folder}/libsite.so
	${CXX} -c main.cpp -o ${build_folder}/main.o

${build_folder}/libconfiguration.so : ${build_folder}/configuration.o ${build_folder}/libsite.so
	${CXX} -shared ${build_folder}/configuration.o -o ${build_folder}/libconfiguration.so -L${build_folder} -lsite

${build_folder}/configuration.o : configuration.cpp
	${CXX} -fpic -c configuration.cpp -o ${build_folder}/configuration.o

${build_folder}/libsite.so : ${build_folder}/site.o
	${CXX} -shared ${build_folder}/site.o -o ${build_folder}/libsite.so

${build_folder}/site.o : site.cpp 
	${CXX} -fpic -c site.cpp -o ${build_folder}/site.o



.PHONY : clean
clean: 
	rm -r main ${build_folder}/*.o ${build_folder}/*so