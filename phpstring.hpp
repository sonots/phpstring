/** @file
 * C++ phpstring library
 *
 * This is a header-only library which provides c++ string functions
 * similar to php's string functions. This requires only typical libraries.
 *
 * @link http://docs.google.com/View?id=drw35kw_20g32df6cz
 * @requirements <stdio>, <string>, <vector>
 * @author Naotoshi Seo <sonots(at)sonots.com>
 * @version v1.0 2008/08/31
 *
 * The MIT License
 * 
 * Copyright (c) 2008, Naotoshi Seo <sonots(at)sonots.com>
 * 
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */
#ifndef _PHPSTRING_H
#define _PHPSTRING_H

#include <stdio.h>
#include <stdarg.h>
#include <string>
#include <vector>
#ifndef _MSC_VER
#include <unistd.h>
#endif
#include <limits.h>

namespace phpstring 
{
#if defined(_WIN32) || defined(_WIN64)
    std::string directory_sep = "\\";
#else
    std::string directory_sep = "/";
#endif

    inline std::string::size_type strlen( const std::string& str )
    {
        return str.size();
    }
    inline std::string substr( const std::string& str, std::string::size_type offset, 
                               std::string::size_type len = std::string::npos )
    {
        return std::string( str, offset, len );
    }
    inline std::string::size_type strpos( const std::string& str, const std::string& needle,
                                          const std::string::size_type offset = 0 )
    {
        return str.find( needle, offset );
    }
    inline std::string::size_type strrpos( const std::string& str, const std::string& needle,
                                           const std::string::size_type offset = 0 )
    {
        return str.rfind( needle, offset );
    }
    inline int strcmp( const std::string& str1, const std::string& str2 )
    {
        return str1.compare( str2 );
    }
    inline int strncmp( const std::string& str1, const std::string& str2, 
                        std::string::size_type len )
    {
        return str1.compare( 0, len, str2 );
    }

    std::string sprintf( const std::string& format, ...)
    {
        char str[2048]; // hmm
        va_list ap;
        va_start(ap, format);
        vsprintf(str, format.c_str(), ap);
        va_end(ap);
        return std::string( str );
    }

    std::string trim( const std::string& str )
    {
        if( str.length() == 0 ) return str;
        std::string::size_type l = str.find_first_not_of( " \t\r\n" );
        std::string::size_type r = str.find_last_not_of( " \t\r\n" );
        if( l == std::string::npos ) return std::string(); // only whitespaces
        return std::string( str, l, r - l + 1 );
    }

    std::string rtrim( const std::string& str )
    {
        if( str.length() == 0 ) return str;
        std::string::size_type r = str.find_last_not_of( " \t\r\n" );
        if( r == std::string::npos ) return std::string(); // only whitespaces
        return std::string( str, 0, r );
    }

    std::string ltrim( const std::string& str )
    {
        if( str.length() == 0 ) return str;
        std::string::size_type l = str.find_first_not_of( " \t\r\n" );
        if( l == std::string::npos ) return std::string(); // only whitespaces
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
        while( ( pos = ret.find(pattern, pos) ) != std::string::npos ) {
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

    // no .
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
        // @todo: resolve ./ and ../ 
#if defined(_WIN32) || defined(_WIN64)
        return strreplace( path, "/", "\\" );
#else
        return strreplace( path, "\\", "/" );
#endif
//        char cwd[MAX_PATH];
//#ifdef _MSC_VER
//        _getcwd( cwd, MAX_PATH );
//#else
//        getcwd( cwd, MAX_PATH );
//#endif
    }

    std::vector<std::string> explode( const std::string& str, const std::string& delim )
    {
        std::vector<std::string> splits;
        std::string::size_type start = 0;
        std::string::size_type end = 0;
        std::string::size_type delimsize = delim.size();
        while( 1 ) {
            end = str.find( delim, start + 1 );
            if( end == std::string::npos ) break;
            splits.push_back( std::string( str, start, end - start ) );
            start = end + delimsize;
        }
        splits.push_back( substr( str, start ) );
        return splits;
    }
    
    std::string implode( const std::vector<std::string>& strs, const std::string& glue )
    {
        std::string str;
        std::string::size_type i;
        for( i = 0; i < strs.size() - 1; i++ ) {
            str += strs[i] + glue;
        }
        str += strs[i];
        return str;
    }

    bool in_array( const std::vector<std::string>& array,
                   const std::string& needle )
    {
        std::string::size_type i;
        for( i = 0; i < array.size() - 1; i++ ) {
            if( needle == array[i] ) return true;
        }
        return false;
    }
}
#endif
