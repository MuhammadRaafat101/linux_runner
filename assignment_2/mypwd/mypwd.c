#include <unistd.h>
#include <stdio.h>

int main()
{


char buff[100];

if(buff ==getcwd(buff,100)){
	
printf("%s\n",buff);
}
return 0;
}
