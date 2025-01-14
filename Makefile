CXX = g++
CXXFLAGS = -std=c++11 -Wall

DP_EXEC = dp_partition
BRUTE_EXEC = brute_partition
TEST_EXEC = test_generator 

DP_SRC = dp_partition.cpp
BRUTE_SRC = brute_partition.cpp
TEST_SRC = test_generator.cpp


all: $(DP_EXEC) $(BRUTE_EXEC) $(TEST_EXEC)

$(DP_EXEC): $(DP_SRC)
	$(CXX) $(CXXFLAGS) -o $@ $^

$(BRUTE_EXEC): $(BRUTE_SRC)
	$(CXX) $(CXXFLAGS) -o $@ $^

$(TEST_EXEC): $(TEST_SRC)
	$(CXX) $(CXXFLAGS) -o $@ $^

clean:
	rm -f $(DP_EXEC) $(BRUTE_EXEC) $(TEST_EXEC)
