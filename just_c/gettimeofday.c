/* C routine: sample gettimeofday with time in milliseconds
   mmc mchirico@users.sourceforge.net

Downloads:
http://prdownloads.sourceforge.net/cpearls/date_calc.tar.gz?download

*/
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <sys/time.h>
#include <time.h>
#include <unistd.h>

uint32_t         stampstart();
uint32_t         stampstop(uint32_t start);


int main(void)
{

  uint32_t         start, stop;

  start = stampstart();

  /* Your code goes here */
  char buffer[30];
  struct timeval tv;
  struct timespec ts;
  struct timezone tz;

  time_t curtime;

  gettimeofday(&tv, &tz);
  curtime=tv.tv_sec;

  strftime(buffer,30,"%Y",gmtime(&curtime));
  printf("%s\n",buffer);

  strftime(buffer,30,"%m",gmtime(&curtime));
  printf("%s\n",buffer);

  strftime(buffer,30,"%d",gmtime(&curtime));
  printf("%s\n",buffer);

  strftime(buffer,30,"%H",gmtime(&curtime));
  printf("%s\n",buffer);

  strftime(buffer,30,"%T",gmtime(&curtime));
  printf("%s\n",buffer);

  strftime(buffer,30,"%Y-%m-%d  %T.",gmtime(&curtime));
  printf("%s%ld\n",buffer,tv.tv_usec);

  printf("%ld\n",tv.tv_sec);
  printf("%ld\n",tv.tv_usec);

  printf("%ld\n",ts.tv_sec);
  printf("%ld\n",ts.tv_nsec);

  printf("%ld\n",tz.tz_minuteswest);
  printf("%ld\n",tz.tz_dsttime);

  stop = stampstop(start);
  return 0;

}

  uint32_t
stampstart()
{
  struct timeval  tv;
  struct timezone tz;
  struct tm      *tm;
  uint32_t         start;

  gettimeofday(&tv, &tz);
  tm = localtime(&tv.tv_sec);

  printf("TIMESTAMP-START\t  %d:%02d:%02d:%d (~%d ms)\n", tm->tm_hour,
      tm->tm_min, tm->tm_sec, tv.tv_usec,
      tm->tm_hour * 3600 * 1000 + tm->tm_min * 60 * 1000 +
      tm->tm_sec * 1000 + tv.tv_usec / 1000);

  start = tm->tm_hour * 3600 * 1000 + tm->tm_min * 60 * 1000 +
    tm->tm_sec * 1000 + tv.tv_usec / 1000;

  return (start);

}

  uint32_t
stampstop(uint32_t start)
{

  struct timeval  tv;
  struct timezone tz;
  struct tm      *tm;
  uint32_t         stop;

  gettimeofday(&tv, &tz);
  tm = localtime(&tv.tv_sec);

  stop = tm->tm_hour * 3600 * 1000 + tm->tm_min * 60 * 1000 +
    tm->tm_sec * 1000 + tv.tv_usec / 1000;

  printf("TIMESTAMP-END\t  %d:%02d:%02d:%d (~%d ms) \n", tm->tm_hour,
      tm->tm_min, tm->tm_sec, tv.tv_usec,
      tm->tm_hour * 3600 * 1000 + tm->tm_min * 60 * 1000 +
      tm->tm_sec * 1000 + tv.tv_usec / 1000);

  printf("ELAPSED\t  %d ms\n", stop - start);

  return (stop);

}
