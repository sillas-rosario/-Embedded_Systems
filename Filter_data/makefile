#Makefile: Utilizado para copilar varios arquivos de uma vez. Arquivo sem extensão
all:
	# Compilação Tarefa 1
	gcc -c -Wall gerador.c
	gcc -c -Wall funcoes_gerador.c
	gcc gerador.o funcoes_gerador.o -o gerador -lm

	# Compilação Tarefa 2
	gcc -c -Wall filtro.c
	gcc -c -Wall funcoes_filtro.c
	gcc filtro.o funcoes_filtro.o -o filtro -lm


	#########
	# Tarefa 1: Para gerar o sinal correspondente à soma de duas componentes
	# senoidais depois da compilação dos arquivos relativo a esta tarefa, é
	# necessário utilizar o comando ./gerador <f1> <f2> <N> <nome>, informando
	# os valores <f1> (frequência da primeira componente), <f2> (frequência da
	# segunda componente), <N> (número de amostras a ser gerado) e <nome> (nome
	# base dos arquivos gerados como resultado).
	#################
	#########
	# Tarefa 2: Para realizar a convolução entre o vetor contendo as amostras do
	# sinal de entrada e a resposta ao impulso do filtro, é necessário utilizar o
	# comando ./filtro <dados> <ri>, informando os valores <dados> (nome do arqui-
	# vo texto gerado pelo programa da Tarefa1) e <ri> (nome do arquivo texto, no
	# mesmo formato do arquivo de sinal, contendo a resposta ao impulso do filtro
	# FIR a ser aplicado sobre o sinal).
	#################
