#include <stdio.h> 
#include <sys/types.h> 
#include <unistd.h> 
int main() 
{ 

	// make two process which run same 
	// program after this instruction 
	printf("current process id before fork: %d\n",getpid());
	printf("parent process id before fork: %d\n",getppid());
    if(fork()==0){
        printf("hello from child\n");
        printf("current process id: %d\n",getpid());
        printf("parent process id: %d\n",getppid());
    }
    else{
        printf("hello from parent\n");
        printf("current process id: %d\n",getpid());
        printf("parent process id: %d\n",getppid());
    }
	return 0; 
} 
