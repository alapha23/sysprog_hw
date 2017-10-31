#include <stdio.h>

extern int ext_var;
int strong = 1;
int weak;

void foo(void){
	static int local = 16;
}

int main(){
	foo();
	printf("extern var =%d\n", ext_var);
	return 0;
}
