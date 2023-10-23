#include "../include/forca.h"

void show_menu()
{
  printf("1 - Jogar\n2 - Sobre o Projeto\n0 - Sair\n");
  printf("--> ");
}

void show_project_info()
{
  printf("Essas são as informações do nosso projeto:\n");
}

void show_exit_message()
{
  printf("Obrigado por jogar!!!\n");
}

void read_game_data(int *theme, int *level, char name[50], char theme_name[30], char level_name[10])
{
  printf("Tema:\n1 - Lugares da UFG\n2 - Linguagens de Programação\n3 - CEP\n4 - PCH\n5 - Frutas\n6 - Animais\n--> ");
  scanf("%d", theme);
  printf("Level: \n1 - Fácil\n2 - Médio\n3 - Difícil\n--> ");
  scanf("%d", level);
  printf("Nome: ");
  scanf("%s", name);

  if (*theme == 1)
    strcpy(theme_name, "Lugares da UFG");
  else if (*theme == 2)
    strcpy(theme_name, "Linguagens de Programação"); 
  else if (*theme == 3)
    strcpy(theme_name, "CEP");
  else if (*theme == 4)
    strcpy(theme_name, "PCH");
  else if (*theme == 5)
    strcpy(theme_name, "Frutas");
  else if (*theme == 6)
    strcpy(theme_name, "Animais");
    
  if (*level == 1)
    strcpy(level_name, "Fácil");
  else if (*level == 2)
    strcpy(level_name, "Médio");
  else if (*level == 3)
    strcpy(level_name, "Difícil");
    
  printf("Tema: %s, Level: %s, Nome: %s\n", theme_name, level_name, name);

}

void display_hangman(int mistakes)
{
  char hangman[10][21] = 
  {
    "  |----------------",
    "  |               |",
    "  |",
    "  |",
    "  |",
    "  |",
    "  |",
    "  |",
    "  |",
    "  |"
  };

  if (mistakes >= 1)
    strcpy(hangman[2], "  |               O");
	  
  if (mistakes >= 2)
    strcpy(hangman[3], "  |               |");

  if (mistakes >= 3)
    strcpy(hangman[3], "  |              /|");
  
  if (mistakes >= 4)
    strcpy(hangman[3], "  |              /|\\");

  if (mistakes >= 5)
    strcpy(hangman[4], "  |              /");

  if (mistakes >= 6)
    strcpy(hangman[4], "  |              / \\");

  for (int i = 0; i < 21; i++)
    printf("%s\n", hangman[i]);
}

