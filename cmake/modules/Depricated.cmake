#include_directories is depricated
macro(include_directories)
	message(DEPRICATION "\nInclude directories should not be used.\n Use target include directories instead")
	_include_directories($[ARGV])
endmacro()

#add_compile_options is depricated
macro(add_compile_options)
	message(DEPRICATION "\nadd_compile_options should not be used.")
	_add_compile_options($[ARGV])
endmacro()

#link_directories is depricated
macro(link_directories)
	message(DEPRICATION "\nlink_directories should not be used.")
	_link_directories($[ARGV])
endmacro()

#link_libraries is depricated
macro(link_libraries)
	message(DEPRICATION "\nlink_libraries should not be used.")
	_link_libraries($[ARGV])
endmacro()
