#include "cacaPalavras.h"

void textcolor (int iColor) {
    HANDLE hl = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO bufferInfo;
    BOOL b = GetConsoleScreenBufferInfo(hl, &bufferInfo);
    bufferInfo.wAttributes &= 0x00F0;
    SetConsoleTextAttribute (hl, bufferInfo.wAttributes |= iColor);
}

void imprimeCmds(){
    textcolor(6);
printf("- APERTE 1 PARA ACHAR UMA PALAVRA.  \n");
printf("- APERTE 2 PARA CARREGAR OUTRO JOGO.\n");
printf("- APERTE 3 PARA SAIR.               \n\n");
    textcolor(RESET);
    textcolor(8);
printf("Digite o comando: ");
    textcolor(RESET);
}

void imprimeJogada(){
printf("\n");
    textcolor(6);
printf("DIRECOES:\n\n");
printf("Aperte (1) para ESQUERDA\n");
printf("Aperte (2) para DIREITA\n");
printf("Aperte (3) para CIMA\n");
printf("Aperte (4) para BAIXO\n");
printf("Aperte (5) para DIAGONAL SUPERIOR ESQUEDA\n");
printf("Aperte (6) para DIAGONAL SUPERIOR DIREITA\n");
printf("Aperte (7) para DIAGONAL INFERIOR ESQUERDA\n");
printf("Aperte (8) para DIAGONAL INFERIOR DIREITA\n\n");
    textcolor(8);
printf("ESCREVA A CORDENADA DA PRIMEIRA LETRA (x,y), O TAMANHO DA PALAVRA E A DIRECAO: ");
    textcolor(RESET);
}

void imprimeInicia(){
    textcolor(6);
printf("BEM-VINDO AO CACA-PALAVRAS!\n\n\n");
    textcolor(RESET);
printf("- PRESSIONE 1 PARA COMECAR\n");
printf("- PRESSIONE QUALQUER OUTRA TECLA PARA SAIR\n\n");
textcolor(8);
printf("Digite o comando: ");
textcolor(RESET);
}

void imprimeMatriz(matriz mat){
    printf("\n");
    printf("   ");

    for(int i = 0; i < mat.n_col ; i++){
            textcolor(YELLOW);
            printf("%i ", i);
            if(i < 9) printf(" ");
    }
    printf("\n");
    textcolor(RESET);
    for(int i = 0; i < mat.n_lin ; i++){
            if(i < 10) printf(" ");

            textcolor(YELLOW);
            printf("%i ", i);
            textcolor(RESET);

    for(int j = 0; j < mat.n_col ; j++){
        if(mat.data[i][j].achou == 1){
          textcolor(BROWN);
          printf("%c ", mat.data[i][j].letra);
          textcolor(RESET);
        }else{
          printf("%c ", mat.data[i][j].letra);
        }
        printf(" ");
    }
      printf("\n");
    }
    printf("\n");
}

void imprimePalavras(matriz mat, matriz plv){
     int j = 0;
     textcolor(YELLOW);
     printf("PALAVRAS: \n\n");
     textcolor(RESET);

     for(int i = 0; i < mat.n_pal; i++){
        while(true){
            if(plv.data[i][j].letra != '\n'){
                if(plv.data[i][j].achou == 1){
                     textcolor(BLACK);
                     printf("%c", plv.data[i][j].letra);
                } else{
                printf("%c", plv.data[i][j].letra);
                }
                j++;
            }else{
              printf("%c", plv.data[i][j].letra);
              j = 0;
              textcolor(RESET);
              break;
            }
        }
     }
     printf("\n\n");
}

int achaTamanho(int nPal, pontMatriz plv){
    int i = 0;
    int tam = 0;
    while(plv->data[nPal][i].letra != '\n'){
        printf("%c",plv->data[nPal][i].letra);
        tam++;
        i++;
    }
    return tam;
}

