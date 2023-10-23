#include "../include/forca.h"

int main()
{
  srand(time(NULL));
  char word[50];
  int option, theme, level, play_again;
  char name[50];
  char theme_name[30];
  char level_name[10];

  do 
  {
    show_menu();
    if (scanf("%d", &option) != 1)
    {
      printf("ERRO: Opção Inválida.\n");
      while (getchar() != '\n'); // clear the input buffer
      continue;
    }

    switch (option)
    {
      case 1:
      {
        game();
        read_game_data(&theme, &level, name, theme_name, level_name);
        choose_word(level, theme, word);
        printf("%s\n", word);

        do
        {
          show_play_again_message();
          if (scanf("%d", &play_again) != 1)
          {
            printf("ERRO: Opção Inválida.\n");
            while (getchar() != '\n'); // clear the input buffer
            continue;
          }

          if (play_again != 1 && play_again != 2)
            printf("ERRO: Opção Inválida.\n");
        }
        while (play_again != 1 && play_again != 2);

        if (play_again == 2)
          show_exit_message();

        break;
      }

      case 2:
      {
        show_project_info();
        break;
      }

      case 0:
      {
        show_exit_message();
        break;
      }

      default:
      {
        if (option != 0)
        {
          printf("ERRO: Opção Inválida.\n");
        }
      }
    }
  }
  while (option != 2 && option != 0 && play_again != 2);

  return 0;
}
