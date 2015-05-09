#include <time.h>
#include <stdio.h>
#include <string.h>


/* Converts a timer value into a year, month, day, hour, minute, second, etc.
#include <time.h>
struct tm *gmtime( const time_t *timer );
The gmtime( ) function converts a numeric time value (usually a number of seconds
since January 1, 1970, but not necessarily) into the equivalent date and time structure
in Coordinated Universal Time (UTC, formerly called Greenwich Mean Time; hence
the function's name). To obtain similar values for the local time, use the function
localtime( ).
The function's argument is not the number of seconds itself, but a pointer to that
value. Both the structure type struct tm and the arithmetic type time_t are defined in
the header file time.h.
The tm structure is defined as follows:
*/


//~ struct tm {
  //~ int tm_sec;     /* Seconds since the full minute: 0 to 60 */
	//~ int tm_min;    /* Minutes since the full hour: 0 to 59 */
	//~ int tm_hour;  /* Hours since midnight: 0 to 23 */
  //~ int tm_mday; /* Day of the month: 1 to 31 */
  //~ int tm_mon;   /* Months since January: 0 to 11 */
  //~ int tm_year;  /* Years since 1900 */
  //~ int tm_wday; /* Days since Sunday: 0 to 6 */
  //~ int tm_yday;  /* Days since Jan. 1: 0 to 365 */
  //~ int tm_isdst;  /* Flag for Daylight Savings Time:
                            //~ greater than 0 if time is DST;
                            //~ equal to 0 if time is not DST;
                            //~ less than 0 if unknown.
                        //~ */
//~ }; 





/*The argument most often passed to gmtime( ) is the current time, obtained as a number
with type time_t by calling the function time( ). The type time_t is defined in time.h,
usually as equivalent to long or unsigned long.
Example
The following program prints a string showing the offset of the local time zone from
UTC:
*/

int
main (void)
{
	time_t rawtime;
  struct tm utc_tm, local_tm, *ptr_tm;
  char buffer[1024] = "";

	time( &rawtime ); // Get current time as an integer.
  ptr_tm = gmtime( &rawtime ); // Convert to UTC in a struct tm.
  memcpy( &utc_tm, ptr_tm, sizeof(struct tm) ); // Save a local copy.
  ptr_tm = localtime( &rawtime ); // Do the same for local time zone.
  memcpy( &local_tm, ptr_tm, sizeof(struct tm) );
  if ( strftime( buffer, sizeof(buffer),
    "It's %A, %B %d, %Y, %R o'clock, UTC.", &utc_tm ) )
    puts( buffer );
  if ( strftime( buffer, sizeof(buffer),
    "Here it's %A, %B %d, %Y, %R o'clock, UTC %z.", &local_tm ) )
    puts( buffer );
}