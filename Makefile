CC = gcc
CFLAGS = -Wall -Wextra -std=c11 -Isrc -Ithirdparty
LDFLAGS = -lm
DEPSFLAGS = -MMD
TESTFLAGS = -I thirdparty

EXEC_NAME = fifteen_puzzle
SRC_DIR = src
TEST_DIR = test

EXEC_PATH = $(SRC_DIR)/$(EXEC_NAME)
TEST_EXEC = $(TEST_DIR)/$(EXEC_NAME)_test

EXEC_SOURCES = $(wildcard $(SRC_DIR)/*.c)
EXEC_OBJECTS = $(patsubst %.c, %.o, $(EXEC_SOURCES))

TEST_SOURCES = $(wildcard $(TEST_DIR)/*.c) $(TEST_DIR)/test_move.c
TEST_OBJECTS = $(patsubst %.c, %.o, $(TEST_SOURCES))

DEPS = $(EXEC_OBJECTS:.o=.d) $(TEST_OBJECTS:.o=.d)

all: $(EXEC_PATH)

$(EXEC_PATH): $(EXEC_OBJECTS)
	$(CC) $(CFLAGS) -o  $@ $^ $(LDFLAGS)

$(SRC_DIR)/%.o: %.c
	$(CC) $(CFLAGS) $(DEPSFLAGS) -c $< -o $@

test: $(TEST_EXEC)

$(TEST_EXEC): $(TEST_OBJECTS) $(filter-out $(SRC_DIR)/main.o, $(EXEC_OBJECTS))
	$(CC) $(TESTFLAGS) $(CFLAGS) $(DEPSFLAGS) -o $@ $^ $(LDFLAGS)

$(TEST_DIR)/%.o: %.c
	$(CC) $(TESTFLAGS) $(CFLAGS) $(DEPSFLAGS) -c -o $@ $< $(LDFLAGS)

-include $(DEPS)

clean:
	rm -f $(SRC_DIR)/*.o $(SRC_DIR)/*.d $(TEST_DIR)/*.o $(TEST_DIR)/*.d

.PHONY: all clean test run

run: all
	$(EXEC_PATH)
