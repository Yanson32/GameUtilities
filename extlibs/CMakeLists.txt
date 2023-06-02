
#Build testing library if GU_BUILD_TESTING is defined
if(GU_BUILD_TESTING)
    add_subdirectory("Catch2")
endif()
