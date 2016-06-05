project(assignment)

set(HEADER_FILES
        LargeNumber.h
        Math.h
        Number.h
        SmallNumber.h)

set(SOURCE_FILES
        LargeNumber.cpp
        Math.cpp
        Number.cpp
        SmallNumber.cpp DoublyLinkedList.cpp DoublyLinkedList.h)

add_library(assignment STATIC ${SOURCE_FILES} ${HEADER_FILES})