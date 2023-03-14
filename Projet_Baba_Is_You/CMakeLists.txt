cmake_minimum_required(VERSION 3.24)
project(Projet_Baba_Is_You)

set(CMAKE_CXX_STANDARD 20)

add_executable(Projet_Baba_Is_You sourceFile/controller/main.cpp headerFile/model/position.h headerFile/model/direction.h enum_to_class_to_enum.pro headerFile/model/enum.h headerFile/model/board.h headerFile/model/tiles.h headerFile/model/element.h)
