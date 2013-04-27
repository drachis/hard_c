#include "ex1.h"

int main(int argc,char *argv[])
{
	/*
	puts("Hello world.\n");
	ex3();
	ex4();
	ex6();
	ex7();
	ex8();
	ex9();
	ex10(argc,argv);
	ex11(argc,argv);
	ex12(argc,argv);
	ex13(argc,argv);
	*/
	ex14(argc,argv);
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

	long universe_of_defects = 1L*1024L*1024L*1024L;
	printf("The entire universe has %ld bugs.\n",universe_of_defects);

	double expected_bugs = bugs * bug_rate;
	printf("You are expected to have %f bugs.\n",expected_bugs);

	double part_of_universe = expected_bugs / universe_of_defects;
	printf("That is only a %e portion of the universe.\n",part_of_universe);

	//illogical demo code
		// char null_byte = '\0'; //causes a compile error during insertion to string changed %c->%i and char->int
	int null_byte = '\0';
	int care_percentage = bugs * null_byte;
	printf("Which meand you should care %d%%,%i.\n",care_percentage,null_byte);
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
	areas[1] = name[2];
	printf("The size of an int: %d\n",sizeof(int));
	printf("THe size of areas (int[]): %d\n", sizeof(areas));

	printf("The number of ints in areas: %d\n",areas[0]/sizeof(int));
	printf("%i\n",areas[1]);
}

void ex9()
{
	int numbers[4] = {0};
	char name[4] = {'a'};
	//printing raw contents
	
	printf(
		"numbers %d %d %d %d \n",
		numbers[0],numbers[1],
		numbers[2],numbers[3]
		);
	
	printf(
		"name each %c %c %c %c \n",
		name[0],name[1],
		name[2],name[3]
		);
	printf("name: %s\n",name);
	
	//numbers setup
	numbers[0] = 1;
	numbers[1] = 2;
	numbers[2] = 3;
	numbers[3] = 4;
	
	//name setup
	name[0] = 'Z';
	name[1] = 'e';
	name[2] = 'd';
	name[3] = '\0';
	
	//print initialzed 
	printf("numbers: %d %d %d %d\n",
		  numbers[0],numbers[1],
		  numbers[2],numbers[3]
		  );
	
	printf("name each: %c %c %c %c\n",
		  name[0],name[1],
		  name[2],name[3]
		  );
	//print name like a string
	printf("name: %s \n", name);
	
	
	char *another = "Zed";
	
	printf("another: %s\n",another);
	
	printf("antoher each: %c %c %c %c\n",
		  another[0],another[1],
		  another[2],another[3]
		  );
	/*
	//initialization from incompatible pointer type
	int *letter = name;
	printf("letter to number: %i %i %i %i\n",
		   name[0], name[1],
		   letter[2], letter[3]);
	*/
}
void ex10(int argc, char *argv[]){
	int i = 0;
	
	//go through each string in argv
	//skips argv[0]
	
	for( i = 1; i < argc; i++){
		printf("arg %d: %s\n", i, argv[i]);
	}
	
	// string array time
	char *states[] = {
		"California", "Oregon",
		"Washington","Texas"
	};
	int num_states = 4;
	
	for(i = 0; i < num_states; i++) {
		printf("state %d: %s\n", i, states[i]);
	}

}
void ex11(int argc, char *argv[]){
	int i = 0;
	while(i < argc) {
		printf("arg %d: %s\n",i,argv[i]);
		i++;
	}
	
	char *states[] = {
		"California","Oregon",
		"Washington","Texas"
	};
	
	int num_states = 4;
	i = 0; //watch for this (?)
	while(i<num_states) {
	printf("state %d: %s\n",i,states[i]);
		i++;
	}
	/*
	while(TEST){
		CODE;
	}
	*/
}

void ex12(int argc, char *argv[]){
	
	if(argc==1) {
		printf("Only one argument, minimauler.\n");
	} else if (1 < argc && argc < 4 ){
		printf("Seems legit, arguments inc:\n");
		
		int i=0; //tring out JIT decleration
		for(i=0;i < argc; i++) {
			printf("%i:%s ",i, argv[i]);
		}
		printf("\n");
	} else {
		printf("Totally overloaded here. Beep Boop!\n");
	}
}
void ex13 (int argc,char *argv[]){
	if(argc !=2){
		printf("Error: requires one argument. \n");
		
	} else {
		int i = 0;
		for(i=0;argv[1][i] != '\0'; i++){
			char letter = argv[1][i];
			
			switch(letter) {
				case 'a':
				case 'A':
					printf("%d: 'A'\n",i);
					break;
				case 'e':
				case 'E':
					printf("%d: 'E'\n",i);
					break;
				case 'i':
				case 'I':
					printf("%d: 'I'\n",i);
					break;
				case 'o':
				case 'O':
					printf("%d: 'O'\n",i);
					break;
				case 'u':
				case 'U':
					printf("%d: 'U'\n",i);
					break;
				case 'y':
				case 'Y':
					if(i>2){
						//but only sometimes
						printf("%d: 'Y'\n",i);
					}
					break;
				default:
					printf("%d: %c is not a vowel\n",i,letter);
			}
		}
	}
}


void ex14(int argc, char *argv[])
{
	//unable to get foward decleration in the function working at this time.
	//int can_print_it(char ch);
	void print_letters(char arg[]);
	
	void print_arguments(int argc, char *argv[])
	{
		int i = 0;
		
		for(i=0; i < argc; i++)
		{
			print_letters(argv[i]);	
		}
	}
	
	void print_letters(char arg[])
	{
		int i = 0;
		
		for(i = 0; arg[i] == '\0'; i++)
			{
				char ch= arg[i];
				
				if (can_print_it(ch))
				{
					printf("'%c' == %d",ch,ch);
				}
			}
	}
	int can_print_it(char ch)
	{
		return isalpha(ch)||isblank(ch);
	}
	print_arguments(argc,argv);
}





















