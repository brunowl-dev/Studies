/*DROP TABLE tb_veiculo
DROP TABLE tb_servico
DROP TABLE tb_manutencao*/

--CRIAÇÃO TABELA VEICULO
CREATE TABLE tb_veiculo
(
	id_veiculo INT PRIMARY KEY,
	nm_veiculo VARCHAR(100) NOT NULL,
	qt_ano INT NOT NULL
);

--INSERIR 5 VEÍCULOS DIFERENTES
INSERT INTO tb_veiculo VALUES (1, 'Gol', 2010);
INSERT INTO tb_veiculo VALUES (2, 'Kwid', 2017);
INSERT INTO tb_veiculo VALUES (3, 'Palio', 2005);
INSERT INTO tb_veiculo VALUES (4, 'Celta', 2007);
INSERT INTO tb_veiculo VALUES (5, 'Corsa', 2009);

--CRIAÇÃO TABELA SERVICO
CREATE TABLE tb_servico
(
	id_servico INT PRIMARY KEY,
	nm_servico VARCHAR(100) NOT NULL,
	qt_custo MONEY
);

--INSERIR 5 SERVIÇOS DIFERENTES
INSERT INTO tb_servico VALUES(1,'Troca de câmbio', 2500);
INSERT INTO tb_servico VALUES(2, 'Troca de óleo', 500);
INSERT INTO tb_servico VALUES(3, 'Revisão de freio', 300);
INSERT INTO tb_servico VALUES(4, 'Manutenção da suspensão', 500);
INSERT INTO tb_servico VALUES(5, 'Inserir multimedia', 300);

--CRIAÇÃO TABELA MANUTENCAO
CREATE TABLE tb_manutencao
(
	id_veiculo INT, --FK
	id_manutencao INT,
	id_servico INT, --FK
	dt_manutencao DATE,
	FOREIGN KEY (id_veiculo) REFERENCES tb_veiculo(id_veiculo), --RELACIONANDO ID_VEICULO COM A TB_VEICULO
	FOREIGN KEY (id_servico) REFERENCES tb_servico(id_servico), --RELACIONANDO ID_SERVICO COM A TB_SERVICO
	PRIMARY KEY (id_veiculo, id_manutencao)
);

-- Inserir manutenções de forma que:  
--1 veículo com 1 manutenção  
INSERT INTO tb_manutencao VALUES (1, 1, 1, '02/04/2026');

--2 veículos com 2 manutenções  
INSERT INTO tb_manutencao VALUES (2, 1, 2, '03/04/2026');
INSERT INTO tb_manutencao VALUES (2, 2, 3, '03/04/2026');

INSERT INTO tb_manutencao VALUES (3, 1, 4, '04/04/2026');
INSERT INTO tb_manutencao VALUES (3, 2, 5, '04/04/2026');

--2 veículos com 3 manutenções  
INSERT INTO tb_manutencao VALUES (4, 1, 1, '05/04/2026');
INSERT INTO tb_manutencao VALUES (4, 2, 2, '05/04/2026');
INSERT INTO tb_manutencao VALUES (4, 3, 3, '05/04/2026');

INSERT INTO tb_manutencao VALUES (5, 1, 4, '06/04/2026');
INSERT INTO tb_manutencao VALUES (5, 2, 5, '06/04/2026');
INSERT INTO tb_manutencao VALUES (5, 3, 1, '06/04/2026');

--Alguns veículos sem manutenções ?
INSERT INTO tb_manutencao VALUES (1, 0, 1, '07/04/2026');
INSERT INTO tb_manutencao VALUES (2, 0, 1, '07/04/2026');
INSERT INTO tb_manutencao VALUES (3, 0, 1, '07/04/2026');

/*
--Testar integridade referencial 
--1. Inserir manutenção com veículo inexistente → deve gerar erro  
INSERT INTO tb_manutencao VALUES (0, 1, 1, '08/04/2026');

--2. Inserir manutenção com serviço inexistente → deve gerar erro  
INSERT INTO tb_manutencao VALUES (1, 1, 0, '09/04/2026');

--3. Tentar deletar veículo com manutenção → deve gerar erro  
DELETE FROM tb_veiculo WHERE id_veiculo = 1;

--4. Tentar deletar serviço usado em manutenção → deve gerar erro 
DELETE FROM tb_servico WHERE id_servico = 1; */

--CONSULTAS
--Listar todos os veículos  
SELECT * FROM tb_veiculo
--Listar todos os serviços  
SELECT * FROM tb_servico
--Listar manutenções com veículo e serviço   - ?
SELECT  
v.nm_veiculo, 
s.nm_servico,
m.id_manutencao 
FROM tb_veiculo v, tb_servico s, tb_manutencao m 
WHERE v.id_veiculo = m.id_veiculo AND s.id_servico = m.id_servico 
ORDER BY v.id_veiculo, s.id_servico, m.id_manutencao; 
--Contar quantidade de veículos 
SELECT COUNT(*) AS qt_total_veiculos 
FROM tb_veiculo; 