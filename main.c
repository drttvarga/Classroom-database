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
char SPACE[] = " ";
int pos = 0;



//Data structures

typedef struct  {
    char name [MAX_DATABASE_NAME_LEN];
    int seat;
    int window;
    float lightness; //0.0-10.0
    char orientation; // N, S, E, W
    float area; // m2
}classroom_data_t;

//Function declarations
void add_classroom(char command[], char *space, classroom_data_t *rooms);
void delete_classroom(int index, classroom_data_t *rooms);
void write_file(classroom_data_t *rooms, char *path);
void read_file(classroom_data_t *rooms, char *path);
int countlines(char *filename);
void most_seats(classroom_data_t *rooms);
void most_light(classroom_data_t *rooms);
void most_area(classroom_data_t *rooms);
void average_lightness(classroom_data_t *rooms);
int get_orientation(char *orientation, classroom_data_t *rooms);


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


int main()
{

	print_usage();

	char command[256];

    classroom_data_t rooms[100];

	while (1) {
		// Get command string
		gets(command);

		// Search for command
		if (strstr(command, LIST_CLASSROOM) != NULL) {

            printf("Index\t");
            printf("Name\t");
            printf("Seats\t");
            printf("Window\t");
            printf("Ligthness\t");
            printf("Orientation\t");
            printf("Area\t");
            printf("\n");
            printf("-------------------------------------------------------------------------\n");

            for(int i = 0; i < pos; i++){

                printf("%d\t", i);
                printf("%s\t", rooms[i].name);
                printf("%d\t", rooms[i].seat);
                printf("%d\t", rooms[i].window);
                printf("%f\t", rooms[i].lightness);
                printf("%c\t\t", rooms[i].orientation);
                printf("%f\t", rooms[i].area);

                printf("\n");
            }

		}else if (strstr(command, AVERAGE_LIGHTNESS) != NULL) {

		    average_lightness(rooms);


		} else if (strstr(command, DELETE_CLASSROOM) != NULL) {

		    strtok(command, SPACE);//command
            char *del = strtok(NULL, SPACE);
            int index = atoi(del);

            delete_classroom(index, rooms);

		} else if (strstr(command, MOST_SEATS) != NULL) {

                most_seats(rooms);

		} else if (strstr(command, MOST_LIGHT) != NULL) {

            most_light(rooms);


		} else if (strstr(command, MOST_AREA) != NULL) {

		    most_area(rooms);

		}  else if (strstr(command, ADD_CLASSROOM) != NULL) {


                 add_classroom(command, SPACE, rooms);


		}else if (strstr(command, ORIENTATION ) != NULL) {

		    strtok(command, SPACE);//command
            char *orientation = strtok(NULL, SPACE);

            get_orientation(orientation, rooms);

		} else if (strstr(command, WRITE_TO_FILE) != NULL) {

            strtok(command, SPACE);//command
            char *path = strtok(NULL, SPACE);

            write_file(rooms, path);

		} else if (strstr(command, READ_FROM_FILE) != NULL) {

		    strtok(command, SPACE);//command
            char *path = strtok(NULL, SPACE);

            read_file(rooms,path);

		}else {
			printf("Wrong command!");
		}
	}

	return 0;

}

//Functions

void add_classroom(char command[], char space[], classroom_data_t *rooms)
{
    char *arg1 = strtok(command, space);//command
    char *arg2 = strtok(NULL, space);
    char *arg3 = strtok(NULL, space);
    char *arg4 = strtok(NULL, space);
    char *arg5 = strtok(NULL, space);
    char *arg6 = strtok(NULL, space);
    char *arg7 = strtok(NULL, space);

    memcpy(&rooms[pos].name, arg2, strlen(arg2)+1);
    rooms[pos].seat = atoi(arg3);
    rooms[pos].window = atoi(arg4);
    rooms[pos].lightness = atof(arg5);
    memcpy(&rooms[pos].orientation, arg6, strlen(arg6)+1);
    rooms[pos].area = atof(arg7);

    pos++;
// -a TOTORO 12 12 3.4 N 2.3
};

