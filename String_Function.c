* Library Function
1. IBM Knowledge Center 
 - https://www.ibm.com/support/knowledgecenter/ko/ssw_ibm_i_73/rtref/keyword.htm
2. Cplusplus
 - http://www.cplusplus.com/reference/
3. Falinux.com
 - http://forum.falinux.com/zbxe/index.php?mid=C_LIB
==============================================================================
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
/* strpbrk example */
#include <stdio.h>
#include <string.h>

int main ()
{
  char str[] = "This is a sample string";
  char key[] = "aeiou";
  char * pch;
  printf ("Vowels in '%s': ",str);
  pch = strpbrk (str, key);
  while (pch != NULL)
  {
    printf ("%c " , *pch);
    pch = strpbrk (pch+1,key);
  }
  printf ("\n");
  return 0;
}
Output:
Vowels in 'This is a sample string': i i a a e i 
==============================================================================
/* strrchr example */
#include <stdio.h>
#include <string.h>

int main ()
{
  char str[] = "This is a sample string";
  char * pch;
  pch=strrchr(str,'s');
  printf ("Last occurence of 's' found at %d \n",pch-str+1);
  return 0;
}
Output:
Last occurrence of 's' found at 18
==============================================================================
/* strspn example */
#include <stdio.h>
#include <string.h>

int main ()
{
  int i;
  char strtext[] = "129th";
  char cset[] = "1234567890";

  i = strspn (strtext,cset);
  printf ("The initial number has %d digits.\n",i);
  return 0;
}
Output:
The initial number has 3 digits.
==============================================================================
/* strstr example */
#include <stdio.h>
#include <string.h>

int main ()
{
  char str[] ="This is a simple string";
  char * pch;
  pch = strstr (str,"simple");
  strncpy (pch,"sample",6);
  puts (str);
  return 0;
}
Output:
This is a sample string
==============================================================================
/* strtok example */
#include <stdio.h>
#include <string.h>

int main ()
{
  char str[] ="- This, a sample string.";
  char * pch;
  printf ("Splitting string \"%s\" into tokens:\n",str);
  pch = strtok (str," ,.-");
  while (pch != NULL)
  {
    printf ("%s\n",pch);
    pch = strtok (NULL, " ,.-");
  }
  return 0;
}
Output:
Splitting string "- This, a sample string." into tokens:
This
a
sample
string
==============================================================================
/* memcpy example */
#include <stdio.h>
#include <string.h>

struct {
  char name[40];
  int age;
} person, person_copy;

int main ()
{
  char myname[] = "Pierre de Fermat";

  /* using memcpy to copy string: */
  memcpy ( person.name, myname, strlen(myname)+1 );
  person.age = 46;

  /* using memcpy to copy structure: */
  memcpy ( &person_copy, &person, sizeof(person) );
  printf ("person_copy: %s, %d \n", person_copy.name, person_copy.age );

  return 0;
}
Output:
person_copy: Pierre de Fermat, 46 
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
'DWgaOtP12df0' is greater than 'DWGAOTP12DF0'
==============================================================================
/* memchr example */
#include <stdio.h>
#include <string.h>

int main ()
{
  char * pch;
  char str[] = "Example string";
  pch = (char*) memchr (str, 'p', strlen(str));
  if (pch!=NULL)
    printf ("'p' found at position %d.\n", pch-str+1);
  else
    printf ("'p' not found.\n");
  return 0;
}
Output:
'p' found at position 5.
==============================================================================
/* memmove example */
#include <stdio.h>
#include <string.h>

int main ()
{
  char str[] = "memmove can be very useful......";
  memmove (str+20,str+15,11);
  puts (str);
  return 0;
}
Output:
memmove can be very very useful.
==============================================================================
/* atof example: sine calculator */
#include <stdio.h>      /* printf, fgets */
#include <stdlib.h>     /* atof */
#include <math.h>       /* sin */

int main ()
{
  double n,m;
  double pi=3.1415926535;
  char buffer[256];
  printf ("Enter degrees: ");
  fgets (buffer,256,stdin);
  n = atof (buffer);
  m = sin (n*pi/180);
  printf ("The sine of %f degrees is %f\n" , n, m);
  return 0;
}

