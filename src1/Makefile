PROJECT := main


DIR_SRC = ./src
DIR_INC = ./inc
DIR_BUILD = ./build


SRC_CPP = $(addsuffix /*.cpp, $(DIR_SRC))
OBJECTS = $(addsuffix /*.o, $(DIR_BUILD))


CXX = g++
CXXFLAGS = -Wall -Og -std=c++20

INCFLAGS = -I$(DIR_INC)

LDFLAGS = -L$(DIR_BUILD)
LDLIBS = -lconfiguration -lsite



main : $(DIR_BUILD)/main.o $(DIR_BUILD)/libconfiguration.so $(DIR_BUILD)/libsite.so
	$(CXX) $(CXXFLAGS) ${DIR_BUILD}/main.o -o $@ $(INCFLAGS) $(LDFLAGS) $(LDLIBS)

$(DIR_BUILD)/main.o : main.cpp
	$(CXX) $(CXXFLAGS) -c main.cpp -o $@ $(INCFLAGS)

$(DIR_BUILD)/libconfiguration.so : $(DIR_BUILD)/configuration.o $(DIR_BUILD)/libsite.so
	$(CXX) $(CXXFLAGS) -shared $(DIR_BUILD)/configuration.o -o $@ $(INCFLAGS) -L./build -lsite 

$(DIR_BUILD)/configuration.o : $(DIR_SRC)/configuration.cpp
	$(CXX) $(CXXFLAGS) -fpic -c $(DIR_SRC)/configuration.cpp -o $(DIR_BUILD)/configuration.o $(INCFLAGS)

$(DIR_BUILD)/libsite.so : $(DIR_BUILD)/site.o
	$(CXX) $(CXXFLAGS) -shared $^ -o $@ $(INCFLAGS)

$(DIR_BUILD)/site.o : $(DIR_SRC)/site.cpp
	$(CXX) $(CXXFLAGS) -fpic -c $^ -o $@ $(INCFLAGS)

.PHONY : clean
clean:
	rm -r build/* ./main