bool esquerda(pontMatriz mat, pontMatriz plv, int tam, int dir, int x, int y){
    bool achou = false;
    int nPal = 0;
    int tamPalDaLista = 0;
    int aux = 0;
    while(!achou || nPal <= mat->n_pal){
        tamPalDaLista = achaTamanho(nPal, plv);
        if(tamPalDaLista != tam) nPal++;
        else{
            for(int i = 0; i < tam; i++){
                if(mat->data[y][x-i].letra == plv->data[nPal][i].letra) aux++;
                else
                break;
            }
            if(aux == tam){
              achou = true;
              break;
            }else{
            nPal++;
            }
        }
    }

    if(achou){
        for(int i = 0; i < tam; i++){
            mat->data[y][x-i].achou = 1;
            plv->data[nPal][i].achou = 1;
            }
            return true;
    }else{
     return false;
    }
}

bool direita(pontMatriz mat, pontMatriz plv, int tam, int dir, int x, int y){
    bool achou = false;
    int nPal = 0;
    int tamPalDaLista = 0;
    int aux = 0;
    while(!achou || nPal <= mat->n_pal){
        tamPalDaLista = achaTamanho(nPal, plv);
        if(tamPalDaLista != tam) nPal++;
        else{
            for(int i = 0; i < tam; i++){
                if(mat->data[y][x+i].letra == plv->data[nPal][i].letra) aux++;
                else
                break;
            }
            if(aux == tam){
              achou = true;
              break;
            }else{
            nPal++;
            }
        }
    }

    if(achou){
        for(int i = 0; i < tam; i++){
            mat->data[y][x+i].achou = 1;
            plv->data[nPal][i].achou = 1;
            }
            return true;
    }else{
     return false;
    }
}

bool cima(pontMatriz mat, pontMatriz plv, int tam, int dir, int x, int y){
    bool achou = false;
    int nPal = 0;
    int tamPalDaLista = 0;
    int aux = 0;
    while(!achou || nPal <= mat->n_pal){
        tamPalDaLista = achaTamanho(nPal, plv);
        if(tamPalDaLista != tam) nPal++;
        else{
            for(int i = 0; i < tam; i++){
                if(mat->data[y-i][x].letra == plv->data[nPal][i].letra) aux++;
                else
                break;
            }
            if(aux == tam){
              achou = true;
              break;
            }else{
            nPal++;
            }
        }
    }

    if(achou){
        for(int i = 0; i < tam; i++){
            mat->data[y-i][x].achou = 1;
            plv->data[nPal][i].achou = 1;
            }
            return true;
    }else{
     return false;
    }
}

bool baixo(pontMatriz mat, pontMatriz plv, int tam, int dir, int x, int y){
    bool achou = false;
    int nPal = 0;
    int tamPalDaLista = 0;
    int aux = 0;
    while(!achou || nPal <= mat->n_pal){
        tamPalDaLista = achaTamanho(nPal, plv);
        if(tamPalDaLista != tam) nPal++;
        else{
            for(int i = 0; i < tam; i++){
                if(mat->data[y+i][x].letra == plv->data[nPal][i].letra) aux++;
                else
                break;
            }
            if(aux == tam){
              achou = true;
              break;
            }else{
            nPal++;
            }
        }
    }

    if(achou){
        for(int i = 0; i < tam; i++){
            mat->data[y+i][x].achou = 1;
            plv->data[nPal][i].achou = 1;
            }
            return true;
    }else{
     return false;
    }
}

bool dSupEsquerda(pontMatriz mat, pontMatriz plv, int tam, int dir, int x, int y){
    bool achou = false;
    int nPal = 0;
    int tamPalDaLista = 0;
    int aux = 0;
    while(!achou || nPal <= mat->n_pal){
        tamPalDaLista = achaTamanho(nPal, plv);
        if(tamPalDaLista != tam) nPal++;
        else{
            for(int i = 0; i < tam; i++){
                if(mat->data[y-i][x-i].letra == plv->data[nPal][i].letra) aux++;
                else
                break;
            }
            if(aux == tam){
              achou = true;
              break;
            }else{
            nPal++;
            }
        }
    }

    if(achou){
        for(int i = 0; i < tam; i++){
            mat->data[y-i][x-i].achou = 1;
            plv->data[nPal][i].achou = 1;
            }
            return true;
    }else{
     return false;
    }
}

