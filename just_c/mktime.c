#include <stdio.h>
#include <string.h>
#include <time.h> 

int main ()
{
   int ret;
   struct tm info;
   char buffer[80];

   info.tm_year = 2001 - 1900;
   info.tm_mon = 7 - 1;
   info.tm_mday = 4;
   info.tm_hour = 0;
   info.tm_min = 0;
   info.tm_sec = 1;
   info.tm_isdst = -1;

   ret = mktime(&info);
   if( ret == -1 )
   {
      printf("Error: unable to make time using mktime\n");
   }
   else
   {
      strftime(buffer, sizeof(buffer), "%c", &info );
      printf(buffer);
   }

   return(0);
}