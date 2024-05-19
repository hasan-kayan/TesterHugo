#include "../include/structure_creator/structure.h"
#include <iostream>
#include <fstream>

int ProjectStructureCreator::createProjectBase(const std::string& projectName) {
    // Create project directory
    std::string projectDir = "./" + projectName;
    if (mkdir(projectDir.c_str(), 0777) != 0) {
        std::cerr << "Error: Failed to create project directory" << std::endl;
        return 1; // Return non-zero for failure
    }

    // Create CMakeLists.txt
    std::ofstream cmakeFile(projectDir + "/CMakeLists.txt");
    if (!cmakeFile.is_open()) {
        std::cerr << "Error: Failed to create CMakeLists.txt" << std::endl;
        return 1;
    }
    cmakeFile << "cmake_minimum_required(VERSION 3.0)\n";
    cmakeFile << "project(" << projectName << ")\n";
    cmakeFile.close();

    // Create main.cpp
    std::ofstream mainFile(projectDir + "/main.cpp");
    if (!mainFile.is_open()) {
        std::cerr << "Error: Failed to create main.cpp" << std::endl;
        return 1;
    }
    mainFile << "#include <iostream>\n\n";
    mainFile << "int main() {\n";
    mainFile << "    std::cout << \"Hello, " << projectName << "!\" << std::endl;\n";
    mainFile << "    return 0;\n";
    mainFile << "}\n";
    mainFile.close();

    // Create library and include folders
    std::string libraryDir = projectDir + "/library";
    std::string includeDir = projectDir + "/include";
    if (mkdir(libraryDir.c_str(), 0777) != 0 || mkdir(includeDir.c_str(), 0777) != 0) {
        std::cerr << "Error: Failed to create library and include directories" << std::endl;
        return 1;
    }

    // Create config.json
    std::ofstream configFile(projectDir + "/config.json");
    if (!configFile.is_open()) {
        std::cerr << "Error: Failed to create config.json" << std::endl;
        return 1;
    }
    configFile << "{\n";
    configFile << "    \"projectName\": \"" << projectName << "\"\n";
    configFile << "}\n";
    configFile.close();

    std::cout << "Basic project structure created for project: " << projectName << std::endl;
    return 0; // Return 0 for success
}
