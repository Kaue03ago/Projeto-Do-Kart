/* ==========================================================================
 * Universidade Federal de São Carlos - Campus Sorocaba
 * Disciplina: Organização de Recuperação da Informação
 * Prof. Tiago A. Almeida
 *
 * Trabalho 01 - Indexação
 *
 * ========================================================================== *
 *   <<< IMPLEMENTE AQUI!!! COPIE E COLE O CONTEÚDO DESTE ARQUIVO NO AVA >>>
 * ========================================================================== */

/* Bibliotecas */
#include "ORI_T01_HEADER.h"

/* ===========================================================================
 * ================================= FUNÇÕES ================================= */


/* <<< COLOQUE AQUI OS DEMAIS PROTÓTIPOS DE FUNÇÕES, SE NECESSÁRIO >>> */


/* Funções auxiliares para o qsort.
 * Com uma pequena alteração, é possível utilizá-las no bsearch, assim, evitando código duplicado.
 * */

/* Função de comparação entre chaves do índice corredores_idx */
int qsort_corredores_idx(const void *a, const void *b) {
    return strcmp( ( (corredores_index *)a )->id_corredor, ( (corredores_index *)b )->id_corredor);
}

/* Função de comparação entre chaves do índice veiculos_idx */
int qsort_veiculos_idx(const void *a, const void *b) {
	/*IMPLEMENTE A FUNÇÃO AQUI*/
	return strcmp(
		((veiculos_index*)a)->id_veiculo,
		((veiculos_index*)b)->id_veiculo
		);
}

/* Função de comparação entre chaves do índice pistas_idx */
int qsort_pistas_idx(const void *a, const void *b) {
	/*IMPLEMENTE A FUNÇÃO AQUI*/
	//printf(ERRO_NAO_IMPLEMENTADO, "qsort_pistas_idx()");

	return strcmp( 
		( (pistas_index *)a )->id_pista, 
		( (pistas_index *)b )->id_pista
		);
}

/* Função de comparação entre chaves do índice corridas_idx */
int qsort_corridas_idx(const void *a, const void *b) {
	/*IMPLEMENTE A FUNÇÃO AQUI*/
	//printf(ERRO_NAO_IMPLEMENTADO, "qsort_corridas_idx()");

	int aux = strcmp(
		((corridas_index*)a)->id_pista,
		((corridas_index*)b)->id_pista
	);

	if(aux!=0){
		return aux;
	}
	return qsort_data_idx(a,b);


}

/* Funções de comparação apenas entre data de ocorrencia do índice corridas_idx */
int qsort_data_idx(const void *a, const void *b){
	/*IMPLEMENTE A FUNÇÃO AQUI*/
	//printf(ERRO_NAO_IMPLEMENTADO, "qsort_data_idx()");

	return strcmp( 
		( (corridas_index *)b )->ocorrencia,
		( (corridas_index *)a )->ocorrencia
		);

}

/* Função de comparação entre chaves do índice nome_pista_idx */
int qsort_nome_pista_idx(const void *a, const void *b){
	/*IMPLEMENTE A FUNÇÃO AQUI*/
	//printf(ERRO_NAO_IMPLEMENTADO, "qsort_nome_pista_idx()");

	return strcmp(
		( (nome_pista_index *)a )->nome,
		( (nome_pista_index *)b )->nome
		);
}

/* Função de comparação entre chaves do índice preco_veiculo_idx */
int qsort_preco_veiculo_idx(const void *a, const void *b){
	/*IMPLEMENTE A FUNÇÃO AQUI*/
	//printf(ERRO_NAO_IMPLEMENTADO, "qsort_preco_veiculo_idx()");
	    
	// Converte os ponteiros para double para comparar os valores de preço entre os elementos a e b
	double *aux = (double *)a, *aux2 = (double *)b;

	if (*aux > *aux2){
		return 1;
	}
    if (*aux < *aux2){
		return -1;
	}

    return 0;
}

/* Função de comparação entre chaves do índice secundário de corredor_veiculos_secundario_idx */
int qsort_corredor_veiculos_secundario_idx(const void *a, const void *b){
	/*IMPLEMENTE A FUNÇÃO AQUI*/
	//printf(ERRO_NAO_IMPLEMENTADO, "qsort_corredor_veiculos_secundario_idx()");

	return strcmp(
		((corredor_veiculos_secundario_index *)a)->chave_secundaria,
		((corredor_veiculos_secundario_index *)b)->chave_secundaria
		);

}

/* Cria o índice respectivo */
void criar_corredores_idx() {
    if (!corredores_idx)
        corredores_idx = malloc(MAX_REGISTROS * sizeof(corredores_index));
 
    if (!corredores_idx) {
        printf(ERRO_MEMORIA_INSUFICIENTE);
        exit(1);
    }
 
    for (unsigned i = 0; i < qtd_registros_corredores; ++i) {
        Corredor c = recuperar_registro_corredor(i);
 
        if (strncmp(c.id_corredor, "*|", 2) == 0)
            corredores_idx[i].rrn = -1; // registro excluído
        else
            corredores_idx[i].rrn = i;
 
        strcpy(corredores_idx[i].id_corredor, c.id_corredor);
    }
 
    qsort(corredores_idx, qtd_registros_corredores, sizeof(corredores_index), qsort_corredores_idx);
    printf(INDICE_CRIADO, "corredores_idx");
}

