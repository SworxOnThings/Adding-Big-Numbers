#include <assert.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* sDup(const char* s)
{
  size_t len = strlen(s);
  char*  str = (char*)malloc(len + 1);
  if (str == NULL) {
    return NULL;
  }
  memcpy(str, s, len + 1);
  return str;
}

void swap(char** lhs, char** rhs)
{
  char* temp = *lhs;
  *lhs       = *rhs;
  *rhs       = temp;
}

void iterSwap(char* lhs, char* rhs)
{
  char temp = *lhs;
  *lhs      = *rhs;
  *rhs      = temp;
}

void lengthSwap(size_t* lhs, size_t* rhs)
{
  size_t temp = *lhs;
  *lhs        = *rhs;
  *rhs        = temp;
}

void reverse(char* first, char* last)
{
  if (first == last) {
    return;
  }

//meet in the middle
  for (--last; first < last; ++first, --last) {
    iterSwap(first, last);
  }
}

size_t maximum(size_t a, size_t b)
{
  if (a > b) {
    return a;
  }

  return b;
}


char* addStrings(const char* a, const char* b)
{

  char* lhs = sDup(a);
  if (lhs == NULL) {
    return NULL;
  }

  char* rhs = sDup(b);
  if (rhs == NULL) {
    free(lhs);
    return NULL;
  }

  size_t lhsLen = strlen(lhs);
  size_t rhsLen = strlen(rhs);


  if (lhsLen > rhsLen) {
    swap(&lhs, &rhs);
    lengthSwap(&lhsLen, &rhsLen);
  }


  char* result = (char*)calloc(maximum(lhsLen, rhsLen) + 1 + 1, sizeof(char));
  if (result == NULL) {
    free(lhs);
    free(rhs);
    return NULL;
  }
  *result            = '\0';

  size_t resultIndex = 0;

  reverse(lhs, lhs + lhsLen);
  reverse(rhs, rhs + rhsLen);

  int carry = 0;

  for (size_t i = 0; i < lhsLen; i++) {
    int sum             = (lhs[i] - '0') + (rhs[i] - '0') + carry;

    result[resultIndex] = sum % 10 + '0';
    carry               = sum / 10;
    resultIndex++;
  }

  for (size_t i = lhsLen; i < rhsLen; i++) {
    int sum             = (rhs[i] - '0') + carry;
    result[resultIndex] = sum % 10 + '0';
    carry               = sum / 10;
    resultIndex++;
  }

  if (carry != 0) {
    result[resultIndex] = carry + '0';
    resultIndex++;
  }

  reverse(result, result + resultIndex);
  result[resultIndex] = '\0';
  return result;
}

char* add(const char* a, const char* b)
{
  return addStrings(a, b);
}

int main(void)
{
  char* test = add("1372", "69");
  if (strcmp(test, "1441") != 0) {
    printf("test failed. test: %s\n", test);
  }
  else {
    printf("success!\n");
  }
  free(test);

  return 0;
}
