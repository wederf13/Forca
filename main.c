#include <stdio.h>
int main ()
{
  int i, n;
  int f = 1;
 
  scanf("%d", &n);
 
  for (i = n; i > 1; i--)
  {
      f = f * i;
  }
    
  printf("%d! = %d", n, f);
 
  return 0;
}
