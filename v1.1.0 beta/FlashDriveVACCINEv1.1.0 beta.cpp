/* Program Description: Vaccinates your flash drive against autorun, recycler, and shortcut virus
   Program Name: Flash Drive VACCINE
   Version: 1.1.0 beta
   Developer: Raymel Francisco
   Date Written: Friday, August 29, 2014 8 pm, GMT+8, PST
   Written in: C++
   IDE used: Orwell Dev-C++ 5.7.1
   Compiler used: MinGW GCC 4.8.1 32-bit Release
   
   Text Editors for batch and vbs file: Notepad v6.1, Notepad++ v6.6.8
   Icon information:
   		
*/
#define WIN32_LEAN_AND_MEAN

#include <iostream> // cout <<
#include <windows.h> // WinMain ()
#include <stdio.h> // sprintf ()
#include <stdlib.h> // system ()
#include <time.h>

int WINAPI WinMain (HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd) {
	
	SetConsoleTitle("Flash Drive VACCINE v1.1.0 beta by Raymel Francisco");
	std::cout << "Flash Drive VACCINE v1.1.0 beta\n\n";
	system("sampl.bat");
	
	struct tm *ctime;
	time_t nsecs;
	char buf[80];
	
	time(&nsecs);
	ctime = localtime(&nsecs);
	
	strftime(buf, sizeof buf, "%A, %B %d, %Y", ctime);
	
	char str[500];
	sprintf(str,"Process done at %s \n\nAbout\n--------------------------------------\nFlash Drive VACCINE v1.1.0 beta\nby Raymel Francisco\n\nCopyright (c) 2014. All rights reserved.", buf);
			
	MessageBox(NULL, str, "Flash Drive VACCINE v1.1.0 beta by Raymel Francisco", MB_OK | MB_ICONINFORMATION);

	return 0;
	
} // end WINAPI WinMain () */
