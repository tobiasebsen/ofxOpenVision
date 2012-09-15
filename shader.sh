#!/bin/sh

path="${1##*/}"
name="${path%%[.]*}"
header="src/shaders/${name}.h"

sed '
s/^/\    \"/
s/$/\\n\"/
1 i\
/* AUTO-GENERATED CODE BY shader.sh */\
\
#pragma once\
\
static string '$name'Source =
$ a\
\    \"\";
' "$1" > "$header"
