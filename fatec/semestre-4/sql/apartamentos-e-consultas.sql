DROP TABLE IF EXISTS TB_Reserva_BrunoAguiar;
DROP TABLE IF EXISTS TB_Status_BrunoAguiar;
DROP TABLE IF EXISTS TB_Areacomum_BrunoAguiar;
DROP TABLE IF EXISTS TB_Apartamento_BrunoAguiar;
DROP TABLE IF EXISTS TB_Proprietario_BrunoAguiar;
DROP TABLE IF EXISTS TB_Bloco_BrunoAguiar;
DROP TABLE IF EXISTS TB_Condominio_BrunoAguiar;

CREATE TABLE TB_Condominio_BrunoAguiar
(
	id_cond INT PRIMARY KEY,
	nm_cond VARCHAR(100) NOT NULL,
	nr_cnpj VARCHAR(25) NOT NULL
);

CREATE TABLE TB_Bloco_BrunoAguiar
(
	id_bloco INT PRIMARY KEY,
	id_cond INT,
	nm_bloco VARCHAR(100) NOT NULL,
	
	FOREIGN KEY (id_cond) REFERENCES TB_Condominio_BrunoAguiar(id_cond)
);

CREATE TABLE TB_Proprietario_BrunoAguiar
(
	id_prop INT PRIMARY KEY,
	nm_prop VARCHAR(100) NOT NULL,
	nr_cpf VARCHAR(14) NOT NULL,
	nr_tel VARCHAR(20) NOT NULL
);

CREATE TABLE TB_Apartamento_BrunoAguiar
(
	id_ap INT PRIMARY KEY,
	id_bloco INT,
	nr_ap INT,
	nr_andar INT,
	id_prop INT, 
	valor_venal DECIMAL(18,2), 
	nr_metragem DECIMAL(10,2),
	
	FOREIGN KEY (id_bloco) REFERENCES TB_Bloco_BrunoAguiar(id_bloco),
	FOREIGN KEY (id_prop) REFERENCES TB_Proprietario_BrunoAguiar(id_prop)
);

CREATE TABLE TB_Areacomum_BrunoAguiar
(
	id_area INT PRIMARY KEY,
	nm_area VARCHAR(100) NOT NULL
);

CREATE TABLE TB_Status_BrunoAguiar
(
	id_status INT PRIMARY KEY,
	nm_status VARCHAR(100) NOT NULL
);

CREATE TABLE TB_Reserva_BrunoAguiar
(
	id_reserva INT PRIMARY KEY,
	id_area INT,
	id_prop INT,
	dt_reserva DATE,
	id_status INT,

	FOREIGN KEY (id_area) REFERENCES TB_Areacomum_BrunoAguiar(id_area),
	FOREIGN KEY (id_prop) REFERENCES TB_Proprietario_BrunoAguiar(id_prop),
	FOREIGN KEY (id_status) REFERENCES TB_Status_BrunoAguiar(id_status)
);

-- TB_Condominio
INSERT INTO TB_Condominio_BrunoAguiar VALUES (1, 'Residencial Verde', '101.001.222/0001-76');

-- TB_Bloco
INSERT INTO TB_Bloco_BrunoAguiar VALUES (1, 1, 'Araucária');
INSERT INTO TB_Bloco_BrunoAguiar VALUES (2, 1, 'Cambuci');
INSERT INTO TB_Bloco_BrunoAguiar VALUES (3, 1, 'Pitangueira');

