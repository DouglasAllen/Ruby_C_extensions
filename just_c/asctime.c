//~ struct tm {
   //~ int tm_sec;         /* seconds,  range 0 to 59          */
   //~ int tm_min;         /* minutes, range 0 to 59           */
   //~ int tm_hour;        /* hours, range 0 to 23             */
   //~ int tm_mday;        /* day of the month, range 1 to 31  */
   //~ int tm_mon;         /* month, range 0 to 11             */
   //~ int tm_year;        /* The number of years since 1900   */
   //~ int tm_wday;        /* day of the week, range 0 to 6    */
   //~ int tm_yday;        /* day in the year, range 0 to 365  */
   //~ int tm_isdst;       /* daylight saving time             */
//~ };

#include <stdio.h>
#include <string.h>
#include <time.h>

int main()
{
	struct tm t;

   t.tm_sec    = 10;
   t.tm_min    = 10;
   t.tm_hour   = 6;
   t.tm_mday   = 25;
   t.tm_mon    = 2;
   t.tm_year   = 89;
   t.tm_wday;//   = 6;

   puts(asctime(&t));
   
   return(0);
}