void criar_veiculos_idx() {
	/*IMPLEMENTE A FUNÇÃO AQUI*/
	//printf(ERRO_NAO_IMPLEMENTADO, "criar_veiculos_idx()");

	// criar o indice de veiculos alocar mem p armazena lo, preencher com os registros de veiculos 
	//disponiveis e imprimir uma msg mostrando q o indice foi criado com sucesso

	if (!veiculos_idx){
		veiculos_idx = malloc(MAX_REGISTROS * sizeof(veiculos_index));
	}

	if (!veiculos_idx){//verificando alocação 
		printf(ERRO_MEMORIA_INSUFICIENTE);
		exit(1);
	}

	for (unsigned i = 0; i < qtd_registros_veiculos; ++i){
		Veiculo auxVeiculo = recuperar_registro_veiculo(i);
		if (strncmp(auxVeiculo.id_veiculo, "*|", 2) == 0){
			veiculos_idx[i].rrn = -1;
		}
		else{
			veiculos_idx[i].rrn = i;
		}


		strcpy(veiculos_idx[i].id_veiculo, auxVeiculo.id_veiculo);
	}

	printf(INDICE_CRIADO, "veiculos_idx");
}

void criar_pistas_idx() {
	/*IMPLEMENTE A FUNÇÃO AQUI*/
	//printf(ERRO_NAO_IMPLEMENTADO, "criar_pistas_idx()");


	if (!pistas_idx){
		pistas_idx = malloc(MAX_REGISTROS * sizeof(pistas_index));
	}
	if (!pistas_idx){
		printf(ERRO_MEMORIA_INSUFICIENTE);
		
		exit(1);
	}

	for (unsigned i = 0; i < qtd_registros_pistas; ++i){
		Pista auxPista = recuperar_registro_pista(i);

		pistas_idx[i].rrn = i;//ind recebe o rrn=i
		
		strcpy(pistas_idx[i].id_pista, auxPista.id_pista);//copiando o id da pista para o indice
	}
	printf(INDICE_CRIADO, "pistas_idx");
}

void criar_corridas_idx() {
    /*IMPLEMENTE A FUNÇÃO AQUI*/
	//printf(ERRO_NAO_IMPLEMENTADO, "criar_corridas_idx()");

    if (!corridas_idx){
		corridas_idx = malloc(MAX_REGISTROS * sizeof(corridas_index));
	}
	if (!corridas_idx){
		printf(ERRO_MEMORIA_INSUFICIENTE);
		exit(1);
	}

	for (unsigned i = 0; i < qtd_registros_corridas; ++i){
		Corrida auxCorrida = recuperar_registro_corrida(i);

		corridas_idx[i].rrn = i;
		strncpy(corridas_idx[i].id_pista, auxCorrida.id_pista,8);
		//strncpy(corridas_idx[i].ocorrencia, auxCorrida.ocorrencia,4);//tam string errado
		strncpy(corridas_idx[i].ocorrencia, auxCorrida.ocorrencia,12);


	}
	qsort(corridas_idx, qtd_registros_corridas, sizeof(corridas_index), qsort_corridas_idx);//ordenando o indice

	printf(INDICE_CRIADO, "corridas_idx");
}

void criar_nome_pista_idx() {
    /*IMPLEMENTE A FUNÇÃO AQUI*/
	//printf(ERRO_NAO_IMPLEMENTADO, "criar_nome_pista_idx()");


	if (!nome_pista_idx){
		nome_pista_idx = malloc(MAX_REGISTROS * sizeof(nome_pista_index));
	}
	if (!nome_pista_idx){
		printf(ERRO_MEMORIA_INSUFICIENTE);
		exit(1);
	}
	for(unsigned i = 0; i < qtd_registros_pistas; ++i){
		
		Pista auxPista = recuperar_registro_pista(i);

		strcpy(nome_pista_idx[i].nome, auxPista.nome);
		//nome_pista_idx[i].rrn = i;
		strcpy(nome_pista_idx[i].id_pista, auxPista.id_pista);
	}
	qsort(nome_pista_idx, qtd_registros_pistas, sizeof(nome_pista_index), qsort_nome_pista_idx);//
	
	printf(INDICE_CRIADO, "nome_pista_idx");
}

void criar_preco_veiculo_idx() {
    /*IMPLEMENTE A FUNÇÃO AQUI*/
	//printf(ERRO_NAO_IMPLEMENTADO, "criar_preco_veiculo_idx()");


	if(!preco_veiculo_idx){
		preco_veiculo_idx = malloc(MAX_REGISTROS * sizeof(preco_veiculo_index));
	}
	if(!preco_veiculo_idx){
		printf(ERRO_MEMORIA_INSUFICIENTE);
		exit(1);
	}
	for(unsigned i = 0; i < qtd_registros_veiculos; ++i){
		Veiculo auxVeiculo = recuperar_registro_veiculo(i);

		if(strncmp(auxVeiculo.id_veiculo, "*|", 2) == 0){
			veiculos_idx[i].rrn = -1;
			}
		else{
			veiculos_idx[i].rrn = i;
		}
		preco_veiculo_idx[i].preco = auxVeiculo.preco;

		strcpy(preco_veiculo_idx[i].id_veiculo, auxVeiculo.id_veiculo);
	}
	qsort(preco_veiculo_idx, qtd_registros_veiculos, sizeof(preco_veiculo_index), qsort_preco_veiculo_idx);

	printf(INDICE_CRIADO, "preco_veiculo_idx");
}

