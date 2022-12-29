--
-- PostgreSQL database dump
--

-- Dumped from database version 11.7 (Debian 11.7-0+deb10u1)
-- Dumped by pg_dump version 11.7 (Debian 11.7-0+deb10u1)

SET statement_timeout = 0;
SET lock_timeout = 0;
SET idle_in_transaction_session_timeout = 0;
SET client_encoding = 'UTF8';
SET standard_conforming_strings = on;
SELECT pg_catalog.set_config('search_path', '', false);
SET check_function_bodies = false;
SET xmloption = content;
SET client_min_messages = warning;
SET row_security = off;

--
-- Name: G4_Farmacia; Type: SCHEMA; Schema: -; Owner: labdb
--

CREATE SCHEMA "G4_Farmacia";


ALTER SCHEMA "G4_Farmacia" OWNER TO labdb;

--
-- Name: SCHEMA "G4_Farmacia"; Type: COMMENT; Schema: -; Owner: labdb
--

COMMENT ON SCHEMA "G4_Farmacia" IS 'Guilherme de Lima
Kaylan
Lucas Lobato
Lucas Gonçalves e Alves';


--
-- Name: cargo_seq; Type: SEQUENCE; Schema: G4_Farmacia; Owner: labdb
--

CREATE SEQUENCE "G4_Farmacia".cargo_seq
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER TABLE "G4_Farmacia".cargo_seq OWNER TO labdb;

SET default_tablespace = '';

SET default_with_oids = false;

--
-- Name: cargo; Type: TABLE; Schema: G4_Farmacia; Owner: labdb
--

CREATE TABLE "G4_Farmacia".cargo (
    id integer DEFAULT nextval('"G4_Farmacia".cargo_seq'::regclass) NOT NULL,
    privilegio integer NOT NULL,
    "remuneração" double precision NOT NULL,
    descricao character varying(100) NOT NULL
);


ALTER TABLE "G4_Farmacia".cargo OWNER TO labdb;

--
-- Name: consumidor_seq; Type: SEQUENCE; Schema: G4_Farmacia; Owner: labdb
--

CREATE SEQUENCE "G4_Farmacia".consumidor_seq
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER TABLE "G4_Farmacia".consumidor_seq OWNER TO labdb;

--
-- Name: consumidor; Type: TABLE; Schema: G4_Farmacia; Owner: labdb
--

CREATE TABLE "G4_Farmacia".consumidor (
    id integer DEFAULT nextval('"G4_Farmacia".consumidor_seq'::regclass) NOT NULL,
    num_rua integer NOT NULL,
    rua character varying(100) NOT NULL,
    compl_rua character varying(30) NOT NULL,
    nome character varying(50) NOT NULL,
    telefone character varying(12) NOT NULL,
    email character varying(50) NOT NULL
);


ALTER TABLE "G4_Farmacia".consumidor OWNER TO labdb;

--
-- Name: distribuidora_seq; Type: SEQUENCE; Schema: G4_Farmacia; Owner: labdb
--

CREATE SEQUENCE "G4_Farmacia".distribuidora_seq
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER TABLE "G4_Farmacia".distribuidora_seq OWNER TO labdb;

--
-- Name: distribuidora; Type: TABLE; Schema: G4_Farmacia; Owner: labdb
--

CREATE TABLE "G4_Farmacia".distribuidora (
    id integer DEFAULT nextval('"G4_Farmacia".distribuidora_seq'::regclass) NOT NULL,
    num_rua integer,
    compl_rua character varying(15) NOT NULL,
    nome character varying(50) NOT NULL,
    rua character varying(100) NOT NULL
);


ALTER TABLE "G4_Farmacia".distribuidora OWNER TO labdb;

--
-- Name: estoque_seq; Type: SEQUENCE; Schema: G4_Farmacia; Owner: labdb
--

CREATE SEQUENCE "G4_Farmacia".estoque_seq
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER TABLE "G4_Farmacia".estoque_seq OWNER TO labdb;

