aux_source_directory(. SRC_LIST)

include_directories(libgraphics simpleGUI)

aux_source_directory(libgraphics SRC_LIST1)
aux_source_directory(simpleGUI SRC_LIST2)

add_executable(main ${SRC_LIST} ${SRC_LIST1} ${SRC_LIST2})

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
