#!/bin/bash

hash_old=""

while true
do
  hash_new=$(md5sum $(ls | grep "\.h\|\.cpp\|\.hpp"))
  if [[ $hash_new != $hash_old ]]
  then
  hash_old=$hash_new
    cmake . && make && ./UnitTests
  fi
  sleep 1
done
