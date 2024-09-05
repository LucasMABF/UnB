// Projeto APC - Number Sums
// Lucas Mendes de A. B. Fonseca - 241020750
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
// ANSI Escape codes:

// cria novo buffer de terminal
void new_buffer(){
  printf("\x1b[?1049h\x1b[H"); // abre buffer alternativo e posiciona cursor
}

// retorna ao buffer anterior
void restore_buffer(){
  printf("\x1b[?1049l");
}

// move cursor para o inicio da tela
void top(){
  printf("\x1b[H");
}

// move cursor para cima n linhas, para o comeco da linha
void up(int n){
  printf("\x1b[%dF", n);
}

// move cursor para baixo n linhas, para o comeco da linha
void down(int n){
  printf("\x1b[%dE", n);
}

// move cursor para direita n caracteres, para o comeco da linha
void right(int n){
  printf("\x1b[%dC", n);
}

// limpa tela e posiciona o cursor no topo
void cleartop(){
  printf("\x1b[2J"); 
  top();
}

// limpa o resto da tela
void clear_end(){
    printf("\x1b[0J");
}

// limpa resto da linha
void clear_line(){
  printf("\x1b[0K");
}

// salva posicao do cursor
void save_cursor_pos(){
  printf("\x1b""7");
}

// volta cursor para posicao anterior
void restore_cursor_pos(){
  printf("\x1b""8");
}


void handle_ctrlc(int sig){
  signal(SIGINT, SIG_IGN);
  restore_buffer();
  exit(0);
}


// limpa o buffer de teclado 
// e tambem pode ser usado para esperar o ENTER
void cleanbuffer(){
  char c;
  while((c = getchar() != '\n' && c != EOF));
}

void tela_inicio(char *nickname){
  printf("\nBem vindo(a) ao Jogo de somas de APC!!\n\n");

  printf("Insira seu nickname: ");
  scanf("%s", nickname);
  printf("Bem vindo(a), %s!\n", nickname);
  printf("Pressione ENTER para continuar.\n");
  cleanbuffer();
  cleanbuffer();
}

int menu(){
  cleartop();
  printf("*** JOGO DAS SOMAS ***\n\n");
  printf("1 - Jogar\n");
  printf("2 - Configuracoes\n");
  printf("3 - Instrucoes\n");
  printf("4 - Ranking\n");
  printf("5 - Sair\n\n");
  int opc = -1;
  while(1){
    save_cursor_pos();
    printf("Digite a opcao desejada: ");
    int lidos = scanf("%d", &opc);
    cleanbuffer();
    if(opc >= 1 && opc <= 5 && lidos == 1) break;
    restore_cursor_pos();
    clear_end();
    printf("\nOpcao invalida.");
    up(1);
  }
  return opc;
}

void inst(){
  cleartop();
  printf("\n\n\n Instrucoes sobre o jogo das somas:\n\n");
  printf("Sera mostrado uma  matriz de numeros, e as somas que cada linha e cada coluna deveriam ter.\n");
  printf("Eh seu trabalho falar quais numeros estao incorretos na matriz para que as somas fiquem iguais com as fornecidas.\n");
  printf("Voce vai informar a posicao na matriz q tem um numero que deve ser apagado. Exemplo: 1 1 para x = 1 e y = 1\n");
  printf("Voce tem 5 vidas, e seu score vai aumentando ao passo que voce acerta os desafios.\n");
  printf("No final seu score sera salvado no ranking.\n\n\n");
  printf("Boa sorte!\n\n\n");
  printf("Pressione ENTER para continuar.");
  cleanbuffer();
}

char fgetccr(FILE *f){
  char c = fgetc(f);
  if(c == '\r'){
    c = fgetc(f);
  }
  return c;
}

