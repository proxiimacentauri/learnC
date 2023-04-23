/////////////////////////////////////////////////////
//
// 'wc' is a unix utility that display the count of characters, words and lines present in a file.
//     - If no file is specified it reads from the standard input.
//     - If more than one file name is specified it displays the counts for each file along with the filename.
//
// In this problem, we will be implementing wc.
//     - One of the ways to build a complex program is to develop it iteratively
//     - Solving one problem at a time and testing it throroughly.
//
// For this problem, start with the following shell and then iteratively add the missing components.
//
/////////////////////////////////////////////////////

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
            int cNext = getc(fp);
            if (!((c == '\n') && (c == ' ') && (c == '\t') ))
                nc++;

            if ((cNext == ' ') && ( !( (c == ' ') && (c == '\t') && (c == '\n') )))
                nw++;

            if (c == '\n')
                nl++;
        }
        printf("\n File ==> %s"
                "\n nc = %lu"
                "\n nw = %lu"
                "\n nl = %lu \n", currfile, nc, nw, nl);
        //printf("\n%ld %s\n\n",nc,currfile);
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
// nc = 1057 nw = 98 nl = 46