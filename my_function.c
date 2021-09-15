#include "my_function.h"

// 用 _execlp 运行 cmd 命令，此命令会取代当前程序。
void exec_ping( void )
{
    _execlp( "c:\\windows\\system32\\ping", "ping", "baidu.com", NULL );
}

// 用 _popen 运行
void pipe_ping( void )
{
    char psBuffer[128];
    FILE *pPipe = _popen( "c:\\windows\\system32\\ping baidu.com", "rt" );
    if( pPipe == NULL ) exit( 1 );

    int i = 0;
    while(fgets(psBuffer, 128, pPipe))
    {
        printf(psBuffer);
    }
    
    _pclose( pPipe );
}
