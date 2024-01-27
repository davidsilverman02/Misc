/*
	Author:       David Silverman
	Class:		  CSI-281-01
	Assignment: Final Project
	Date Assigned: 11/30/21
	Due Date: 11/10/21 1:00 PM

		Description:
			Encrypt a text into numbers

		Certification of Authenticity:
			I certify that this is entirely my own work, except where I have given fully-
			documented references to the work of others. I understand the definition and
			consequences of plagiarism and acknowledge that the assessor of this assignment
			may, for the purpose of assessing this assignment:
				-Reproduce  this  assignment  and  provide  a  copy  to  another  member  of
				 academic staff; and/or
				-Communicate a copy of this assignment to a plagiarism checking service
				(which may then retain a copy of this assignment on its database for
				the purpose of future plagiarism checking)
*/

#include <ctime>
#include <windows.h>

using namespace std;
/* Pre:  Nothing
*  Post:  Works with time
*  Purpose:  Runs time
*********************************************************/
class TimerSystem
{
private:
	// for high speed timers and frequency timer
	LARGE_INTEGER starting, finishing, frequency;

public:
	/* Pre:  A created timer system
	*  Post:  The time currently on the clock
	*  Purpose:  Return the time as it is
	*********************************************************/
	double getTime();

	/* Pre:  A created timer system
	*  Post:  The timer is started
	*  Purpose:  Start the timer
	*********************************************************/
	void startClock();

	/* Pre:  Nothing
	*  Post:  Creates the timer system
	*  Purpose:  Sets up the variables
	*********************************************************/
	TimerSystem();
};
