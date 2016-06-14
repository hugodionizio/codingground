#include <stdio.h>
#include <string.h>

main()
{
   FILE *fp;
   char buff[255];

   fp = fopen("input.txt", "r");
   if( fp != NULL ){
      while ( !feof(fp ) ){
         memset(buff, '\0', sizeof( buff) );
         fgets(buff, 255, (FILE*)fp);
         printf("%s", buff );
      }
      fclose(fp);
   }
}

