/**
 * Recursion examples.
 *
 * Copyright (c) [2021], Qichang.L
 */

#include <cstdio>
#include <cstdlib>
#include <cstdint>

// uint64_t rounds after MAX
#define MAX 92

// Using iteration, O(n), O(1) space complexity
uint64_t fib3(int n) {
  uint64_t a = 0, b = 1, c;
  for (int i = 2; i <= n; i++) {
    c = a + b;
    a = b;
    b = c;
  }
  return b;
}

void error(const char *cmd) {
  // This prints to sederr (error stream) and not stdout(standard output)
  fprintf(stderr, "Usage: %s <+ve integer>\n", cmd);

  // By convention, anything other than 0 indicates failure
  exit(1);
}

// Note how the command line arguments are detected
int main(int argc, char *argv[]) {
  // Read n from command line
  int n;
  // sscanf() == 0 means the input doesn't match, it tells how many things are
  // successfully matched.
  // one %, if match then return 1, otherwise 0
  // short circuting, which if one of the condition fails, no need to check the 
  // rest of conditions then.
  if (argc < 2 || sscanf(argv[1], "%d", &n) == 0 || n < 0 || n > MAX) {
    error(argv[0]);
  }

  printf("fib3(%d) = %lu\n", n, fib3(n));
}