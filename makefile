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
            src/dominios/testes/super_teste.cpp \
            src/dominios/testes/teste_avaliacao.cpp \
            src/dominios/testes/teste_codigo.cpp \
            src/dominios/testes/teste_data.cpp \
            src/dominios/testes/teste_dinheiro.cpp \
            src/dominios/testes/teste_duracao.cpp \
            src/dominios/testes/teste_horario.cpp \
            src/dominios/testes/teste_nome.cpp \
            src/dominios/testes/teste_senha.cpp \
            testes_dominios.cpp \
      src/entidades/testes/teste_conta.cpp \
	  src/entidades/testes/teste_destino.cpp \
	  src/entidades/testes/teste_hospedagem.cpp \
	  src/entidades/testes/teste_atividade.cpp \
	  src/entidades/testes/teste_viagem.cpp \



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
	rm -f *.o *.exe

# Rule to force recompilation of the target
rebuild: clean $(TARGET)

