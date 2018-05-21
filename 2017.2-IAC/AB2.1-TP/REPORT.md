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

Utilizando o comando para consumo somente do processador 

```
$ ./bin ucp
```
![alt text](https://github.com/Ufal20172-MACC-LAPCS/teaching/blob/master/2017.2-IAC/AB2.1-TP/graphs/cpu_cpu.png "Utilização da CPU")

Utilizando o comando para consumo do processador juntamente com o consumo progressivo de memória

```
$ ./bin ucp-mem
```
![alt text](https://github.com/Ufal20172-MACC-LAPCS/teaching/blob/master/2017.2-IAC/AB2.1-TP/graphs/cpu_cpu-mem.png "Utilização da CPU")
![alt text](https://github.com/Ufal20172-MACC-LAPCS/teaching/blob/master/2017.2-IAC/AB2.1-TP/graphs/mem_cpu-mem.png "Utilização da Memória")

##

* TODO: Plotar um gráfico com os resultados das medições das seguintes métricas utilizadas para avaliar o comportamento do **processo filho**:
	*  **UCP**: consumo da UCP em porcentagem.
	*  **UCP-MEM**: consumo da memória principal em Kilobytes.
* TODO: Cada métrica deve ser plotada em duas curvas separadas.
* TODO: o eixo das abscissas deve representar o tempo medido a cada segundo e o eixo das coordenadas deve representar a métrica medida.


# Discussão

## Utilização intensa da UCP



TODO: explicar se o comportamento da curva **UCP** foi o esperado, sempre justificando sua resposta, referenciando o código fonte do programa e o gráfico do experimento realizado.

## Utilização intensa da UCP e memória

TODO: explicar se o comportamento da curva **UCP-MEM** foi o esperado, sempre justificando sua resposta, referenciando o código fonte do programa e o gráfico do experimento realizado.
