/************************************************************************
 *
 * Purpose: To play with the time.h functions.
 *
 * Author:  M.J. Leslie
 *
 * Date:    18-Mar-95
 *
 ************************************************************************/

#include <stdio.h>		        /* NULL		       */
#include <time.h>		        /* ctime, asctime      */

int main()
{
	
	/* define 'now'. time_t is probably a typedef	 */
  time_t now;				

	/* Calender time is the number of seconds since 1/1/1970   	*/

	/* Get the system time and put it into 'now' as 'calender time' */
  now = time((time_t *)NULL);		

	/* Format data in 'now' NOTE that 'ctime' inserts a '\n' */
  printf("%s", ctime(&now));	

   /*********************************************************************/

	/* Here is another way to extract the time/date information	*/

  time(&now);

	/* Format data in 'now'		*/
  printf("%s", ctime(&now));	

   /*********************************************************************/

  {
    struct tm *l_time;
		/* Convert 'calender time' to 'local time' 
		    - return a pointer to the 'tm' structure. localtime
				reserves the storage for us.	*/			 
    l_time = localtime(&now);		
    printf("%s", asctime(l_time));
  }

   /*********************************************************************/

  time(&now);
  printf("%s", asctime(localtime( &now  )));

   /*********************************************************************/

  {
    struct tm *l_time;
    char string[20];
					 
    time(&now);
    l_time = localtime(&now);
    strftime(string, sizeof string, "%d-%b-%y\n", l_time);
    printf("%s", string);
  }
}

