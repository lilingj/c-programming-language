#include<string.h>

void reverse(char* s) {
  int len = strlen(s);
  for (int i = 0, j = len - 1; i < j; i++, j--){
    char tmp = s[i];
    s[i] = s[j];
    s[j] = tmp;
  }
}