-- TB_Proprietario (Cadastros únicos sem duplicidade de chaves)
INSERT INTO TB_Proprietario_BrunoAguiar VALUES (1, 'João Silva', '11111111111', '11999999999');
INSERT INTO TB_Proprietario_BrunoAguiar VALUES (2, 'Maria Souza', '22222222222', '11988888888');
INSERT INTO TB_Proprietario_BrunoAguiar VALUES (3, 'Carlos Pereira', '33333333333', '11977777777');
INSERT INTO TB_Proprietario_BrunoAguiar VALUES (4, 'Ana Lima', '44444444444', '11966666666');
INSERT INTO TB_Proprietario_BrunoAguiar VALUES (5, 'Fernanda Rocha', '66666666666', '11944444444');
INSERT INTO TB_Proprietario_BrunoAguiar VALUES (6, 'Ricardo Alves', '77777777777', '11933333333');
INSERT INTO TB_Proprietario_BrunoAguiar VALUES (7, 'Paula Martins', '88888888888', '11922222222');
INSERT INTO TB_Proprietario_BrunoAguiar VALUES (8, 'Lucas Mendes', '99999999999', '11911111111');
INSERT INTO TB_Proprietario_BrunoAguiar VALUES (9, 'Marcos Silva', '10101010101', '11888888888');
INSERT INTO TB_Proprietario_BrunoAguiar VALUES (10, 'Juliana Castro', '20202020202', '11777777777');
INSERT INTO TB_Proprietario_BrunoAguiar VALUES (11, 'Roberto Dias', '30303030303', '11666666666');
INSERT INTO TB_Proprietario_BrunoAguiar VALUES (12, 'Patrícia Gomes', '40404040404', '11555555555');
INSERT INTO TB_Proprietario_BrunoAguiar VALUES (13, 'Eduardo Ribeiro', '50505050505', '11444444444');
INSERT INTO TB_Proprietario_BrunoAguiar VALUES (14, 'Camila Freitas', '60606060606', '11333333333');
INSERT INTO TB_Proprietario_BrunoAguiar VALUES (15, 'Rafael Teixeira', '70707070707', '11222222222');
INSERT INTO TB_Proprietario_BrunoAguiar VALUES (16, 'Beatriz Lima', '80808080808', '11111111110');
INSERT INTO TB_Proprietario_BrunoAguiar VALUES (17, 'Gustavo Santos', '90909090909', '11000000000');

-- TB_Apartamento (Bloco Araucária)
INSERT INTO TB_Apartamento_BrunoAguiar VALUES (1, 1, 101, 1, 1, 250000.00, 100);
INSERT INTO TB_Apartamento_BrunoAguiar VALUES (2, 1, 102, 1, 2, 655000.00, 150);
INSERT INTO TB_Apartamento_BrunoAguiar VALUES (3, 1, 201, 2, 3, 260000.00, 100);
INSERT INTO TB_Apartamento_BrunoAguiar VALUES (4, 1, 202, 2, 4, 262000.00, 150);
INSERT INTO TB_Apartamento_BrunoAguiar VALUES (5, 1, 301, 3, 5, 272000.00, 150);
INSERT INTO TB_Apartamento_BrunoAguiar VALUES (6, 1, 302, 3, 6, 274000.00, 100);
INSERT INTO TB_Apartamento_BrunoAguiar VALUES (7, 1, 401, 4, 7, 280000.00, 150);
INSERT INTO TB_Apartamento_BrunoAguiar VALUES (8, 1, 402, 4, 8, 285000.00, 100);

-- TB_Apartamento (Bloco Cambuci)
INSERT INTO TB_Apartamento_BrunoAguiar VALUES (9, 2, 101, 1, 9, 250000.00, 100);
INSERT INTO TB_Apartamento_BrunoAguiar VALUES (10, 2, 102, 1, 10, 255000.00, 150);
INSERT INTO TB_Apartamento_BrunoAguiar VALUES (11, 2, 201, 2, 11, 260000.00, 100);
INSERT INTO TB_Apartamento_BrunoAguiar VALUES (12, 2, 202, 2, 12, 262000.00, 150);
INSERT INTO TB_Apartamento_BrunoAguiar VALUES (13, 2, 301, 3, 13, 270000.00, 100);
INSERT INTO TB_Apartamento_BrunoAguiar VALUES (14, 2, 302, 3, 14, 272000.00, 150);
INSERT INTO TB_Apartamento_BrunoAguiar VALUES (15, 2, 401, 4, 15, 280000.00, 100);
INSERT INTO TB_Apartamento_BrunoAguiar VALUES (16, 2, 402, 4, 16, 282000.00, 150);

