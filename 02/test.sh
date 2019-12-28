#!/bin/sh

function test_gate {
  echo "Testing $1..."
  HardwareSimulator.sh $1
}

export -f test_gate

find . -name '*.tst' -exec /bin/bash -c 'test_gate "$0"' {} \;

