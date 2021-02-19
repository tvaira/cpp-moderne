SRC := $(wildcard *.cpp)
SRC_C14 := binaire.cpp lambda.cpp litteraux.cpp
SRC_C17 := any.cpp byte.cpp invoke.cpp optional.cpp
SRC_PTHREAD := future.cpp mutex.cpp ref.cpp thread-1.cpp thread-2.cpp
SRC_TEMP = $(filter-out $(SRC_C17),$(SRC))
SRC_C11 = $(filter-out $(SRC_PTHREAD),$(SRC_TEMP))

$(info C++11 : $(SRC_C11))
$(info C++14 : $(SRC_C14))
$(info C++17 : $(SRC_C17))
$(info THREAD : $(SRC_PTHREAD))

TARGETS := $(patsubst %.cpp, %, $(SRC))
TARGETS_C14 := $(patsubst %.cpp, %, $(SRC_C14))
TARGETS_C17 := $(patsubst %.cpp, %, $(SRC_C17))
TARGETS_PTHREAD := $(patsubst %.cpp, %, $(SRC_PTHREAD))
TARGETS_C11 := $(patsubst %.cpp, %, $(SRC_C11))

OPTIONS_C11 := -std=c++11 
OPTIONS_C14 := -std=c++14 
OPTIONS_C17 := -std=c++17
OPTIONS_PTHREAD := -lpthread -std=c++11

all : $(TARGETS_C11) $(TARGETS_PTHREAD) $(TARGETS_C14) $(TARGETS_C17)

$(TARGETS_C11):
	g++ -o $@ $@.cpp $(OPTIONS_C11)

$(TARGETS_C14):
	g++ -o $@ $@.cpp $(OPTIONS_C14)

$(TARGETS_PTHREAD):
	g++ -o $@ $@.cpp $(OPTIONS_PTHREAD)

$(TARGETS_C17):
	g++ -o $@ $@.cpp $(OPTIONS_C17)

.PHONY: clean

clean:
	rm -f $(TARGETS)

rebuild: clean all
