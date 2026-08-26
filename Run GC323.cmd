@echo off
rem Launch the 16-bit GC323 build through otvdm (winevdm) on 64-bit Windows.
rem Double-click this file. Keep it in the same folder as the .exe.

setlocal
set "HERE=%~dp0"
set "OTVDM=%HERE%_tools\otvdm\otvdm-v0.9.0\otvdmw.exe"
set "APP=%HERE%GC323_v70.28.exe"

if not exist "%OTVDM%" (
  echo Cannot find otvdm at:
  echo   %OTVDM%
  echo Download otvdm-v0.9.0.zip from https://github.com/otya128/winevdm/releases
  echo and extract it to  _tools\otvdm\
  pause
  exit /b 1
)

if not exist "%APP%" (
  echo Cannot find %APP%
  pause
  exit /b 1
)

start "" "%OTVDM%" "%APP%"
endlocal
