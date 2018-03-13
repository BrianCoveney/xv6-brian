#include "types.h"
#include "stat.h"
#include "user.h"
#include "syscall.h"


int
main()
{
	char *echoargv[] = { "echo test" };
  	
  	int pid = getpid();
	
	trace(1);

	fork();
	wait();
	sbrk(0);
	exec("echo", echoargv);
	
	if(getpid() == pid){
		printf(1, "Count of syscalls: %d\n", trace(0)); 
	}
  	exit();
}