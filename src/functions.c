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
 src/functions.c