int jogo(FILE *f){
  int vidas = 5;
  cleartop();

  // carregar tabuleiro
  long pos_init = ftell(f);

  // pegar tamanho matriz
  int n = 0;
  char c;

  while(( c = fgetccr(f)) != '\n' && c != '\r') n++; 

  fseek(f, pos_init, SEEK_SET);

  // printa matriz
  down(2);
  right(4); // posiciona cursor lugar certo
  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      c = fgetccr(f);
      printf(" %c ", c);
    }
    down(1);
    right(4);
    fgetccr(f); // remove \n
  }

  // printa somas
  top();
  down(1);
  right(3);
  printf("-");  
  for(int i = 0; i < n; i++){
    printf("---");
  }

  top();
  right(3);
  for(int i = 0; i < n; i++){
    c = fgetccr(f);
    char d = fgetccr(f);
    printf(" %c%c", c, d);
  }
  fgetccr(f); // remove \n

  top();
  down(2);
  for(int i = 0; i < n; i++){
    c = fgetccr(f);
    char d = fgetccr(f);
    printf("%c%c |\n", c, d);
  }
  fgetccr(f); // remove \n

  int gabarito[n][n];
  int todas_apagadas = 0;  

  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      c = fgetccr(f);
      if(c == '0') todas_apagadas++;
      gabarito[i][j] = c - '0';
    }
    fgetccr(f); // remove \n
  }

  fgetccr(f);
  fgetccr(f); // remove * e \n

  printf("\n*** Voce tem %d vidas ***\n", vidas);
  save_cursor_pos();
  while(1){
    int x, y;
    while(1){
      printf("Digite a linha e coluna do elemento a ser apagado: ");
      clear_line();
      int lidos = scanf("%d %d", &x, &y);
      restore_cursor_pos();
      cleanbuffer();
      if(lidos == 2 && x > 0 && y > 0 && x < n + 1 && y < n + 1){
        x--; // zero index
        y--;
        if(gabarito[y][x] != -1){
          break;    
        }else{
          down(1);
          clear_end();
          printf("Voce ja tentou esse numero. Tente novamente.");
          up(1);
          continue;
        }
      }
      down(1);
      clear_end();
      printf("Valores digitados Invalidos. Tente novamente.");
      up(1);
    }

    down(1);
    clear_end();

    if(gabarito[y][x] == 0){
      gabarito[y][x] = -1;
      printf("Voce acertou!");
      int lineoffset = 2 + (n - y);
      int colunaoffset = 4 + 3 * x;
      restore_cursor_pos();
      up(lineoffset);
      right(colunaoffset);
      printf("   ");
      restore_cursor_pos();
      down(2);

      // checa linhas completas
      int completa = 1;
      for(int i = 0; i < n; i++){
        if(gabarito[y][i] == 0){
          completa = 0;
        }  
      }
      if(completa){
        printf("Voce completou a linha %d.\n", y + 1);
        int offset = 5 + (n - y);
        up(offset);
        printf("  ");
        down(offset);
      }

      // checa colunas completas
      completa = 1;
      for(int i = 0; i < n; i++){
        if(gabarito[i][x] == 0){
          completa = 0;
        }   
      }
      if(completa){
        printf("Voce completou a coluna %d.\n", x + 1);
        int offset = 4 + (x * 3);
        top();
        right(offset);
        printf("  ");
        restore_cursor_pos();
        down(4);
      }

      todas_apagadas--;
      if(todas_apagadas == 0){
        printf("\nParabens! Voce completou a fase! Pressione ENTER para ir para o menu.");
        cleanbuffer();
        return 1;
      }
    }else{
      gabarito[y][x] = -1;
      printf("Voce errou.");
      vidas--;
      up(2);
      printf("*** Voce tem %d vidas ***", vidas);
      down(3);
      if(vidas == 0){
        printf("\nVoce perdeu todas suas vidas. Pressione ENTER para voltar para o menu, e tentar novamente.");
        cleanbuffer();
        fseek(f, pos_init, SEEK_SET);
        return 0;
      }
    }

    printf("\nPressione ENTER para continuar.");

    cleanbuffer();
    restore_cursor_pos();
    clear_end();
  }
}

typedef enum dificuldade{
  Iniciante,
  Intermediario,
  Avancado
} dificuldade;


FILE *opennivel(dificuldade dif){
  if(dif == Iniciante){
    return fopen("iniciante.txt", "rb");
  }else if(dif == Intermediario){
    return fopen("intermediario.txt", "rb");
  }else{
    return fopen("avancado.txt", "rb");
  }
}

int main(){
  signal(SIGINT, handle_ctrlc);
  new_buffer();

  char nickname[21];
  tela_inicio(nickname);

  dificuldade nivel = Iniciante;
  FILE *f = opennivel(nivel);

  int erro = 0;
  if(f == NULL){
    printf("Erro ao abrir arquivo das fases. Pressione ENTER para sair.");
    cleanbuffer();
    erro = 1;
  }

  while(1 && (! erro)){
    int opc = menu();
    if(opc == 1){
      int passou = jogo(f);
      if(passou){
        /*add to ranking*/
        // check EOF
        // nivel terminado
        if(fgetccr(f) == EOF){
          nivel++;
          if(nivel > Avancado){
            printf("Parabens!! Voce zerou o jogo!\n");
            printf("\nPressione ENTER para voltar para o menu.");
            cleanbuffer();           

            nivel = Iniciante;
          }
          fclose(f);
          f = opennivel(nivel);
          if(f == NULL){
            printf("Erro ao abrir arquivo das fases. Pressione ENTER para sair.");
            cleanbuffer();
            erro = 1;
          }
        }else fseek(f, -1, SEEK_CUR);
      }
    }else if(opc == 2){
      /*config();*/
    }else if(opc == 3){
      inst();
    }else if(opc == 4){
      /*show_rank();*/
    }else if(opc == 5){
      break;
    }
  }

  fclose(f);
  restore_buffer();
  printf("Tchau, %s, volte sempre!", nickname);
  return 0;
}

