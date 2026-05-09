## collect all source files in the project
# set(CALCULATOR_SOURCES
#   Calculator.cpp
#   Physics.cpp
#   sub1/Foo.cpp
#   sub1/Bar.cpp
#   sub2/Baz.cpp
# )
file(GLOB_RECURSE ALL_SOURCES CONFIGURE_DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp")
list(REMOVE_ITEM ALL_SOURCES
  "${CMAKE_CURRENT_SOURCE_DIR}/main.cpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/export.cpp"
)

if(BUILD_LIB)
  add_library(LIB SHARED ${ALL_SOURCES} export.cpp)
  target_include_directories(LIB PUBLIC
      ${CMAKE_CURRENT_SOURCE_DIR}
  )
  target_compile_features(LIB PUBLIC cxx_std_14)
  enable_project_warnings(LIB)
  target_compile_definitions(LIB
    PRIVATE PROJECT_BUILDING
    PUBLIC  PROJECT_SHARED
  )
  if(CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
    target_compile_options(LIB PRIVATE -fvisibility=hidden)
  endif()
else()
  add_executable(MAIN ${ALL_SOURCES} main.cpp)
  target_include_directories(MAIN PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
  target_compile_features(MAIN PRIVATE cxx_std_14)
  enable_project_warnings(MAIN)
endif()