--
-- Name: estoque; Type: TABLE; Schema: G4_Farmacia; Owner: labdb
--

CREATE TABLE "G4_Farmacia".estoque (
    id integer DEFAULT nextval('"G4_Farmacia".estoque_seq'::regclass) NOT NULL,
    id_produto integer NOT NULL,
    id_farmacia integer NOT NULL,
    quantidade integer NOT NULL
);


ALTER TABLE "G4_Farmacia".estoque OWNER TO labdb;

--
-- Name: farmacia_seq; Type: SEQUENCE; Schema: G4_Farmacia; Owner: labdb
--

CREATE SEQUENCE "G4_Farmacia".farmacia_seq
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER TABLE "G4_Farmacia".farmacia_seq OWNER TO labdb;

--
-- Name: farmacia; Type: TABLE; Schema: G4_Farmacia; Owner: labdb
--

CREATE TABLE "G4_Farmacia".farmacia (
    id integer DEFAULT nextval('"G4_Farmacia".farmacia_seq'::regclass) NOT NULL,
    nome character varying(50) NOT NULL,
    telefone character varying(12) NOT NULL,
    rua character varying(100) NOT NULL,
    compl_rua character varying(15) NOT NULL,
    email character varying(50) NOT NULL,
    num_rua integer
);


ALTER TABLE "G4_Farmacia".farmacia OWNER TO labdb;

--
-- Name: funcionario_seq; Type: SEQUENCE; Schema: G4_Farmacia; Owner: labdb
--

CREATE SEQUENCE "G4_Farmacia".funcionario_seq
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER TABLE "G4_Farmacia".funcionario_seq OWNER TO labdb;

--
-- Name: funcionario; Type: TABLE; Schema: G4_Farmacia; Owner: labdb
--

CREATE TABLE "G4_Farmacia".funcionario (
    id integer DEFAULT nextval('"G4_Farmacia".funcionario_seq'::regclass) NOT NULL,
    id_farmacia integer NOT NULL,
    nif character varying(11) NOT NULL,
    id_cargo integer NOT NULL,
    nome character(100) NOT NULL
);


ALTER TABLE "G4_Farmacia".funcionario OWNER TO labdb;

--
-- Name: lote_seq; Type: SEQUENCE; Schema: G4_Farmacia; Owner: labdb
--

CREATE SEQUENCE "G4_Farmacia".lote_seq
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER TABLE "G4_Farmacia".lote_seq OWNER TO labdb;

--
-- Name: lote; Type: TABLE; Schema: G4_Farmacia; Owner: labdb
--

CREATE TABLE "G4_Farmacia".lote (
    id integer DEFAULT nextval('"G4_Farmacia".lote_seq'::regclass) NOT NULL,
    id_farmacia integer NOT NULL,
    id_distribuidora integer NOT NULL,
    validade date NOT NULL,
    produto integer NOT NULL
);


ALTER TABLE "G4_Farmacia".lote OWNER TO labdb;

--
-- Name: pedido_seq; Type: SEQUENCE; Schema: G4_Farmacia; Owner: labdb
--

CREATE SEQUENCE "G4_Farmacia".pedido_seq
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER TABLE "G4_Farmacia".pedido_seq OWNER TO labdb;

--
-- Name: pedido; Type: TABLE; Schema: G4_Farmacia; Owner: labdb
--

CREATE TABLE "G4_Farmacia".pedido (
    id integer DEFAULT nextval('"G4_Farmacia".pedido_seq'::regclass) NOT NULL,
    data_compra date NOT NULL,
    id_consumidor integer NOT NULL,
    valor double precision NOT NULL
);


ALTER TABLE "G4_Farmacia".pedido OWNER TO labdb;

--
-- Name: produto_seq; Type: SEQUENCE; Schema: G4_Farmacia; Owner: labdb
--

CREATE SEQUENCE "G4_Farmacia".produto_seq
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER TABLE "G4_Farmacia".produto_seq OWNER TO labdb;

