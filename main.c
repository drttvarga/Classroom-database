//#include "printer.h"
//#include "printer.c"

#include "database.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Command list
#define LIST_CLASSROOM    "-l"
#define ADD_CLASSROOM     "-a"
#define DELETE_CLASSROOM  "-d" // delete index
#define MOST_SEATS        "-mseats"
#define MOST_LIGHT        "-mlight"
#define MOST_AREA         "-marea"
#define AVERAGE_LIGHTNESS "-avglight"
#define ORIENTATION       "-o"
#define WRITE_TO_FILE     "-wtf"
#define READ_FROM_FILE    "-rff"

//Definitions
#define MAX_DATABASE_NAME_LEN 256

//Data structures

struct classroom_data {
    int index;
    char name [MAX_DATABASE_NAME_LEN];
    int seat;
    int window;
    float lightness; //0.0-10.0
    char orientation; // N, S, E, W
    float area; // m2
};

struct data_storage {
    struct classroom_data rooms[100];
    int length;
};

void print_usage()
{
	clear_screen();
	printf("Classroom database\n");
	printf("====================\n");
	printf("Commands:\n");
	printf(" -l        Lists all classrooms\n");
	printf(" -a        Adds new classroom\n");
	printf(" -d        Delete a classroom\n");
	printf(" -mseats   Prints out the classroom with the most seats\n");
	printf(" -mlight   Prints out the classroom with the most light\n");
	printf(" -marea    Prints out the classroom with the most area\n");
	printf(" -avglight Prints out the average lightness of classrooms\n");
	printf(" -o        Prints out the orientation of classrooms\n");
	printf(" -wtf      Write data to file\n");
	printf(" -rff      Read data from file\n");
}

void clear_screen()
{
	system("cls");
}

char *parser(char *command, char *token, int substring)
{
	// Get parameter
	char *p;
	for (int i = 0; i < substring; i++) {
		if (i == 0 && command != NULL)
			p = strtok(command, token);
		else
			p = strtok(NULL, token);
	}
	return p;
}


int main()
{
    struct data_storage storage = {NULL, 0};

	print_usage();

	char command[256];

	while (1) {
		// Get command string
		gets(command);
		// Search for command
		if (strstr(command, LIST_CLASSROOM) != NULL) {

		    int i;

            printf("Index\t", storage.rooms[i].index);
			printf("Name\t", storage.rooms[i].name);
			printf("Seats\t", storage.rooms[i].seat);
			printf("Window\t", storage.rooms[i].window);
			printf("Ligthness\t", storage.rooms[i].lightness);
			printf("Orientation\t", storage.rooms[i].orientation);
			printf("Area\t", storage.rooms[i].area);

            for(i = 0; i < 100; i++){
			printf("%d\t", storage.rooms[i].index);
			printf("%s\t", storage.rooms[i].name);
			printf("%d\t", storage.rooms[i].seat);
			printf("%d\t", storage.rooms[i].window);
			printf("%f\t", storage.rooms[i].lightness);
			printf("%c\t", storage.rooms[i].orientation);
			printf("%f\t", storage.rooms[i].area);

			printf("\n");
        }





		} else if (strstr(command, ADD_CLASSROOM) != NULL) {
			char name [MAX_DATABASE_NAME_LEN];

            printf("Add a new classroom\n");

		} /*else if (strstr(command, DELETE_CLASSROOM) != NULL) {
			char filename[256];
			// Copy the filename
			strcpy(filename, parser(command, "\"", 2));

			// Save to file
			write_todo(&storage, filename);

		} else if (strstr(command, COMMAND_READ_TODOS) != NULL) {
			char filename[256];

			// Copy the filename
			strcpy(filename, parser(command, "\"", 2));

			// Save to file
			read_todo(&storage, filename);

		} else if (strstr(command, COMMAND_EMPTY_TODOS) != NULL) {
			// Empty the storage
			empty_todo(&storage);
			print_empty();

		} else if (strstr(command, COMMAND_REMOVE_TODOS) != NULL) {
			char number[256];
			// Get the number
			char *p = parser(command, " ", 2);

			// Error handling
			if (p == NULL) {
				print_error(RM_NO_INDEX);
			} else {
				strcpy(number, p);

				// Convert string to number
				char *ptr;
				int num = strtol(number, &ptr, 10);

				// Error handling
				if (ptr == number)
					print_error(RM_NOT_NUMBER);
				else if (num > storage.length || num <= 0)
					print_error(RM_INV_INDEX);
				else
					// Remove todo
					remove_todo(&storage, num);
			}
		} else if (strstr(command, COMMAND_CHECK_TODOS) != NULL) {
			char number[256];
			// Get the number
			char *p = parser(command, " ", 2);

			// Error handling
			if (p == NULL) {
				print_error(CHECK_NO_INDEX);
			} else {
				strcpy(number, p);

				// Convert string to number
				char *ptr;
				int num = strtol(number, &ptr, 10);

				// Error handling
				if (ptr == number)
					print_error(CHECK_NOT_NUMBER);
				else if (num > storage.length || num <= 0)
					print_error(CHECK_INV_INDEX);
				else
					check_todo(&storage, num);
			}
		} else if (strstr(command, COMMAND_ADD_TODOS_PRIO) != NULL) {
			char todo_name[256];
			int error = 0;

			// Get todo name
			char *p = parser(command, "\"", 2);

			// Error handling, save todo name
			if (p == NULL) {
				print_error(PRIO_NO_TASK);
				error = 1;
			} else {
				strcpy(todo_name, p);
			}

			// Get prio number
			p = parser(NULL, "\"", 1);
			char *ptr;
			int prio = strtol(p, &ptr, 10);

			// Error handling
			if (ptr == p) {
				print_error(PRIO_NOT_NUMBER);
				error = 1;
			} else {
				error = 0;
			}

			if (!error)
				add_todo(&storage, todo_name, 0, prio);
		} else if (strstr(command, COMMAND_LIST_TODOS) != NULL) {
			list_todo(&storage);
		} else {
			print_error(INV_ARGUMENT);
		}
	}*/

	return 0;
}
}


