#include <stdio.h>


int main(int argc ,char **argv){

printf("argc is %d\n",argc);

if(argc <2){

   return -1;
}
for(int i =1;i<argc;i++)
      printf("%s ",argv[i]);

printf("\n");

return 0;

}
