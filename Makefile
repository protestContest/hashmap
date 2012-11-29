BUILD = ./build
TEST = ./test
LIB = ./lib
SRC = ./src

GTEST = $(LIB)/gtest-1.6.0
GTEST_MAINA = $(GTEST)/make/gtest_main.a
GTEST_INCLUDES = -I$(GTEST) -I$(GTEST)/include

CPP = g++
CFLAGS = -Wall -Wextra -Werror -ggdb
INCLUDE = -I$(SRC)

hashtest: hashtest.o Hashmap.o Entry.o
	$(CPP) $(CFLAGS) $(INCLUDE) -o $(BUILD)/hashtest -pthread \
			hashtest.o Hashmap.o Entry.o $(GTEST_MAINA)

hashtest.o: $(TEST)/hashtest.cpp
	$(CPP) $(CFLAGS) $(INCLUDE) $(GTEST_INCLUDES) -c $(TEST)/hashtest.cpp

Hashmap.o: $(SRC)/Hashmap.h $(SRC)/Hashmap.cpp
	$(CPP) $(CFLAGS) $(INCLUDE) -c $(SRC)/Hashmap.cpp

Entry.o: $(SRC)/Entry.h $(SRC)/Entry.cpp
	$(CPP) $(CFLAGS) $(INCLUDE) -c $(SRC)/Entry.cpp

$(GTEST_MAINA): $(GTEST)/src/*.cc $(GTEST)/src/*.h 
	cd $(GTEST)/make && $(MAKE)


clean:
	cd $(GTEST)/make && $(MAKE) clean
	rm -rf $(BUILD)/*
	rm -rf *.o
