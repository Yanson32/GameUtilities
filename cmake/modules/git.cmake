function(download_git_repo REPO_NAME GIT_REPO GIT_TAG)
    if(NOT GU_INSTALL_DEPENDENCIES)
        Include(FetchContent)

        #Download Catch2 library
        FetchContent_Declare(
          "${REPO_NAME}" 
          GIT_REPOSITORY "${GIT_REPO}" 
          GIT_TAG         "${GIT_TAG}"
        )

        FetchContent_MakeAvailable(Catch2)
    elseif(GU_INSTALL_DEPENDENCIES)
        message("Installing dependencies not implimented")
    endif()
endfunction()
