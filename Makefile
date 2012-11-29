BUILD = ./build
TEST = ./test
LIB = ./lib
SRC = ./src

GTEST = $(LIB)/gtest-1.6.0
GTEST_MAINA = $(GTEST)/make/gtest_main.a
GTEST_INCLUDES = -I$(GTEST) -I$(GTEST)/include

CPP = g++
CFLAGS = -Wall -Wextra
INCLUDE = -I$(SRC)

hashtest: hashtest.o hashmap.o entry.o
	$(CPP) $(CFLAGS) $(INCLUDE) -o $(BUILD)/hashtest -pthread \
			hashtest.o hashmap.o entry.o

hashtest.o: $(TEST)/hashtest.cpp
	$(CPP) $(CFLAGS) $(INCLUDE) -c $(TEST)/hashtest.cpp

hashmap.o: $(SRC)/hashmap.h $(SRC)/hashmap.cpp
	$(CPP) $(CFLAGS) $(INCLUDE) -c $(SRC)/hashmap.cpp

entry.o: $(SRC)/entry.h $(SRC)/entry.cpp
	$(CPP) $(CFLAGS) $(INCLUDE) -c $(SRC)/entry.cpp

$(GTEST_MAINA): $(GTEST)/src/*.cc $(GTEST)/src/*.h
	cd $(GTEST)/make && $(MAKE)


clean:
	rm -rf $(BUILD)/*
	rm -rf *.o
