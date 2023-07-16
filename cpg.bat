@echo off

if "%1" == "" goto NoPara
if "%1" == "/c" goto Clean
if "%1" == "-c" goto Clean
if "%1" == "/b" goto Build
if "%1" == "-b" goto Build

goto End

:NoPara

if exist main.c (
    gcc main.c -o main.exe
    main.exe 
)
goto End

:Clean
for /f "usebackq delims=" %%i in (`dir /b/s /aa ^| find /v ".git" ^| find /v ".h" ^| find /v ".c" ^| find /v ".txt" ^| find /v ".bat"`) do (
    del %%i
)
for /f "usebackq delims=" %%d in (`"dir /ad/b/s | sort /r"`) do rd "%%d" > nul 2>&1
goto End

:Build
gcc main.c -o main.exe
goto End

:End