Output:
Enter degrees: 45
The sine of 45.000000 degrees is 0.707101
==============================================================================
/* atoi example */
#include <stdio.h>      /* printf, fgets */
#include <stdlib.h>     /* atoi */

int main ()
{
  int i;
  char buffer[256];
  printf ("Enter a number: ");
  fgets (buffer, 256, stdin);
  i = atoi (buffer);
  printf ("The value entered is %d. Its double is %d.\n",i,i*2);
  return 0;
}
Output:
Enter a number: 73
The value entered is 73. Its double is 146.
==============================================================================
/* atol example */
#include <stdio.h>      /* printf, fgets */
#include <stdlib.h>     /* atol */

int main ()
{
  long int li;
  char buffer[256];
  printf ("Enter a long number: ");
  fgets (buffer, 256, stdin);
  li = atol(buffer);
  printf ("The value entered is %ld. Its double is %ld.\n",li,li*2);
  return 0;
}

Output:
Enter a number: 567283
The value entered is 567283. Its double is 1134566.
==============================================================================
/* atoll example */
#include <stdio.h>      /* printf, fgets */
#include <stdlib.h>     /* atoll */

int main ()
{
  long long int lli;
  char buffer[256];
  printf ("Enter a long number: ");
  fgets (buffer, 256, stdin);
  lli = atoll(buffer);
  printf ("The value entered is %lld. Its double is %lld.\n",lli,lli*2);
  return 0;
}

Output:
Enter a number: 9275806
The value entered is 9275806. Its double is 18551612.
==============================================================================
/* at_quick_exit example */
#include <stdio.h>      /* puts */
#include <stdlib.h>     /* at_quick_exit, quick_exit, EXIT_SUCCESS */

void fnQExit (void)
{
  puts ("Quick exit function.");
}

int main ()
{
  at_quick_exit (fnQExit);
  puts ("Main function: Beginning");
  quick_exit (EXIT_SUCCESS);
  puts ("Main function: End");  // never executed
  return 0;
}
Output:

Main function: Beginning
Quick exit function.
==============================================================================
/* bsearch example with strings */
#include <stdio.h>      /* printf */
#include <stdlib.h>     /* qsort, bsearch, NULL */
#include <string.h>     /* strcmp */

char strvalues[][20] = {"some","example","strings","here"};

int main ()
{
  char * pItem;
  char key[20] = "example";

  /* sort elements in array: */
  qsort (strvalues, 4, 20, (int(*)(const void*,const void*)) strcmp);

  /* search for the key: */
  pItem = (char*) bsearch (key, strvalues, 4, 20, (int(*)(const void*,const void*)) strcmp);

  if (pItem!=NULL)
    printf ("%s is in the array.\n",pItem);
  else
    printf ("%s is not in the array.\n",key);
  return 0;
}
Output:
example is in the array.

// 구조체 정렬
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define REC 5

struct record {
    char name[5];
    char number[4];
};

int cmp(struct record *a, struct record *b)
{
    return strncmp(a->number, b->number, 3);
}

int cmpbyname(struct record *a, struct record *b)
{
    return strncmp(a->name, b->name, 3);
}

int main()
{
    int i;
    struct record data[REC] = {{"kim", "312"}, {"lee", "300"}, {"park", "213"}, {"kang", "915"}, {"dong", "318"}};

    printf("=============sort by number==============\n");
    qsort((void *)data, REC, sizeof(struct record), cmp);

    for (i=0; i<REC; i++) {
        printf("%s %s\n", data[i].name, data[i].number);
    }

    printf("=============sort by name==============\n");
    qsort((void *)data, REC, sizeof(struct record), cmpbyname);

    for (i=0; i<REC; i++) {
        printf("%s %s\n", data[i].name, data[i].number);
    }
    return 0;
}

// 문자열 정렬 (down, up)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int sort_function_up( const void *a, const void *b);
int sort_function_down( const void *a, const void *b);

char list[5][4] = {"cat", "car", "cab", "cap", "can"};

