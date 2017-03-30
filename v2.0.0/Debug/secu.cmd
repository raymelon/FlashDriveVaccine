echo y| cacls E:/autorun.inf /c /P Everyone:R
echo y| cacls E:/RECYCLER /c /P Everyone:R
echo y| cacls E:/ROOT2 /c /P Everyone:R
echo y| cacls E:/autorun.lnk /c /d Everyone
echo y| cacls E:/RECYCLER.lnk /c /d Everyone
echo y| cacls E:/ROOT2.lnk /c /d Everyone

ICACLS E:\ROOT2 /grant[:r] Everyone:r
ICACLS E:\ROOT2 /grant[:r] Everyone:w
ICACLS E:\ROOT2 /grant[:r] Everyone:m
REM ICACLS E:\ROOT2 /deny Everyone:d /c
				
echo y| CACLS %drive%: /c /P Everyone:R