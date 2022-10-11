#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>


#define RET 1
int main(int argc,char** argv){

char buff[100];

printf("argc= %d\n",argc);

if(argc !=3){

return -1;
}

int fd1=open(argv[1],O_RDONLY);
int fd2=open(argv[2],O_WRONLY|O_CREAT,0644);

int count = read(fd1,buff,100);

write(fd2,buff,count);

close(fd1);
close(fd2);

return RET;

}