int main(void) {
    int x;
    printf("=======down->up=====\n");
    qsort((void *)list, 5, sizeof(list[0]), sort_function_up);

    for(x=0; x<5; x++)
        printf("%s\n", list[x]);

    printf("=======up->down=====\n");

    qsort((void *)list, 5, sizeof(list[0]), sort_function_down);

    for(x=0; x<5; x++)
        printf("%s\n", list[x]);

    return 0;
}

int sort_function_up( const void *a, const void *b) {
    return (strcmp((char *)a, (char *)b));
}

int sort_function_down( const void *a, const void *b) {
    return (strcmp((char *)b, (char *)a));
}

// 숫자 정렬
#include <stdio.h>
#include <stdlib.h>

int compare_up(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int compare_down(const void *a, const void *b) {
    return (*(int *)b - *(int *)a);
}

int main()
{
    int values[] = {40, 10, 100, 90, 20, 25};
    int n;

    qsort(values, 6, sizeof(int), compare_up);
    for(n=0; n<6; n++) printf("%d ", values[n]);
    printf("\n");

    qsort(values, 6, sizeof(int), compare_down);
    for(n=0; n<6; n++) printf("%d ", values[n]);
    printf("\n");

    return 0;
}
  
  
  
  
==============================================================================
/* malloc example: random string generator*/
#include <stdio.h>      /* printf, scanf, NULL */
#include <stdlib.h>     /* malloc, free, rand */

int main ()
{
  int i,n;
  char * buffer;

  printf ("How long do you want the string? ");
  scanf ("%d", &i);

  buffer = (char*) malloc (i+1);
  if (buffer==NULL) exit (1);

  for (n=0; n<i; n++)
    buffer[n]=rand()%26+'a';
  buffer[i]='\0';

  printf ("Random string: %s\n",buffer);
  free (buffer);

  return 0;
}

/* calloc example */
#include <stdio.h>      /* printf, scanf, NULL */
#include <stdlib.h>     /* calloc, exit, free */

int main ()
{
  int i,n;
  int * pData;
  printf ("Amount of numbers to be entered: ");
  scanf ("%d",&i);
  pData = (int*) calloc (i,sizeof(int));
  if (pData==NULL) exit (1);
  for (n=0;n<i;n++)
  {
    printf ("Enter number #%d: ",n+1);
    scanf ("%d",&pData[n]);
  }
  printf ("You have entered: ");
  for (n=0;n<i;n++) printf ("%d ",pData[n]);
  free (pData);
  return 0;
}

/* realloc example: rememb-o-matic */
#include <stdio.h>      /* printf, scanf, puts */
#include <stdlib.h>     /* realloc, free, exit, NULL */

int main ()
{
  int input,n;
  int count = 0;
  int* numbers = NULL;
  int* more_numbers = NULL;

  do {
     printf ("Enter an integer value (0 to end): ");
     scanf ("%d", &input);
     count++;

     more_numbers = (int*) realloc (numbers, count * sizeof(int));

     if (more_numbers!=NULL) {
       numbers=more_numbers;
       numbers[count-1]=input;
     }
     else {
       free (numbers);
       puts ("Error (re)allocating memory");
       exit (1);
     }
  } while (input!=0);

  printf ("Numbers entered: ");
  for (n=0;n<count;n++) printf ("%d ",numbers[n]);
  free (numbers);

  return 0;
}
==============================================================================
/* div example */
#include <stdio.h>      /* printf */
#include <stdlib.h>     /* div, div_t */

int main ()
{
  div_t divresult;
  divresult = div (38,5);
  printf ("38 div 5 => %d, remainder %d.\n", divresult.quot, divresult.rem);
  return 0;
}
Output:
38 div 5 => 7, remainder 3.
==============================================================================  
/* ldiv example */
#include <stdio.h>      /* printf */
#include <stdlib.h>     /* ldiv, ldiv_t */

int main ()
{
  ldiv_t ldivresult;
  ldivresult = ldiv (1000000L,132L);
  printf ("1000000 div 132 => %ld, remainder %ld.\n", ldivresult.quot, ldivresult.rem);
  return 0;
}
Output:
1000000 div 132 => 7575, remainder 100.  
==============================================================================    
/* lldiv example */
#include <stdio.h>      /* printf */
#include <stdlib.h>     /* lldiv, lldiv_t */

int main ()
{
  lldiv_t res;
  res = lldiv (31558149LL,3600LL);
  printf ("Earth orbit: %lld hours and %lld seconds.\n", res.quot, res.rem);
  return 0;
}  

Output:
Earth orbit: 8766 hours and 549 seconds.
==============================================================================
/* labs example */
#include <stdio.h>      /* printf */
#include <stdlib.h>     /* labs */

int main ()
{
  long int n,m;
  n=labs(65537L);
  m=labs(-100000L);
  printf ("n=%ld\n",n);
  printf ("m=%ld\n",m);
  return 0;
}
Output:
n=65537
m=100000
==============================================================================
/* llabs example */
#include <stdio.h>      /* printf */
#include <stdlib.h>     /* llabs */

int main ()
{
  long long int n,m;
  n=llabs(31558149LL);
  m=llabs(-100000000LL);
  printf ("n=%lld\n",n);
  printf ("m=%lld\n",m);
  return 0;
}

Output:
n=31558149
m=100000000
==============================================================================
/* mblen example */
#include <stdio.h>      /* printf */
#include <stdlib.h>     /* mblen, mbtowc, wchar_t(C) */

void printbuffer (const char* pt, size_t max)
{
  int length;
  wchar_t dest;

  mblen (NULL, 0);         /* reset mblen */
  mbtowc (NULL, NULL, 0);  /* reset mbtowc */

  while (max>0) {
    length = mblen (pt, max);
    if (length<1) break;
    mbtowc(&dest,pt,length);
    printf ("[%lc]",dest);
    pt+=length; max-=length;
  }
}

int main()
{
  const char str [] = "test string";

  printbuffer (str,sizeof(str));

  return 0;
}
Output:
[t][e][s][t][ ][s][t][r][i][n][g]
==============================================================================
/* qsort example */
#include <stdio.h>      /* printf */
#include <stdlib.h>     /* qsort */

int values[] = { 40, 10, 100, 90, 20, 25 };

int compare (const void * a, const void * b)
{
  return ( *(int*)a - *(int*)b );
}

int main ()
{
  int n;
  qsort (values, 6, sizeof(int), compare);
  for (n=0; n<6; n++)
     printf ("%d ",values[n]);
  return 0;
}

Output:
10 20 25 40 90 100  
==============================================================================
#include <stdio.h>
 
int main( )
{   
    FILE *pFile = NULL;
 
    pFile = fopen( "d:\\Text.txt", "r" );
    if( pFile == NULL )
    {
        //에러 처리
    }
    else
    {
        int nCount;
        float fRatio;
        char strDesc[255];
 
        while( !feof( pFile ) )
        {
            //공백으로 분리된 파일 읽기
            fscanf( pFile, "%d %f %s\n", &nCount, &fRatio, strDesc );
            printf( "공백으로 분리 : %d %f %s\n", nCount, fRatio, strDesc );
             
            //,로 분리된 파일 읽기
            fscanf( pFile, "%d, %f, %s\n", &nCount, &fRatio, strDesc );
            printf( ",로 분리 : %d, %f, %s\n", nCount, fRatio, strDesc );
 
            //탭으로 분리된 파일 읽기
            fscanf( pFile, "%d\t%f\t%s\n", &nCount, &fRatio, strDesc );
            printf( "탭으로 분리 : %d\t%f\t%s\n", nCount, fRatio, strDesc );
 
            //선별적으로 읽기 - [%*]을 사용하면 값을 읽지 않는다.
            fscanf( pFile, "%*d %*f %s\n", strDesc );
            printf( "선별적으로 읽기 : %s\n", strDesc );
        }
        fclose( pFile );
    }
    return 0;
}
==============================================================================
/* feof example: byte counter */
#include <stdio.h>

int main ()
{
  FILE * pFile;
  int n = 0;
  pFile = fopen ("myfile.txt","rb");
  if (pFile==NULL) perror ("Error opening file");
  else
  {
    while (fgetc(pFile) != EOF) {
      ++n;
    }
    if (feof(pFile)) {
      puts ("End-of-File reached.");
      printf ("Total number of bytes read: %d\n", n);
    }
    else puts ("End-of-File was not reached.");
    fclose (pFile);
  }
  return 0;
}
==============================================================================
/* log example */
#include <stdio.h>      /* printf */
#include <math.h>       /* log */

int main ()
{
  double param, result;
  param = 5.5;
  result = log (param);
  printf ("log(%f) = %f\n", param, result );
  return 0;
}

Output:
log(5.500000) = 1.704748
==============================================================================
/* pow example */
#include <stdio.h>      /* printf */
#include <math.h>       /* pow */

int main ()
{
  printf ("7 ^ 3 = %f\n", pow (7.0, 3.0) );
  printf ("4.73 ^ 12 = %f\n", pow (4.73, 12.0) );
  printf ("32.01 ^ 1.54 = %f\n", pow (32.01, 1.54) );
  return 0;
}

Output:
7 ^ 3 = 343.000000
4.73 ^ 12 = 125410439.217423
32.01 ^ 1.54 = 208.036691
==============================================================================
The smallest integral value that is not less than x (as a floating-point value).
/* ceil example */
#include <stdio.h>      /* printf */
#include <math.h>       /* ceil */

int main ()
{
  printf ( "ceil of 2.3 is %.1f\n", ceil(2.3) );
  printf ( "ceil of 3.8 is %.1f\n", ceil(3.8) );
  printf ( "ceil of -2.3 is %.1f\n", ceil(-2.3) );
  printf ( "ceil of -3.8 is %.1f\n", ceil(-3.8) );
  return 0;
}

Output:
ceil of 2.3 is 3.0
ceil of 3.8 is 4.0
ceil of -2.3 is -2.0
ceil of -3.8 is -3.0
==============================================================================

  /* sqrt example */
#include <stdio.h>      /* printf */
#include <math.h>       /* sqrt */

int main ()
{
  double param, result;
  param = 1024.0;
  result = sqrt (param);
  printf ("sqrt(%f) = %f\n", param, result );
  return 0;
}

Output:
sqrt(1024.000000) = 32.000000
==============================================================================
/* round vs floor vs ceil vs trunc */
#include <stdio.h>      /* printf */
#include <math.h>       /* round, floor, ceil, trunc */

int main ()
{
  const char * format = "%.1f \t%.1f \t%.1f \t%.1f \t%.1f\n";
  printf ("value\tround\tfloor\tceil\ttrunc\n");
  printf ("-----\t-----\t-----\t----\t-----\n");
  printf (format, 2.3,round( 2.3),floor( 2.3),ceil( 2.3),trunc( 2.3));
  printf (format, 3.8,round( 3.8),floor( 3.8),ceil( 3.8),trunc( 3.8));
  printf (format, 5.5,round( 5.5),floor( 5.5),ceil( 5.5),trunc( 5.5));
  printf (format,-2.3,round(-2.3),floor(-2.3),ceil(-2.3),trunc(-2.3));
  printf (format,-3.8,round(-3.8),floor(-3.8),ceil(-3.8),trunc(-3.8));
  printf (format,-5.5,round(-5.5),floor(-5.5),ceil(-5.5),trunc(-5.5));
  return 0;
}

Output:
value   round   floor   ceil    trunc
-----   -----   -----   ----    -----
 2.3     2.0     2.0     3.0     2.0
 3.8     4.0     3.0     4.0     3.0
 5.5     6.0     5.0     6.0     5.0
-2.3    -2.0    -3.0    -2.0    -2.0
-3.8    -4.0    -4.0    -3.0    -3.0
-5.5    -6.0    -6.0    -5.0    -5.0
==============================================================================

==============================================================================

==============================================================================

==============================================================================

==============================================================================

==============================================================================

==============================================================================

==============================================================================

==============================================================================

==============================================================================

==============================================================================

==============================================================================

==============================================================================

==============================================================================

==============================================================================

==============================================================================

==============================================================================

