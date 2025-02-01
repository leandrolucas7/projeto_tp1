# MAKEFILE PROVISÓRIO
	# Não vai reconhecer mudanças nos headers

# Compiler and flags
CXX = g++
CXXFLAGS = -g3 -Wall -O2 -std=c++17 

# Directories
DOM = ../src/dominios/
ENT = ../src/entidades/
MOD = ../src/


# Source files and object files
SRC =   $(wildcard $(DOM)*.cpp) \
		$(wildcard $(ENT)*.cpp) \
		../src/controladoresSer.cpp \
		../src/controladoresApr.cpp \
		../src/container.cpp \
		../src/builder.cpp \
		driver_projeto_tp1.cpp \


OBJ = $(SRC:.cpp=.o)

# Target executable
TARGET = driver_projeto_tp1

# Rule to build the target executable
$(TARGET): $(OBJ)
	$(CXX) $(OBJ) -o $(TARGET)

# Rule to compile source files into object files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Rule to clean up generated files
clean:
	rm -f $(OBJ) $(TARGET)

# Rule to force recompilation of the target
rebuild: clean $(TARGET)

