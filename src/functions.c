#include "../include/forca.h"

void display_menu()
{
  printf("1 - Jogar\n2 - Sobre o Projeto\n0 - Sair\n");
  printf("--> ");
}

void show_project_info()
{
  printf("Essas são as informações do nosso projeto:\n");
  printf("Jogo de Forca desenvolvido como 1° projeto para a matéria de Introdução à Programação do curso de Ciência da Computação.\n"
         "Feito por: Rebeca, Sebastião, Sofia, Tiago, Vitória e Weder.\n\n"
         "Conceitos utilizados no programa:\n\n"
         "1 - Inclusão de Bibliotecas: O código inclui um arquivo de cabeçalho chamado 'forca.h' usando '#include'. Esse arquivo contém declarações de funções e definições de constantes usadas no programa.\n"
  	 "2 - Função 'main': Esta é a função principal do programa, onde a execução começa.\n"
         "3 - Inicialização do Gerador de Números Aleatórios: 'srand(time(NULL))'; é usado para inicializar o gerador de números aleatórios com uma semente baseada no tempo atual.\n"
         "4 - Declaração de Variáveis: O código declara variáveis como 'word', 'option', 'theme', 'level', 'play_again', 'name', 'theme_name', e 'level_name'. Essas variáveis serão usadas para armazenar informações do jogo e escolhas do jogador.\n"
         "5 - Estrutura de Repetição 'do while': O programa entra em um loop 'do while' que continuará sendo executado até que a variável 'option' seja igual a 2 ou 0, ou até que 'play_again' seja igual a 2. Isso permite que o jogador escolha continuar jogando ou sair do jogo.\n"
         "6 - Menu e Seleção de Opções: O programa exibe um menu com opções para o jogador escolher. A escolha do jogador é lida com 'scanf', e há verificações para garantir que uma escolha válida seja feita. Se a entrada não for um número, uma mensagem de erro é exibida.\n"
         "7 - Estrutura de Controle 'switch': O código usa uma estrutura de controle switch para lidar com diferentes opções selecionadas pelo jogador. A opção 1 inicia o jogo, a opção 2 mostra informações do projeto e a opção 0 encerra o jogo.\n"
         "8 - Chamadas de Função: O programa chama várias funções, como 'show_menu()', 'game()', 'read_game_data()', 'choose_word()', 'show_play_again_message()', 'show_exit_message()', e 'show_project_info()'. A função 'game()' é responsável por executar o jogo da forca.\n"
         "9 - Encerramento do Jogo: O jogo permite ao jogador escolher se deseja jogar novamente ou sair. O jogador pode selecionar as opções 1 para jogar novamente ou 2 para sair do jogo.\n"
        "10 - Retorno da Função 'main': O programa retorna 0 no final, indicando uma execução bem-sucedida.\n"
        "11 - Makefile: O arquivo 'Makefile' faz a junção de todos os outros arquivos para o funcionamento do código.\n");
}

void display_exit_message()
{
  printf("Obrigado por jogar!!!\n");
}

void read_game_data(int *theme, int *level, char name[50], char theme_name[30], char level_name[10])
{
	
  int valid_input = 0;

  while (!valid_input)
	{
    printf("Tema:\n1 - Lugares da UFG\n2 - Linguagens de Programação\n3 - CEP\n4 - PCH\n5 - Frutas\n6 - Animais\n--> ");

    if (scanf("%d", theme) != 1) {
      printf("ERRO: Opção Inválida. Insira um número.\n");
      while (getchar() != '\n'); // limpa o buffer de entrada
      continue;
    }

    if (*theme < 1 || *theme > 6) {
      printf("ERRO: Tema Inválido. Insira um número de 1 a 6.\n");
      continue;
    }

    system("clear");

    valid_input = 1;
  }

  valid_input = 0;

  while (!valid_input)
  {
    printf("Level: \n1 - Fácil\n2 - Médio\n3 - Difícil\n--> ");

    if (scanf("%d", level) != 1) {
      printf("ERRO: Opção Inválida. Insira um número.\n");
      while (getchar() != '\n');
      continue;
    }

    if (*level < 1 || *level > 3) {
      printf("ERRO: Nível Inválido. Insira um número de 1 a 3\n");
      continue;
    }

    valid_input = 1;
  }
  
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

  for (int i = 0; i < 10; i++)
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

int is_word_guessed(char word[], char guessed_word[]) 
{
    return strcmp(word, guessed_word) == 0;
}

void game(char word[50], char guessed_word[50], char incorrect_letters[26], char name[50], char theme_name[30], char level_name[10])
{
  int word_length = strlen(word);
  int mistakes = 0;

  for (int i = 0; i < word_length; i++)
    guessed_word[i] = '_';
  guessed_word[word_length] = '\0';
 
  for (int i = 0; i < 26; i++)
    incorrect_letters[i] = 0;

  display_hangman(mistakes);

  while (mistakes < 6)
  {
    printf("\n%s\n", guessed_word);
    
    printf("Letras incorretas: ");
    for (int i = 0; i < 26; i++)
    {
      if (incorrect_letters[i] == 1)
        printf("%c ", 'a' + i);
    }
    printf("\n");

    printf("--> ");
    char guess;
    scanf(" %c", &guess);
    guess = tolower(guess);
  
    int correct = 0;
    for (int i = 0; i < word_length; i++)
    {
      if (word[i] == guess)
      {
        guessed_word[i] = guess;
        correct = 1;
      }
    }
    if (!correct)
    {
      incorrect_letters[guess - 'a'] = 1;
      mistakes++;
    }
    
    system("clear");
    printf("Tema: %s, Nível: %s, Nome: %s\n", theme_name, level_name, name);
    display_hangman(mistakes);

    if (is_word_guessed(word, guessed_word))
    {
      printf("\nParabens: %s\n", word);
      break;
    }

    if (mistakes == 6)
    {
      printf("\nThe word was: %s\n", word);
      display_hangman(mistakes);
    }
  }

  printf("O jogo está funcionando.\n");
  system("clear");
}

void display_play_again_message()
{
  printf("Deseja jogar novamente?[1 - SIM / 2 - NÃO]\n");
  printf("--> ");
}
