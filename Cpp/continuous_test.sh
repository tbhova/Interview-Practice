#!/bin/bash

while true
do
  cmake . && make && ./UnitTests
  sleep 1
done
