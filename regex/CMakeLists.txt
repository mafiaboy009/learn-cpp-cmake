project( learn-cpp-regex )

set( header )

set( src1 
    regex-match-01.cpp
    )

set( src2 
    regex-match-02.cpp
    )

set( src3 
    regex-search-01.cpp
)

set( src4 
    regex-replace-01.cpp
)

set( src5
    regex-application-emailIDValidation.cpp
)

set( src6 
    regex-application-imageFilenameValidation.cpp
)

set( src7 
    regex-application-inputValidation.cpp
)

add_executable( regex-match-01
    ${src1}
    ${header} 
)

add_executable( regex-match-02
    ${src2}
    ${header} 
)

add_executable( regex-search-01
    ${src3}
    ${header} 
)

add_executable( regex-replace-01
    ${src4}
    ${header} 
)

add_executable( regex-app-emailIDValidation
    ${src5}
    ${header} 
)

add_executable( regex-app-imageFilenameValidation
    ${src6}
    ${header} 
)

add_executable( regex-app-inputValidation
    ${src7}
    ${header} 
)
