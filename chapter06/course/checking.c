#include <stdio.h>

int main(void) {

  printf("*** ACME checkbook-balancing program ***\n");
  printf("Commands: 0=clear, 1=credit, 2=debit, 3=balance, 4=exit\n");

  int choose;
  float credit, debit, balance = .0f;

  while (1) {
    printf("Enter command: ");
    scanf("%d", &choose);
    switch (choose) {
    case 0:
      balance = .0f;
      break;
    case 1:
      printf("Enter amount of credit: ");
      scanf("%f", &credit);
      balance += credit;
      break;
    case 2:
      printf("Enter amount of debit: ");
      scanf("%f", &debit);
      balance -= debit;
      break;
    case 3:
      printf("Current balance: $%.2f\n", balance);
      break;
    case 4:
      // exit(0);
      return 0;

    default:
      printf("Commands: 0=clear, 1=credit, 2=debit, 3=balance, 4=exit\n");
      break;
    }
  }

  return 0;
}

// *** ACME checkbook-balancing program ***
// Commands: 0=clear, 1=credit, 2=debit, 3=balance, 4=exit
// Enter command: 1
// Enter amount of credit: 1042.56
// Enter command: 2
// Enter amount of debit: 133.79
// Enter command: 1
// Enter amount of credit: 1754.32
// Enter command: 2
// Enter amount of debit: 1400
// Enter command: 2
// Enter amount of debit: 68
// Enter command: 2
// Enter amount of debit: 50
// Enter command: 3
// Current balance: $1145.09
// Enter command: 4