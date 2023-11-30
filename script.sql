-- CRIA AS TABELAS
CREATE TABLE IF NOT EXISTS usuario_cliente(
	id SERIAL PRIMARY KEY,
	cpf TEXT,
	nome TEXT,
	email TEXT,
	senha TEXT
);

ALTER TABLE usuario_cliente
ADD CONSTRAINT cpf_unique UNIQUE (cpf);

ALTER TABLE usuario_cliente
ADD CONSTRAINT email_unique UNIQUE (email);

CREATE TABLE IF NOT EXISTS hotel(
	id SERIAL PRIMARY KEY,
	nome TEXT,
	cnpj TEXT,
	telefone_contato TEXT,
	endereco TEXT
);

CREATE TABLE IF NOT EXISTS quarto (
    id SERIAL PRIMARY KEY,
    numero INT NOT NULL,
    hotel_id INT REFERENCES hotel(id) ON DELETE CASCADE
);

ALTER TABLE quarto
ADD COLUMN localizacao TEXT;

CREATE TABLE IF NOT EXISTS reserva (
    id SERIAL PRIMARY KEY,
    data_inicio DATE NOT NULL,
    data_fim DATE NOT NULL,
    quarto_id INT REFERENCES quarto(id) ON DELETE cascade,
    usuario_cliente_id INT REFERENCES usuario_cliente(id) ON DELETE cascade
);

ALTER TABLE reserva
ADD COLUMN forma_pagamento INT;

-- ADICIONA ALGUNS DADOS
insert into hotel (nome, cnpj, telefone_contato, endereco)
values ('Hotel 5 Estrelas', '89.802.696/0001-83', '00-00000-0000', 'Rua das Árvores, n. 5');
insert into hotel (nome, cnpj, telefone_contato, endereco)
values ('Hotel Resort', '66.323.826/0001-08', '11-11111-1111', 'Rua da Floresta, s/n');
insert into hotel (nome, cnpj, telefone_contato, endereco)
values ('Hotel Fazenda', '77.363.826/0001-09', '22-22222-2222', 'Rua dos Eucaliptos');

insert into usuario_cliente (cpf, nome,	email, senha)
values ('000.000.000-00', 'Maria','maria@email.com', '123');
insert into usuario_cliente (cpf, nome,	email, senha)
values ('111.111.111-11', 'José','jose@email.com', '123');

INSERT INTO public.quarto
(numero, hotel_id, localizacao)
VALUES(1, 1, 'Térreo');
INSERT INTO public.quarto
(numero, hotel_id, localizacao)
VALUES(2, 1, '1o andar');
INSERT INTO public.quarto
(numero, hotel_id, localizacao)
VALUES(3, 1, '1o andar');
INSERT INTO public.quarto
(numero, hotel_id, localizacao)
VALUES(1, 2, '2o andar');
INSERT INTO public.quarto
(numero, hotel_id, localizacao)
VALUES(2, 2, '2o andar');
INSERT INTO public.quarto
(numero, hotel_id, localizacao)
VALUES(3, 2, '2o andar');
INSERT INTO public.quarto
(numero, hotel_id, localizacao)
VALUES(1, 3, 'Cobertura');
INSERT INTO public.quarto
(numero, hotel_id, localizacao)
VALUES(2, 3, 'Cobertura');

insert into reserva(data_inicio, data_fim, quarto_id, usuario_cliente_id, forma_pagamento)
values ('2023-12-15', '2023-12-18', 2, 1, 3);
insert into reserva(data_inicio, data_fim, quarto_id, usuario_cliente_id, forma_pagamento)
values ('2024-04-15', '2024-04-18', 2, 2, 2);
insert into reserva(data_inicio, data_fim, quarto_id, usuario_cliente_id, forma_pagamento)
values ('2024-02-23', '2024-02-26', 3, 1, 4);