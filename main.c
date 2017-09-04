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

int main()
{
    struct data_storage storage;

    storage.rooms[5].orientation = 'N';

    printf("W: %c", storage.rooms[5].orientation);

    print_usage();

    char command[256];

    return 0;
}