bool dSupDireita(pontMatriz mat, pontMatriz plv, int tam, int dir, int x, int y){
    bool achou = false;
    int nPal = 0;
    int tamPalDaLista = 0;
    int aux = 0;
    while(!achou || nPal <= mat->n_pal){
        tamPalDaLista = achaTamanho(nPal, plv);
        if(tamPalDaLista != tam) nPal++;
        else{
            for(int i = 0; i < tam; i++){
                if(mat->data[y-i][x+i].letra == plv->data[nPal][i].letra) aux++;
                else
                break;
            }
            if(aux == tam){
              achou = true;
              break;
            }else{
            nPal++;
            }
        }
    }

    if(achou){
        for(int i = 0; i < tam; i++){
            mat->data[y-i][x+i].achou = 1;
            plv->data[nPal][i].achou = 1;
            }
            return true;
    }else{
     return false;
    }
}

bool dInfEsquerda(pontMatriz mat, pontMatriz plv, int tam, int dir, int x, int y){
    bool achou = false;
    int nPal = 0;
    int tamPalDaLista = 0;
    int aux = 0;
    while(!achou || nPal <= mat->n_pal){
        tamPalDaLista = achaTamanho(nPal, plv);
        if(tamPalDaLista != tam) nPal++;
        else{
            for(int i = 0; i < tam; i++){
                if(mat->data[y+i][x-i].letra == plv->data[nPal][i].letra) aux++;
                else
                break;
            }
            if(aux == tam){
              achou = true;
              break;
            }else{
            nPal++;
            }
        }
    }

    if(achou){
        for(int i = 0; i < tam; i++){
            mat->data[y+i][x-i].achou = 1;
            plv->data[nPal][i].achou = 1;
            }
            return true;
    }else{
     return false;
    }
}

bool dInfDireita(pontMatriz mat, pontMatriz plv, int tam, int dir, int x, int y){
    bool achou = false;
    int nPal = 0;
    int tamPalDaLista = 0;
    int aux = 0;
    while(!achou || nPal <= mat->n_pal){
        tamPalDaLista = achaTamanho(nPal, plv);
        if(tamPalDaLista != tam) nPal++;
        else{
            for(int i = 0; i < tam; i++){
                if(mat->data[y+i][x+i].letra == plv->data[nPal][i].letra) aux++;
                else
                break;
            }
            if(aux == tam){
              achou = true;
              break;
            }else{
            nPal++;
            }
        }
    }

    if(achou){
        for(int i = 0; i < tam; i++){
            mat->data[y+i][x+i].achou = 1;
            plv->data[nPal][i].achou = 1;
            }
            return true;
    }else{
     return false;
    }
}

bool jogada(pontMatriz mat, pontMatriz plv){
int tam, dir, x, y;
bool aux;
imprimeJogada();
scanf("%i %i %i %i", &x, &y, &tam, &dir);
if(x < 0 || y < 0 || tam < 0 || dir < 0) return false;

switch(dir){
    case 1: aux = esquerda(mat,plv, tam, dir, x, y);
            if(aux) return true;
            return false;
            break;
    case 2: aux = direita(mat,plv, tam, dir, x, y);
            if(aux) return true;
            return false;
            break;
    case 3: aux = cima(mat,plv, tam, dir, x, y);
            if(aux) return true;
            return false;
            break;
    case 4: aux = baixo(mat,plv, tam, dir, x, y);
            if(aux) return true;
            return false;
            break;
    case 5: aux = dSupEsquerda(mat,plv, tam, dir, x, y);
            if(aux) return true;
            return false;
            break;
    case 6: aux = dSupDireita(mat,plv, tam, dir, x, y);
            if(aux) return true;
            return false;
            break;
    case 7: aux = dInfEsquerda(mat,plv, tam, dir, x, y);
            if(aux) return true;
            return false;
            break;
    case 8: aux = dInfDireita(mat,plv, tam, dir, x, y);
            if(aux) return true;
            return false;
            break;
}
}

