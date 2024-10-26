if(NOT TARGET Boost::boost)
  return()
endif()

message(STATUS "libremidi: Network support using Boost.ASIO")
set(LIBREMIDI_HAS_BOOST_ASIO 1)
set(LIBREMIDI_HAS_NETWORK 1)

target_compile_definitions(libremidi
  ${_public}
    LIBREMIDI_NETWORK
)
target_link_libraries(libremidi
  ${_public}
    $<BUILD_INTERFACE:Boost::boost>
)

# Calling aligned_alloc in pre 10.15 just reuslts in a crash
if(APPLE)
  if(CMAKE_OSX_DEPLOYMENT_TARGET)
    if(CMAKE_OSX_DEPLOYMENT_TARGET VERSION_LESS 10.15)
      target_compile_definitions(libremidi
        ${_public} BOOST_ASIO_DISABLE_STD_ALIGNED_ALLOC=1)
    endif()
  endif()
endif()

# Incompetent versions
if(Boost_VERSION VERSION_LESS 1.81)
  target_compile_definitions(libremidi
    ${_public}
      BOOST_ASIO_DISABLE_CONCEPTS=1
  )
endif()

# Workaround for boost being broken with clang 13
# (at least until 1.77) - confirmed still broken in 1.86
if (CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
  if (CMAKE_CXX_COMPILER_VERSION VERSION_GREATER_EQUAL 13.0)
    target_compile_definitions(libremidi
      ${_public}
        BOOST_ASIO_HAS_STD_INVOKE_RESULT=1
    )
  endif()
endif()