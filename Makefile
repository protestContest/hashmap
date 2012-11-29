BUILD = ./build
TEST = ./test
LIB = ./lib
SRC = ./src
GTEST = $(LIB)/gtest-1.6.0
GTEST_MAINA = $(GTEST)/make/gtest_main.a
GTEST_INCLUDES = -I$(GTEST) -I$(GTEST)/include

CPP = g++
CFLAGS = -Wall -Wextra

hashtest: hashmap.o $(TEST)/hashtest.cpp $(GTEST_MAINA)
	$(CPP) $(CFLAGS) -o $(BUILD)/hashtest hashmap.o $(TEST)/hashtest.cpp \
			-pthread

hashmap.o: $(SRC)/hashmap.h $(SRC)/hashmap.cpp
	$(CPP) $(CFLAGS) -c $(SRC)/hashmap.cpp

$(GTEST_MAINA): $(GTEST)/src/*.cc $(GTEST)/src/*.h
	cd $(GTEST)/make && $(MAKE)


clean:
	rm -rf $(BUILD)/*
	rm -rf *.o
