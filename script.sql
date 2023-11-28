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