#include <Date.au3>
#include <MsgBoxConstants.au3>

Dim $iMsgBoxAnswer
$iMsgBoxAnswer = MsgBox(64,"Flash Drive VACCINE v1.0.0 alpha","Vaccination done at " & _Now() & @CRLF & "" & @CRLF & "" & "About" & @CRLF & "------------------------------------------------------------------" & @CRLF & "Flash Drive VACCINE v1.0.0 alpha" & @CRLF & "by Raymel Francisco" & @CRLF & "" & @CRLF & "Copyright (c) 2014. All rights reserved.",0)
Select
   Case $iMsgBoxAnswer = -1 ;Timeout

   Case Else                ;OK

EndSelect