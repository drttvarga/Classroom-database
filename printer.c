#include "printer.h"
#include "database.h"
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

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