--
-- Name: produto; Type: TABLE; Schema: G4_Farmacia; Owner: labdb
--

CREATE TABLE "G4_Farmacia".produto (
    id integer DEFAULT nextval('"G4_Farmacia".produto_seq'::regclass) NOT NULL,
    data_validade date NOT NULL,
    data_compra date NOT NULL,
    codigo character varying(10) NOT NULL,
    principio_ativo character varying(50) NOT NULL
);


ALTER TABLE "G4_Farmacia".produto OWNER TO labdb;

--
-- Name: produto_pedido; Type: TABLE; Schema: G4_Farmacia; Owner: labdb
--

CREATE TABLE "G4_Farmacia".produto_pedido (
    id integer NOT NULL,
    id_pedido integer NOT NULL,
    id_produto integer
);


ALTER TABLE "G4_Farmacia".produto_pedido OWNER TO labdb;

--
-- Name: produto_pedido_seq; Type: SEQUENCE; Schema: G4_Farmacia; Owner: labdb
--

CREATE SEQUENCE "G4_Farmacia".produto_pedido_seq
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER TABLE "G4_Farmacia".produto_pedido_seq OWNER TO labdb;

--
-- Data for Name: cargo; Type: TABLE DATA; Schema: G4_Farmacia; Owner: labdb
--

INSERT INTO "G4_Farmacia".cargo VALUES (1, 1, 1200, 'Auxiliar de Caixa');
INSERT INTO "G4_Farmacia".cargo VALUES (2, 1, 2000, 'Estagiário');
INSERT INTO "G4_Farmacia".cargo VALUES (3, 2, 1800, 'Caixa');
INSERT INTO "G4_Farmacia".cargo VALUES (4, 2, 2100, 'Auxiliar Administrativo');
INSERT INTO "G4_Farmacia".cargo VALUES (5, 3, 3100, 'Farmacêutico');
INSERT INTO "G4_Farmacia".cargo VALUES (6, 3, 2500, 'Mercearia ');
INSERT INTO "G4_Farmacia".cargo VALUES (7, 4, 5000, 'Gerente');


--
-- Data for Name: consumidor; Type: TABLE DATA; Schema: G4_Farmacia; Owner: labdb
--

INSERT INTO "G4_Farmacia".consumidor VALUES (1, 55, 'Copacabana Palace', '202', 'Luerbio Fazia', '21998704567', 'lufazia@hotmail.com');
INSERT INTO "G4_Farmacia".consumidor VALUES (2, 88, 'Rua Major Freitas', 'fundos', 'Lucas Lobato', '21998784567', 'lobatoo@hotmail.com');
INSERT INTO "G4_Farmacia".consumidor VALUES (3, 90, 'Tenente Lazaro', 'casa', 'Andrea Costo', '21978704567', 'cosdrea@hotmail.com');


--
-- Data for Name: distribuidora; Type: TABLE DATA; Schema: G4_Farmacia; Owner: labdb
--

INSERT INTO "G4_Farmacia".distribuidora VALUES (1, 9, 'fabrica', 'Insul Manipulada', 'Rua Hebreus');
INSERT INTO "G4_Farmacia".distribuidora VALUES (2, 45, 'fabrica', 'Pirulas Rocha', 'Projetada');
INSERT INTO "G4_Farmacia".distribuidora VALUES (3, 89, 'fabrica', 'Colgate SA', 'Rua General Andrade de Neves');


--
-- Data for Name: estoque; Type: TABLE DATA; Schema: G4_Farmacia; Owner: labdb
--



--
-- Data for Name: farmacia; Type: TABLE DATA; Schema: G4_Farmacia; Owner: labdb
--

