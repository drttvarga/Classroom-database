#ifndef DATABASE_H_INCLUDED
#define DATABASE_H_INCLUDED

//Definitions
#define MAX_DATABASE_NAME_LEN 256

//Data structures

struct classroom_data {
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

//Function declarations

int add_classroom();
int delete_classroom();
int most_seats();
int most_light();
int most_area();
int average_lightness();
int write_file();
int read_file();

#endif // DATABASE_H_INCLUDED
