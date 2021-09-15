#include <stdio.h>
#include <stdlib.h>
#include <process.h>
#include <errno.h>
#include "my_function.h"

void test_f( void )
{
    char psBuffer[128];
    FILE *pPipe = _popen( "c:\\windows\\system32\\dism.exe /online /get-drivers /format:table", "rt" );
    if( pPipe == NULL ) exit( 1 );

    int i = 0;
    while(fgets(psBuffer, 128, pPipe))
    {
        printf(psBuffer);
    }
    
    _pclose( pPipe );
}

int main( int argc, char *argv[], char **envp )
{
    // char buffer[200];

    // sprintf( buffer, "It's %s \n", *argv);

    // printf( buffer );

    // test_f();

    // printf( "Got there\n");

 int count;

    // Display each command-line argument.
    printf( "\nCommand-line arguments:\n" );
    for( count = 0; count < argc; count++ )
        printf( "  argv[%d]   %s\n", count, argv[count] );

    // Display each environment variable.
    printf( "\nEnvironment variables:\n" );
    while( *envp != NULL )
        printf( "  %s\n", *(envp++) );

        system ( "pause" );

    exit( 0 );
}
