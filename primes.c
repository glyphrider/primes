#include <stdio.h>
#include <stdlib.h>

typedef struct factor_node {
  int factor;
  struct factor_node *next;
} node;

int parse_commandline(int argc, char *argv[])
{
  int result = 10000;
  if(argc >= 2)
    sscanf(argv[1],"%d",&result);
  return result;
}

int addnode(node **start, node **end, int value)
{
  if(*start)
  {
    (*end)->next = (node*)malloc(sizeof(node));
    *end = (*end)->next;
  }
  else
  {
    *start = (node*)malloc(sizeof(node));
    *end = *start;
  }
  (*end)->factor = value;
  (*end)->next = 0;
}

int is_prime(int candidate,node *factors)
{
  for(;factors && factors->factor * factors->factor <= candidate; factors = factors->next)
    if(candidate % factors->factor == 0)
      return 0;
  return 1;
}

int main(int argc, char *argv[])
{
  int count = 0;
  int candidate = 2;
  node *factors;
  node *last;

  factors = 0;
  last = 0;

  int number_to_find = parse_commandline(argc,argv);

  while(1)
  {
    if(is_prime(candidate,factors))
    {
      addnode(&factors,&last,candidate);
      fprintf(stdout,"%d is prime %d.\n",candidate,++count);
    }
    if(count == number_to_find) break;
    candidate++;
  }
  return 0;
}

