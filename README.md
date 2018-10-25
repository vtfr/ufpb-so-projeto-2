# [UFPB] Sistemas Operacionais: Projeto 2

## Introdução
Segundo projeto da disciplina de Sistemas Operacionais sobre Paginação de Memória Virtual.

## Descrição do Projeto

Foi requisitado a implementação de três algoritmos de paginação de memória virtual: **FIFO, LRU e Ótimo**. O programa deverá ler da entrada padrão ```STDIN``` o número de quadros que a memória virtual terá e, em seguida, os acessos de memória feitos em sequência. No final da execução o programa deverá reportar pelo ```STDOUT``` a quantidade de erros de cada algoritmo.

## Instalação

No diretório do projeto, execute

    $ make
    
Para gerar o binário ```projeto```.

## Desenvolvimento

Para compilar a versão de debug, execute:

    $ make debug

## Execução

- [x] Leitura da entrada padrão
- [x] Implementação FIFO
- [x] Implementação LRU
- [x] Implementação Ótimo
- [x] Implementação Paginador
- [x] Escrita na saída padrão
