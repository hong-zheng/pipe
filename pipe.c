#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>
int main(){

        int fd[2];
	size_t pid;	
	int ret = pipe(fd);
	if(ret == -1){
		perror(" pipe error \n");
		exit(1);
	}
	pid = fork();
	if( -1 == pid){
		perror(" pipe error ");
	}else if( 0 == pid ){
		// child r
		close(fd[1]);
		char buf[1024];
		ret=read(fd[0],buf,sizeof(buf));
		if( 0 == ret){
			printf("end\n");
		}
		write(1,buf,ret);
	}else{
		close(fd[0]);
		write(fd[1] , " hehe \n",sizeof(" hehe \n"));
	}
	return 0;
}
