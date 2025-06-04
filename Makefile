CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -g

SRC_DIR = src
INCLUDE_DIR = include
OBJ_DIR = obj
BIN = oraculo.exe

SRC = $(wildcard $(SRC_DIR)/*.cpp)
OBJ = $(SRC:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)

all: $(BIN)

$(BIN): $(OBJ)
	$(CXX) $(CXXFLAGS) $^ -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	mkdir -p $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -I$(INCLUDE_DIR) -c $< -o $@

clean:
	del /S /Q $(OBJ_DIR)\*.o
	del $(BIN)
	rmdir $(OBJ_DIR)

.PHONY: all clean
