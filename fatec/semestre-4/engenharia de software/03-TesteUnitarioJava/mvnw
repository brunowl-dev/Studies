#!/bin/sh
set -e

BASE_DIR=$(CDPATH= cd -- "$(dirname -- "$0")" && pwd)
WRAPPER_DIR="$BASE_DIR/.mvn/wrapper"
PROPERTIES_FILE="$WRAPPER_DIR/maven-wrapper.properties"
WRAPPER_JAR="$WRAPPER_DIR/maven-wrapper.jar"

if [ ! -f "$PROPERTIES_FILE" ]; then
  echo "Missing $PROPERTIES_FILE" >&2
  exit 1
fi

wrapper_url=$(sed -n 's/^wrapperUrl=//p' "$PROPERTIES_FILE")

if [ ! -f "$WRAPPER_JAR" ]; then
  echo "Downloading Maven wrapper jar..."
  if command -v curl >/dev/null 2>&1; then
    curl -fsSL "$wrapper_url" -o "$WRAPPER_JAR"
  elif command -v wget >/dev/null 2>&1; then
    wget -q "$wrapper_url" -O "$WRAPPER_JAR"
  else
    echo "Neither curl nor wget is available to download the Maven wrapper jar." >&2
    exit 1
  fi
fi

exec java -Dmaven.multiModuleProjectDirectory="$BASE_DIR" -classpath "$WRAPPER_JAR" org.apache.maven.wrapper.MavenWrapperMain "$@"