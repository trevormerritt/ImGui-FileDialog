# Version 3.17 needed because of the use of ZIP_LISTS in the git submodules.
cmake_minimum_required(VERSION 3.17)

project(
  ImGuiFileDialog
  VERSION 0.0.2
  LANGUAGES C CXX
  DESCRIPTION "ImGuiFileDialog Widget * FORKED *")
set (CMAKE_CXX_STANDARD 17)

set(LIB_NAME ImGuiFileDialog)
set(SRC_FILES
        src/imgui_filedialog.cpp
)

include(FetchContent)
FetchContent_Declare(imgui
        GIT_REPOSITORY https://github.com/ocornut/imgui
        GIT_TAG master
)
FetchContent_MakeAvailable(imgui)

if(CMAKE_CURRENT_SOURCE_DIR STREQUAL CMAKE_SOURCE_DIR)
    message(STATUS "BUILDING DIRECTLY")
elseif ()
    message(STATUS "Building as Library")
endif ()

message(STATUS "Building directly")
add_library(${LIB_NAME} STATIC ${SRC_FILES})
target_include_directories(${LIB_NAME} PRIVATE ${imgui_SOURCE_DIR})
target_link_libraries(${LIB_NAME} PRIVATE imgui)
set_target_properties(${LIB_NAME} PROPERTIES VERSION ${PROJECT_VERSION})
set_target_properties(${LIB_NAME} PROPERTIES SOVERSION ${PROJECT_VERSION_MAJOR})
set_target_properties(${LIB_NAME} PROPERTIES PUBLIC_HEADER src/imgui_filedialog.h)
include(GNUInstallDirs)
install(TARGETS ${LIB_NAME} LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR} PUBLIC_HEADER DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})
configure_file(src/imgui_filedialog.pc.in ${CMAKE_INSTALL_LIBDIR}/imgui_filedialog.pc @ONLY)
install(FILES ${CMAKE_BINARY_DIR}/imgui_filedialog.pc DESTINATION ${CMAKE_INSTALL_LIBDIR}/pkgconfig)
install(TARGETS ${LIB_NAME} DESTINATION lib)
install(FILES ${LIB_NAME}
        src/imgui_filedialog.h
        DESTINATION include
)