void criar_corredor_veiculos_idx() {
    /*IMPLEMENTE A FUNÇÃO AQUI*/
	//printf(ERRO_NAO_IMPLEMENTADO, "criar_corredor_veiculos_idx()");

		printf(INDICE_CRIADO, "corredor_veiculos_idx");

}

/* Exibe um registro com base no RRN */
bool exibir_corredor(int rrn) {
    if (rrn < 0)
        return false;
 
    Corredor c = recuperar_registro_corredor(rrn);
 
    printf("%s, %s, %s, %s, %.2lf\n", c.id_corredor, c.nome, c.apelido, c.cadastro, c.saldo);
    return true;
}

bool exibir_veiculo(int rrn) {
    /*IMPLEMENTE A FUNÇÃO AQUI*/
	//printf(ERRO_NAO_IMPLEMENTADO, "exibir_veiculo()");

	if(rrn < 0){
		return false;
	}

	Veiculo auxVeiculo = recuperar_registro_veiculo(rrn);

	printf("%s, %s, %s, %s, %d, %d, %d, %.2lf\n", auxVeiculo.id_veiculo, auxVeiculo.marca, auxVeiculo.modelo, auxVeiculo.poder, auxVeiculo.velocidade, auxVeiculo.aceleracao, auxVeiculo.peso, auxVeiculo.preco);
	
	return true;
}

bool exibir_pista(int rrn) {
	/*IMPLEMENTE A FUNÇÃO AQUI*/
	// printf(ERRO_NAO_IMPLEMENTADO, "exibir_pista()");
	


	if(rrn < 0){
		return false;
	}

	Pista auxPista = recuperar_registro_pista(rrn);

	printf("%s, %s, %d, %d, %d\n", auxPista.id_pista, auxPista.nome, auxPista.dificuldade, auxPista.distancia, auxPista.recorde);
	return true;
}

bool exibir_corrida(int rrn) {
	/*IMPLEMENTE A FUNÇÃO AQUI*/
	//printf(ERRO_NAO_IMPLEMENTADO, "exibir_corrida()");
	

	if(rrn < 0){
		return false;
	}

	Corrida auxCorrida = recuperar_registro_corrida(rrn);

	printf("%s, %s, %s, %s\n", auxCorrida.id_pista, auxCorrida.ocorrencia, auxCorrida.id_corredores, auxCorrida.id_veiculos);
	return true;
}

/* Recupera do arquivo o registro com o RRN informado
 * e retorna os dados nas structs */
Corredor recuperar_registro_corredor(int rrn) {
	Corredor c;
	char temp[TAM_REGISTRO_CORREDOR + 1], *p;
	strncpy(temp, ARQUIVO_CORREDORES + (rrn * TAM_REGISTRO_CORREDOR), TAM_REGISTRO_CORREDOR);
	temp[TAM_REGISTRO_CORREDOR] = '\0';

	p = strtok(temp, ";");
	strcpy(c.id_corredor, p);
	p = strtok(NULL, ";");
	strcpy(c.nome, p);
	p = strtok(NULL, ";");
	strcpy(c.apelido, p);
	p = strtok(NULL, ";");
	strcpy(c.cadastro, p);
	p = strtok(NULL, ";");
	c.saldo = atof(p);
	p = strtok(NULL, ";");

	for(int i = 0; i < QTD_MAX_VEICULO; ++i)
		c.veiculos[i][0] = '\0';

	if(p[0] != '#') {
		p = strtok(p, "|");

		for(int pos = 0; p; p = strtok(NULL, "|"), ++pos)
			strcpy(c.veiculos[pos], p);
	}

	return c;
}

Veiculo recuperar_registro_veiculo(int rrn) {
	Veiculo v;
	/*IMPLEMENTE A FUNÇÃO AQUI*/
	//printf(ERRO_NAO_IMPLEMENTADO, "recuperar_registro_veiculo()");

	char temp[TAM_REGISTRO_VEICULO + 1], *p;
	strncpy(temp, ARQUIVO_VEICULOS + (rrn * TAM_REGISTRO_VEICULO), TAM_REGISTRO_VEICULO);
	temp[TAM_REGISTRO_VEICULO] = '\0';

	p = strtok(temp, ";");
	strcpy(v.id_veiculo, p);
	p = strtok(NULL, ";");
	strcpy(v.marca, p);
	p = strtok(NULL, ";");
	strcpy(v.modelo, p);
	p = strtok(NULL, ";");
	strcpy(v.poder, p);
	p = strtok(NULL, ";");
	v.velocidade = atoi(p);
	p = strtok(NULL, ";");
	v.aceleracao = atoi(p);
	p = strtok(NULL, ";");
	v.peso = atoi(p);
	p = strtok(NULL, ";");
	v.preco = atof(p);
	return v;
	}

