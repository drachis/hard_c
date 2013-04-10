#include "ex1.h"

int main(int argc,char *argv[])
{
  puts("Hello world.\n");
  ex3();
  ex4();
  ex6();
  ex7();
  ex8();
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

void ex6()
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

void ex7()
{
  int bugs = 100;
  double bug_rate = 1.2;
  
  printf("you have %d bugs at the imaginary rate of %f.\n",bugs,bug_rate);
  
  long universe_of_defects = 1L*1024L*1024L*1024L;l
  printf("The entire universe has %ld bugs.\n",universe_of_defects);
  
  double expected_bugs = bugs * bug_rate;
  printf("You are expected to have %f bugs.\n",expected_bugs);
  
  double part_of_universe = expected_bugs / universe_of_defects;
  printf("That is only a %e portion of the universe.\n",part_of_universe);
  
  //illogical demo code
  char null_byte = '\0';
  int care_percentage = bugs * null_byte;
  printf("Which meand you should care %d%%,%s.\n",care_percentage,null_byte);
}

void ex8()
{
	int areas[] = {10,12,13,14,20};
	char name[] = "Zed";
	char full_name[] = {
		'Z','e','d',
		' ','A','.',' ',
		'S','h','a','w','\0'
	};
	
	printf("The size of an int: %ld\n",sizeof(int));
	printf("THe size of areas (int[]): %ld\n", sizeof(areas));
	
	printf("The number of ints in areas: %ld\n",areas[0]/sizeof(int));
}
