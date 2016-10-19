-- phpMyAdmin SQL Dump
-- version 3.5.2.2
-- http://www.phpmyadmin.net
--
-- Servidor: localhost
-- Tempo de Geração: 18/05/2013 às 20:43:15
-- Versão do Servidor: 5.5.27
-- Versão do PHP: 5.4.7

SET SQL_MODE="NO_AUTO_VALUE_ON_ZERO";
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8 */;

--
-- Banco de Dados: `Contato`
--

-- --------------------------------------------------------

--
-- Estrutura da tabela `Informacoes`
--

CREATE TABLE IF NOT EXISTS `Informacoes` (
  `id_contatos` int(11) NOT NULL AUTO_INCREMENT,
  `nomeCompleto` varchar(40) COLLATE utf8_unicode_ci NOT NULL,
  `eMail` varchar(20) COLLATE utf8_unicode_ci NOT NULL,
  `empresa` varchar(40) COLLATE utf8_unicode_ci NOT NULL,
  `assunto` varchar(20) COLLATE utf8_unicode_ci NOT NULL,
  `mensagem` varchar(100) COLLATE utf8_unicode_ci NOT NULL,
  PRIMARY KEY (`id_contatos`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COLLATE=utf8_unicode_ci AUTO_INCREMENT=1 ;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
