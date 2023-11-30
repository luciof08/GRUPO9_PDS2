# Comando do compilador
CXX = g++
# Flags de compilação e de linkagem
CXXFLAGS = -Wall -Wextra -std=c++17
LDFLAGS = -lpqxx -lpq

# Diretórios dos arquivos fonte, cabeçalhos e compilação
SRCDIR = src
INCDIR = include
BUILDDIR = build

# Arquivos da aplicação
SRCS_APP = $(wildcard $(SRCDIR)/*.cpp)
OBJS_APP = $(patsubst $(SRCDIR)/%.cpp,$(BUILDDIR)/%.o,$(SRCS_APP))

# Arquivos de teste do Doctest
TESTDIR = test
SRCS_TEST = $(wildcard $(TESTDIR)/*.cpp)
OBJS_TEST = $(patsubst $(TESTDIR)/%.cpp,$(BUILDDIR)/%.o,$(SRCS_TEST))

# Nome dos executáveis
EXEC = programa.out
TEST_EXEC = testes.out

.PHONY: all clean build test run

# Regra padrão, compila tudo
all: build

# Regra para criar a pasta de compilação
$(BUILDDIR):
	mkdir -p $(BUILDDIR)

# Regra para compilar os arquivos da aplicação
$(BUILDDIR)/%.o: $(SRCDIR)/%.cpp | $(BUILDDIR)
	$(CXX) $(CXXFLAGS) -I$(INCDIR) -c -o $@ $<

# Regra para compilar os arquivos de teste
$(BUILDDIR)/%.o: $(TESTDIR)/%.cpp | $(BUILDDIR)
	$(CXX) $(CXXFLAGS) -I$(INCDIR) -c -o $@ $<

# Regra para compilar a aplicação e os testes
build: $(BUILDDIR) $(EXEC) $(TEST_EXEC)

# Linkagem dos objetos para criar o executável da aplicação
$(EXEC): $(OBJS_APP)
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LDFLAGS)

# Linkagem dos objetos para criar o executável dos testes
$(TEST_EXEC): $(OBJS_TEST) $(filter-out $(BUILDDIR)/main.o,$(OBJS_APP))
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LDFLAGS)

# Regra para executar os testes
test: $(TEST_EXEC)
	./$(TEST_EXEC)

# Regra para executar a aplicação
run: $(EXEC)
	./$(EXEC)

# Limpa os arquivos objetos e os executáveis
clean:
	rm -rf $(BUILDDIR) $(EXEC) $(TEST_EXEC)
