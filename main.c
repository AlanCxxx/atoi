#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int16_t rdInt(void)
{
  int16_t Ax;
  int16_t x2;
  int16_t x8;
  char digit;
  int16_t sgn=1;
  int16_t minus=45;
  int16_t zero=48;
  int16_t nine=57;
  int16_t number=0;

  Ax=-32768;
  NEXT:
    digit=getchar();
    if (digit=='\n') goto DONE;
    if (digit==minus) {
      sgn=-sgn;
      goto NEXT;
    }
    if (digit<zero) goto ERROR;
    if (digit>nine) goto ERROR;
    x2=number+number;
    x8=x2+x2;
    x8=x8+x8;
    number=x8+x2;
    number=number+digit;
    number=number-48;
    if (number<0) goto ERROR;
    goto NEXT;
DONE:
    if (sgn<=0) {
      number=-number;
    }
    Ax=number;
ERROR:
    // Clear buffer
    while (digit!='\n') {
      digit=getchar();
    }
    return Ax;
}

int main(void)
{
  printf("Enter an integer ");
  while (1) printf("%d\nEnter an integer ",rdInt());
  return 0;
}