-- TB_Apartamento (Bloco Pitangueira - IDs de proprietários mapeados para os cadastros corretos)
INSERT INTO TB_Apartamento_BrunoAguiar VALUES (17, 3, 101, 1, 17, 290000.00, 100); -- Gustavo Santos
INSERT INTO TB_Apartamento_BrunoAguiar VALUES (18, 3, 102, 1, 4,  295000.00, 150); -- Ana Lima (id_prop: 4)
INSERT INTO TB_Apartamento_BrunoAguiar VALUES (19, 3, 201, 2, 1,  250000.00, 100); -- João Silva (id_prop: 1)
INSERT INTO TB_Apartamento_BrunoAguiar VALUES (20, 3, 202, 2, 2,  255000.00, 150); -- Maria Souza (id_prop: 2)
INSERT INTO TB_Apartamento_BrunoAguiar VALUES (21, 3, 301, 3, 3,  260000.00, 100); -- Carlos Pereira (id_prop: 3)
INSERT INTO TB_Apartamento_BrunoAguiar VALUES (22, 3, 302, 3, 5,  272000.00, 150); -- Fernanda Rocha (id_prop: 5)
INSERT INTO TB_Apartamento_BrunoAguiar VALUES (23, 3, 401, 4, 6,  274000.00, 100); -- Ricardo Alves (id_prop: 6)
INSERT INTO TB_Apartamento_BrunoAguiar VALUES (24, 3, 402, 4, 7,  280000.00, 150); -- Paula Martins (id_prop: 7)
INSERT INTO TB_Apartamento_BrunoAguiar VALUES (25, 3, 501, 5, 8,  285000.00, 100); -- Lucas Mendes (id_prop: 8)
INSERT INTO TB_Apartamento_BrunoAguiar VALUES (26, 3, 502, 5, 9,  290000.00, 150); -- Marcos Silva (id_prop: 9)

-- TB_Areacomum
INSERT INTO TB_Areacomum_BrunoAguiar VALUES (1, 'Churrasqueira');
INSERT INTO TB_Areacomum_BrunoAguiar VALUES (2, 'Salão de festas');
INSERT INTO TB_Areacomum_BrunoAguiar VALUES (3, 'Quadra');

-- TB_Status
INSERT INTO TB_Status_BrunoAguiar VALUES (1, 'Pendente');
INSERT INTO TB_Status_BrunoAguiar VALUES (2, 'Confirmada');
INSERT INTO TB_Status_BrunoAguiar VALUES (3, 'Cancelada');

-- TB_Reserva (IDs de proprietários mapeados para os cadastros corretos)
INSERT INTO TB_Reserva_BrunoAguiar VALUES (1, 1, 1, '2025-06-15', 2);
INSERT INTO TB_Reserva_BrunoAguiar VALUES (2, 3, 1, '2025-06-20', 2);
INSERT INTO TB_Reserva_BrunoAguiar VALUES (3, 2, 2, '2025-06-22', 1);
INSERT INTO TB_Reserva_BrunoAguiar VALUES (4, 3, 3, '2025-06-18', 2);
INSERT INTO TB_Reserva_BrunoAguiar VALUES (5, 1, 6, '2025-06-28', 2);
INSERT INTO TB_Reserva_BrunoAguiar VALUES (6, 2, 6, '2025-07-02', 1);
INSERT INTO TB_Reserva_BrunoAguiar VALUES (7, 3, 7, '2025-07-01', 2);
INSERT INTO TB_Reserva_BrunoAguiar VALUES (8, 2, 9, '2025-05-07', 2);
INSERT INTO TB_Reserva_BrunoAguiar VALUES (9, 3, 9, '2025-07-07', 2);
INSERT INTO TB_Reserva_BrunoAguiar VALUES (10, 1, 10, '2025-07-02', 1);
INSERT INTO TB_Reserva_BrunoAguiar VALUES (11, 3, 11, '2025-07-10', 2);
INSERT INTO TB_Reserva_BrunoAguiar VALUES (12, 2, 13, '2025-07-12', 1);
INSERT INTO TB_Reserva_BrunoAguiar VALUES (13, 1, 15, '2025-07-15', 2);
INSERT INTO TB_Reserva_BrunoAguiar VALUES (14, 3, 15, '2025-07-18', 3);
INSERT INTO TB_Reserva_BrunoAguiar VALUES (15, 2, 17, '2025-07-20', 2);
INSERT INTO TB_Reserva_BrunoAguiar VALUES (16, 3, 1, '2025-07-22', 2);  -- João Silva (id_prop: 1)
INSERT INTO TB_Reserva_BrunoAguiar VALUES (17, 1, 1, '2025-07-25', 2);  -- João Silva (id_prop: 1)
INSERT INTO TB_Reserva_BrunoAguiar VALUES (18, 2, 3, '2025-07-28', 1);  -- Carlos Pereira (id_prop: 3)
INSERT INTO TB_Reserva_BrunoAguiar VALUES (19, 3, 6, '2025-08-01', 2);  -- Ricardo Alves (id_prop: 6)
INSERT INTO TB_Reserva_BrunoAguiar VALUES (20, 2, 6, '2025-08-03', 2);  -- Ricardo Alves (id_prop: 6)
INSERT INTO TB_Reserva_BrunoAguiar VALUES (21, 1, 8, '2025-08-05', 3);  -- Lucas Mendes (id_prop: 8)

