# Comando do compilador
CXX = g++
# Flags de compilação e de linkagem
CXXFLAGS = -Wall -Wextra -std=c++17
LDFLAGS = -lpqxx -lpq

# Diretórios dos arquivos fonte, cabeçalhos e compilação
SRCDIR = src
INCDIR = include
BUILDDIR = build
BUILD_APP_DIR = $(BUILDDIR)/app
BUILD_TEST_DIR = $(BUILDDIR)/test

# Arquivos da aplicação
SRCS_APP = $(wildcard $(SRCDIR)/*.cpp)
OBJS_APP = $(patsubst $(SRCDIR)/%.cpp,$(BUILD_APP_DIR)/%.o,$(SRCS_APP))

# Arquivos de teste do Doctest
TESTDIR = test
SRCS_TEST = $(wildcard $(TESTDIR)/*.cpp)
OBJS_TEST = $(patsubst $(TESTDIR)/%.cpp,$(BUILD_TEST_DIR)/%.o,$(SRCS_TEST))

# Nome dos executáveis
EXEC = programa.out
TEST_EXEC = testes.out

.PHONY: all clean build test run

# Regra padrão, compila tudo
all: build

# Regra para criar os diretórios de compilação
$(BUILD_APP_DIR):
	mkdir -p $(BUILD_APP_DIR)

$(BUILD_TEST_DIR):
	mkdir -p $(BUILD_TEST_DIR)

# Regra para compilar os arquivos da aplicação
$(BUILD_APP_DIR)/%.o: $(SRCDIR)/%.cpp | $(BUILD_APP_DIR)
	$(CXX) $(CXXFLAGS) -I$(INCDIR) -c -o $@ $<

# Regra para compilar os arquivos de teste
$(BUILD_TEST_DIR)/%.o: $(TESTDIR)/%.cpp | $(BUILD_TEST_DIR)
	$(CXX) $(CXXFLAGS) -I$(INCDIR) -c -o $@ $<

# Regra para compilar a aplicação e os testes
build: $(BUILD_APP_DIR) $(BUILD_TEST_DIR) $(EXEC) $(TEST_EXEC)

# Linkagem dos objetos para criar o executável da aplicação
$(EXEC): $(OBJS_APP)
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LDFLAGS)

# Linkagem dos objetos para criar o executável dos testes
$(TEST_EXEC): $(OBJS_TEST) $(filter-out $(BUILD_APP_DIR)/main.o,$(OBJS_APP))
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