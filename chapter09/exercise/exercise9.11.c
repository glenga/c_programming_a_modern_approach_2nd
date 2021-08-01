#include <stdio.h>
#include <ctype.h>

#define SIZE ((int)sizeof(grades) / sizeof(grades[0]))

float computer_GPA(char grades[], int n);

int main() {
  char grades[] = {'A', 'a', 'b', 'B', 'c', 'C', 'D', 'd','F', 'f'};
  printf("The average of grades: %.2f", computer_GPA(grades, SIZE));
  return 0;
}

float computer_GPA(char grades[], int n) {
    int sum = 0;
    char ch;
    for(int i = 0; i < n; i++){
        ch = toupper(grades[i]);
        switch(ch){
            case 'A':
            sum += 4;
            break;
            case 'B':
            sum+=3;
            break;
            case 'C':
            sum+=2;
            break;
            case 'D':
            sum+=1;
            break;
            case 'F':
            break;
            default:
            printf("The grades error!\n");
            return 0;
        }
    }

    return sum / n;
}