#include <ctype.h>
#include <math.h>
#include "../utils.h"

/*
  例子atof增强，处理“ 123.45e-6”这种情况
*/
double myatof(char s[]) {
  int i, sign, power, psign;
  double val, pval;
  for(i = 0; isspace(s[i]); i++) 
    ;
  sign = s[i] == '-' ? -1 : 1;
  if (s[i] == '+' || s[i] == '-') 
    i++;
  for(val = 0.0; isdigit(s[i]); i++) 
    val = val * 10.0 + (s[i] - '0');
  if (s[i] == '.') 
    i++;
  for(power = 0; isdigit(s[i]); i++) {
    val = val * 10.0 + (s[i] - '0');
    power--;
  }
  if (s[i] == 'e' || s[i] == 'E')
    i++;
  psign = s[i] == '-' ? -1 : 1;
  if (s[i] == '+' || s[i] == '-')
    i++;
  for(pval = 0.0; isdigit(s[i]); i++) {
    pval = pval * 10.0 + (s[i] - '0');
  }
  return sign * val * pow(10, power + psign * pval);
}


//      unit test
int main(void) {
  assert_equal(myatof("  123.45e2"), 12345.0);
  assert_equal(myatof("  -123.45e3"), -123450.0);
  assert_equal(myatof("-0.0e2"), 0.0);
  assert_equal(myatof("0"), 0.0);
  assert_equal(myatof("1e-2"), 0.01);
  return 0;
}