--CONSTRUINDO SELECTS
/*1. Quantos apartamentos existem no condomínio?*/
SELECT COUNT(id_ap) FROM TB_Apartamento_BrunoAguiar

/*2. Qual o nome dos condomínios cadastrados?*/
SELECT DISTINCT nm_cond FROM TB_Condominio_BrunoAguiar;

/*3. Quais blocos pertencem ao condomínio Residencial Verde?*/
SELECT DISTINCT nm_bloco FROM TB_Bloco_BrunoAguiar;

/*4. Quantas reservas existem no total?*/
select COUNT(id_reserva) FROM TB_Reserva_BrunoAguiar;

/*5. Quais apartamentos estão no bloco Araucária?*/
SELECT * FROM TB_Apartamento_BrunoAguiar WHERE id_bloco = 1;

/*6. Quantas reservas estão confirmadas?*/
SELECT * FROM TB_Reserva_BrunoAguiar WHERE id_status = 2;

/*7. Quais apartamentos têm valor venal acima de 270.000?*/
SELECT * FROM TB_Apartamento_BrunoAguiar WHERE valor_venal > 270000;

/*8. Quantos apartamentos existem por bloco?*/
SELECT COUNT(id_ap) AS Bloco_Araucaria FROM TB_Apartamento_BrunoAguiar WHERE id_bloco = 1;
SELECT COUNT(id_ap) AS Bloco_Cambuci FROM TB_Apartamento_BrunoAguiar WHERE id_bloco = 2;
SELECT COUNT(id_ap) AS Bloco_Pitangueira FROM TB_Apartamento_BrunoAguiar WHERE id_bloco = 3;

/*9. Qual o valor médio dos apartamentos por bloco?*/
SELECT AVG(valor_venal) AS VM_Araucaria FROM TB_Apartamento_BrunoAguiar WHERE id_bloco = 1;
SELECT AVG(valor_venal) AS VM_Cambuci FROM TB_Apartamento_BrunoAguiar WHERE id_bloco = 2;
SELECT AVG(valor_venal) AS VM_Pitangueira FROM TB_Apartamento_BrunoAguiar WHERE id_bloco = 3;

/*10.Listar nome do condomínio, nome do bloco, nr apartamento e nome do
proprietário.*/
SELECT
    c.nm_cond AS Nome_Condominio,
    b.nm_bloco AS Nome_Bloco,
    a.nr_ap AS Numero_Apartamento,
    p.nm_prop AS Nome_Proprietario
FROM 
    TB_Condominio_BrunoAguiar c, 
    TB_Bloco_BrunoAguiar b, 
    TB_Apartamento_BrunoAguiar a, 
    TB_Proprietario_BrunoAguiar p
WHERE 
    b.id_cond = c.id_cond 
    AND a.id_bloco = b.id_bloco 
    AND a.id_prop = p.id_prop
ORDER BY 
    c.nm_cond, 
    b.nm_bloco, 
    a.nr_ap;

