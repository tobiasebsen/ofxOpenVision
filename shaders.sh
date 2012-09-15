#!/usr/bin/bash

for file in shaders/*
do
  . shader.sh "$file"
done