INSERT INTO "G4_Farmacia".farmacia VALUES (1, 'G4_Farm Copacabana', '213488-6969', 'Av. Nossa Sra. de Copacabana', 'Fachada', 'copacabana@g4farm.com.br', 551);
INSERT INTO "G4_Farmacia".farmacia VALUES (2, 'G4_Farm Caxias', '2134865512', 'Rua Mariano Sendra dos Santos', 'segundo andar', 'caxias@g4farm.com.br', 32);
INSERT INTO "G4_Farmacia".farmacia VALUES (3, 'G4_Farm Tijuca I', '2132134577', 'Rua Conde de Bonfim', 'Fachada', 'tijucai@g4farm.com.br', 120);


--
-- Data for Name: funcionario; Type: TABLE DATA; Schema: G4_Farmacia; Owner: labdb
--

INSERT INTO "G4_Farmacia".funcionario VALUES (1, 3, '18609120788', 1, 'Fernando Costinha                                                                                   ');
INSERT INTO "G4_Farmacia".funcionario VALUES (3, 3, '02344456788', 3, 'Luerbio Fazia                                                                                       ');
INSERT INTO "G4_Farmacia".funcionario VALUES (4, 3, '02346456788', 4, 'Alexandre Rojas                                                                                     ');
INSERT INTO "G4_Farmacia".funcionario VALUES (5, 3, '02346456088', 5, 'Francisco Zero Ponto Cinco                                                                          ');
INSERT INTO "G4_Farmacia".funcionario VALUES (2, 3, '02366789678', 7, 'Lucas Gonçalves e Alves                                                                             ');


--
-- Data for Name: lote; Type: TABLE DATA; Schema: G4_Farmacia; Owner: labdb
--

INSERT INTO "G4_Farmacia".lote VALUES (1, 3, 1, '2022-12-25', 1);
INSERT INTO "G4_Farmacia".lote VALUES (2, 1, 1, '2022-12-25', 1);
INSERT INTO "G4_Farmacia".lote VALUES (3, 2, 1, '2022-12-25', 1);
INSERT INTO "G4_Farmacia".lote VALUES (4, 2, 3, '2023-06-25', 2);
INSERT INTO "G4_Farmacia".lote VALUES (6, 2, 2, '2023-12-30', 4);


--
-- Data for Name: pedido; Type: TABLE DATA; Schema: G4_Farmacia; Owner: labdb
--

INSERT INTO "G4_Farmacia".pedido VALUES (1, '2022-04-20', 2, 150.5);


--
-- Data for Name: produto; Type: TABLE DATA; Schema: G4_Farmacia; Owner: labdb
--

INSERT INTO "G4_Farmacia".produto VALUES (1, '2022-12-25', '2022-05-03', '1111111111', 'insulina glargina');
INSERT INTO "G4_Farmacia".produto VALUES (2, '2024-12-25', '2022-05-04', '2687899999', 'Enxaguante Bucal');
INSERT INTO "G4_Farmacia".produto VALUES (3, '2022-12-25', '2022-05-03', '1117899999', 'Insulina Novo Rapid');
INSERT INTO "G4_Farmacia".produto VALUES (4, '2024-12-25', '2022-04-20', '2687898979', 'Hidroxicloroquina');
INSERT INTO "G4_Farmacia".produto VALUES (5, '2022-12-20', '2022-04-20', '2587898979', 'Vitamina C');


--
-- Data for Name: produto_pedido; Type: TABLE DATA; Schema: G4_Farmacia; Owner: labdb
--

INSERT INTO "G4_Farmacia".produto_pedido VALUES (1, 1, 1);
INSERT INTO "G4_Farmacia".produto_pedido VALUES (2, 1, 3);


--
-- Name: cargo_seq; Type: SEQUENCE SET; Schema: G4_Farmacia; Owner: labdb
--

SELECT pg_catalog.setval('"G4_Farmacia".cargo_seq', 7, true);


--
-- Name: consumidor_seq; Type: SEQUENCE SET; Schema: G4_Farmacia; Owner: labdb
--

SELECT pg_catalog.setval('"G4_Farmacia".consumidor_seq', 3, true);


--
-- Name: distribuidora_seq; Type: SEQUENCE SET; Schema: G4_Farmacia; Owner: labdb
--

