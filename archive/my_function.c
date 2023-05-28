#include "my_function.h"

// 用 _execlp 运行 cmd 命令，此命令会取代当前程序。
// 其中 l 表示运行的参数逐个传送，e 代表用数组传送。
// p 代表使用当前环境变量。
void mf_ping_exec( void )
{
    _execlp( "c:\\windows\\system32\\ping", "ping", "baidu.com", NULL );
}

// 用 _popen 运行 cmd 命令，此命令不会取代当前程序。
void mf_ping_pipe( void )
{
    char psBuffer[128];
    FILE *pPipe = _popen( "c:\\windows\\system32\\ping baidu.com", "rt" );
    if( pPipe == NULL ) exit( 1 );

    while(fgets(psBuffer, 128, pPipe))
    {
        printf(psBuffer);
    }
    
    _pclose( pPipe );
}

// 测试用，输出当前运行环境变量。
// mf_print_env( argc, argv, envp );
void mf_print_env( int argc, char *argv[], char **envp )
{
    int count;

    // Display each command-line argument.
    printf( "\nCommand-line arguments:\n" );
    for( count = 0; count < argc; count++ )
        printf( "  argv[%d]   %s\n", count, argv[count] );

    // Display each environment variable.
    printf( "\nEnvironment variables:\n" );
    while( *envp != NULL )
        printf( "  %s\n", *(envp++) );
}

// 测试用，用 Dism 获取当前安装的所有驱动，需要管理员权限运行。
void mf_print_dism_driver_list( void )
{
    char psBuffer[128];
    FILE *pPipe = _popen( "c:\\windows\\system32\\dism.exe /online /get-drivers /format:table", "rt" );
    if( pPipe == NULL ) exit( 1 );

    while(fgets(psBuffer, 128, pPipe))
    {
        printf(psBuffer);
    }
    
    _pclose( pPipe );
}