bool inicializaMatriz(pontMatriz mat, pontMatriz plv){
    mat->data = (elemento**)malloc(sizeof(elemento)*(mat->n_lin));
    int i;
    for(i = 0; i < mat->n_lin; i++){
        mat->data[i] = (elemento*)malloc(sizeof(elemento)*(mat->n_col+1));
    }

    for(int i = 0; i < mat->n_lin; i++){
        for(int j = 0; j < mat->n_col;j++){
            mat->data[i][j].achou = 0;
        }
    }

    plv->data = (elemento**)malloc(sizeof(elemento)*(mat->n_pal));
    for(i = 0; i < mat->n_lin; i++){
        plv->data[i] = (elemento*)malloc(sizeof(elemento)*(stringMax));
    }
    return true;
}

bool leituraArquivo(pontMatriz mat, pontMatriz plv){
    int lin, col, pal, jogo;
    char ch, buf;
    char nome[150];
    char jogo_1[150] = "C:\\Users\\Amd\\Documents\\Codeblocks\\caca-palavras\\matrizTeste01.txt";
    char jogo_2[150] = "C:\\Users\\Amd\\Documents\\Codeblocks\\caca-palavras\\matrizGolpa.txt";

    printf("\n");
    textcolor(6);
    printf("ESCOLHA O JOGO: \n\n");
    textcolor(RESET);
    printf("1 - %s\n", jogo_1);
    printf("2 - %s\n", jogo_2);
    printf("\n");
    textcolor(8);
    printf("Digite o comando: ");
    textcolor(RESET);
    scanf("%i", &jogo);

    switch(jogo){
            case 1: strcpy(nome,jogo_1);
                    break;
            case 2: strcpy(nome,jogo_2);
                    break;
            default: printf("POR FAVOR, PRESSIONE UM NUMERO VALIDO.\n");
                     break;
        }

    FILE* file = fopen(nome, "r");

    if (!file)
    {
        printf( "Arquivo invalido\n" );
        return false;
    }

    fscanf(file,"%i %i %i\n", &lin, &col, &pal);

    if(lin <= 0 || col <= 0 || pal <= 0) return false;

    mat->n_lin = lin;
    mat->n_col = col;
    mat->n_pal = pal;
    /*
    printf("\n");
    printf("LINHAS: %i\n", mat->n_lin);
    printf("COLUNAS: %i\n", mat->n_col);
    printf("PALAVRAS: %i\n", mat->n_pal);
    printf("\n");
    */
    int inicializou = inicializaMatriz(mat, plv);
    if(!inicializou) return false;

    for(int i = 0; i < mat->n_lin; i++){
        for(int j = 0; j < mat->n_col+1; j++){
            if((mat->n_col+1) - j == 1)
            {
             ch = getc(file);
             break;
            }
            ch = getc(file);
            mat->data[i][j].letra = ch;
        }
    }

    int i = 0;
    int j = 0;
    buf = getc(file);
    while(buf != EOF){
        plv->data[i][j].letra = buf;
        if(buf != '\n') j++;
        else{
        i++;
        j = 0;
        }
        buf = getc(file);
    }

    fclose(file);
    return true;
}

bool processaLeitura(pontMatriz mat, pontMatriz plv){
    return leituraArquivo(mat, plv);
}

void processCmd(pontMatriz mat, pontMatriz plv){
    bool carregou = false;
    int acertou = 0;
    bool jogou = false;
    int n = 0;
while(n != 3){
    if(!carregou){
       carregou = processaLeitura(mat, plv);
    }else{
        if(carregou){
         imprimeMatriz(*mat);
         imprimePalavras(*mat, *plv);
        }
        imprimeCmds();

        scanf("%d", &n);
        switch(n){
            case 1: jogou = jogada(mat, plv);
                    if(jogou) acertou ++;
                    break;
            case 2: carregou = processaLeitura(mat, plv);
                    break;
            case 3: printf("O JOGO ACABOU!");
                    break;
            default: printf("POR FAVOR, PRESSIONE UM NUMERO VALIDO.\n");
                     continue;
        }
      }
}
}

void inicia(pontMatriz mat, pontMatriz plv){
int a = 0;
    imprimeInicia();
    scanf("%d", &a);
    if(a == 1)processCmd(mat,plv);
}

int main(){
matriz C;
matriz P;
inicia(&C,&P);
}
