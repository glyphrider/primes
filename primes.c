#include <stdio.h>


int parse_commandline(int argc, char *argv[])
{
  int result = 10000;
  if(argc >= 2)
    sscanf(argv[1],"%d",&result);
  return result;
}

int is_prime(int candidate)
{
  for(int factor = 2; factor < candidate; factor++)
    if(candidate % factor == 0)
      return 0;
  return 1;
}

int main(int argc, char *argv[])
{
  int count = 0;
  int candidate = 2;

  int number_to_find = parse_commandline(argc,argv);

  while(1)
  {
    if(is_prime(candidate))
    {
      fprintf(stdout,"%d is prime %d.\n",candidate,++count);
    }
    if(count == number_to_find) break;
    candidate++;
  }
  return 0;
}

