#include "test_function.h"

// Todo:
// 将 pPipe 运行得到的输出存储起来。
void tf_test( void )
{
    char psBuffer[128];
    FILE *pPipe = _popen( "c:\\windows\\system32\\pnputil.exe -?", "rt" );
    if( pPipe == NULL ) exit( 1 );

    while(fgets(psBuffer, 128, pPipe))
    {
        printf(psBuffer);
    }
    
    _pclose( pPipe );
}

