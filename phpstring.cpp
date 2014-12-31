/**
* C++ phpstring library
*
* This is a header-only library which provides c++ string functions
* similar to php's string functions. This requires only typical libraries.
*
* URL
*   http://docs.google.com/View?id=drw35kw_20g32df6cz
* Author(s)
 *   Naotoshi Seo <sonots(at)sonots.com>
 * License
 *   New BSD License
 * History
 *   2008/08/31 - First Edition
 *
 * Requirements
 *   <stdio>, <string>, <vector>
 */
#include <stdio.h>
#include <stdarg.h>
#include <string>
#include <vector>

#ifndef PHPSTRING_INCLUDED
#define PHPSTRING_INCLUDED

namespace phpstring
{
    std::string::size_type strlen( const std::string& str )
    {
        return str.size();
    }
    std::string substr( const std::string& str, std::string::size_type offset, std::string::size_type len = std::string::npos )
    {
        return std::string( str, offset, len );
    }
    std::string::size_type strpos( const std::string& str, const std::string& needle )
    {
        return str.find( needle );
    }
    std::string::size_type strrpos( const std::string& str, const std::string& needle )
    {
        return str.rfind( needle );
    }
    int strcmp( const std::string& str1, const std::string& str2 )
    {
        return str1.compare( str2 );
    }
    int strncmp( const std::string& str1, const std::string& str2, std::string::size_type len )
    {
        return str1.compare( 0, len, str2 );
    }
    std::string sprintf( const char* format, ...)
    {
        char s[2048]; // hmm
        va_list ap;
        va_start(ap, format);
        vsprintf(s, format, ap);
        va_end(ap);
        return std::string( s );
    }

    std::string trim( const std::string& str )
    {
        if( str.length() == 0 ) return str;
        std::string::size_type l = str.find_first_not_of( " \t\r\n" );
        std::string::size_type r = str.find_last_not_of( " \t\r\n" );
        if( l == -1 ) ""; // only whitespaces
        return std::string( str, l, r - l + 1 );
    }

    std::string rtrim( const std::string& str )
    {
        if( str.length() == 0 ) return str;
        std::string::size_type r = str.find_last_not_of( " \t\r\n" );
        if( r == -1 ) ""; // only whitespaces
        return std::string( str, 0, r );
    }

    std::string ltrim( const std::string& str )
    {
        if( str.length() == 0 ) return str;
        std::string::size_type l = str.find_first_not_of( " \t\r\n" );
        if( l == -1 ) ""; // only whitespaces
        return std::string( str, l );
    }

    std::string strrev( const std::string& str )
    {
        std::string ret;
        for( std::string::size_type i = str.size(); i >= 0; i-- )
        {
            ret += str[i];
        }
        return ret;
    }

    std::string strtoupper( const std::string& str )
    {
        std::string ret = str;
        //transform(ret.begin(), ret.end(), ret.begin(), toupper);
        for( std::string::size_type i = 0; i < ret.size(); i++ )
        {
            ret[i] = toupper(ret[i]);
        }
        return ret;
    }

    std::string strtolower( const std::string& str )
    {
        std::string ret = str;
        //transform(ret.begin(), ret.end(), ret.begin(), tolower);
        for( std::string::size_type i = 0; i < ret.size(); i++ )
        {
            ret[i] = tolower(ret[i]);
        }
        return ret;
    }

    std::string strstr( const std::string& str, const std::string& needle, bool before )
    {
        std::string::size_type pos = str.find( needle );
        if( pos == std::string::npos ) return "";
        if( before )
        {
            return std::string( str, 0, pos );
        }
        else
        {
            return std::string( str, pos + 1, std::string::npos );
        }
    }

    std::string strreplace( const std::string& str, const std::string& pattern, const std::string& replace )
    {
        std::string ret = str;
        std::string::size_type pos = 0;
        while(pos = ret.find(pattern, pos), pos != std::string::npos) {
            ret.replace(pos, pattern.length( ), replace);
            pos += replace.length();
        }
        return ret;
    }

    std::string basename( const std::string& path )
    {
#if defined(_WIN32) || defined(_WIN64)
        std::string directory_sep = "\\";
#else
        std::string directory_sep = "/";
#endif
        std::string::size_type pos = path.rfind( directory_sep );
        if( pos == std::string::npos ) return path;
        return std::string( path, pos + 1 );
    }

    std::string dirname( const std::string& path )
    {
#if defined(_WIN32) || defined(_WIN64)
        std::string directory_sep = "\\";
#else
        std::string directory_sep = "/";
#endif
        std::string::size_type pos = path.rfind( directory_sep );
        if( pos == std::string::npos ) return "";
        return std::string( path, 0, pos );
    }

    std::string extension( const std::string& path )
    {
        std::string::size_type pos = path.rfind(".");
        if( pos == std::string::npos ) return "";
        return std::string( path, pos + 1 );
    }

    std::string filename( const std::string& path )
    {
        std::string basename = phpstring::basename( path );
        std::string::size_type pos = basename.rfind(".");
        if( pos == std::string::npos ) return basename;
        return std::string( basename, 0, pos );
    }

    std::string realpath( const std::string& path )
    {
        // @todo: resolve ./ and ../ How to pwd?
#if defined(_WIN32) || defined(_WIN64)
        return strreplace( path, "/", "\\" );
#else
        return strreplace( path, "\\", "/" );
#endif
    }
}

#endif
