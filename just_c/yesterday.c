/************************************************************************
 * 
 * Purpose: By default, display yesterdays date. 
 *	    If a number is given on the command line, it is subtracted
 *	    from todays date and the result printed.
 *
 * Author:  M.J. Leslie.
 *
 * Date:    10-Jan-95 
 *
 ************************************************************************/

#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define  DAYS 1
/* Validate the command line 
 * parmeters 			*/
int check_parm(int argc, char *argv[]);	

/************************************************************************/

int main(int argc, char *argv[])
{

	time_t seconds;
	const int one_day = 86400;		/* Number of seconds in a day	*/
	int days=DAYS;			/* Number of days to subtract.	*/


	/* Checkout the cmd line parms  */
	if (check_parm( argc, argv))	
	{
		/* Data is OK. 
		 * Override the default.	*/
		days = atoi(argv[1]);	
	}
	/* Get current calendar time.
	 * This is the number of seconds
	 * since 1-jan-1970		*/
	time(&seconds);

	/* Subtract the required number
	 * of days.			*/
	seconds -= one_day*days;

	/* Return the required date.	*/
	printf("%s", ctime(&seconds));

	/* All done - time to go home.	*/
	exit(1);
}

/************************************************************************
 *
 *	Validate the data enter on the command line.
 *
 ************************************************************************/
int check_parm(int argc, char *argv[])
{
	if (argc > 1 )                       /* Q. Have we got parms?        */      
	{
		if ( !strcmp("-h", argv[1]))	/* Q. Help requested?		*/
		{
			/* Y.				*/
			printf("%s will return the date of a passed day.", argv[0]);	
			puts("\nFor example:");
			printf("\t%s    \tReturns yesterdays date.\n", argv[0]);
			printf("\t%s 1  \tReturns yesterdays date.\n", argv[0]);
			printf("\t%s 365\tReturns the date one year ago.\n\n", argv[0]);
			exit(0);
		}
		/* Do a simple check to validate
		 * the I/P data - not 100% reliable
		 */
		if (!isdigit(*argv[1]))
		{
			/* Data naff.
			 * End the program.             */
			printf("%s: Numeric value required.\n", argv[0]);
			printf("\n\tTry: %s -h for some info.\n\n", argv[0]);
			exit(0);
		}
		return(1);
	}
	return(0);
}

