#include <stdio.h>

#define STUDS 5
#define SCORES 5

int main() {
  float array[STUDS][SCORES];

  for (int stu = 0; stu < STUDS; stu++) {
    printf("Enter student's %d scores for 5 courses: ", stu + 1);
    for (int score = 0; score < SCORES; score++) {
      scanf("%f", &array[stu][score]);
    }
  }

  float sum;

  for (int stu = 0; stu < STUDS; stu++) {
    sum = 0;
    for (int score = 0; score < SCORES; score++) {
      sum += array[stu][score];
    }
    printf("student %d:  total: %6.1f  average: %6.1f\n", stu, sum, sum / STUDS);
  }

  printf("\n");

  float max, min;

  for (int score = 0; score < SCORES; score++) {
    sum = 0;
    max = array[score][0];
    min = array[score][0];

    for (int stu = 0; stu < STUDS; stu++) {
      sum += array[stu][score];
      if (array[stu][score] > max)
        max = array[stu][score];
      if (array[stu][score] < min)
        min = array[stu][score];
    }
    printf(
        "course %d average: %6.1f  the highest score: %6.1f  the lowest score: "
        "%6.1f\n",
        score, sum / STUDS, max, min);
  }

  printf("\n");

  return 0;
}


// Enter student's 1 scores for 5 courses: 87 95 88 78 89
// Enter student's 2 scores for 5 courses: 85.5 86 88 89 80
// Enter student's 3 scores for 5 courses: 75 76 77 70 69
// Enter student's 4 scores for 5 courses: 56 65 76 59 68
// Enter student's 5 scores for 5 courses: 45 55 58 70 68