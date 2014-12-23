cmake_minimum_required(VERSION 2.8)
#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
add_custom_command(OUTPUT
    lexer.cc
    COMMAND /usr/local/bin/ragel -C -o lexer.cc "${CMAKE_CURRENT_SOURCE_DIR}/lex/lexer.rl"
    COMMAND cp  lexer.cc "${CMAKE_CURRENT_BINARY_DIR}/lexer.cc"
    WORKING_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/lex"
    DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/lex/lexer.rl"
    )
	
IF (EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/parser/lemon-parser.cc)
    FILE(REMOVE "${CMAKE_CURRENT_SOURCE_DIR}/parser/lemon-parser.cc")
ENDIF()
add_custom_command(OUTPUT
    lemon-parser.cc
    COMMAND /usr/local/bin/lemon -sb "${CMAKE_CURRENT_SOURCE_DIR}/parser/lemon-parser.lm"
    #COMMAND rm    "${CMAKE_CURRENT_SOURCE_DIR}/parser/lemon-parser.out"
    COMMAND mv    "${CMAKE_CURRENT_SOURCE_DIR}/parser/lemon-parser.c" "${CMAKE_CURRENT_SOURCE_DIR}/parser/lemon-parser.cc"
    COMMAND cp    "${CMAKE_CURRENT_SOURCE_DIR}/parser/lemon-parser.h" "${CMAKE_CURRENT_BINARY_DIR}/lemon-parser.h"
    COMMAND cp    "${CMAKE_CURRENT_SOURCE_DIR}/parser/lemon-parser.cc" "${CMAKE_CURRENT_BINARY_DIR}/lemon-parser.cc"
    WORKING_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/parser"
    DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/parser/lemon-parser.lm"
)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/lex)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/parser)

set(uModLexer_SOURCES
    lexer.cc
    lex/lexeme.h
    lex/lexer.h
    lex/types.h
    parser/lemon-parser.h
    lex/lexeme.cc
	lex/lexer.rl
	)

set(uModParser_SOURCES
     lemon-parser.cc
     parser/exception.cc
     parser/exception.h
     parser/parser.h
     parser/parser.cc
     parser/lemon-parser.lm
     parser/ast/node.h
     parser/ast/tools/visitor.h
	)

#add_executable(uModLexer ${uModLexer_SOURCES} lex/main.cc)
add_library(uModLexer STATIC ${uModLexer_SOURCES})
add_library(uModParser STATIC ${uModParser_SOURCES})
