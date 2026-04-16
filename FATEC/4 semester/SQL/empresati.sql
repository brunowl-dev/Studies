CREATE TABLE TB_Cliente
(
	id_cliente INT PRIMARY KEY,
	nm_cliente VARCHAR(100) NOT NULL,
	nr_cnpj VARCHAR(14) NOT NULL,
	ds_email VARCHAR(100) NOT NULL
);

INSERT INTO TB_Cliente VALUES (1, 'Contabilidade Fama', '00', 'contato@contabilfama.com.br');
INSERT INTO TB_Cliente VALUES (2, 'FATEC Rubens Lara', '11', 'matriz@fatecrubenslara.com.br');
INSERT INTO TB_Cliente VALUES (3, 'Lotus Garimpo', '22', 'lotusgarimpo@lotus.com.br');

CREATE TABLE TB_Status_projeto
(
	id_status INT PRIMARY KEY,
	nm_status VARCHAR(100) NOT NULL
);

INSERT INTO TB_Status_projeto VALUES (1, 'TO-DO');
INSERT INTO TB_Status_projeto VALUES (2, 'EM ANDAMENTO');
INSERT INTO TB_Status_projeto VALUES (3, 'FEITO');

CREATE TABLE TB_Proj
(
	id_projeto INT,
	nm_projeto VARCHAR(100) NOT NULL,
	ds_projeto VARCHAR(100) NOT NULL,
	dt_inicio DATE NOT NULL,
	dt_fim DATE NOT NULL,
	vl_orcamento MONEY,
	id_cliente INT, --FK
	id_status INT, --FK

	FOREIGN KEY (id_cliente) REFERENCES TB_Cliente(id_cliente),
	FOREIGN KEY (id_status) REFERENCES TB_Status_projeto(id_status),
	PRIMARY KEY (id_projeto)
);

INSERT INTO TB_Proj VALUES (1, 'Automação de IR', 'Automações para declaração de imposto de renda', '16/04/2026', '16/05/2026', 1500, 1, 1);
INSERT INTO TB_Proj VALUES (2, 'Repositório remoto de materiais', 'Site contendo os materiais/apostilas usados pelos professores', '16/04/2026', '16/05/2026', 1000, 2, 2);
INSERT INTO TB_Proj VALUES (3, 'E-Commerce', 'Site próprio de venda de roupas', '16/04/2026', '16/05/2026', 1000, 3, 3);

CREATE TABLE TB_Cargo2
(
	id_cargo INT PRIMARY KEY,
	nm_cargo VARCHAR(100) NOT NULL
);

INSERT INTO TB_Cargo2 VALUES (1, 'Estagiário');
INSERT INTO TB_Cargo2 VALUES (2, 'Coordenador');
INSERT INTO TB_Cargo2 VALUES (3, 'Desenvolvedor web pleno');

CREATE TABLE TB_Prof
(
	id_profissional INT PRIMARY KEY,
	nm_profisisonal VARCHAR(100) NOT NULL,
	ds_email VARCHAR(100) NOT NULL,
	id_cargo INT,
	FOREIGN KEY (id_cargo) REFERENCES TB_Cargo2(id_cargo)
);

INSERT INTO TB_Prof VALUES (1, 'Bruno Wai Lu', 'brunoantoniowl@gmail.com', 1);
INSERT INTO TB_Prof VALUES (2, 'Valdir Tobias', 'valdir@gmail.com', 2);
INSERT INTO TB_Prof VALUES (3, 'Rafael Durval', 'fafaelsagaz@gmail.com', 3);

CREATE TABLE TB_Alocacao
(
	id_profissional INT,
	id_projeto INT,
	dt_inicio DATE NOT NULL,
	dt_fim DATE NOT NULL,

	FOREIGN KEY (id_profissional) REFERENCES TB_Prof(id_profissional),
	FOREIGN KEY (id_projeto) REFERENCES TB_Proj(id_projeto)
);

INSERT INTO TB_Alocacao VALUES (1, 1, '16/04/2026', '16/05/2026');
INSERT INTO TB_Alocacao VALUES (2, 2, '16/04/2026', '16/05/2026');
INSERT INTO TB_Alocacao VALUES (3, 3, '16/04/2026', '16/05/2026');

SELECT
prof.nm_profisisonal,
proj.nm_projeto
FROM TB_Proj proj, TB_Prof prof, TB_Alocacao a
WHERE a.id_profissional = prof.id_profissional AND a.id_projeto = proj.id_projeto
ORDER BY proj.id_projeto, prof.id_profissional;


SELECT  
p.nm_projeto,
c.nm_cliente,
s.nm_status
FROM TB_Proj p, TB_Cliente c, TB_Status_projeto s
WHERE p.id_cliente = c.id_cliente AND s.id_status = p.id_status
ORDER BY p.id_projeto, c.id_cliente, s.id_status;

