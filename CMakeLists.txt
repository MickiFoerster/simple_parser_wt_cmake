cmake_minimum_required (VERSION 2.8)

find_program(BISON bison)
find_program(FLEX flex)
message(STATUS "flex: ${FLEX}")
message(STATUS "bison: ${BISON}")
# Exec Yacc
set(BISON_SRC parser.ypp)
set(BISON_OUT_CPP parser.tab.cpp)
set(BISON_OUT_H   parser.tab.h)

add_custom_command(
	OUTPUT ${BISON_OUT_CPP} ${BISON_OUT_H}
	COMMAND ${BISON} ARGS --defines=${BISON_OUT_H} ${BISON_SRC}
	DEPENDS ${BISON_SRC}
	)
set(GENERATED_SRCS ${GENERATED_SRCS} ${BISON_OUT_CPP} ${BISON_OUT_H} )

# Exec Lex
set(FLEX_SRC scanner.lpp)
set(FLEX_OUT_CPP scanner.cpp)
add_custom_command(
	OUTPUT ${FLEX_OUT_CPP}
	COMMAND ${FLEX} ARGS -o${FLEX_OUT_CPP} ${FLEX_SRC}
	DEPENDS ${FLEX_SRC}
	)
set(GENERATED_SRCS ${GENERATED_SRCS} ${FLEX_OUT_CPP})

# Tell CMake that some files are generated
set_source_files_properties(${GENERATED_SRCS} PROPERTIES GENERATED TRUE)


set (EXESRC ${EXESRC} ${FLEX_OUT_CPP})
set (EXESRC ${EXESRC} ${BISON_OUT_CPP})
set (EXESRC ${EXESRC} main.cpp)

add_executable (main ${EXESRC})
 
