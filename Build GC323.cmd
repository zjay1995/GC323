@echo off
rem Open the Borland C++ 3.1 IDE in DOSBox-X with the GC323 project mounts.
rem   S: = BORLANDC      D: = GC323 source      C: = scratch (C:\TEMP)
rem Once the IDE is up:  Project | Open Project | WPEAK.PRJ,  then Compile | Build All.

setlocal
set "HERE=%~dp0"
set "DBX=%HERE%_tools\dosbox-x\bin\x64\Release\dosbox-x.exe"
set "CFG=%HERE%_tools\dosbox-x\gc323.conf"

if not exist "%DBX%" (
  echo Cannot find DOSBox-X at:
  echo   %DBX%
  echo Download the portable Windows build from
  echo   https://github.com/joncampbell123/dosbox-x/releases
  echo and extract it to  _tools\dosbox-x\
  pause
  exit /b 1
)

start "" "%DBX%" -conf "%CFG%"
endlocal
