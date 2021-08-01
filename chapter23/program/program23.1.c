#include <math.h>
#include <stdio.h>

int main() {
  double a, b, c, radical, root1, root2;

  printf("For ax^2 + bx + c = 0, enter a b c: ");
  scanf("%lf%*[ ,]%lf%*[ ,]%lf", &a, &b, &c);

  // printf("%lf %lf %lf\n", a, b, c);

  radical = b * b - 4 * a * c;
  if (radical < 0)
    printf("The roots to the given quadratic are complex.\n");
  else {
    radical = sqrt(radical);
    root1 = (-b + radical) / (2 * a);
    root2 = (-b - radical) / (2 * a);
    if (root1 == root2)
      printf("1 root: x = %lf\n", root1);
    else
      printf("2 roots: x = %lf or %lf\n", root1, root2);
  }

  return 0;
}

// For ax^2 + bx + c = 0, enter a b c: 5 16 3