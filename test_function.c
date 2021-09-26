#include "test_function.h"

// Todo:
// 将 pPipe 运行得到的输出存储起来。
// 2021.09.26: 从暂存中读取有用数据。
//      善用库：https://docs.microsoft.com/en-us/cpp/c-runtime-library/string-manipulation-crt?view=msvc-160
void tf_test( void )
{

    // 读取时触发，仅能触发一次。因此数据坐标不可用。
    FILE *pPipe = _popen( "c:\\windows\\system32\\pnputil.exe /enum-devices /drivers", "rt" );
    if( pPipe == NULL ) exit( 1 );

    // 可以用 FILE 中的暂存数据做处理，前提是遍历一次便可完成。
    // char psBuffer[128];
    // while( fgets( psBuffer, 128, pPipe ) )
    // {
    //     fputs( psBuffer, stdout );
    // }

    // 先存到局部变量中，分多次遍历保存所需要的数据。
    int numread = 0;
    char bbuffer[2097152]; // 预留 2 * 1024 * 1024 Byte = 1 MB
    char *pdest;
    int  result;
    char str[] = "Instance ID:";

    // 
    struct instance
    {
        int num;
        char name[64];
        char version[64];
        char used[64];
        char instance_id[64];
        char device_name[64];
        char device_status[64];
    };
    numread = fread( bbuffer, sizeof( char ), 2097152, pPipe );
    pdest = strstr( bbuffer, str );
    result = ( int )( pdest - bbuffer + 1 );
    _pclose( pPipe );

}

