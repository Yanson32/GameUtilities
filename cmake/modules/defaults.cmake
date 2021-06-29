include_guard()

#set custom module path
if(CMAKE_MODULE_PATH)   
    set(CMAKE_MODULE_PATH "${CMAKE_MODULE_PATH}" "${CMAKE_CURRENT_LIST_DIR}" CACHE STRING "All cmake modules can be found in this path")
else()
    set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}" CACHE STRING "All cmake modules can be found in this path")
endif()


