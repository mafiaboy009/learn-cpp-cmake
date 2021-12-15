#https://cppsecrets.com/users/36681111069711511910546971161041031049711497575664103109971051084699111109/Ubuntu-install-poco-C00-library-Linux.php

project( learn-cpp-framework-poco )

find_package(Poco REQUIRED Crypto)

set(
    src1
    poco01.cpp
    )

set(
    src2
    poco02.cpp
    )

set(
    header
    )

add_executable(
    frameworkPoco1
    ${src1}
    ${header}
    )

add_executable(
    frameworkPoco2
    ${src2}
    ${header}
    )

target_link_libraries( frameworkPoco1 PUBLIC Poco::Crypto)
