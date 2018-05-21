# Instruções de instalação

## GIT

* Instale o GIT e clone o repositório;

Abra o terminal, localize a pasta onde deseja salvar o projeto e digite os comandos:

```
# apt install git
```
```
$ git clone https://github.com/Ufal20172-MACC-LAPCS/iac.git
```

## Compilação e Execução

Ainda no terminal, na mesma pasta em que fez o Clone do repositório, localize a pasta **src**

```
$ cd teaching/2017.2-IAC/AB2.1-TP/src
```

Compile o código do programa **main.c**

```
$ gcc main.c -o bin
```

* Para execução do código com utilização intensa da UCP, utilize o seguinte comando:

```
$ ./bin ucp
```

* Para execução do código com utilização intensa da UCP e da memória:

```
$ ./bin ucp-mem
```
