# Identificação

* Página do repositório do trabalho ([GitHub Repo](https://github.com/Ufal20172-MACC-LAPCS/teaching)) 

* Discente 1
	* Nome: Matheus Artur Cabral Costa
	* Matrícula: 17212344
	* Distribuição da nota (%): 50
* Discente 2
	* Nome: Luis Alberto Pontes Cabus Setton
	* Matrícula: 17210977
	* Distribuição da nota (%): 50
	
# Resultados

## **Gráficos** de comportamento e métricas do processo

### Utilizando o comando para consumo somente do processador 

Executa-se o programa utilizando o comando:
```
$ ./bin ucp
```

O programa então processa o código, executando um loop infinito até que seja limitada a sua utilização da UCP pelo sistema operacional.
```C
for (;;){}
```

![alt text](https://github.com/Ufal20172-MACC-LAPCS/teaching/blob/master/2017.2-IAC/AB2.1-TP/graphs/cpu_cpu.png "Curva de utilização da CPU")

### Utilizando o comando para consumo do processador juntamente com o consumo progressivo de memória

Executa-se o programa utilizando o comando:

```
$ ./bin ucp-mem
```

O programa então processa o seguinte código, executando um loop infinito, alocando memória progressivamente, até que seja limitada a UCP ou o a Memória pelo sistema operacional.
```C
for(;;)
{
	malloc(sizeof(100));
}
```

![alt text](https://github.com/Ufal20172-MACC-LAPCS/teaching/blob/master/2017.2-IAC/AB2.1-TP/graphs/cpu_cpu-mem.png "Curva de utilização da CPU")
![alt text](https://github.com/Ufal20172-MACC-LAPCS/teaching/blob/master/2017.2-IAC/AB2.1-TP/graphs/mem_cpu-mem.png "Curva de utilização da Memória")


# Discussão

## Utilização intensa da UCP

TODO: explicar se o comportamento da curva **UCP** foi o esperado, sempre justificando sua resposta, referenciando o código fonte do programa e o gráfico do experimento realizado.

O nosso experimento foi realizado num notebook **ThinkPad** de configuração de processador Core Duo T2400 1.83ghz 2T, 32bits, com 3GB de memória RAM DDR-2.

Tínhamos a expectativa de que o consumo de processamento tivesse uma curva acentuada, porém gradual, com crescimento linear e apenas aritmético. 

Porém, como se pode verificar no gráfico de "consumo somente do processador", o consumo de processamento em nosso experimento foi elevado desde o início, deixando a máquina quase irresponsiva durante quase todos os 10 segundos de duração da tarefa, fazendo com que nossa experiência não acontecesse conforme esperávamos.

## Utilização intensa da UCP e memória

TODO: explicar se o comportamento da curva **UCP-MEM** foi o esperado, sempre justificando sua resposta, referenciando o código fonte do programa e o gráfico do experimento realizado.

