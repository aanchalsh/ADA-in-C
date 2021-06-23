//b.Implement Brute force String matching algorithm.
#include <stdio.h>
#include <string.h>
int bruteForcealgo(char [],char []);
int main() 
{
  char a[100], b[100];
  int pos;
  printf("Enter string\n");
  gets(a);
  printf("Enter string to search for \n");
  gets(b);
  pos = bruteForcealgo(a, b);
  if (pos != -1) {
    printf("String found at position: %d\n", pos + 1);
  }
  else {
    printf("Error! String not found\n");
  }
  return 0;
}

int bruteForcealgo(char s[], char p[]) 
{
  int c,d,e,l1,l2,pos = -1;
  l1=strlen(s);
  l2=strlen(p);
  if (l2 > l1)
    return -1;
  for (c=0;c<= l1-l2;c++)
  {
    pos=e=c;
    for (d=0;d<l2;d++) 
    {
      if (p[d]==s[e]){
        e++;
      }
      else
        break;
    }
    if (d==l2) 
      return pos;
  }
  return -1;
}
