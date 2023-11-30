# Apresentação

Sistema desenvolvido para realizar reserva em hospedagem.


## Funcionalidades

1. O usuário se cadastra (caso ainda não tenha cadastro)
2. O usuário realiza login
3. O sistema exibe para o usuário:
    - As opções de hotéis para reserva
    - As reservas já realizadas
    - A opção de realizar reserva 
4. O usuário escolhe o hotel
5. O sistema exibe ao usuário os quartos e as datas disponíveis para os quartos
6. O usuário escolhe o quarto que deseja reservar e informa as datas de início e fim da estadia
    - O sistema valida se o quarto está disponível naquela data
    - O sistema valida se a data inicial é maior ou igual que a data atual
    - O sistema valida se a data final é superior a data inicial
7. Após a seleção das datas, o sistema deve informar o preço final
8. O sistema exibe as formas de pagamento disponíveis para o hotel
9. O usuário informa a forma de pagamento e confirma a reserva 

# Dependências para execução do projeto

- framework doctest para testes de unidade (https://github.com/doctest/doctest)
- ferramenta Doxygen para documentação (http://www.doxygen.org/)
- banco de dados postgres para armazenamento dos dados
   - como instalar a lib para o banco de dados postgres para Ubuntu (linux): [https://howtoinstall.co/package/libpqxx-dev#google_vignette](https://howtoinstall.co/package/libpqxx-dev#google_vignette)


# Instruções de compilação e execução

## Para iniciar o banco de dados

Deve-se instalar um banco de dados postgres e executar os scripts do arquivo `script.sql`, para criar
as tabelas e inicializar alguns dados.

## Para compilar a aplicação e os testes

```
make build
```

## Para executar os testes

```
make test
```

## Para executar a aplicação

```
make run
```

## Para gerar a documentação

```
doxygen Doxyfile
```