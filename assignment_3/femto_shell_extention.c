#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>
#include <stdlib.h>

#define ENTER 0x0A
#define MAX_LIST 100
#define SIZE 20

struct items {
    char name[100];
    char value[100];
};
static int local_var = 0;

struct items localItems[SIZE];

void print_local_vars(struct items items_t[20], char local_var)
{
    for (int i = 0; i < local_var; i++) {
	printf("local_var[%d] is %s = %s\n", i,
	       items_t[i].name, items_t[i].value);
    }
}

int main()
{
    int status;

    while (1) {
	char buff[100] = { 0 };
	size_t buffer_size = 100;
	printf("Ana Gahez ya basha>");
	fgets(buff, 100, stdin);
	if (buff[0] == ENTER) {
	    continue;
	}
	int ret_pid = fork();

	if (ret_pid < 0)
	    printf("fork failed\n");
	else if (ret_pid > 0) {
	    wait(&status);
	} else if (ret_pid == 0) {
	    char *argv[MAX_LIST];
	    int arg_num = 0;
	    int len = 0;
	    int i = 0;
	    int name_count = 0;
	    int value_count = 0;
	    int local_variable_flag = 0;

	    len = strlen(buff);
	    buff[len - 1] = 0;
	    if (strcmp(buff, "set") == 0) {
		print_local_vars(localItems,local_var);
		memset(buff, 0, 100);
	    }
	    if (strcmp(buff, "set") == 0) {
                print_local_vars(localItems,local_var);
                memset(buff, 0, 100);
            }

	    for (name_count = 0; name_count < len; name_count++) {
		if (buff[name_count] == 0) {
		    break;
		}
		if (buff[name_count] == '=') {
		    local_variable_flag = 1;
		    break;
		}

		localItems[local_var].name[name_count] = buff[name_count];

	    }
	    if (local_variable_flag == 1) {
		for (; name_count < len; name_count++) {
		    if (buff[name_count] == 0) {
			local_var++;
			break;
		    }

		    localItems[local_var].value[value_count] =
			buff[name_count];

		}

	    }

	    if (local_variable_flag == 1) {
		local_variable_flag = 0;
		continue;
	    }

	    argv[i] = strtok(buff, " ");
	    while (argv[i] != NULL) {
		i++;
		argv[i] = strtok(NULL, " ");
	    }
	    
	    if(strcmp(argv[0],"export")==0){
		    printf("export is found\n");
	     for(int loop_count =0;loop_count<local_var;loop_count++){
		     printf("loopcount is %d\n",loop_count);
	     if(strcmp(argv[1],localItems[loop_count].name)==0){
		printf("found_local\n");     
		     setenv(localItems[loop_count].name,localItems[loop_count].value,1);	     
	     }
	     }
	    }
	    

	    execvp(buff, argv);
	}
    }
}