Pista recuperar_registro_pista(int rrn) {
	Pista p;
	/*IMPLEMENTE A FUNÇÃO AQUI*/
	//printf(ERRO_NAO_IMPLEMENTADO, "recuperar_registro_pista()");

	char temp[TAM_REGISTRO_PISTA + 1], *point;
	strncpy(temp, ARQUIVO_PISTAS + (rrn * TAM_REGISTRO_PISTA), TAM_REGISTRO_PISTA);
	temp[TAM_REGISTRO_PISTA] = '\0';


	point = strtok(temp, ";");
	strcpy(p.id_pista, point);
	point = strtok(NULL, ";");
	strcpy(p.nome, point);
	point = strtok(NULL, ";");
	p.dificuldade = atoi(point);
	point = strtok(NULL, ";");
	p.distancia = atoi(point);
	point = strtok(NULL, ";");
	p.recorde = atoi(point);
	return p;
}

Corrida recuperar_registro_corrida(int rrn) {
	Corrida c;

	/*IMPLEMENTE A FUNÇÃO AQUI*/
//	printf(ERRO_NAO_IMPLEMENTADO, "recuperar_registro_corrida()");

	char temp[TAM_REGISTRO_CORRIDA + 1];
	char ponto1[9];//id_pista
	char ponto2[13];//ocorrencia
	char ponto3[67];//id_corredores
	//char ponto4[92];//
	char ponto4[43];//id_veiculos

	strncpy(temp, ARQUIVO_CORRIDAS + (rrn * TAM_REGISTRO_CORRIDA), TAM_REGISTRO_CORRIDA);

	temp[TAM_REGISTRO_CORRIDA] = '\0';

	strncpy(ponto1, temp, 8);
	ponto1[8] = '\0';
	strcpy(c.id_pista, ponto1);


	strncpy(ponto2, temp + 8, 12);
	ponto2[12] = '\0';
	strcpy(c.ocorrencia, ponto2);


	strncpy(ponto3, temp + 20, 66);
	ponto3[66] = '\0';
	strcpy(c.id_corredores, ponto3);



	strncpy(ponto4, temp + 86, 42);//
	ponto4[42] = '\0';
	strcpy(c.id_veiculos, ponto4);

	return c;
}

/* Escreve em seu respectivo arquivo na posição informada (RRN) */
void escrever_registro_corredor(Corredor c, int rrn) {
	char temp[TAM_REGISTRO_CORREDOR + 1], p[100];
	temp[0] = '\0'; p[0] = '\0';

	strcpy(temp, c.id_corredor);
	strcat(temp, ";");
	strcat(temp, c.nome);
	strcat(temp, ";");
	strcat(temp, c.apelido);
	strcat(temp, ";");
	strcat(temp, c.cadastro);
	strcat(temp, ";");
	sprintf(p, "%013.2lf", c.saldo);
	strcat(temp, p);
	strcat(temp, ";");

	for(int i = 0, k = 0; i < QTD_MAX_VEICULO; ++i) {
		if(strlen(c.veiculos[i]) > 0) {
			if (k == 0)
				k = 1;
			else
				strcat(temp, "|");
			strcat(temp, c.veiculos[i]);
		}
	}
	strcat(temp, ";");

	strpadright(temp, '#', TAM_REGISTRO_CORREDOR);

	strncpy(ARQUIVO_CORREDORES + rrn*TAM_REGISTRO_CORREDOR, temp, TAM_REGISTRO_CORREDOR);
}

void escrever_registro_veiculo(Veiculo v, int rrn) {
	/*IMPLEMENTE A FUNÇÃO AQUI*/
	//printf(ERRO_NAO_IMPLEMENTADO, "escrever_registro_veiculo()");


	char temp[TAM_REGISTRO_VEICULO + 1], aux[100];
	temp[0] = '\0'; 
	aux[0] = '\0';


	strcpy(temp, v.id_veiculo);
	strcat(temp, ";");
	strcat(temp, v.marca);
	strcat(temp, ";");
	strcat(temp, v.modelo);
	strcat(temp, ";");
	strcat(temp, v.poder);
	strcat(temp, ";");
	sprintf(aux, "%04d", v.velocidade);
	strcat(temp, aux);
	strcat(temp, ";");
	sprintf(aux, "%04d", v.aceleracao);
	strcat(temp, aux);
	strcat(temp, ";");
	sprintf(aux, "%04d", v.peso);
	strcat(temp, aux);
	strcat(temp, ";");
	sprintf(aux, "%013.2lf", v.preco);//013 e 2 casas decimais
	strcat(temp, aux);
	strcat(temp, ";");
	strpadright(temp, '#', TAM_REGISTRO_VEICULO);
	strncpy(ARQUIVO_VEICULOS + (rrn*TAM_REGISTRO_VEICULO), temp, TAM_REGISTRO_VEICULO);//escrevendo no arquivo

}

