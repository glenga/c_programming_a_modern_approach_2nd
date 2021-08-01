/*
这个程序产生一个1-100的随机数,用户尝试用尽可能少的次数猜出这个数。
*/

#include <conio.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_NUMBER 100
#define RANGE_INT(a, b) (rand() % (b - a) + a + 1)

int secret_number;

void initialize_number_generator(void);
void choose_new_secret_number(void);
void read_guesses(void);

int main() {

  printf("Guess the secret number between 1 and %d.", MAX_NUMBER);
  initialize_number_generator();

  do {
    choose_new_secret_number();
    printf("\n\nA new secret number has been chosen.\n\n");
    read_guesses();
    printf("Play again(Y/N)?");
  } while (getch() == 'y' || getch() == 'Y');

  return 0;
}

void initialize_number_generator(void) { srand((unsigned)time(NULL)); }

void choose_new_secret_number(void) {
  secret_number = RANGE_INT(1, MAX_NUMBER + 1);
}

void read_guesses(void) {
  int guess, num_guesses = 0;
  while (true) {
    num_guesses++;
    printf("Enter the guess number: ");
    scanf("%d", &guess);
    if (guess == secret_number) {
      printf("\nYou won in %d guesses!\n\n", num_guesses);
      return;
    } else if (guess < secret_number) {
      printf("Too low; try again.\n");
    } else {
      printf("Too big, Try again.\n");
    }
  }
}