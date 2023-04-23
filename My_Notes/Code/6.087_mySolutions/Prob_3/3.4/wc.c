#include <stdio.h>
#include <stdlib.h>
int main(int argc,char* argv[])
{
    FILE* fp=NULL;
    int   nfiles =--argc; /*ignore the name of the program itself*/
    int   argidx =1;      /*ignore the name of the program itself*/
    char* currfile="";
    char  c;
    /*count of words,lines,characters*/
    unsigned long nw=0,nl=0,nc=0;

    if(nfiles==0)
    {
        fp=stdin; /*standard input*/
        nfiles++;
    }
    else /*set to first*/
    {
        currfile=argv[argidx++];
        fp=fopen(currfile,"r");
    }
    while(nfiles>0) /*files left >0*/
    {
       if(fp==NULL)
        {
            fprintf(stderr,"Unable to open input\n");
            exit(-1);
        }
        nc=nw=nl=0;
        while((c=getc(fp))!=EOF)
        {
	        /*TODO:FILL HERE
		    process the file using getc(fp)
			*/
        }
        printf("%ld %s\n",nc,currfile);
        /*next file if exists*/
        nfiles--;
        if(nfiles>0)
        {
            currfile=argv[argidx++];
            fp     =fopen(currfile,"r");
        }
    }
	return 0;
}


#include <stdio.h>

int main() {
    FILE* fp;
    fp = fopen("filename.txt", "r"); // open the file for reading

    char state_code_origin[3], county_code_origin[4], state_code_dest[3], county_code_dest[4];
    char state_abbrv[3], state_name[50];
    int return_num, exmpt_num, aggr_agi;

    // read the first line and ignore it since it contains only column names
    fscanf(fp, "%*[^\n]\n");

    // read data line by line until the end of file
    while (fscanf(fp, "\"%2s\"\t\"%3s\"\t\"%2s\"\t\"%3s\"\t\"%2s\"\t\"%49[^\"]\"\t%d\t%d\t%d\n", state_code_origin, county_code_origin, state_code_dest, county_code_dest, state_abbrv, state_name, &return_num, &exmpt_num, &aggr_agi) != EOF) {
        // process the data here, e.g. print it to the console
        printf("%s %s %s %s %s %s %d %d %d\n", state_code_origin, county_code_origin, state_code_dest, county_code_dest, state_abbrv, state_name, return_num, exmpt_num, aggr_agi);
    }

    // close the file
    fclose(fp);

    return 0;
}
