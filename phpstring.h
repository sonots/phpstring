/**
 * C++ phpstring library
 *
 * This library provides c++ string functions similar to php's string functions.
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
    std::string::size_type strlen( const std::string& str );
    std::string substr( const std::string& str, std::string::size_type offset, std::string::size_type len = std::string::npos );
    std::string::size_type strpos( const std::string& str, const std::string& needle );
    std::string::size_type strrpos( const std::string& str, const std::string& needle );
    int strcmp( const std::string& str1, const std::string& str2 );
    int strncmp( const std::string& str1, const std::string& str2, std::string::size_type len );
    std::string sprintf( const char* format, ...);
    std::string trim( const std::string& str );
    std::string rtrim( const std::string& str );
    std::string ltrim( const std::string& str );
    std::string strrev( const std::string& str );
    std::string strtoupper( const std::string& str ); 
    std::string strtolower( const std::string& str );
    std::string strstr( const std::string& str, const std::string& needle, bool before );
    std::string strreplace( const std::string& str, const std::string& pattern, const std::string& replace );
    std::string basename( const std::string& path );
    std::string dirname( const std::string& path );
    std::string extension( const std::string& path );
    std::string filename( const std::string& path );
    std::string realpath( const std::string& path );
}

#endif
