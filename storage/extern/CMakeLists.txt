project( learn-cpp-storage-extern )

set(
    src
    main.cpp
    constants.cpp
    )

set(
    header
    constants.hpp
    )

add_executable(
    storageExtern
    ${src}
    ${header}
    )
