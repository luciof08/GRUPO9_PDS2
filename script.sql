CREATE TABLE IF NOT EXISTS usuario_cliente(
	id SERIAL PRIMARY KEY,
	cpf TEXT,
	nome text,
	email text,
	senha text
);

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

CREATE TABLE IF NOT EXISTS disponibilidade_quarto (
    id SERIAL PRIMARY KEY,
    quarto_id INT REFERENCES quarto(id) ON DELETE CASCADE,
    data_inicio DATE NOT NULL,
    data_fim DATE NOT null,
    reservado BOOLEAN DEFAULT FALSE
);

CREATE TABLE IF NOT EXISTS reserva (
    id SERIAL PRIMARY KEY,
    data_inicio DATE NOT NULL,
    data_fim DATE NOT NULL,
    quarto_id INT REFERENCES quarto(id) ON DELETE cascade
);