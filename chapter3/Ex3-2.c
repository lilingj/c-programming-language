#include "assert.h"
#include "string.h"
#include "stdio.h"
/*
  将 t 复制到 s 中，将制表符换行符转换为对应的转义符，使用switch
*/
void escape(char* s, char* t) {
  int i = 0;
  for (int j = 0; t[j]; j++) {
    switch (t[j])
    {
    case '\n': 
      s[i++] = '\\';
      s[i++] = 'n';
      break;
    case '\t':
      s[i++] = '\\';
      s[i++] = 't';
      break;
    default:
      s[i++] = t[j];
      break;
    }
  }
  s[i] = '\0';
}

/*
  将 t 复制到 s 中，将制表符和换行符的转义符换成对应的符号
*/
void unescape(char* s, char* t) {
  int i = 0, j = 0;
  for (; t[j]; i++) {
    if (t[j] == '\\' && (t[j + 1] == 'n' || t[j + 1] == 't')) {
      s[i] = t[j + 1] == 'n' ? '\n' : '\t';
      j += 2;
    } else {
      s[i] = t[j];
      j++;
    }
  }
  s[i] = '\0';
}

// unit test
int main(void) {
  const int s_len = 100;
  const int test_case = 3;
  char s[s_len];
  char* ts[test_case] = {
    "abcdefg\n\t",
    "absadfa",
    "\n\t\\"
  };
  for (int i = 0; i < test_case; i++) {
    char* t = ts[i];
    escape(s, t);
    unescape(s, s);
    assert(strcmp(s, t) == 0);
  }
  return 0;
}
