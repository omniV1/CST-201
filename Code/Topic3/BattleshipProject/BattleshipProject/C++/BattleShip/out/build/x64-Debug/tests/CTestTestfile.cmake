# CMake generated Testfile for 
# Source directory: C:/git/CST-201/Code/Topic3/BattleshipProject/BattleshipProject/C++/BattleShip/tests
# Build directory: C:/git/CST-201/Code/Topic3/BattleshipProject/BattleshipProject/C++/BattleShip/out/build/x64-Debug/tests
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test([=[battleShip_gtests]=] "battleShip_test")
set_tests_properties([=[battleShip_gtests]=] PROPERTIES  _BACKTRACE_TRIPLES "C:/git/CST-201/Code/Topic3/BattleshipProject/BattleshipProject/C++/BattleShip/tests/CMakeLists.txt;19;add_test;C:/git/CST-201/Code/Topic3/BattleshipProject/BattleshipProject/C++/BattleShip/tests/CMakeLists.txt;0;")
subdirs("../_deps/googletest-build")