void choose_word(int level, int theme, char word[50])
{
  // places list
  char easy_places[5][20] = {"ru", "inf", "cab", "biblioteca", "reuni"};
  char normal_places[5][20] = {"dce", "draco", "reitoria", "emac", "fav"};
  char hard_places[5][20] = {"fefd", "face", "letras", "buraco", "delicias"}; 
  
  // programming languages list
  char easy_langs[5][20] = {"c", "python", "javascript", "java", "cplusplus"};
  char normal_langs[5][20] = {"ruby", "php", "golang", "rust", "csharp"};
  char hard_langs[5][20] = {"dart", "haskell", "scala", "erlang", "ocaml"};

  // cepbr list
  char easy_cepbr[5][20] = {"goiania", "brasil", "fortaleza", "goias", "brasilia"};
  char normal_cepbr[5][20] = {"salvador", "uberlandia", "jatai", "amazonas", "nordeste"};
  char hard_cepbr[5][20] = {"jequie", "montividiu", "pindamonhangaba", "doverlandia", "guapo"};

  // pch list
  char easy_pch[5][20] = {"nariz", "olho", "cabelo", "dedo", "boca"};
  char normal_pch[5][20] = {"femur", "coccix", "timo", "tibia", "iris"};
  char hard_pch[5][20] = {"eponiqio", "gnatico", "zigomatico", "tonsila", "antihelice"};
  
  // fruits list
  char easy_fruits[5][20] = {"banana", "manga", "uva", "melancia", "abacaxi"};
  char normal_fruits[5][20] = {"tangerina", "kiwi", "carambola", "framboesa", "damasco"};
  char hard_fruits[5][20] = {"pitaya", "kiwano", "salak", "cajui", "graviola"};

  // animals list
  char easy_animals[5][20] = {"cachorro", "gato", "arara", "cavalo", "coelho"};
  char normal_animals[5][20] = {"caranguejo", "camaleao", "camelo", "hiena", "esquilo"};
  char hard_animals[5][20] = {"crocodilo", "antilope", "seriema", "guaruba", "casuar"};

  // secret phrase
  char secret_phrase[1][50] = {"professor_hebert_passa_todo_mundo_por_favor"};

  char word_list[5][20];
  char word_count;
  
  // copying word list
  if (theme == 1)
  {
    if (level == 1)
    {
      for (int i = 0; i < 5; i++)
        strcpy(word_list[i], easy_places[i]);
      word_count = 5;
    }
    else if (level == 2)
    {
      for (int i = 0; i < 5; i++)
        strcpy(word_list[i], normal_places[i]);
      word_count = 5;
    }
    else
    {
      for (int i = 0; i < 5; i++)
        strcpy(word_list[i], hard_places[i]);
      word_count = 5;
    }
  }
    
  else if (theme == 2)
  {
    if (level == 1)
    {
      for (int i = 0; i < 5; i++)
        strcpy(word_list[i], easy_langs[i]);
      word_count = 5;
    }
    else if (level == 2)
    {
      for (int i = 0; i < 5; i++)
        strcpy(word_list[i], normal_langs[i]);
      word_count = 5;
    }
    else 
    {
      for (int i = 0; i < 5; i++)
        strcpy(word_list[i], hard_langs[i]);
      word_count = 5;
    }
  }
    
  else if (theme == 3)
  {
    if (level == 1)
    {
      for (int i = 0; i < 5; i++)
        strcpy(word_list[i], easy_cepbr[i]);
      word_count = 5;
    }
    else if (level == 2)
    {
      for (int i = 0; i < 5; i++)
        strcpy(word_list[i], normal_cepbr[i]);
      word_count = 5;
    }
    else 
    {
      for (int i = 0; i < 5; i++)
        strcpy(word_list[i], hard_cepbr[i]);
      word_count = 5;
    }
  }

  else if (theme == 4)
  {
    if (level == 1)
    {
      for (int i = 0; i < 5; i++)
        strcpy(word_list[i], easy_pch[i]);
      word_count = 5;
    }
    else if (level == 2)
    {
      for (int i = 0; i < 5; i++)
        strcpy(word_list[i], normal_pch[i]);
      word_count = 5;
    }
    else
    {
      for (int i = 0; i < 5; i++)
        strcpy(word_list[i], hard_pch[i]);
      word_count = 5;
    }
  }

 else if (theme == 5) 
 {
     if (level == 1)
    {
      for (int i = 0; i < 5; i++)
        strcpy(word_list[i], easy_fruits[i]);
      word_count = 5;
    }
    else if (level == 2)
    {
      for (int i = 0; i < 5; i++)
        strcpy(word_list[i], normal_fruits[i]);
      word_count = 5;
    }
    else 
    {
      for (int i = 0; i < 5; i++)
        strcpy(word_list[i], hard_fruits[i]);
      word_count = 5;
    }
  }

  else if (theme == 6)
  {
    if (level == 1)
    {
      for (int i = 0; i < 5; i++)
        strcpy(word_list[i], easy_animals[i]);
      word_count = 5;
    }
    else if (level == 2)
    {
      for (int i = 0; i < 5; i++)
        strcpy(word_list[i], normal_animals[i]);
      word_count = 5;
    }
    else 
    {
      for (int i = 0; i < 5; i++)
        strcpy(word_list[i], hard_animals[i]);
      word_count = 5;
    }
  }
  
  int random_index = rand() % word_count;
  strcpy(word, word_list[random_index]);
  
}

void game()
{
  printf("O jogo está funcionando.\n");
}

void show_play_again_message()
{
  printf("Deseja jogar novamente?[1 - SIM / 2 - NÃO]\n");
  printf("--> ");
}
