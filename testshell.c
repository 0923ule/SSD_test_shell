#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 1024
#define MAX_ARGS 64
#define DELIM " \t\n"
#define HELP "./help.txt"
#define RUN "./ssd"
#define SSD "ssd"

int isDigitFormat(const char* str);
int isHexFormat(const char* str);

int main() {
	char input[MAX_LENGTH];
	char command[MAX_LENGTH];
	char* args[MAX_ARGS];
	char* token;
	int argc;

	while (1) {
		printf("ssd_test_shell >> ");
		fgets(input, MAX_LENGTH, stdin);
		if (input[0] == '\n') continue;

		// ------------tokenize------------ //
		argc = 0;
		char* token = strtok(input, DELIM);

		while (token != NULL && argc < MAX_ARGS) {
			args[argc++] = token;
			token = strtok(NULL, DELIM);
		}

		// ------------command------------ //
		if (strcmp(args[0], "exit") == 0 && argc == 1) {
			break;
		}
		else if (strcmp(args[0], "help") == 0 && argc == 1) {
			sprintf(command, "%s %s", "cat", HELP);
			system(command);
		}
		else if (strcmp(args[0], "write") == 0 && argc == 3 && isDigitFormat(args[1]) && isHexFormat(args[2])) {
			sprintf(command, "%s %s %s %s %s", RUN, SSD, "W", args[1], args[2]);
			system(command);
		}
		else if (strcmp(args[0], "read") == 0 && argc == 2 && isDigitFormat(args[1])) {
			sprintf(command, "%s %s %s %s", RUN, SSD, "R", args[1]);
			system(command);
			system("cat ./result.txt");
			printf("\n");
		}
		else if (strcmp(args[0], "fullwrite") == 0 && argc == 2 && isHexFormat(args[1])) {
			for (int i = 0; i < 100; i++) {
				sprintf(command, "%s %s %s %d %s", RUN, SSD, "W", i, args[1]);
				system(command);
			}
		}
		else if (strcmp(args[0], "fullread") == 0 && argc == 1) {
			for (int i = 0; i < 100; i++) {
				sprintf(command, "%s %s %s %d", RUN, SSD, "R", i);
				system(command);
				system("cat result.txt");
				printf("\n");
			}
		}
		else {
			printf("INVALID COMMAND\n");
		}
	}

	return 0;
}

int isDigitFormat(const char* str) {
	char* endptr;
	int index = strtol(str, &endptr, 10);

	if (*endptr != '\0') return 0;
	if (index < 0 || index >= 100) return 0;
	else return 1;
}

int isHexFormat(const char* str) {
	if (strlen(str) > 10 || strlen(str) < 3) {
		return 0;
	}

	if (str[0] != '0' || (str[1] != 'x' && str[1] != 'X')) {
		return 0;
	}

	for (int i = 2; i < strlen(str); i++) {
		if (!isxdigit(str[i])) {
			return 0; 
		}
	}

	return 1; 
}