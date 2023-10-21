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
  printf("THEME: (1, 2, 3, 4, 5, 6) -> ");
  scanf("%d", &theme);
  printf("LEVEL: (1, 2, 3) -> ");
  scanf("%d", &level);
  printf("USER NAME: ");
  scanf("%s", name);

  printf("THEME %d, LEVEL %d, NAME %s\n", theme, level, name);
}

void display_hangman(int mistakes)
{
  
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
        strcpy(word_list[i], hard_langs[i]);
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
