-- Parse::SQL::Dia      version 0.23                              
-- Documentation        http://search.cpan.org/dist/Parse-Dia-SQL/
-- Environment          Perl 5.018002, /usr/bin/perl              
-- Architecture         x86_64-linux-gnu-thread-multi             
-- Target Database      postgres                                  
-- Input file           /home/hugo/Algoritmos/Mais/SQL/Pessoa.dia 
-- Generated at         Mon Sep 12 02:25:45 2016                  
-- Typemap for postgres not found in input file                   

-- get_constraints_drop 

-- get_permissions_drop 

-- get_view_drop

-- get_schema_drop
drop table Pessoa;

-- get_smallpackage_pre_sql 

-- get_schema_create
create table Pessoa (
   id         int    not null,
   nome       String         ,
   nascimento date           ,
   constraint pk_Pessoa primary key (id)
)   ;

-- get_view_create

-- get_permissions_create

-- get_inserts

-- get_smallpackage_post_sql

-- get_associations_create
