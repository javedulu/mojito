cmake_minimum_required(VERSION 2.8)

add_custom_command(OUTPUT
    lexer.cc
    COMMAND /usr/local/bin/ragel -C -o lexer.cc "${CMAKE_CURRENT_SOURCE_DIR}/lex/lexer.rl"
    COMMAND cp  lexer.cc "${CMAKE_CURRENT_BINARY_DIR}/lexer.cc"
    WORKING_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/lex"
    DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/lex/lexer.rl"
    )
	
add_custom_command(OUTPUT
    lemon-parser.cc
    COMMAND lemon "${CMAKE_CURRENT_SOURCE_DIR}/parser/lemon-parser.lm"
    COMMAND rm    "${CMAKE_CURRENT_SOURCE_DIR}/parser/lemon-parser.out"
    COMMAND mv    "${CMAKE_CURRENT_SOURCE_DIR}/parser/lemon-parser.h" "${CMAKE_CURRENT_BINARY_DIR}/lemon-parser.h"
    COMMAND mv    "${CMAKE_CURRENT_SOURCE_DIR}/parser/lemon-parser.c" "${CMAKE_CURRENT_BINARY_DIR}/lemon-parser.cc"
    DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/parser/lemon-parser.lm")

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/lex)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/parser)

set(uModParser_SOURCES
    lexer.cc
    lex/lexeme.h
    lex/lexer.h
    lex/types.h
    lex/lemon-parser.h
    lex/lexeme.cc
	lex/lexer.rl
	)

add_library(uModParser STATIC ${uModParser_SOURCES})
