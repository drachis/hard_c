#include "ex1.h"

int main(int argc,char *argv[])
{
  puts("Hello world.\n");
  ex3();
  ex4();
  ex5();
  return 0;
}

void ex3()
{
  //exersice three, insterting values into strings
  int age = 10;
  int height = 72;
  
  printf("I am %d years old.\n", age);
  printf("I am %d inches tall.\n",height);

}

void ex4()
{
  //exercise 4 working with vangrid
  int age = 26;
  int height=76; 
  
  printf("I am %d years old.\n",age);
  printf("I am %d inches tall.\n",height);
  
}

void ex5()
{
  int distance = 100;
  float power = 2.345f;
  double super_power = 5678.4532;
  char initial = 'K';
  char initial2 = 'A';
  char first_name[] = "Toli" ;
  char last_name[] = "Carter";
  
  printf("You are %d miles away.\n",distance);
  printf("You have %f levels of power.\n",power);
  printf("You have %f awesome supwer powers.\n",super_power);
  printf("I have an initial %c.\n",initial);
  printf("I have a first name %s.\n",first_name);
  printf("I have a last name %s.\n",last_name);
  printf("My whole name is %s %c%c %s.\n",first_name,initial2,initial,last_name);
}