# MAKEFILE PROVISÓRIO
	# Não vai reconhecer mudanças nos headers

# Compiler and flags
CXX = g++
CXXFLAGS = -Wall -O2 -std=c++17

# Directories
DOM = src/dominios/

# Source files and object files
SRC = $(DOM)avaliacao.cpp \
      $(DOM)codigo.cpp \
      $(DOM)data.cpp \
      $(DOM)dinheiro.cpp \
      $(DOM)duracao.cpp \
      $(DOM)horario.cpp \
      $(DOM)nome.cpp \
      $(DOM)senha.cpp \
      $(DOM)super_dominio.cpp \
	  src/testes/super_teste.cpp \
	  src/testes/teste_avaliacao.cpp \
	  testes_dominios.cpp \
        src/testes/teste_senha.cpp


OBJ = $(SRC:.cpp=.o)

# Target executable
TARGET = testes_dominios

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

