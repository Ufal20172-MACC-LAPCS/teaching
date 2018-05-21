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

## Descrição do Código

O programa pode receber os argumentos **ucp** ou **ucp-mem** como parâmetros de execução. Qualquer outro argumento, ou a ausência destes, é inválido, e o programa retorna uma mensagem adequada. 
```C
if( argc != 2 )
{
	printf("Failed, Invalid number of parameters\n");
	return 0;

}
if( strcmp(argv[1], "ucp") != 0 && strcmp(argv[1], "ucp-mem") != 0 )
{
	printf("Failed, you can only use ucp or ucp-mem as parameter\n");
	return 0;
}
```

O processo PAI monitora o tempo, os processos de consumo de UCP e da Memória, os imprime na tela, e elimina o processo filho, encerrando o programa, quando o tempo limite é excedido. Dentro do código, após fork (criação do processo filho), é criada a string para verificar o consumo imediato da UCP e o consumo da Memória.

```C
void finish(int sig)
{
    kill(pid,SIGKILL); /* Kills the child proccess */
}

int main 
	/*.. code ..*/
	signal(SIGALRM,(void (*)(int))finish); /* Flag the function finish to kill the child processes after 10 seconds */
	/*.. code ..*/
	else if(pid > 0)
	{
	    alarm(10);
	    /*.. code ..*/
		wait(NULL);
}
```


## Utilização intensa da UCP

O nosso experimento foi realizado num notebook **ThinkPad** de configuração de processador Core Duo T2400 1.83ghz 2T, 32bits, com 3GB de memória RAM DDR-2.

Tínhamos a expectativa de que o consumo de processamento tivesse uma curva acentuada, porém gradual, com crescimento linear e apenas aritmético. 

Porém, como se pode verificar no gráfico de "consumo somente do processador", o consumo de processamento em nosso experimento foi elevado desde o início, deixando a máquina quase irresponsiva durante quase todos os 10 segundos de duração da tarefa, fazendo com que nossa experiência não acontecesse conforme esperávamos.

## Utilização intensa da UCP e memória


