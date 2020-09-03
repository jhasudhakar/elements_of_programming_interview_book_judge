#include "test_framework/generic_test.h"
bool IsPalindromeNumber(int x) {
  // TODO - you fill in here.
    if (x < 0)
        return false;
    if (x == 0)
        return true;

    int N=0, val[64];
    while (x)
    {
        int temp = x % 10;
        val[N] = temp;
        N++;
        x = x / 10;
    }
    for (int i = 0; i < N/2; i++)
    {
        if (val[i] != val[N - 1 - i])
            return false;
    }
  return true;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"x"};
  return GenericTestMain(args, "is_number_palindromic.cc",
                         "is_number_palindromic.tsv", &IsPalindromeNumber,
                         DefaultComparator{}, param_names);
}
