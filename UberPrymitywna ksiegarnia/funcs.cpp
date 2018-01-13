#include "funcs.h"

string magic( const std::string & str, const char ch, const unsigned int v )
{
    std::string ret = "";
    for( size_t i = 0, tmp = 0; i < str.size(); ++i ) {
        if( str[ i ] == ch ) {
            if( tmp > v ) break;
            else ++tmp;
            
        }
        else if( tmp == v ) ret += str[ i ];
        
    }
    return ret;
}