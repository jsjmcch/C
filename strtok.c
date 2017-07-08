#include <stdio.h>
#include <string.h>

int main() 
{ 
  chr str[] = "- This, a sample string.";
  char* pch;
  
  printf("Splitting string \"%s\" into tokens:\n", str);
  pch = strtok (str, " ,.-");
  while (pch != NULL)
  {
    printf ("%s\n", pch);
    pch = strtok (NULL, " ,.-");
  }
  
  return 0;
}

* result : 
Splitting string "- This, a sample string." into tokens:
This
a
sample
string
 
