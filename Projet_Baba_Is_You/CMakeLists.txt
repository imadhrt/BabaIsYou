cmake_minimum_required(VERSION 3.24)
project(Projet_Baba_Is_You)

set(CMAKE_CXX_STANDARD 20)

add_executable(Projet_Baba_Is_You sourceFile/controller/main.cpp
        headerFile/model/position.h headerFile/model/direction.h enum_to_class_to_enum.pro
        headerFile/model/enum.h headerFile/model/board.h headerFile/model/tiles.h headerFile/model/element.h
        headerFile/model/materials.h headerFile/model/words.h
        headerFile/model/subject.h
        headerFile/model/operator.h headerFile/model/complement.h
        headerFile/model/levelLoader.h sourceFile/model/board.cpp
        sourceFile/model/complement.cpp sourceFile/model/element.cpp
        sourceFile/model/levelLoader.cpp
        sourceFile/model/materials.cpp sourceFile/model/operator.cpp
        sourceFile/model/subject.cpp sourceFile/model/tiles.cpp
        sourceFile/model/words.cpp
        headerFile/model/rule.h sourceFile/model/rule.cpp
        headerFile/model/ruleManager.h sourceFile/model/ruleManager.cpp headerFile/model/managerCommand.h
        sourceFile/model/managerCommand.cpp headerFile/model/babaisyou.h sourceFile/model/babaIsYou.cpp headerFile/view/view.h
        sourceFile/view/view.cpp headerFile/controller/controller.h sourceFile/controller/controller.cpp headerFile/util/observer.h
        headerFile/util/observable.h headerFile/model/command.h headerFile/model/moveCommand.h sourceFile/model/moveCommand.cpp)
