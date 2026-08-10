///////////// bradsahw  logit()

#define BRADSHAW "babb"  // LUPTON
#define LIMITLOG 0

int logit(const char *logmsg);

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>


int logit(const char *logmsg)
{
    FILE *fPtr;
    char pbuf[256];      // seems adequate 256 here + 256 user
    char logbuf[512];

    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    sprintf(pbuf,"piRshared.org %d/%02d/%02d %02d:%02d:%02d :: ", tm.tm_year + 1900, tm.tm_mon+1, tm.tm_mday, tm.tm_hour, tm.tm_min, tm.tm_sec);// tm.tm_sec >;

    strcpy(logbuf,pbuf);
    strcat(logbuf,logmsg);
    strcat(logbuf,"\n");

    fPtr = fopen("log.txt","a");
    fputs(logbuf, fPtr);
    fflush(stdin);  //new 11/2/20
    fclose(fPtr);
}
/////////////////// bradshaw

