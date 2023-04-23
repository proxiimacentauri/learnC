/////////////////////////////////////////////////////
//
// In this problem, we will be reading in formatted data and generating a report.
//     - One of the common formats for interchange of formatted data is 'tab delimited'
//     - Where each line corresponds to a single record
//     - The individual fields of the record are separated by tabs
//
//     For this problem, download the file stateoutflow0708.txt from Stellar.
//     - This contains the emigration of people from individual states
//     - The first row of the file contains the column headings.
//     - There are eight self explanatory fields.
//     - Your task is to read the file using fscanf
//     - Generate a report outlining the migration of people from Massachusetts to all the other states.
//
//     Use the field ”Aggr AGI” to report the numbers.
//     Also, at the end, display a total and verify it is consistent with the one shown below.
//
// An example report should look like the following:
//
//     STATE           TOTAL
//     -----------------------
//     "FLORIDA"       590800
//     "NEW_HAMPSHIRE" 421986
//     ..........
//     -----------------------
//     Total           4609483
//
//     Make sure that the fields are aligned.
//
/////////////////////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[])
{
    FILE *fp=NULL;
    int nfiles =--argc; // ignore the name of the program
    int argidx = 1;      // ignore the name of the program
    char *currfile = ""; // get the name of the file we are processing
    char c;

    if (nfiles == 0)
    {
        fprintf(stderr, "No file was given.");
        exit(-1);
    }
    else
    {
        currfile = argv[argidx++]; // argidx = 1 assign and then increment
        fp = fopen(currfile, "r");
    }

    while (nfiles > 0)
    {
        if (fp == NULL)
        {
            fprintf(stderr, "\nUnable to open the given file.\n");
            exit(-1);
        }

        int State_Origin, County_Origin, State_Dest, County_Dest, Return_Num, Exmpt_Num, Aggr_AGI;
        char State_Abbrv[10], State_Name[60];
        long int sum_pop = 0;

        while( (c = getc(fp)) != EOF )
        {
            //Perform File Processing

            // read the first line and ignore it since it contains only column names
            fscanf(fp, "%*[^\n]\n");

            fscanf(fp, "\"%2d\"\t\"%3d\"\t\"%2d\"\t\"%3d\"\t\"%2s\"\t\"%50[^\"]\"\t%4d\t%4d\t%7d\n", &State_Origin, &County_Origin, &State_Dest, &County_Dest, State_Abbrv, State_Name, &Return_Num, &Exmpt_Num, &Aggr_AGI);

            if (strcmp(State_Name,"MASSACHUSETTS") == 0)
            {

                sum_pop += Aggr_AGI;

                // printf("\nRead State_Origin  |%2d|\n"
                //     "Read County_Origin |%3d|\n"
                //     "Read State_Dest    |%2d|\n"
                //     "Read County_Dest   |%3d|\n"
                //     "Read State_Abbrv   |%2s|\n"
                //     "Read State_Name    |%s|\n"
                //     "Read Return_Num    |%4d|\n"
                //     "Read Exmpt_Num     |%4d|\n"
                //     "Read Aggr_AGI      |%7d|\n\n\n"
                //     , State_Origin, County_Origin, State_Dest, County_Dest, State_Abbrv, State_Name, Return_Num, Exmpt_Num, Aggr_AGI);
            }

        }
        nfiles--;
        printf("\n\nSTATE           TOTAL\n"
               "-----------------------\n"
               "\"MASSACHUSETTS\" %li\n"
               "..........\n"
               "-----------------------\n"
               "Total           %li\n\n", sum_pop, sum_pop);
    }

    return 0;
}