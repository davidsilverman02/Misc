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

#include "timersystem.h"

using namespace std;


double TimerSystem::getTime()
{
	QueryPerformanceCounter(&finishing);

	return static_cast<double>((finishing.QuadPart - starting.QuadPart) / static_cast<double>(frequency.QuadPart));
}

void TimerSystem::startClock()
{
	QueryPerformanceCounter(&starting);
}

TimerSystem::TimerSystem()
{
	starting.QuadPart = 0;
	finishing.QuadPart = 0;

	QueryPerformanceFrequency(&frequency);
}