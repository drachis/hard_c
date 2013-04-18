#include <stdio.h>


void func1(int nu){
	nu++;
	printf("f1:%i\n",nu);
}

void func2(int *nu){
	*nu++;
	printf("%i\n",*nu);
}

int main(){
	int num = {5};
	printf("a:%i\n",num);
	func1(num);
	printf("b:%i\n",num);
	func2(num);
	printf("c:%i\n",num);
}
