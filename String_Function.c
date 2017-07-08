/* strcpy example */
#include <stdio.h>
#include <string.h>

int main ()
{
  char str1[]="Sample string";
  char str2[40];
  char str3[40];
  strcpy (str2,str1);
  strcpy (str3,"copy successful");
  printf ("str1: %s\nstr2: %s\nstr3: %s\n",str1,str2,str3);
  return 0;
}

Output:
str1: Sample string
str2: Sample string
str3: copy successful

==============================================================================
/* strncpy example */
#include <stdio.h>
#include <string.h>

int main ()
{
  char str1[]= "To be or not to be";
  char str2[40];
  char str3[40];

  /* copy to sized buffer (overflow safe): */
  strncpy ( str2, str1, sizeof(str2) );

  /* partial copy (only 5 chars): */
  strncpy ( str3, str2, 5 );
  str3[5] = '\0';   /* null character manually added */

  puts (str1);
  puts (str2);
  puts (str3);

  return 0;
}

Output:
To be or not to be
To be or not to be
To be 
==============================================================================

/* memcmp example */
#include <stdio.h>
#include <string.h>

int main ()
{
  char buffer1[] = "DWgaOtP12df0";
  char buffer2[] = "DWGAOTP12DF0";

  int n;

  n=memcmp ( buffer1, buffer2, sizeof(buffer1) );

  if (n>0) printf ("'%s' is greater than '%s'.\n",buffer1,buffer2);
  else if (n<0) printf ("'%s' is less than '%s'.\n",buffer1,buffer2);
  else printf ("'%s' is the same as '%s'.\n",buffer1,buffer2);

  return 0;
}

Output:
'DWgaOtP12df0' is greater than 'DWGAOTP12DF0'.

==============================================================================
/* memset example */
#include <stdio.h>
#include <string.h>

int main ()
{
  char str[] = "almost every programmer should know memset!";
  memset (str,'-',6);
  puts (str);
  return 0;
}

Output:
------ every programmer should know memset!
==============================================================================
/* strcat example */
#include <stdio.h>
#include <string.h>

int main ()
{
  char str[80];
  strcpy (str,"these ");
  strcat (str,"strings ");
  strcat (str,"are ");
  strcat (str,"concatenated.");
  puts (str);
  return 0;
}

Output:
these strings are concatenated. 
==============================================================================
/* strchr example */
#include <stdio.h>
#include <string.h>

int main ()
{
  char str[] = "This is a sample string";
  char * pch;
  printf ("Looking for the 's' character in \"%s\"...\n",str);
  pch=strchr(str,'s');
  while (pch!=NULL)
  {
    printf ("found at %d\n",pch-str+1);
    pch=strchr(pch+1,'s');
  } 
  return 0;
}
Output:

Looking for the 's' character in "This is a sample string"...
found at 4
found at 7
found at 11
found at 18
==============================================================================
#include <stdio.h>
#include <string.h>

int main ()
{
  char key[] = "apple";
  char buffer[80];
  do {
     printf ("Guess my favorite fruit? ");
     fflush (stdout);
     scanf ("%79s",buffer);
  } while (strcmp (key,buffer) != 0);
  puts ("Correct answer!");
  return 0;
}

Output:
Guess my favourite fruit? orange
Guess my favourite fruit? apple
Correct answer!
==============================================================================
/* strcspn example */
#include <stdio.h>
#include <string.h>

int main ()
{
  char str[] = "fcba73";
  char keys[] = "1234567890";
  int i;
  i = strcspn (str,keys);
  printf ("The first number in str is at position %d.\n",i+1);
  return 0;
}

Output:
The first number in str is at position 5
==============================================================================
/* strerror example : error list */
#include <stdio.h>
#include <string.h>
#include <errno.h>

int main ()
{
  FILE * pFile;
  pFile = fopen ("unexist.ent","r");
  if (pFile == NULL)
    printf ("Error opening file unexist.ent: %s\n",strerror(errno));
  return 0;
}
Possible output:
Error opening file unexist.ent: No such file or directory
==============================================================================

==============================================================================

==============================================================================

==============================================================================

==============================================================================

==============================================================================



