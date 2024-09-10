// Projeto APC - Number Sums
// Lucas Mendes de A. B. Fonseca - 241020750
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <string.h>
// ANSI Escape codes:

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

// move cursor para direita n caracteres
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

// cria novo buffer de terminal
void new_buffer(){
  printf("\x1b[?1049h"); // abre buffer alternativo
  top();
}

// retorna ao buffer anterior
void restore_buffer(){
  printf("\x1b[?1049l");
}


void handle_ctrlc(int sig){
  signal(SIGINT, SIG_IGN);
  restore_buffer();
  exit(0);
}


// limpa o buffer de teclado 
// e tambem pode ser usado para esperar o ENTER
void clearbuffer(){
  while(getchar() != '\n');
}


// pega character valido do arquivo
char fgetvc(FILE *f){
  char c = fgetc(f);
  if((c < '0' || c > '9') && (c != '\n' && c != EOF)){
    c = fgetvc(f);
  }
  return c;
}


// pega input do usuario para os menus
int get_opc(int min, int max){
  int opc = -1;
  while(1){
    save_cursor_pos();
    printf("Digite a opcao desejada: ");
    int lidos = scanf("%d", &opc);
    clearbuffer();
    if(opc >= min && opc <= max && lidos == 1) break;
    restore_cursor_pos();
    clear_end();
    printf("\nOpcao invalida.");
    up(1);
  }
  clear_line();
  return opc;
}


void tela_inicio(char *nickname, int size){
  printf("\nBem vindo(a) ao Jogo de somas de APC!!\n\n");

  printf("Insira seu nickname: ");
  char parser[6];
  snprintf(parser, 6, "%%%ds", size - 1);
  scanf(parser, nickname);
  printf("Bem vindo(a), %s!\n", nickname);
  printf("Pressione ENTER para continuar.");
  clearbuffer();
  clearbuffer();
}

int menu(){
  cleartop();
  printf("*** JOGO DAS SOMAS ***\n\n");
  printf("1 - Jogar\n");
  printf("2 - Configuracoes\n");
  printf("3 - Instrucoes\n");
  printf("4 - Ranking\n");
  printf("5 - Sair\n\n");
  return get_opc(1, 5);
}

void inst(){
  cleartop();
  printf("\n\nInstrucoes sobre o jogo das somas:\n\n");
  printf("Sera mostrado uma  matriz de numeros, e as somas que cada linha e cada coluna deveriam ter.\n");
  printf("Eh seu trabalho falar quais numeros estao incorretos na matriz para que as somas fiquem iguais as fornecidas.\n");
  printf("Voce vai informar a posicao na matriz q tem um numero que deve ser apagado. Exemplo: 1 1 para x = 1 e y = 1\n");
  printf("Voce tem 5 vidas, e seu score vai aumentando ao passo que voce acerta os desafios.\n");
  printf("No final seu score sera salvado no ranking.\n\n\n");
  printf("Boa sorte!\n\n\n");
  printf("Pressione ENTER para continuar.");
  clearbuffer();
}

