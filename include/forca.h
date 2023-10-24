#ifndef FORCA
#define FORCA

// the forca project header

// including an unreasonable
// amount of libraries:
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

// function declarations
int is_word_guessed(char word[], char guessed_word[]);

// procedures declarations
void read_game_data(int *theme, int *level, char name[50], char theme_name[30], char level_name[10]);
void display_hangman(int mistakes);
void choose_word(int level, int theme, char word[50]);
void game(char word[50], char guessed_word[50], char incorrect_letters[26], char name[50], char theme_name[30], char level_name[10]);
void display_menu();
void display_skull();
void display_project_info();
void display_exit_message();
void display_play_again_message();

#endif 
