#include "../include/forca.h"

void show_menu()
{
  printf("1 - Jogar\n2 - Sobre o Projeto\n0 - Sair\n");
  printf("--> ");
}

void show_project_info()
{
  printf("Essas são as informações do nosso projeto.\n");
}

void show_exit_message()
{
  printf("Obrigado por jogar\n");
}

void read_game_data(int theme, int level, char name[50])
{
  printf("THEME: (1, 2, 3, 4) -> ");
  scanf("%d", &theme);
  printf("LEVEL: (1, 2, 3, 4) -> ");
  scanf("%d", &level);
  printf("USER NAME: ");
  scanf("%s", name);

  printf("THEME %d, LEVEL %d, NAME %s\n", theme, level, name);
}

void choose_word(int level, int theme, char word[50])
{
  char easy_places[5][20] = {"ru", "inf", "cab"};

  // programming language list
  char easy_langs[5][20] = {"c", "python", "javascript", "java", "cplusplus"};
  char normal_langs[5][20] = {"ruby", "php", "golang", "rust", "csharp"};
  char hard_langs[5][20] = {"dart", "haskell", "scala", "erlang", "ocaml"};

  // programming cepbr list
  char easy_cepbr[5][20] = {"goiania", "brasil", "rio de janeiro", "goias", "brasilia"};
  char normal_cepbr[5][20] = {"rio verde", "uberlandia", "jatai", "amazonas", "nordeste"};
  char hard_cepbr[5][20] = {"passa tempo", "montividiu", "pindamonhangaba", "doverlandia", "guapo"};

  // programming pch list
  char easy_pch[5][20] = {"nariz", "olho", "cabelo", "dedo", "boca"};
  char normal_pch[5][20] = {"femur", "coccix", "timo", "tibia", "iris"};
  char hard_pch[5][20] = {"eponiqio", "gnatico", "zigomatico", "tonsila", "antihelice"};
  
  //fruits list
  char easy_fruits[5][20] = {"banana", "manga", "uva", "melancia", "abacaxi"};
  char normal_fruits[5][20] = {"tangerina", "kiwi", "carambola", "framboesa", "damasco"};
  char hard_fruits[5][20] = {"pitaya", "kiwano", "salak", "cajui", "graviola"};
  
}

void game(int theme, int level, char name[50])
{
  printf("O jogo está funcionando.\n");
  read_game_data(theme, level, name);
}

void show_play_again_message()
{
  printf("Deseja jogar novamente?[1 - SIM/2 - NÃO]\n");
  printf("--> ");
}
