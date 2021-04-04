#include <stddef.h>
#include <stdbool.h>
#include <stdio.h>
#include <dlfcn.h>

void (*print_message) (char *);

bool init_library()
{
	void *hdl = dlopen("./libhello_ariel.so",RTLD_LAZY);
	if(NULL == hdl){
		return false;
	}

	print_message = (void(*)(char *))dlsym(hdl,"print_message");
	if(NULL == print_message){
		return false;
	}
	return true;
}

int main(){
	if(init_library()){
		print_message("hello ariel");
	}
	else{
		printf("couldn`t load the library!!!\n");
	}
	return 0;

}



