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

/*char *parser(char *command, char *token, int substring)
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
}*/


int main()
{
    struct data_storage storage = {NULL, 0};

	print_usage();

	char command[256];



	while (1) {
		// Get command string
		gets(command);

        printf("Index\t");
        printf("Name\t");
        printf("Seats\t");
        printf("Window\t");
        printf("Ligthness\t");
        printf("Orientation\t");
        printf("Area\t");
        printf("\n");

		// Search for command
		if (strstr(command, LIST_CLASSROOM) != NULL) {

            for(int i = 0; i < 100; i++){

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

             //add_classroom();

			 for(int i = 0; i < 100; i++){

                scanf("%d\t%s\t%d\t%d\t%f\t%c\t%f\t", storage.rooms[i].index, storage.rooms[i].name, storage.rooms[i].seat, storage.rooms[i].window, storage.rooms[i].lightness, storage.rooms[i].orientation, storage.rooms[i].area);

			 }

            printf("Add a new classroom\n");

		} /*else if (strstr(command, DELETE_CLASSROOM) != NULL) {


		} else if (strstr(command, MOST_SEATS) != NULL) {


		} else if (strstr(command, MOST_LIGHT) != NULL) {


		} else if (strstr(command, MOST_AREA) != NULL) {

		} else if (strstr(command, AVERAGE_LIGHTNESS) != NULL) {

		} else if (strstr(command, ORIENTATION ) != NULL) {

		} else if (strstr(command, WRITE_TO_FILE) != NULL) {

		} else if (strstr(command, READ_FROM_FILE) != NULL) {

		}else {
			printf("Wrong command!);
		}
	}*/

	return 0;
}
}

//Function declarations

int add_classroom();
int delete_classroom();
int most_seats();
int most_light();
int most_area();
int average_lightness();
int get_orientation();
int write_file();
int read_file();