SELECT pg_catalog.setval('"G4_Farmacia".distribuidora_seq', 3, true);


--
-- Name: estoque_seq; Type: SEQUENCE SET; Schema: G4_Farmacia; Owner: labdb
--

SELECT pg_catalog.setval('"G4_Farmacia".estoque_seq', 1, false);


--
-- Name: farmacia_seq; Type: SEQUENCE SET; Schema: G4_Farmacia; Owner: labdb
--

SELECT pg_catalog.setval('"G4_Farmacia".farmacia_seq', 3, true);


--
-- Name: funcionario_seq; Type: SEQUENCE SET; Schema: G4_Farmacia; Owner: labdb
--

SELECT pg_catalog.setval('"G4_Farmacia".funcionario_seq', 5, true);


--
-- Name: lote_seq; Type: SEQUENCE SET; Schema: G4_Farmacia; Owner: labdb
--

SELECT pg_catalog.setval('"G4_Farmacia".lote_seq', 6, true);


--
-- Name: pedido_seq; Type: SEQUENCE SET; Schema: G4_Farmacia; Owner: labdb
--

SELECT pg_catalog.setval('"G4_Farmacia".pedido_seq', 1, true);


--
-- Name: produto_pedido_seq; Type: SEQUENCE SET; Schema: G4_Farmacia; Owner: labdb
--

SELECT pg_catalog.setval('"G4_Farmacia".produto_pedido_seq', 1, false);


--
-- Name: produto_seq; Type: SEQUENCE SET; Schema: G4_Farmacia; Owner: labdb
--

SELECT pg_catalog.setval('"G4_Farmacia".produto_seq', 5, true);


--
-- Name: cargo cargo_pkey; Type: CONSTRAINT; Schema: G4_Farmacia; Owner: labdb
--

ALTER TABLE ONLY "G4_Farmacia".cargo
    ADD CONSTRAINT cargo_pkey PRIMARY KEY (id);


--
-- Name: consumidor consumidor_pkey; Type: CONSTRAINT; Schema: G4_Farmacia; Owner: labdb
--

ALTER TABLE ONLY "G4_Farmacia".consumidor
    ADD CONSTRAINT consumidor_pkey PRIMARY KEY (id);


--
-- Name: distribuidora distribuidora_pkey; Type: CONSTRAINT; Schema: G4_Farmacia; Owner: labdb
--

ALTER TABLE ONLY "G4_Farmacia".distribuidora
    ADD CONSTRAINT distribuidora_pkey PRIMARY KEY (id);


--
-- Name: estoque estoque_pkey; Type: CONSTRAINT; Schema: G4_Farmacia; Owner: labdb
--

ALTER TABLE ONLY "G4_Farmacia".estoque
    ADD CONSTRAINT estoque_pkey PRIMARY KEY (id);


--
-- Name: farmacia farmacia_pkey; Type: CONSTRAINT; Schema: G4_Farmacia; Owner: labdb
--

ALTER TABLE ONLY "G4_Farmacia".farmacia
    ADD CONSTRAINT farmacia_pkey PRIMARY KEY (id);


--
-- Name: funcionario funcionario_pkey; Type: CONSTRAINT; Schema: G4_Farmacia; Owner: labdb
--

ALTER TABLE ONLY "G4_Farmacia".funcionario
    ADD CONSTRAINT funcionario_pkey PRIMARY KEY (id);


--
-- Name: lote lote_pkey; Type: CONSTRAINT; Schema: G4_Farmacia; Owner: labdb
--

ALTER TABLE ONLY "G4_Farmacia".lote
    ADD CONSTRAINT lote_pkey PRIMARY KEY (id);


--
-- Name: pedido pedido_pkey; Type: CONSTRAINT; Schema: G4_Farmacia; Owner: labdb
--

ALTER TABLE ONLY "G4_Farmacia".pedido
    ADD CONSTRAINT pedido_pkey PRIMARY KEY (id);


