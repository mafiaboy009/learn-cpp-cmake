project( learn-cpp-desgin-pattern-behavioural-mediator )

set(
    src
    mediator.cpp
    )

set(
    header
    mediator.hpp
    )

add_executable(
    designPatternBehaviouralMediator
    ${src}
    ${header}
    )
