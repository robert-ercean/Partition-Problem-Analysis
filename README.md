# Partition Problem Analysis

## **Overview**
This repository contains an analysis of the **Partition Problem**, a well-known **NP-complete** problem. The project explores different algorithms to solve the problem, including:

- **Brute Force Approach**: Exhaustively checks all subsets.
- **Dynamic Programming Approach**: Uses **top-down memoization** to optimize the search.

Additionally, we conduct **performance and memory usage analysis** to compare these two approaches.

---

## **Test Case Generation**
The test cases used for performance evaluation are generated dynamically using the `test_generator` utility.

### **Test Case Structure**
Each test case consists of:
1. **A unique test ID** (integer).
2. **The size of the array** (number of elements).
3. **The array values**, which vary depending on the type of test.

The test cases are stored in `test_cases.txt` in the following format:
```
<Test_ID> <Array_Size> <Array_Elements...>
```

#### **Example:**
```
1 5 10 12 14 16 18 
2 10 14 16 18 20 22 24 26 28 30
```

---

## **Using the Test Case Generator**
The test cases can be generated using:

```bash
./test_generator <test_id> <array_size> <big_numbers_flag>
```

Where:
- `<test_id>`: A unique identifier for the test case.
- `<array_size>`: The number of elements in the test array.
- `<big_numbers_flag>`:
  - `0`: Generates small numbers to test brute force.
  - `1`: Generates large numbers to stress the DP approach.

#### **Example:**
```bash
./test_generator 5 20 0
```
This will append a test case with 20 elements to `test_cases.txt`, containing small numbers.

---

## **Running the Tests**
### **Execution Time Measurement**
To evaluate the execution time of the two approaches, use:

```bash
./run_tests.sh <test_id>
```

This will execute both `dp_partition` and `brute_partition` on the specified test case and log the results in `time_outs.txt`.

#### **Example:**
```bash
./run_tests.sh 10
```

#### **Output (logged in `time_outs.txt`):**
```
dp_partition (Test ID: 10) - 0.059 seconds
brute_partition (Test ID: 10) - 0.0111 seconds
```

## **Project Structure**
```
📂 Partition_Problem_Analysis
│── brute_partition.cpp    # Brute Force implementation
│── dp_partition.cpp       # Dynamic Programming implementation
│── test_generator.cpp     # Test case generator
│── test_cases.txt         # Stored test cases
│── run_tests.sh           # Measures execution time
│── Makefile               # Compilation script
│── README.md              # Documentation
│── time_outs.txt          # Execution time results
```

---

## **Conclusion**
The results confirm that:
- **Brute Force** is only feasible for small inputs, as it exponentially grows in execution time.
- **Dynamic Programming** significantly reduces execution time but requires more memory.
- The **total sum of elements** greatly affects the efficiency of DP, making it **pseudo-polynomial**.

For practical applications, **Dynamic Programming** is preferred, but alternative optimizations should be considered for large sum values.
