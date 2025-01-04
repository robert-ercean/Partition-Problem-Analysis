#!/bin/bash

# check if test case number exists
if [ $# -ne 1 ]; then
    echo "Usage: ./run_tests.sh <test_case_number>"
    exit 1
fi

TEST_ID=$1
OUTPUT_FILE="time_outs.txt"

# time the exec and log it into the out file
run_test() {
    EXEC=$1
    TEST_ID=$2
    START_TIME=$(date +%s.%N)
    ./$EXEC $TEST_ID > /dev/null 2>&1
    END_TIME=$(date +%s.%N)
    TIME_TAKEN=$(echo "$END_TIME - $START_TIME" | bc)  # elapsed time
    echo "$EXEC (Test ID: $TEST_ID) - $TIME_TAKEN seconds" | tee -a $OUTPUT_FILE
}

# clear previous outputs
echo "Running test case: $TEST_ID" | tee -a $OUTPUT_FILE

# run both algos
run_test "dp_partition" $TEST_ID
run_test "brute_partition" $TEST_ID

echo "Results saved to $OUTPUT_FILE"
