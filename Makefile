FCFS_SOURCE_FILE = src/FCFS/fcfs.cpp
SJF_SOURCE_FILE = src/SJF/sjf.cpp 
SRTF_SOURCE_FILE = src/SRTF/srtf.cpp
RR_SOURCE_FILE = src/RR/rr.cpp

INCLUDES = $(wildcard $(include)/*.hpp)

SOURCE_FILE = ${FCFS_SOURCE_FILE} ${SJF_SOURCE_FILE} ${SRTF_SOURCE_FILE} ${RR_SOURCE_FILE} ${source_path}

compiler_driver = g++

name = osps

source_path = src/${name}.cpp

# Third party libraries
TABULATE_INCLUDE = $(wildcard $(include/tabulate)/*.hpp)

all: build run

build: ${source_path}
	mkdir -p bin
	$(compiler_driver) -std=c++17 ${INCLUDES} ${TABULATE_INCLUDE} ${SOURCE_FILE} -o ./bin/${name}.exe

run: ./bin/${name}.exe
	./bin/${name}.exe

clean: ./bin/
	rm -f ./bin/${name}.exe