void escrever_registro_pista(Pista p, int rrn) {
	/*IMPLEMENTE A FUNÇÃO AQUI*/
	//printf(ERRO_NAO_IMPLEMENTADO, "escrever_registro_pista()");

	char temp[TAM_REGISTRO_PISTA + 1], buff[100];
	temp[0] = '\0';
	buff[0] = '\0';

	strcpy(temp, p.id_pista);
	strcat(temp, ";");
	strcat(temp, p.nome);
	strcat(temp, ";");
	sprintf(buff, "%04d", p.dificuldade);
	strcat(temp, buff);
	strcat(temp, ";");
	sprintf(buff, "%04d", p.distancia);
	strcat(temp, buff);
	strcat(temp, ";");
	sprintf(buff, "%04d", p.recorde);
	strcat(temp, buff);
	strcat(temp, ";");
	strpadright(temp, '#', TAM_REGISTRO_PISTA);
	strncpy(ARQUIVO_PISTAS + (rrn * TAM_REGISTRO_PISTA), temp, TAM_REGISTRO_PISTA);

}

void escrever_registro_corrida(Corrida i, int rrn) {
	/*IMPLEMENTE A FUNÇÃO AQUI*/
	printf(ERRO_NAO_IMPLEMENTADO, "escrever_registro_corrida()");
}

/* Funções principais */
void cadastrar_corredor_menu(char *id_corredor, char *nome, char *apelido){
	/*IMPLEMENTE A FUNÇÃO AQUI*/
//	printf(ERRO_NAO_IMPLEMENTADO, "cadastrar_corredor_menu()");

	Corredor corredor;

	strcpy(corredor.id_corredor, id_corredor);
	strcpy(corredor.nome, nome);
	strcpy(corredor.apelido, apelido);
	//strcpy(corredor.cadastro, datetime);
	corredor.saldo = 0.0;
	current_datetime(corredor.cadastro);

	strcpy(corredor.veiculos[0], "");
	strcpy(corredor.veiculos[1], "");
	strcpy(corredor.veiculos[2], "");

	// int rrn = qtd_registros_corredores;

	corredores_index *fond =bsearch(corredor.id_corredor, corredores_idx,qtd_registros_corredores, sizeof(corredores_index), qsort_corredores_idx);

	if(fond != NULL){
		printf(ERRO_PK_REPETIDA, corredor.id_corredor);
		//return;
	}
	else {
		escrever_registro_corredor(corredor, qtd_registros_corredores);
		strcpy(corredores_idx[qtd_registros_corredores].id_corredor, corredor.id_corredor);
		corredores_idx[qtd_registros_corredores].rrn = qtd_registros_corredores;
		// qtd_registros_corredores++;
		qtd_registros_corredores = qtd_registros_corredores + 1;
		qsort(corredores_idx->id_corredor, qtd_registros_corredores, sizeof(corredores_index), qsort_corredores_idx);
		printf(SUCESSO);
	}
}

void remover_corredor_menu(char *id_corredor) {
	/*IMPLEMENTE A FUNÇÃO AQUI*/
	printf(ERRO_NAO_IMPLEMENTADO, "remover_corredor_menu()");
}

void adicionar_saldo_menu(char *id_corredor, double valor) {
	adicionar_saldo(id_corredor, valor, true);
}

void adicionar_saldo(char *id_corredor, double valor, bool flag){
	/*IMPLEMENTE A FUNÇÃO AQUI*/
	//printf(ERRO_NAO_IMPLEMENTADO, "adicionar_saldo()");

	corredores_index *fond = bsearch(id_corredor, corredores_idx, qtd_registros_corredores, sizeof(corredores_index), qsort_corredores_idx);

	if(fond == NULL){
		printf(ERRO_REGISTRO_NAO_ENCONTRADO);
	}
	else if (valor <=0)
	{
		printf(ERRO_VALOR_INVALIDO);
	}
	else{
		Corredor corredor = recuperar_registro_corredor(fond->rrn);
		
		corredor.saldo += valor;
		escrever_registro_corredor(corredor, fond->rrn);
		printf(SUCESSO);
	}
}

void comprar_veiculo_menu(char *id_corredor, char *id_veiculo) {
	/*IMPLEMENTE A FUNÇÃO AQUI*/
	printf(ERRO_NAO_IMPLEMENTADO, "comprar_veiculo_menu()");
}