int jogo(FILE *f){
  int vidas = 5;
  cleartop();

  // carregar tabuleiro
  long pos_init = ftell(f);

  // pegar tamanho matriz
  int n = 0;
  char c;

  while(( c = fgetvc(f)) != '\n') n++; 

  fseek(f, pos_init, SEEK_SET);

  // printa matriz
  down(2);
  right(4); // posiciona cursor lugar certo
  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      c = fgetvc(f);
      printf(" %c ", c);
    }
    down(1);
    right(4);
    fgetvc(f); // remove \n
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
    c = fgetvc(f);
    char d = fgetvc(f);
    printf(" %c%c", c, d);
  }
  fgetvc(f); // remove \n

  top();
  down(2);
  for(int i = 0; i < n; i++){
    c = fgetvc(f);
    char d = fgetvc(f);
    printf("%c%c |\n", c, d);
  }
  fgetvc(f); // remove \n

  // pega matriz expelho
  int gabarito[n][n];
  int todas_apagadas = 0;  

  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      c = fgetvc(f);
      if(c == '0') todas_apagadas++;
      gabarito[i][j] = c - '0';
    }
    fgetvc(f); // remove \n
  }

  fgetvc(f); // remove \n

  // logica principal jogo
  printf("\n*** Voce tem %d vidas ***\n", vidas);
  save_cursor_pos();
  while(1){
    int x, y;
    while(1){
      printf("Digite a linha e coluna do elemento a ser apagado: ");
      clear_line();
      int lidos = scanf("%d %d", &x, &y);
      restore_cursor_pos();
      clearbuffer();
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
        clearbuffer();
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
        clearbuffer();
        fseek(f, pos_init, SEEK_SET);
        return 0;
      }
    }

    printf("\nPressione ENTER para continuar.");

    clearbuffer();
    restore_cursor_pos();
    clear_end();
  }
}

typedef enum Dificuldade{
  Iniciante,
  Intermediario,
  Avancado
} Dificuldade;


FILE *opennivel(Dificuldade dif){
  if(dif == Iniciante){
    return fopen("iniciante.txt", "rb");
  }else if(dif == Intermediario){
    return fopen("intermediario.txt", "rb");
  }else{
    return fopen("avancado.txt", "rb");
  }
}

void config(FILE **f, Dificuldade *current_dif){
  while(1){
    cleartop();
    printf("=== Configuracoes ===\n\n");
    printf("1 - Zerar ranking\n");
    printf("2 - Ajustar modo de dificuldade\n");
    printf("3 - Voltar ao menu principal\n\n");
    int opc = get_opc(1, 3);
    if(opc == 1){
      printf("Confirmar zerar o ranking? (S/N): ");
      char c = getchar();
      clearbuffer();
      if(c == 's' || c == 'S'){
        FILE *d = fopen("ranking.bin", "wb");
        fclose(d);
        printf("Ranking zerado.\n");
      }else{
        printf("Operacao cancelada.\n");
      }
      printf("Pressione ENTER para continuar.");
      clearbuffer();
    }else if(opc == 2){
      cleartop();
      printf("=== Escolha dificuldade ===\n\n");
      printf("1 - Iniciante\n");
      printf("2 - Intermediario\n");
      printf("3 - Avancado\n");
      printf("4 - Retornar\n\n");

      int opc1 = get_opc(1, 4);
      if(opc1 == 1){
        *current_dif = Iniciante;
        fclose(*f);
        *f = opennivel(Iniciante);
        printf("Configurado para modo Iniciante.\n");
        printf("Pressione ENTER para continuar.");
        clearbuffer();
      }else if(opc1 == 2){
        *current_dif = Intermediario;
        fclose(*f);
        *f = opennivel(Intermediario);
        printf("Configurado para modo Intermediario.\n");
        printf("Pressione ENTER para continuar.");
        clearbuffer();
      }else if(opc1 == 3){
        *current_dif = Avancado;
        fclose(*f);
        *f = opennivel(Avancado);
        printf("Configurado para modo Avancado.\n");
        printf("Pressione ENTER para continuar.");
        clearbuffer();
      }
    }else{
      return;
    }
  }
}

typedef struct RegistroRank{
  char nickname[21];
  int score;
} RegistroRank;


