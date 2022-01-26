name = osps

source_path = src/${name}.cpp

FCFS_SOURCE_FILE = src/FCFS/fcfs.cpp
SJF_SOURCE_FILE = src/SJF/sjf.cpp 
SRTF_SOURCE_FILE = src/SRTF/srtf.cpp
RR_SOURCE_FILE = src/RR/rr.cpp
PS_SOURCE_FILE = src/PS/ps.cpp

# include header files
# INCLUDES = $(wildcard $(include)/*.hpp)
# INCLUDES = $(foreach dir, -I./include, $(wildcard $(dir)/*hpp))

SOURCE_FILE = ${FCFS_SOURCE_FILE} \
			  ${SJF_SOURCE_FILE}  \
			  ${SRTF_SOURCE_FILE} \
			  ${RR_SOURCE_FILE}  \
			  ${PS_SOURCE_FILE} \
			  ${source_path}

# Third party libraries
TABULATE_INCLUDE = $(wildcard $(include/tabulate)/*.hpp)

# creating resource file
RES_COMMAND = windres ./res/icon.rc -O coff -o ./bin/${name}.res

# Compile
compiler_driver = g++
compiler_flags = -std=c++17

BUILD_COMMAND = $(compiler_driver) ${compiler_flags} \
				-I ./include/ ${TABULATE_INCLUDE} ${SOURCE_FILE} \
				./bin/${name}.res \
				-o ./bin/${name}.exe

all: build run

command:
	@echo "${BUILD_COMMAND}"

build: ${source_path}
	@mkdir -p bin
	@echo "[✓] bin directory created"
	@echo "[...] Building ${name}..."
	@${RES_COMMAND}
	@${BUILD_COMMAND}
	@echo "[✓] Built successfully..."
	@echo " ⓘ  Use 'make run' or './bin/${name}.exe' to run the program"

run: ./bin/${name}.exe
	@echo " ⓘ  Running ${name}..."
	@./bin/${name}.exe

clean: ./bin/
	@rm -f ./bin/${name}.exe
	@rm -f ./bin/${name}.res
	@echo " ⓘ  Cleaned successfully..."