void cadastrar_veiculo_menu(char *marca, char *modelo, char *poder, int velocidade, int aceleracao, int peso, double preco) {
	/*IMPLEMENTE A FUNÇÃO AQUI*/
	//printf(ERRO_NAO_IMPLEMENTADO, "cadastrar_veiculo_menu()");

	Veiculo veiculo;


	sprintf(veiculo.id_veiculo, "%07d", qtd_registros_veiculos);//07 pq o id_veiculo tem 7 digitos
	strcpy(veiculo.marca, marca);
	strcpy(veiculo.modelo, modelo);
	strcpy(veiculo.poder, poder);
	veiculo.velocidade = velocidade;

	veiculo.aceleracao = aceleracao;
	veiculo.peso = peso;
	veiculo.preco = preco;



	veiculos_index *fond = bsearch(veiculo.id_veiculo, veiculos_idx, qtd_registros_veiculos, sizeof(veiculos_index), qsort_veiculos_idx);
	if(fond != NULL){
		printf(ERRO_PK_REPETIDA, veiculo.id_veiculo);
	}
	else{
		escrever_registro_veiculo(veiculo, qtd_registros_veiculos);
		strcpy(veiculos_idx[qtd_registros_veiculos].id_veiculo, veiculo.id_veiculo);
		veiculos_idx[qtd_registros_veiculos].rrn = qtd_registros_veiculos;
		strcpy(preco_veiculo_idx[qtd_registros_veiculos].id_veiculo, veiculo.id_veiculo);//preco_veiculo_idx eh um indice secundario
		preco_veiculo_idx[qtd_registros_veiculos].preco = veiculo.preco;
		
		
		qtd_registros_veiculos++;
		qsort(preco_veiculo_idx, qtd_registros_veiculos, sizeof(preco_veiculo_index), qsort_preco_veiculo_idx);
		printf(SUCESSO);
		


	}
}

void cadastrar_pista_menu(char *nome, int dificuldade, int distancia, int recorde){
	/*IMPLEMENTE A FUNÇÃO AQUI*/
	//printf(ERRO_NAO_IMPLEMENTADO, "cadastrar_pista_menu()");

	Pista pista;

	snprintf(pista.id_pista, sizeof(pista.id_pista), "%08d", qtd_registros_pistas);// usnado snprintf para evitar buffer overflow
	
	strcpy(pista.nome, nome);
	pista.dificuldade = dificuldade;
	pista.distancia = distancia;
	pista.recorde = recorde;

	pistas_index *fond = bsearch(pista.nome, nome_pista_idx, qtd_registros_pistas, sizeof(nome_pista_index), qsort_nome_pista_idx);
	// pistas_index *fond = bsearch(pista.id_pista, nome_pista_idx, qtd_registros_pistas, sizeof(nome_pista_index), qsort_nome_pista_idx);

	if(fond == NULL){
		escrever_registro_pista(pista, qtd_registros_pistas);
		strcpy(pistas_idx[qtd_registros_pistas].id_pista, pista.id_pista);
		pistas_idx[qtd_registros_pistas].rrn = qtd_registros_pistas;//indice primario
		strcpy(nome_pista_idx[qtd_registros_pistas].nome, pista.nome);
		strcpy(nome_pista_idx[qtd_registros_pistas].id_pista, pista.id_pista);

		qtd_registros_pistas++;
		qsort(nome_pista_idx, qtd_registros_pistas, sizeof(nome_pista_index), qsort_nome_pista_idx);//ordenando o indice dnv



		printf(SUCESSO);
     }
	else{
		printf(ERRO_PK_REPETIDA, pista.nome);
	}
}

void executar_corrida_menu(char *id_pista, char *ocorrencia, char *id_corredores, char *id_veiculos) {
	/*IMPLEMENTE A FUNÇÃO AQUI*/
	printf(ERRO_NAO_IMPLEMENTADO, "executar_corrida_menu()");
}

/* Busca */
void buscar_corredor_id_menu(char *id_corredor) {
	corredores_index index;
	strcpy(index.id_corredor, id_corredor);
    corredores_index *found = busca_binaria((void*)&index, corredores_idx, qtd_registros_corredores, sizeof(corredores_index), qsort_corredores_idx, true, 0);
	
	if (found == NULL || found->rrn < 0)
		printf(ERRO_REGISTRO_NAO_ENCONTRADO);
	else
		exibir_corredor(found->rrn);
}

void buscar_pista_id_menu(char *id_pista) {
	/*IMPLEMENTE A FUNÇÃO AQUI*/
	// printf(ERRO_NAO_IMPLEMENTADO, "buscar_pista_id_menu()");

	pistas_index index;
	strcpy(index.id_pista, id_pista);
	pistas_index *fond = busca_binaria((void*)&index, pistas_idx, qtd_registros_pistas, sizeof(pistas_index), qsort_pistas_idx, true, 0);


	if(fond == NULL || fond->rrn < 0){
		printf(ERRO_REGISTRO_NAO_ENCONTRADO);
	}
	else{
		exibir_pista(fond->rrn);
	}
}

void buscar_pista_nome_menu(char *nome_pista) {
	/*IMPLEMENTE A FUNÇÃO AQUI*/
	// printf(ERRO_NAO_IMPLEMENTADO, "buscar_pista_nome_menu()");

	nome_pista_index index;

	strcpy(index.nome, nome_pista);
	nome_pista_index *fond = busca_binaria((void*)&index, nome_pista_idx, qtd_registros_pistas, sizeof(nome_pista_index), qsort_nome_pista_idx, true, 0);

	// if(fond == NULL || fond->rrn < 0){
	if(fond == NULL){
		printf(ERRO_REGISTRO_NAO_ENCONTRADO);
	}
	else{
		buscar_pista_id_menu(fond->id_pista);
	}
		
}

/* Listagem */
void listar_corredores_id_menu() {
	if (qtd_registros_corredores == 0)
		printf(AVISO_NENHUM_REGISTRO_ENCONTRADO);
	else
		for (unsigned int i = 0; i < qtd_registros_corredores; i++)
			exibir_corredor(corredores_idx[i].rrn);
}

