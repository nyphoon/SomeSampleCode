/*****************************
 * test some MACROs:
 * __cplusplus __LINE__ __FILE__
 *
 * my environment:
 *    g++ i686-pc-cygwin/4.9.3
 *    gcc i686-pc-cygwin/4.9.3
 *
 * __cpluspllus:
 *     g++ sample_macro.c -> version C++
 *     gcc sample_macro.c -> version C
 * **************************/
#ifdef __cplusplus

//C++
#include<iostream>
using namespace std;
int main()
{
    cout<<"version C++"<<endl;
    cout<<__LINE__<<endl;
    cout<<__FILE__<<endl;
    return 0;
}

#else
//C
#include<stdio.h>
int main()
{
    printf("%s\r\n", "version C");
    printf("%s\r\n", __LINE__);
    printf("%s\r\n", __FILE__);

    return 0;
}
#endif // __cplusplus