--11. Quais proprietários possuem mais de um apartamento?
SELECT p.nm_prop AS Nome_Proprietario, COUNT(a.id_ap) AS Total_Apartamentos
FROM TB_Proprietario_BrunoAguiar p
INNER JOIN TB_Apartamento_BrunoAguiar a ON p.id_prop = a.id_prop
GROUP BY p.nm_prop
HAVING COUNT(a.id_ap) > 1;

--12. Quais apartamentos nunca fizeram reserva?
SELECT id_ap, nr_ap, nr_andar
FROM TB_Apartamento_BrunoAguiar
WHERE id_prop NOT IN (
    SELECT DISTINCT id_prop 
    FROM TB_Reserva_BrunoAguiar
);

--13. Quantas reservas existem por status?
SELECT s.nm_status AS Status_Reserva, COUNT(r.id_reserva) AS Quantidade_Reservas
FROM TB_Status_BrunoAguiar s
LEFT JOIN TB_Reserva_BrunoAguiar r ON s.id_status = r.id_status
GROUP BY s.nm_status;

--14. Qual área comum foi mais reservada?
SELECT TOP 1 ac.nm_area AS Area_Comum, COUNT(r.id_reserva) AS Total_Reservas
FROM TB_Areacomum_BrunoAguiar ac
INNER JOIN TB_Reserva_BrunoAguiar r ON ac.id_area = r.id_area
GROUP BY ac.nm_area
ORDER BY Total_Reservas DESC;

--15. Quais apartamentos possuem reservas pendentes?
SELECT DISTINCT ap.nr_ap AS Numero_Apartamento, b.nm_bloco AS Nome_Bloco
FROM TB_Apartamento_BrunoAguiar ap
INNER JOIN TB_Bloco_BrunoAguiar b ON ap.id_bloco = b.id_bloco
INNER JOIN TB_Reserva_BrunoAguiar r ON ap.id_prop = r.id_prop
WHERE r.id_status = 1;

--16. Qual o valor total dos apartamentos por condomínio?
SELECT c.nm_cond AS Nome_Condominio, SUM(a.valor_venal) AS Valor_Total
FROM TB_Condominio_BrunoAguiar c
INNER JOIN TB_Bloco_BrunoAguiar b ON c.id_cond = b.id_cond
INNER JOIN TB_Apartamento_BrunoAguiar a ON b.id_bloco = a.id_bloco
GROUP BY c.nm_cond;

--17. Qual a média de metragem dos apartamentos?
SELECT AVG(nr_metragem) AS Media_Metragem_Geral
FROM TB_Apartamento_BrunoAguiar;

--18. Qual a média de metragem dos apartamentos por bloco?
SELECT b.nm_bloco AS Nome_Bloco, AVG(a.nr_metragem) AS Media_Metragem
FROM TB_Bloco_BrunoAguiar b
INNER JOIN TB_Apartamento_BrunoAguiar a ON b.id_bloco = a.id_bloco
GROUP BY b.nm_bloco;


--19. Quais apartamentos nunca fizeram nenhuma reserva?
SELECT ap.id_ap, ap.nr_ap, b.nm_bloco AS Nome_Bloco
FROM TB_Apartamento_BrunoAguiar ap
INNER JOIN TB_Bloco_BrunoAguiar b ON ap.id_bloco = b.id_bloco
LEFT JOIN TB_Reserva_BrunoAguiar r ON ap.id_prop = r.id_prop
WHERE r.id_reserva IS NULL;

--20. Qual o apartamento (condomínio, bloco e apto) mais caro?
SELECT TOP 1 c.nm_cond AS Nome_Condominio, b.nm_bloco AS Nome_Bloco, a.nr_ap AS Numero_Apartamento, a.valor_venal AS Valor
FROM TB_Condominio_BrunoAguiar c
INNER JOIN TB_Bloco_BrunoAguiar b ON c.id_cond = b.id_cond
INNER JOIN TB_Apartamento_BrunoAguiar a ON b.id_bloco = a.id_bloco
ORDER BY a.valor_venal DESC;