void listar_corredores_modelo_menu(char *modelo){
	/*IMPLEMENTE A FUNÇÃO AQUI*/
	printf(ERRO_NAO_IMPLEMENTADO, "listar_corredores_modelo_menu()");
}

void listar_veiculos_compra_menu(char *id_corredor) {
	/*IMPLEMENTE A FUNÇÃO AQUI*/
	printf(ERRO_NAO_IMPLEMENTADO, "listar_veiculos_compra_menu()");
}

void listar_corridas_periodo_menu(char *data_inicio, char *data_fim) {
	/*IMPLEMENTE A FUNÇÃO AQUI*/
	printf(ERRO_NAO_IMPLEMENTADO, "listar_corridas_periodo_menu()");
}

/* Liberar espaço */
void liberar_espaco_menu() {
	/*IMPLEMENTE A FUNÇÃO AQUI*/
	printf(ERRO_NAO_IMPLEMENTADO, "liberar_espaco_menu()");
}

/* Imprimir arquivos de dados */
void imprimir_arquivo_corredores_menu() {
	if (qtd_registros_corredores == 0)
		printf(ERRO_ARQUIVO_VAZIO);
	else
		printf("%s\n", ARQUIVO_CORREDORES);
}

void imprimir_arquivo_veiculos_menu() {
	if (qtd_registros_veiculos == 0)
		printf(ERRO_ARQUIVO_VAZIO);
	else
		printf("%s\n", ARQUIVO_VEICULOS);
}

void imprimir_arquivo_pistas_menu() {
	if (qtd_registros_pistas == 0)
		printf(ERRO_ARQUIVO_VAZIO);
	else
		printf("%s\n", ARQUIVO_PISTAS);
}

void imprimir_arquivo_corridas_menu() {
	if (qtd_registros_corridas == 0)
		printf(ERRO_ARQUIVO_VAZIO);
	else
		printf("%s\n", ARQUIVO_CORRIDAS);
}

/* Imprimir índices primários */
void imprimir_corredores_idx_menu() {
	if (corredores_idx == NULL || qtd_registros_corredores == 0)
		printf(ERRO_ARQUIVO_VAZIO);
	else
		for (unsigned i = 0; i < qtd_registros_corredores; ++i)
			printf("%s, %d\n", corredores_idx[i].id_corredor, corredores_idx[i].rrn);
}

void imprimir_veiculos_idx_menu() {
	/*IMPLEMENTE A FUNÇÃO AQUI*/
	//printf(ERRO_NAO_IMPLEMENTADO, "imprimir_veiculos_idx_menu()");

	if(veiculos_idx == NULL || qtd_registros_veiculos == 0){
		printf(ERRO_ARQUIVO_VAZIO);
	}
	else{
		for(unsigned i = 0; i < qtd_registros_veiculos; ++i){
			printf("%s, %d\n", veiculos_idx[i].id_veiculo, veiculos_idx[i].rrn);
		}
	}
}

void imprimir_pistas_idx_menu() {
	/*IMPLEMENTE A FUNÇÃO AQUI*/
	// printf(ERRO_NAO_IMPLEMENTADO, "imprimir_pistas_idx_menu()");

	if(pistas_idx == NULL || qtd_registros_pistas == 0){
		printf(ERRO_ARQUIVO_VAZIO);
	}
	else{
		for(unsigned i = 0; i < qtd_registros_pistas; ++i){
			printf("%s, %d\n", pistas_idx[i].id_pista, pistas_idx[i].rrn);
		}
	}
}

void imprimir_corridas_idx_menu() {
	/*IMPLEMENTE A FUNÇÃO AQUI*/
	printf(ERRO_NAO_IMPLEMENTADO, "imprimir_corridas_idx_menu()");
}

/* Imprimir índices secundários */
void imprimir_nome_pista_idx_menu() {
	/*IMPLEMENTE A FUNÇÃO AQUI*/
	// printf(ERRO_NAO_IMPLEMENTADO, "imprimir_nome_pista_idx_menu()");

	if(nome_pista_idx == NULL || qtd_registros_pistas == 0){
		printf(ERRO_ARQUIVO_VAZIO);
	}
	// else{
	// 	for(unsigned i = 0; i < qtd_registros_pistas; ++i){
	// 		printf("%.50s, %.8s\n", nome_pista_idx[i].nome, nome_pista_idx[i].id_pista);
	// 	}
	// }
	
	else{char nome[34];
// convertentedo para maiuscula
		for(unsigned i = 0; i < qtd_registros_pistas; ++i){
			strcpy(nome, nome_pista_idx[i].nome);
			// for(int j=0; j<34; j++){
				for(int j=0; j<sizeof(nome)/sizeof(nome[0]); j++){ 
					nome[j] = toupper(nome[j]);
				}
				printf("%s, %s\n", nome, nome_pista_idx[i].id_pista);
		}
	}
				
}

