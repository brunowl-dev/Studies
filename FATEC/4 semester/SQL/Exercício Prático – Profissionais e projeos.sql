--Criação tabela cargos e seus valores
CREATE TABLE tb_cargo 
(
	id_cargo INT PRIMARY KEY,
	nm_cargo VARCHAR(100) NOT NULL
);

INSERT INTO tb_cargo VALUES (1, 'Gerente de projetos');
INSERT INTO tb_cargo VALUES (2, 'Analista de dados');
INSERT INTO tb_cargo VALUES (3, 'Desenvolvedor web');
INSERT INTO tb_cargo VALUES (4, 'Especialista em IA');

--Criação tabela profissional e inserção de valores
CREATE TABLE tb_profissional
(
	id_prof INT PRIMARY KEY,
	nm_prof VARCHAR(100) NOT NULL,
	id_cargo INT,
	FOREIGN KEY (id_cargo) REFERENCES tb_cargo(id_cargo)
);

INSERT INTO tb_profissional VALUES (1, 'Bruno Wai Lu', 1);
INSERT INTO tb_profissional VALUES (2, 'Jefferson Braga', 2);
INSERT INTO tb_profissional VALUES (3, 'Isadora Silva', 2);
INSERT INTO tb_profissional VALUES (4, 'Maria Eduarda Aguiar', 3);
INSERT INTO tb_profissional VALUES (5, 'Rafael Durval', 4);

--Criação da tabela projeto e inserção de seus valores
CREATE TABLE tb_projeto
(
	id_proj INT PRIMARY KEY,
	nm_proj VARCHAR(100) NOT NULL
);

INSERT INTO tb_projeto VALUES (1, 'CRUD');
INSERT INTO tb_projeto VALUES (2, 'Sistema de sócios');
INSERT INTO tb_projeto VALUES (3, 'IA corretora de programação');

--União das tabelas projeto e profissional
CREATE TABLE tb_proj_prof
(
	id_consulta INT PRIMARY KEY,
	id_proj INT,
	id_prof INT,
	id_cargo INT,
	FOREIGN KEY (id_prof) REFERENCES tb_profissional(id_prof),
	FOREIGN KEY (id_cargo) REFERENCES tb_cargo(id_cargo),
	FOREIGN KEY (id_proj) REFERENCES tb_projeto(id_proj)
);

INSERT INTO tb_proj_prof VALUES (1,1,1,1)
INSERT INTO tb_proj_prof VALUES (2,1,2,2)

INSERT INTO tb_proj_prof VALUES (3,2,3,3)
INSERT INTO tb_proj_prof VALUES (4,2,4,4)

INSERT INTO tb_proj_prof VALUES (5,3,5,1)
INSERT INTO tb_proj_prof VALUES (6,3,1,2)


--CONSULTA DAS TABELAS
SELECT * FROM tb_cargo;
SELECT * FROM tb_profissional;
SELECT * FROM tb_projeto;

--CONSULTA DA TABELA GERAL
SELECT
cargo.nm_cargo,
prof.nm_prof,
proj.nm_proj,
consulta.id_consulta
FROM tb_cargo cargo, tb_profissional prof, tb_projeto proj, tb_proj_prof consulta
WHERE cargo.id_cargo = consulta.id_cargo AND prof.id_prof = consulta.id_prof AND proj.id_proj = consulta.id_proj
ORDER BY proj.id_proj, prof.id_prof, cargo.id_cargo, consulta.id_consulta;

