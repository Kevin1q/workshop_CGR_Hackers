#include <stdlib.h>
#include <stdio.h>

int win()
{
  system("cat /pwn/flag.txt");

  return 0;
}

void vuln()
{
  char buff[8];

  printf("Tell me something : ");
  gets(buff);

}

int main()
{
  puts("Hello !");
  vuln();
  return 0;
}
