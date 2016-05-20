
#include <stdio.h>
#include <math.h>

/*
* Filename: dna.c
* Author: Andrés Villagra de la Fuente
*
* Description: Prints a DNA lookalike curve. That's it.
*/

#define PI                 3.14159265
#define MIDDLE             21
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_RESET   "\x1b[0m"

int main()
{
  int x, pos, pos2, printIndex;
  pos = pos2 = 0;
  x = 0;
  char line[43] = "------------------------------------------";

  while (1)
  {
    line[pos-1]  = ' ';
    line[pos]    = ' ';
    line[pos+1]  = ' ';
    line[pos2-1] = ' ';
    line[pos2]   = ' ';
    line[pos2+1] = ' ';
    x += 10;
    pos  = sin((x*(PI/180))/2)   *   20+MIDDLE;
    pos2 = sin((x*(PI/180))/2)* (-1)*20+MIDDLE;
    line[pos-1]  = 'X';
    line[pos]    = 'X';
    line[pos+1]  = 'X';
    line[pos2-1] = 'X';
    line[pos2]   = 'X';
    line[pos2+1] = 'X';

    printIndex = 0;
    while(line[printIndex] != '\0')
    {
      if (line[printIndex] == 'X')
      {
        printf(ANSI_COLOR_MAGENTA);
        putchar(line[printIndex]);
        printf(ANSI_COLOR_RESET);
      }
      else if ( x % 40 == 0 &&
               (
                (printIndex > pos && printIndex < pos2)||
                (printIndex < pos && printIndex > pos2)
               )
              )
      {
        printf(ANSI_COLOR_BLUE); 
        putchar('T');
        printf(ANSI_COLOR_RESET);
      }
      else
        putchar(line[printIndex]);
      printIndex++;
    }
    putchar('\n');
  } 
}