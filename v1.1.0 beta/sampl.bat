@echo off
REM Batch file of Autorun, recycler, and shortcut virus VACCINE.
REM This batch file creates a fake autorun folder, recycler, and shortcuts at flash drive's ROOT.
REM Mechanism:
REM 	When the virus associated with these filenames mentioned detects a similar file,
REM		it tends to delete and replace the file, or use it for propagation of the virus.
REM		Using these command-line codes assembled in this batch file to automate the process,
REM		the virus may detect any similar filename

REM		but won't be able to replace,
REM		delete, or modify the folders itself.

REM Written by: Raymel Francisco
REM Date: August 19, 2014
REM Filename: sampl.bat
REM Text editor used: Notepad v6.1, Notepad++ v6.6.8


set /p drive=Enter the drive letter: 

echo You chose drive %drive%:.
echo.
set /p ans=Format %drive%: ? [y/n]: 
echo. 
IF %ans%==y (	echo CMD MODE ON ----------------------------------------------------
				format %drive%: /q /fs:ntfs /v:IMMUNIZED
				echo CMD MODE OFF ---------------------------------------------------
				echo.
				echo %drive%: is formatted at %DATE%, %TIME%.
			)

IF %ans%==n (	echo ------------------------------------------------------- 
				echo %drive%: is not formatted. Because you chose not to.
				echo.
			)
echo.
set /p ans=Start vaccination? [y/n]: 
echo.
IF %ans%==y (	echo CMD MODE ON ----------------------------------------------------

					echo Creating FAKE %drive%:\autorun.inf ...
					md %drive%:\autorun.inf
					
					echo Creating %drive%:\autorun.inf\con ...
					md %drive%:\autorun.inf\.\con\
					
					echo Setting %drive%:\autorun.inf attributes ...
					attrib +r +h +a %drive%:\autorun.inf
		
				echo CMD MODE OFF ---------------------------------------------------

					echo.
					echo FAKE autorun.inf created at %drive%:.
					echo %drive%:\autorun.inf\con created.
					echo FAKE autorun.inf attributes set to hidden, read-only, archive.
					echo.

				echo CMD MODE ON ----------------------------------------------------
		
					echo Setting %drive%:\autorun.inf special permissions ...
					
					echo y| cacls %drive%:\autorun.inf /c /P Everyone:R

				echo CMD MODE OFF ---------------------------------------------------

					echo.
					echo FAKE autorun.inf sepcial permissions changed.
					echo.

				echo CMD MODE ON ----------------------------------------------------

					echo Creating FAKE %drive%:\RECYCLER ...
					
					md %drive%:\RECYCLER\
					
					echo Creating %drive:\RECYCLER\con ...
					
					md %drive%:\RECYCLER\recycler.exe
					md %drive%:\RECYCLER\.\con\
					attrib +r +h +a %drive%:\RECYCLER

				echo CMD MODE OFF ---------------------------------------------------

					echo.
					echo FAKE RECYCLER created at %drive%:.
					echo FAKE recycler.exe created at %drive%:\RECYCLER
					echo %drive%:\RECYCLER\con created.
					echo FAKE RECYCLER attributes set to hidden, read-only, archive.
					echo.
		

				echo CMD MODE ON ----------------------------------------------------
		
					echo Setting %drive%:\RECYCLER special permissions ...
					
					echo y| CACLS %drive%:\RECYCLER /c /P Everyone:R

				echo CMD MODE OFF ---------------------------------------------------

					echo.
					echo FAKE RECYCLER sepcial permissions changed.
					echo.
		
				echo CMD MODE ON ----------------------------------------------------
			
					echo Creating FAKE shortcuts ...
					
					md %drive%:\ROOT2.lnk
					md %drive%:\RECYCLER.lnk
					md %drive%:\autorun.inf.lnk
					
					echo Setting FAKE shortcuts attributes ...
					
					attrib +r +h +a %drive%:\ROOT2.lnk
					attrib +r +h +a %drive%:\RECYCLER.lnk
					attrib +r +h +a %drive%:\autorun.inf.lnk
					
					echo Setting FAKE shortcuts special permissions ...
					
					echo y| CACLS %drive%:\ROOT2.lnk /c /P Everyone:R
					
					echo y| CACLS %drive%:\RECYCLER.lnk /c /P Everyone:R
					
					echo y| CACLS %drive%:\autorun.inf.lnk /c /P Everyone:R
					
			
				echo CMD MODE OFF ---------------------------------------------------
		
					echo.
					echo Created FAKE shortcuts at %drive%.
					echo FAKE shortcuts attributes set to hidden, read-only, archive
					echo FAKE shortcuts special permissions changed.
					echo.
		
				echo CMD MODE ON ----------------------------------------------------
		
					echo Creating %drive%:ROOT2 ...
					echo Setting %drive%: special permissions ...
					
					md %drive%:\ROOT2
					
					ICACLS H:\ROOT2 /grant[:r] Everyone:r
					ICACLS H:\ROOT2 /grant[:r] Everyone:w
					ICACLS H:\ROOT2 /grant[:r] Everyone:m
					REM ICACLS H:\ROOT2 /deny Everyone:d /c
					
					
					echo y| CACLS %drive%: /c /P Everyone:R
					

				echo CMD MODE OFF ---------------------------------------------------

					echo.
					echo %drive%\ROOT2 created.
					echo.
					echo Vaccination finished.
					echo %drive%: is vaccinated at %DATE%, %TIME%.
					echo.
			)
IF %ans%==n (	echo ------------------------------------------------------- 
					echo %drive%: is not vaccinated. Because you chose not to.
					echo.
			)
echo.