/* Program Description: Vaccinates your flash drive against autorun, recycler, and shortcut virus
   Program Name: Flash Drive VACCINE
   Version: 1.0.0 alpha
   Developer: Raymel Francisco
   Date Written: Tuesday, August 19, 2014 10 am - 6 pm of Tuesday, August 19, 2014, GMT+8, PST
   Written in: C++
   IDE used: Orwell Dev-C++ 5.7.1
   Compiler used: MinGW GCC 4.8.1 32-bit Release
   
   Text Editors for batch and vbs file: Notepad v6.1, Notepad++ v6.6.8
   Icon information:
   		
*/

#include <iostream>
#include <windows.h>

int main () {
	SetConsoleTitle("Flash Drive VACCINE v1.0.0 alpha by Raymel Francisco");
	std::cout << "Flash Drive VACCINE v1.0.0 alpha\n\n";
	system("sampl.bat");
	system("sampl.vbs");
	return 0;
} // end main ()
