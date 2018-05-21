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

* Utilizando o comando para consumo somente do processador 

Executa-se o programa utilizando o comando:
```
$ ./bin ucp
```

O programa então processa o código, executando um loop infinito até que seja limitada a sua utilização da UCP pelo sistema operacional.
```C
for (;;){}
```

![alt text](https://github.com/Ufal20172-MACC-LAPCS/teaching/blob/master/2017.2-IAC/AB2.1-TP/graphs/cpu_cpu.png "Curva de utilização da CPU")

* Utilizando o comando para consumo do processador juntamente com o consumo progressivo de memória

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




## Utilização intensa da UCP e memória

TODO: explicar se o comportamento da curva **UCP-MEM** foi o esperado, sempre justificando sua resposta, referenciando o código fonte do programa e o gráfico do experimento realizado.
