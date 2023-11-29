# Comando do compilador
CXX = g++
# Flags de compilação e de linkagem
CXXFLAGS = -Wall -Wextra -std=c++17
LDFLAGS = -lpqxx -lpq

# Diretórios dos arquivos fonte e de cabeçalho
SRCDIR = src
INCDIR = include

# Nomes dos arquivos fonte
SRCS = $(wildcard $(SRCDIR)/*.cpp)
SRCS := $(filter-out $(SRCDIR)/doctest_main.cpp, $(SRCS))  # Exclui doctest_main.cpp da lista de fontes

OBJS = $(SRCS:$(SRCDIR)/%.cpp=%.o)
DEPS = $(wildcard $(INCDIR)/*.hpp)

# Arquivos-fonte para os testes
TEST_DIR = test
TEST_SRCS = $(wildcard $(TEST_DIR)/*.cpp) $(wildcard $(SRCDIR)/*.cpp)
TEST_SRCS := $(filter-out $(SRCDIR)/main.cpp, $(TEST_SRCS))  # Exclui main.cpp da lista de fontes de teste

TEST_OBJS = $(TEST_SRCS:$(SRCDIR)/%.cpp=%.o)

# Nome do executável de teste
TEST_EXEC = testes.out

# Nome do executável
EXEC = programa.out

.PHONY: all clean build test run

# Regra padrão, compila todos os arquivos
all: build

# Regra para compilar a aplicação e os testes
build: $(EXEC) $(TEST_EXEC)

# Compilação dos arquivos objeto
$(SRCDIR)/%.o: $(SRCDIR)/%.cpp $(DEPS)
	$(CXX) $(CXXFLAGS) -c -o $@ $<

# Compilação dos arquivos de teste
$(TEST_DIR)/%.o: $(TEST_DIR)/%.cpp $(DEPS)
	$(CXX) $(CXXFLAGS) -c -o $@ $<

# Linkagem dos objetos para criar o executável da aplicação
$(EXEC): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LDFLAGS)

# Regra para executar os testes
test: $(TEST_EXEC)
	./$(TEST_EXEC)

# Linkagem dos objetos para criar o executável dos testes
$(TEST_EXEC): $(TEST_OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LDFLAGS)

# Regra para executar a aplicação
run: $(EXEC)
	./$(EXEC)

# Limpa os arquivos objetos e os executáveis
clean:
	rm -f $(OBJS) $(EXEC) $(TEST_OBJS) $(TEST_EXEC)