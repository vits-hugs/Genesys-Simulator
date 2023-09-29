CC = g++
CFLAGS = -Wall -std=c++14 -g -fdiagnostics-color=always
TARGET = a.out

SRC_DIR = $(PWD)
OUTPUT_DIR = $(PWD)


# Source files list
SRCS = $(wildcard $(SRC_DIR)/../../../source/tools/OutputAnalyser/*.cpp)
SRCS += $(wildcard $(SRC_DIR)/../../../source/tools/OutputAnalyser/unitTests/*.cpp)
SRCS += $(wildcard $(SRC_DIR)/../../../source/kernel/statistics/*.cpp)
SRCS += $(SRC_DIR)/../../../source/kernel/simulator/ExperimentManagerDefaultImpl1.cpp
SRCS += $(wildcard $(SRC_DIR)/../../../source/tools/*.cpp)
SRCS := $(filter-out $(SRC_DIR)/../../../source/tools/OutputAnalyser/main.cpp, $(SRCS))
# Gere a lista de objetos automaticamente
OBJS = $(patsubst $(SRC_DIR)/%.cpp, $(OUTPUT_DIR)/%.o, $(SRCS))

#  ------ Compilation rules ------
all: $(TARGET)

# Compile objects into executable
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(OUTPUT_DIR)/$(TARGET) $(OBJS)

# Compile source file into object
$(OUTPUT_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OUTPUT_DIR)/*.o $(OUTPUT_DIR)/$(TARGET) $(OBJS)

.PHONY: all clean