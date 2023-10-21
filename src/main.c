#include "../include/forca.h"

int main()
{
  int option, theme = 0, level = 0, play_again;
  char name[50];

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
        game(theme, level, name);

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
