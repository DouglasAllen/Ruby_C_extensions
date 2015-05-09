#include <time.h>
#include <stdio.h>

  int
main (void)
{
  /* The argument passed to the ctime( ) function is a pointer to
     a number interpreted as a number of seconds elapsed since
     the epoch (on Unix systems, January 1, 1970).
     */
  char *ctime( const time_t *seconds );

  time_t time_raw_format;

  time ( &time_raw_format );
  printf ( "The current local time: %s", ctime(&time_raw_format));

  time_t curtime;

  time(&curtime);
  printf("Current time = %s", ctime(&curtime));

  return(0);
}
