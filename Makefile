# Makefile para compilar um programa C++ com conexão PostgreSQL usando pqxx/pqxx

# Comando do compilador
CXX = g++

# Flags de compilação e de linkagem
CXXFLAGS = -Wall -Wextra -std=c++17
LDFLAGS = -lpqxx -lpq

# Nomes dos arquivos fonte
SRCS = main.cpp ConexaoBancoDeDados.cpp RepositorioUsuario.cpp UsuarioCliente.cpp Hotel.cpp RepositorioHotel.cpp Quarto.cpp FormaDePagamentoUtil.cpp Reserva.cpp RepositorioReserva.cpp RepositorioQuarto.cpp ServicoDeHospedagem.cpp MenuUsuario.cpp EntradaUtil.cpp
OBJS = $(SRCS:.cpp=.o)
DEPS = ConexaoBancoDeDados.hpp RepositorioUsuario.hpp UsuarioCliente.hpp Hotel.hpp RepositorioHotel.hpp Quarto.hpp FormaDePagamento.hpp FormaDePagamentoUtil.hpp Reserva.hpp RepositorioReserva.hpp RepositorioQuarto.hpp ServicoDeHospedagem.hpp MenuUsuario.hpp EntradaUtil.hpp

# Arquivos-fonte para os testes
TEST_SRCS = UsuarioClienteTest.cpp ConexaoBancoDeDados.cpp RepositorioUsuario.cpp UsuarioCliente.cpp  
TEST_OBJS = $(TEST_SRCS:.cpp=.o)

# Nome do executável de teste
TEST_EXEC = testes.out

# Nome do executável
EXEC = programa.out

.PHONY: all clean

# Regra padrão, compila todos os arquivos
all: $(EXEC)

# Compilação dos arquivos objeto
%.o: %.cpp $(DEPS)
	$(CXX) $(CXXFLAGS) -c -o $@ $<

# Linkagem dos objetos para criar o executável
$(EXEC): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LDFLAGS)

# Regra para compilar os testes
tests: $(TEST_EXEC)
	./$(TEST_EXEC)

$(TEST_EXEC): $(TEST_OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LDFLAGS)

# Limpa os arquivos objetos e o executável
clean:
	rm -f $(OBJS) $(EXEC)