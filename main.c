#include "monty.h"

stack_t *head = NULL;
int isIN(char *key, char **commands);
void execute(char *opcode, int counter, char *data);
int main(int argc, char const *argv[])
{
	instruction_t fake = NULL;
	FILE *fp;
	char *linestr = NULL;
	char *opcode = NULL;
	char *strtok_address = NULL;
	char *data;
	size_t n;
	ssize_t charsprinted;
	int counter = 1;
	fp = fopen(argv[1], "r");
	if (argc != 2)
	{
		printf("USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	while ((charsprinted = getline(&linestr, &n, fp)) != -1)
	{
		strtok_address = linestr;
		linestr = strtok(linestr, "\n");
		opcode = strtok(linestr, " ");
		data = strtok(NULL, " ");
		if (opcode)
			execute(opcode, counter, data);
		counter++;
	}
	fclose(fp);
	free(strtok_address);
	return 0;
}

void execute(char *opcode, int counter, char *data)
{
    if (strcmp(opcode, "push") == 0)
    {
	    if (strdigit(data) != 1){
		    printf("L%u: usage: push integer\n", counter);
		    exit(EXIT_FAILURE);
	    }
        add_dnodeint(&head, atoi(data));
    }
    else if (strcmp(opcode, "pall") == 0)
    {
	    print_dlistint(head);
    }
    else if (strcmp(opcode, "pint") == 0)
    {
	    pint(head);
    }
    else if (strcmp(opcode, "pop") == 0)
    {
	    pop(&head);
    }
}

int isIN(char *key, char **commands)
{
	int len = sizeof(commands)/sizeof(commands[0]);
	int i;

	for(i = 0; i < len; ++i)
	{
		if(!strcmp(commands[i], key))
		{
			return (1);
		}
	}
	return (0);
}
