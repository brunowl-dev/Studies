@ECHO OFF
SETLOCAL

set BASE_DIR=%~dp0
if "%BASE_DIR:~-1%"=="\" set BASE_DIR=%BASE_DIR:~0,-1%
set WRAPPER_DIR=%BASE_DIR%\.mvn\wrapper
set PROPERTIES_FILE=%WRAPPER_DIR%\maven-wrapper.properties
set WRAPPER_JAR=%WRAPPER_DIR%\maven-wrapper.jar

if not exist "%PROPERTIES_FILE%" (
  echo Missing %PROPERTIES_FILE%
  exit /b 1
)

if not exist "%WRAPPER_JAR%" (
  echo Downloading Maven wrapper jar...
  powershell -NoProfile -ExecutionPolicy Bypass -Command "& { $props = Get-Content '%PROPERTIES_FILE%'; $url = ($props | Where-Object { $_ -like 'wrapperUrl=*' } | Select-Object -First 1).Split('=',2)[1]; Invoke-WebRequest -UseBasicParsing -Uri $url -OutFile '%WRAPPER_JAR%' }"
  if errorlevel 1 exit /b 1
)

java -Dmaven.multiModuleProjectDirectory="%BASE_DIR%" -classpath "%WRAPPER_JAR%" org.apache.maven.wrapper.MavenWrapperMain %*