void delete_classroom(int index, classroom_data_t *rooms)
{
    pos--;

    for (int i = index-1; i < pos; i++){

        strcpy(rooms[i].name, rooms[i+1].name);
        rooms[i].seat = rooms[i+1].seat;
        rooms[i].window = rooms[i+1].window;
        rooms[i].lightness = rooms[i+1].lightness;
        rooms[i].orientation = rooms[i+1].orientation;
        rooms[i].area = rooms[i+1].area;
    }

}

void most_seats(classroom_data_t *rooms)
{
     int act_pos;
     int max = 0;
     for(int i = 0; i < pos; i++){
        if(rooms[i].seat > max){
            max = rooms[i].seat;
            act_pos = i;
        }
     }
     printf("%s has the most seats (%d)", rooms[act_pos].name, max);

}
void most_light(classroom_data_t *rooms)
{
    int act_pos;
    float max = 0;
     for(int i = 0; i < pos; i++){
        if(rooms[i].lightness > max){
            max = rooms[i].lightness;
            act_pos = i;
        }
     }
     printf("%s has the most light (%f)", rooms[act_pos].name, max);

}
void most_area(classroom_data_t *rooms)
{
    int act_pos;
    float max = 0;
     for(int i = 0; i < pos; i++){
        if(rooms[i].area > max){
            max = rooms[i].area;
            act_pos = i;
        }
     }
     printf("%s has the most area (%f)", rooms[act_pos].name, max);

}
void average_lightness(classroom_data_t *rooms)
{
    float sum = 0;
    float avg;
    for(int i = 0; i < pos; i++){
        sum += rooms[i].lightness;
    }
    avg = sum / pos;
    printf("The average lightness is %.2f", avg);

}
int get_orientation(char *orientation, classroom_data_t *rooms)
{
    for(int i = 0; i < pos; i++){
          if(strchr(orientation, rooms[i].orientation) != NULL){
            printf("%d\t", i);
            printf("%s\t", rooms[i].name);
            printf("%d\t", rooms[i].seat);
            printf("%d\t", rooms[i].window);
            printf("%f\t", rooms[i].lightness);
            printf("%c\t\t", rooms[i].orientation);
            printf("%f\t\n", rooms[i].area);
          }
    }

}

void write_file(classroom_data_t *rooms, char *path)
{
    // Error handling
	if (path == NULL)
		printf("Invalid path");

	// open file
	FILE *file = fopen(path, "w");
	if (file == NULL)
		printf("Unsuccessful file open");

	// Write data to file
	for (int i = 0; i < pos; i++) {
		fprintf(file, "%s %d %d %f %c %f\n",
        rooms[i].name,
        rooms[i].seat,
        rooms[i].window,
        rooms[i].lightness,
        rooms[i].orientation,
        rooms[i].area);
	}

	fclose(file);

}
void read_file(classroom_data_t *rooms, char *path)
{
    int lines = countlines(path);

    printf("%d", lines);

    // Error handling
	if (path == NULL)
        printf("Invalid path");


	// open file
	FILE *file = fopen(path, "r");
	if (file == NULL)
        printf("Unsuccessful file open");

    char *name;
    int seat;
    int window;
    float lightness;
    char orientation;
    float area;

	for (int i = 0; i < lines; i++) {
		fscanf(file, "%s %d %d %f %c %f\n",
         name,
         &seat,
         &window,
         &lightness,
         &orientation,
         &area);


        memcpy(&rooms[i].name, name, strlen(name)+1);
        rooms[i].seat = seat;
        rooms[i].window = window;
        rooms[i].lightness = lightness;
        memcpy(&rooms[i].orientation, orientation, strlen(orientation)+1);
        rooms[i].area = area;
	}

	pos = lines;

	fclose(file);

}
int countlines(char *filename)
{
  // count the number of lines in the file called filename
  FILE *fp = fopen(filename,"r");
  int ch=0;
  int lines=0;

  if (fp == NULL);
  return 0;

  lines++;
  while ((ch = fgetc(fp)) != EOF)
    {
      if (ch == '\n')
    lines++;
    }
  fclose(fp);
  return lines;
}


