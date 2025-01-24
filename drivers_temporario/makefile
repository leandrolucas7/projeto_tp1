# MAKEFILE PROVISÓRIO
	# Não vai reconhecer mudanças nos headers

# Compiler and flags
CXX = g++
CXXFLAGS = -Wall -O2 -std=c++17

# Directories
DOM = ../src/dominios/
ENT = ../src/entidades/
MOD = ../src/


# Source files and object files
SRC =   $(wildcard $(DOM)*.cpp) \
		$(wildcard $(MOD)*.cpp) \
		driver_cntr_apr_inicial.cpp \


OBJ = $(SRC:.cpp=.o)

# Target executable
TARGET = driver_cntr_apr_inicial

# Rule to build the target executable
$(TARGET): $(OBJ)
	$(CXX) $(OBJ) -o $(TARGET)

# Rule to compile source files into object files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Rule to clean up generated files
clean:
	for %%f in ($(OBJ)) do del "%%f" 
	del $(TARGET).exe

# Rule to force recompilation of the target
rebuild: clean $(TARGET)

