#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include <string>

std::string sum_strings(const std::string& a, const std::string& b)
{
  std::string lhs{a};
  std::string rhs{b};

  if (lhs.size() > rhs.size()) {
    lhs.swap(rhs);
  }

  std::string result{};
  using size_type = std::string::size_type;
  std::reverse(lhs.begin(), lhs.end());
  std::reverse(rhs.begin(), rhs.end());
  int carry{0};

  for (size_type i{0}; i < lhs.size(); i++) {
    const int sum{(lhs[i] - '0') + (rhs[i] - '0') + carry};
    result.push_back(sum % 10 + '0');
    carry = sum / 10;
  }

  for (size_type i{lhs.size()}; i < rhs.size(); i++) {
    const int sum{(rhs[i] - '0') + carry};
    result.push_back(sum % 10 + '0');
    carry = sum / 10;
  }

  if (carry) {
    result.push_back(carry + '0');
  }

  std::reverse(result.begin(), result.end());
  return result;
}

 int main(void)
 {
     std::string test = sum_strings("123", "456");
     if(test != "579")
     {
         printf("test failed.\n");
     }
     else
     {
         printf("success!\n");
     }

     return 0;
 }