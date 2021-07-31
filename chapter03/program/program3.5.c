#include <stdio.h>

int main(void)
{
	int n11, n12, n13, n14, n21, n22, n23, n24,
      n31, n32, n33, n34, n41, n42, n43, n44;
	
	printf("Enter the numbers from 1 to 16 in any order:\n");
	scanf("%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d", 
		&n11, &n12, &n13, &n14, &n21, &n22, &n23, &n24, 
		&n31, &n32, &n33, &n34, &n41, &n42, &n43, &n44);
	
	printf("%d\t%d\t%d\t%d\n", n11, n12, n13, n14);
	printf("%d\t%d\t%d\t%d\n", n21, n22, n23, n24);
	printf("%d\t%d\t%d\t%d\n", n31, n32, n33, n34);
	printf("%d\t%d\t%d\t%d\n", n41, n42, n43, n44);
	
	printf("Row sums: %d %d %d %d\n", 
		n11+n12+n13+n14, n21+n22+n23+n24, 
		n31+n32+n33+n34, n41+n42+n43+n44 );
		
	printf("Column sums: %d %d %d %d\n", 
		n11+n21+n31+n41, n12+n22+n32+n42, 
		n13+n23+n33+n43, n14+n24+n34+n44);
		
	printf("Diagonal sums: %d %d\n", n11+n22+n33+n44, n41+n32+n23+n14);
	
	return 0;
}

// Enter the numbers from 1 to 16 in any order:
// 16 3 2 13 5 10 11 8 9 6 7 12 4 15 14 1