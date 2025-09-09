#include "../include/filehandler.h"
#include <iostream>
#include <string>

FileHandler::FileHandler(const std::string &filename)
    : filepath(filename), separator('|') {}

FileHandler::FileHandler(const std::string &filename, char a_separator)
    : filepath(filename), separator(a_separator) {}

auto FileHandler::parseTaskFromLine(const std::string& line) const -> Task{
  std::vector<std::string> parts;
  std::stringstream sst(line);
  std::string part;

  while (std::getline(sst, part, separator)) {
    parts.push_back(part);   
  }

  if (parts.size()<3) {
    throw std::invalid_argument("Too few parts in line"); 
  }

  int l_id = std::stoi(parts.at(0));
  std::string l_description = parts.at(1);
  bool l_completed = (parts.at(2) == "1");

  return {l_id, l_description, l_completed};
}


auto FileHandler::saveToFile(std::vector<Task>& tasks) -> bool{
  std::ofstream file(filepath);

  try {
    std::ofstream file("output.txt");
    if (!file.is_open()) {
    throw std::runtime_error("Could not open file");
    }

    for (const auto& task : tasks) {
            file << task.toFileString() << '\n';
        }
        
        file.close();
        return true;
    }
  catch (const std::exception& e) {
    std::cerr << "Error while saving: " << e.what() << '\n';
  }

  return false;
}