void imprimir_preco_veiculo_idx_menu() {
	/*IMPLEMENTE A FUNÇÃO AQUI*/
	//printf(ERRO_NAO_IMPLEMENTADO, "imprimir_preco_veiculo_idx_menu()");

	if(preco_veiculo_idx == NULL || qtd_registros_veiculos == 0){
		printf(ERRO_ARQUIVO_VAZIO);
	}
	else{
		for(unsigned i = 0; i < qtd_registros_veiculos; ++i){
			printf("%.2lf, %.8s\n", preco_veiculo_idx[i].preco, preco_veiculo_idx[i].id_veiculo);
		}
	}
}

void imprimir_corredor_veiculos_secundario_idx_menu() {
	/*IMPLEMENTE A FUNÇÃO AQUI*/
	printf(ERRO_NAO_IMPLEMENTADO, "imprimir_corredor_veiculos_secundario_idx_menu()");
}

void imprimir_corredor_veiculos_primario_idx_menu(){
	/*IMPLEMENTE A FUNÇÃO AQUI*/
	printf(ERRO_NAO_IMPLEMENTADO, "imprimir_corredor_veiculos_primario_idx_menu()");
}

/* Liberar memória e encerrar programa */
void liberar_memoria_menu() {
	/*IMPLEMENTE A FUNÇÃO AQUI*/
	//printf(ERRO_NAO_IMPLEMENTADO, "liberar_memoria_menu()");

	free(corredores_idx);
	free(veiculos_idx);
}

void inverted_list_insert(char *chave_secundaria, char *chave_primaria, inverted_list *t) {
	/*IMPLEMENTE A FUNÇÃO AQUI*/
	printf(ERRO_NAO_IMPLEMENTADO, "inverted_list_insert()");
}

bool inverted_list_secondary_search(int *result, bool exibir_caminho, char *chave_secundaria, inverted_list *t) {
	/*IMPLEMENTE A FUNÇÃO AQUI*/
	printf(ERRO_NAO_IMPLEMENTADO, "inverted_list_secondary_search()");
	return false;
}

int inverted_list_primary_search(char result[][TAM_ID_CORREDOR], bool exibir_caminho, int indice, int *indice_final, inverted_list *t) {
	/*IMPLEMENTE A FUNÇÃO AQUI*/
	printf(ERRO_NAO_IMPLEMENTADO, "inverted_list_primary_search()");
	return -1;
}


void* busca_binaria_com_reps(const void *key, const void *base0, size_t nmemb, size_t size, int (*compar)(const void *, const void *), bool exibir_caminho, int posicao_caso_repetido, int retorno_se_nao_encontrado) {
	/*IMPLEMENTE A FUNÇÃO AQUI*/
	//printf(ERRO_NAO_IMPLEMENTADO, "busca_binaria_com_reps()");
	
	const char *base = (const char*) base0, *pivot;
	unsigned int check;
	unsigned int end;

	// if(exibir_caminho && nmemb > 0){
	if((exibir_caminho == true) && (nmemb > 0)){
	
		printf("Registros percorridos:");
	}
	for (end = nmemb; end != 0; end =end/2){
		// define o piv como o meio do intervalo de busca
		pivot = base + (end/2) * size;
		// check = compar(key, pivot);
		check = (*compar)(key, pivot);
		if (exibir_caminho){
			printf(" %ld", (pivot - base) / size);
		}
		// verifica se a chave foi encontrada no pivo
		if (check == 0){
			if (exibir_caminho){
				printf("\n");
				// return (void) *pivot;
				return (void*) pivot;
			}	
		}
		else if(check > 0){
			// se a chave for maior que o elemento no pivo, ajusta a base p a direita
			// base = pivot + size;
			base = (const char*) pivot + size;
			end--;
		}
	}


	if (exibir_caminho && nmemb != 0){
		printf("\n");
	}

	
	if(retorno_se_nao_encontrado == -1){
		if(check > 0){
			
			// return (void*) pivot;
			// return (void*) (pivot - size);
			return (void*) (pivot + size);

		}else 
			{return (void*) pivot;}
	}
	
	
	else if (retorno_se_nao_encontrado == 0){
		return NULL;
	}


	else if(retorno_se_nao_encontrado == 1){
		// retorna o próximo elemento
		if(check>0){
			// return (void*) (pivot + size);
			return (void*) pivot;
		}
		else
			// return (void*) (pivot + size);
			{return (void*)(pivot - size);}
	}
	
	return NULL;// retorna NULL como padrão
	//return (void*) -1;

}

void* busca_binaria(const void *key, const void *base0, size_t nmemb, size_t size, int (*compar)(const void *, const void *), bool exibir_caminho, int retorno_se_nao_encontrado) {
	return busca_binaria_com_reps(key, base0, nmemb, size, compar, exibir_caminho, 0, retorno_se_nao_encontrado);
}



char *strpadright(char *str, char pad, unsigned size){
	for (unsigned i = strlen(str); i < size; ++i)
		str[i] = pad;
	str[size] = '\0';
	return str;
}
char *strupr(char *str){
	for (char *p = str; *p; ++p)
		*p = toupper(*p);
	return str;
}
char *strlower(char *str){
	for (char *p = str; *p; ++p)
		*p = tolower(*p);
	return str;
}