-- phpMyAdmin SQL Dump
-- version 4.1.6
-- http://www.phpmyadmin.net
--
-- Host: localhost
-- Generation Time: 06-Maio-2014 às 19:09
-- Versão do servidor: 5.6.16
-- PHP Version: 5.5.9

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8 */;

--
-- Database: `autohome`
--

-- --------------------------------------------------------

--
-- Estrutura da tabela `evento`
--

CREATE TABLE IF NOT EXISTS `evento` (
  `id` bigint(20) unsigned NOT NULL AUTO_INCREMENT,
  `nome_objeto` varchar(15) NOT NULL,
  `comando` varchar(15) NOT NULL,
  `intensidade` int(11) NOT NULL,
  `data_hora` datetime NOT NULL,
  `descricao` text,
  `estado` varchar(10) NOT NULL,
  PRIMARY KEY (`id`),
  UNIQUE KEY `id` (`id`)
) ENGINE=InnoDB  DEFAULT CHARSET=latin1 AUTO_INCREMENT=13 ;

--
-- Extraindo dados da tabela `evento`
--

INSERT INTO `evento` (`id`, `nome_objeto`, `comando`, `intensidade`, `data_hora`, `descricao`, `estado`) VALUES
(6, 'lamp2', 'Ligar', 0, '2014-04-17 13:02:32', 'Ligar lâmpada da cozinha', 'Aguardando'),
(7, 'lamp2', 'Desligar', 0, '2014-04-14 19:00:00', 'Desligar lâmpada', 'Aguardando'),
(8, 'lamp4', 'Ligar', 0, '2014-04-06 21:00:00', 'Desligar lâmpada', 'Aguardando'),
(9, 'lamp3', 'Desligar', 0, '2014-04-25 19:00:00', 'Desligar lâmpada', 'Aguardando'),
(10, 'lamp4', 'Ligar', 0, '2014-05-17 17:30:00', 'Teste AutoHome', 'Aguardando'),
(11, 'lamp4', 'Desligar', 0, '2014-04-01 00:30:00', 'Teste AutoHome', 'Aguardando'),
(12, 'lamp4', 'Ligar', 0, '2014-04-20 03:00:00', 'Teste AutoHome', 'Aguardando');

-- --------------------------------------------------------

--
-- Estrutura da tabela `objeto`
--

CREATE TABLE IF NOT EXISTS `objeto` (
  `nome` varchar(15) NOT NULL,
  `tipo` varchar(15) NOT NULL,
  `estado` varchar(15) NOT NULL,
  `comodo` varchar(20) NOT NULL,
  `porta_arduino` varchar(5) NOT NULL,
  PRIMARY KEY (`nome`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Extraindo dados da tabela `objeto`
--

INSERT INTO `objeto` (`nome`, `tipo`, `estado`, `comodo`, `porta_arduino`) VALUES
('lamp1', 'Lâmpada', 'Desligado', 'Terraço', '1'),
('lamp2', 'Lâmpada', 'Desligado', 'Garagem', '2'),
('lamp3', 'Lâmpada', 'Desligado', 'Varanda', '3'),
('lamp4', 'Lâmpada', 'Desligado', 'Banheiro', '4');

-- --------------------------------------------------------

--
-- Estrutura da tabela `usuario`
--

CREATE TABLE IF NOT EXISTS `usuario` (
  `login` varchar(50) NOT NULL,
  `senha` varchar(30) NOT NULL,
  `nome` varchar(50) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Extraindo dados da tabela `usuario`
--

INSERT INTO `usuario` (`login`, `senha`, `nome`) VALUES
('admin', 'admin', 'Marcello');

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
