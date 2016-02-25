cmake_minimum_required(VERSION 2.8.3)
project(dsp_filter)

## Find catkin macros and libraries
## if COMPONENTS list like find_package(catkin REQUIRED COMPONENTS xyz)
## is used, also find other catkin packages
find_package(catkin REQUIRED COMPONENTS
  roscpp
  rospy
  std_msgs
)

find_package(Boost REQUIRED)



###################################
## catkin specific configuration ##
###################################
## The catkin_package macro generates cmake config files for your package
## Declare things to be passed to dependent projects
## INCLUDE_DIRS: uncomment this if you package contains header files
## LIBRARIES: libraries you create in this project that dependent projects also need
## CATKIN_DEPENDS: catkin_packages dependent projects also need
## DEPENDS: system dependencies of this project that dependent projects also need
catkin_package(
  INCLUDE_DIRS include
  LIBRARIES  dsp_filter
  DEPENDS Boost 
)

###########
## Build ##
###########

## Specify additional locations of header files
## Your package locations should be listed before other locations
include_directories(
  include
  ${catkin_INCLUDE_DIRS}
  ${Boost_INCLUDE_DIRS}
)
link_directories(${catkin_LIBRARY_DIRS})


## Declare a cpp library
add_library(dsp_filter
   src/Bessel.cpp
   src/Biquad.cpp
   src/Butterworth.cpp
   src/Cascade.cpp
   src/ChebyshevI.cpp
   src/ChebyshevII.cpp
   src/Custom.cpp
   src/Elliptic.cpp
   src/Legendre.cpp
   src/PoleFilter.cpp
   src/RBJ.cpp
   src/RootFinder.cpp
   src/State.cpp
 )


## Add cmake target dependencies of the executable/library
## as an example, message headers may need to be generated before nodes
# add_dependencies(xio_reader_node xio_reader_generate_messages_cpp)

## Specify libraries to link a library or executable target against
target_link_libraries(dsp_filter
  ${catkin_LIBRARIES} ${Boost_LIBRARIES}
)

add_executable(filter_test node/filter_test.cpp)
target_link_libraries(filter_test dsp_filter)

install(TARGETS dsp_filter
  ARCHIVE DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
  LIBRARY DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
  RUNTIME DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION})

install(TARGETS filter_test 
  ARCHIVE DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
  LIBRARY DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
  RUNTIME DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION})