--
-- Name: produto_pedido produto_pedido_pkey; Type: CONSTRAINT; Schema: G4_Farmacia; Owner: labdb
--

ALTER TABLE ONLY "G4_Farmacia".produto_pedido
    ADD CONSTRAINT produto_pedido_pkey PRIMARY KEY (id);


--
-- Name: produto produto_pkey; Type: CONSTRAINT; Schema: G4_Farmacia; Owner: labdb
--

ALTER TABLE ONLY "G4_Farmacia".produto
    ADD CONSTRAINT produto_pkey PRIMARY KEY (id);


--
-- Name: funcionario fk_cargo_funcionario; Type: FK CONSTRAINT; Schema: G4_Farmacia; Owner: labdb
--

ALTER TABLE ONLY "G4_Farmacia".funcionario
    ADD CONSTRAINT fk_cargo_funcionario FOREIGN KEY (id_cargo) REFERENCES "G4_Farmacia".cargo(id);


--
-- Name: pedido fk_consumidor_pedido; Type: FK CONSTRAINT; Schema: G4_Farmacia; Owner: labdb
--

ALTER TABLE ONLY "G4_Farmacia".pedido
    ADD CONSTRAINT fk_consumidor_pedido FOREIGN KEY (id_consumidor) REFERENCES "G4_Farmacia".consumidor(id);


--
-- Name: lote fk_distribuidora_lote; Type: FK CONSTRAINT; Schema: G4_Farmacia; Owner: labdb
--

ALTER TABLE ONLY "G4_Farmacia".lote
    ADD CONSTRAINT fk_distribuidora_lote FOREIGN KEY (id_distribuidora) REFERENCES "G4_Farmacia".distribuidora(id);


--
-- Name: estoque fk_farmacia_estoque; Type: FK CONSTRAINT; Schema: G4_Farmacia; Owner: labdb
--

ALTER TABLE ONLY "G4_Farmacia".estoque
    ADD CONSTRAINT fk_farmacia_estoque FOREIGN KEY (id_farmacia) REFERENCES "G4_Farmacia".farmacia(id);


--
-- Name: lote fk_farmacia_lote; Type: FK CONSTRAINT; Schema: G4_Farmacia; Owner: labdb
--

ALTER TABLE ONLY "G4_Farmacia".lote
    ADD CONSTRAINT fk_farmacia_lote FOREIGN KEY (id_farmacia) REFERENCES "G4_Farmacia".farmacia(id);


--
-- Name: funcionario fk_farmcia_funcionario; Type: FK CONSTRAINT; Schema: G4_Farmacia; Owner: labdb
--

ALTER TABLE ONLY "G4_Farmacia".funcionario
    ADD CONSTRAINT fk_farmcia_funcionario FOREIGN KEY (id_farmacia) REFERENCES "G4_Farmacia".farmacia(id);


--
-- Name: produto_pedido fk_pedido_produto_pedido; Type: FK CONSTRAINT; Schema: G4_Farmacia; Owner: labdb
--

ALTER TABLE ONLY "G4_Farmacia".produto_pedido
    ADD CONSTRAINT fk_pedido_produto_pedido FOREIGN KEY (id_pedido) REFERENCES "G4_Farmacia".pedido(id);


--
-- Name: produto_pedido fk_produto; Type: FK CONSTRAINT; Schema: G4_Farmacia; Owner: labdb
--

ALTER TABLE ONLY "G4_Farmacia".produto_pedido
    ADD CONSTRAINT fk_produto FOREIGN KEY (id_produto) REFERENCES "G4_Farmacia".produto(id);


--
-- Name: estoque fk_produto_estoque; Type: FK CONSTRAINT; Schema: G4_Farmacia; Owner: labdb
--

ALTER TABLE ONLY "G4_Farmacia".estoque
    ADD CONSTRAINT fk_produto_estoque FOREIGN KEY (id_produto) REFERENCES "G4_Farmacia".produto(id);


--
-- PostgreSQL database dump complete
--

