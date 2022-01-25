FCFS_SOURCE_FILE = src/FCFS/fcfs.cpp src/SJF/sjf.cpp src/SRTF/srtf.cpp

INCLUDES = $(wildcard $(include)/*.hpp)

SOURCE_FILE = ${FCFS_SOURCE_FILE} ${source_path}

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