void update_rank(char *nickname, Dificuldade dif){
  int score;
  if(dif == Iniciante) score = 50;
  else if(dif == Intermediario) score = 100;
  else score = 200;

  // carregar ranking

  FILE *frank = fopen("ranking.bin", "rb+");
  if(frank == NULL){
    frank = fopen("ranking.bin", "wb+");
    if(frank == NULL){
      printf("Erro ao abrir, ou criar, arquivo de ranking. Pressione ENTER para continuar.");
      clearbuffer();

      return;
    }
  }

  // get size
  fseek(frank, 0, SEEK_END);
  int size = ftell(frank) / sizeof(RegistroRank);
  fseek(frank, 0, SEEK_SET);

  // read from file to array
  RegistroRank ranking[size + 1];
  int lidos = fread(ranking, sizeof(RegistroRank), size, frank);
  if(lidos != size){
    printf("Erro ao ler de arquivo para salvar ranking. Pressione ENTER para continuar.");
    fclose(frank);
    clearbuffer();

    return;
  }

  // checa se nickname ja esta no ranking
  int found = 0;
  int idx;
  for(int i = 0; i < size; i++){
    if(strcmp(ranking[i].nickname, nickname) == 0){
      found = 1;
      idx = i;
      ranking[i].score += score;
      break;
    }
  }

  if(!found){
    strcpy(ranking[size].nickname, nickname);
    ranking[size].score = score;
    idx = size;
  }

  // ordena ranking
  while(idx - 1 >= 0){
    if(ranking[idx].score > ranking[idx - 1].score){
      RegistroRank tmp = ranking[idx];
      ranking[idx] = ranking[idx - 1];
      ranking[idx - 1] = tmp;
      idx--;
    }else{
      break;
    }
  }

  fseek(frank, 0, SEEK_SET);
  // write ranking
  int escritos = fwrite(ranking, sizeof(RegistroRank), size + !found, frank);
  if(escritos != size + !found){
    printf("Erro ao escrever no arquivo para salvar ranking. Pressione ENTER para continuar.");
    fclose(frank);
    clearbuffer();

    return;
  }

  fclose(frank);
}

void show_ranking(){
  // carregar ranking
  FILE *frank = fopen("ranking.bin", "rb");
  if(frank == NULL){
    printf("Erro ao abrir arquivo de ranking. Pressione ENTER para continuar.");
    clearbuffer();

    return;
  }

  // get size
  fseek(frank, 0, SEEK_END);
  int size = ftell(frank) / sizeof(RegistroRank);

  fseek(frank, 0, SEEK_SET);

  RegistroRank ranking[size];
  int lidos = fread(ranking, sizeof(RegistroRank), size, frank);
  fclose(frank);
  if(lidos != size){
    printf("Erro ao ler ranking. Pressione ENTER para continuar.");
    clearbuffer();

    return;
  }

  // print ranking
  cleartop();
  printf("      ### Ranking ###\n\n");
  for(int i = 0; i < size; i++){
    char tmp_buffer[22];
    snprintf(tmp_buffer, 22, "%s:", ranking[i].nickname);
    printf("%-21s %5d\n", tmp_buffer , ranking[i].score);
  }

  printf("\n\nPressione ENTER para voltar para o menu.");
  clearbuffer();
}


int main(){
  signal(SIGINT, handle_ctrlc);
  new_buffer();

  char nickname[21];
  tela_inicio(nickname, 21);

  Dificuldade nivel = Iniciante;
  FILE *f = opennivel(nivel);

  while(1){
    if(f == NULL){
      printf("Erro ao abrir arquivo das fases. Pressione ENTER para sair.");
      clearbuffer();
      break;
    }
    int opc = menu();
    if(opc == 1){
      int passou = jogo(f);
      if(passou){
        update_rank(nickname, nivel);

        // nivel terminado
        if(fgetvc(f) == EOF){
          nivel++;
          if(nivel > Avancado){
            cleartop();
            printf("\n\n****Parabens!!****\n\nVoce zerou o jogo!\n");
            printf("\nPressione ENTER para voltar para o menu.");
            clearbuffer();           

            nivel = Iniciante;
          }
          fclose(f);
          f = opennivel(nivel);
        }else fseek(f, -1, SEEK_CUR);
      }
    }else if(opc == 2){
      config(&f, &nivel);
    }else if(opc == 3){
      inst();
    }else if(opc == 4){
      show_ranking();
    }else if(opc == 5){
      fclose(f);
      break;
    }
  }

  restore_buffer();
  printf("Tchau, %s, volte sempre!", nickname);
  return 0;
}

