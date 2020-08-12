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
/* Output:
current process id before fork: 12160
parent process id before fork: 12159
hello from parent
current process id: 12160
parent process id: 12159
current process id before fork: 12160
parent process id before fork: 12159
hello from child
current process id: 12210
parent process id: 1
*/
