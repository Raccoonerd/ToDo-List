#include "../include/filehandler.h"
#include <fstream>
#include <iostream>
#include <stdexcept>
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

auto FileHandler::isValidTaskLine(const std::string& line) const -> bool{
  int l_id = 0;

  for(char znak : line){
    if (znak == separator) {
      l_id++;
    }
  }

  return l_id == 2;
}

auto FileHandler::saveToFile(std::vector<Task>& tasks) -> bool{
  std::ofstream file(filepath);

  try {
    if (!file.is_open()) {
      throw std::runtime_error("Could not open file");
    }

    for (const auto& task : tasks) {
      file << task.toFileString() << '\n';
    }
        
    file.close();
    return true;

  }catch (const std::exception& e) {
    std::cerr << "Error while saving: " << e.what() << '\n';
    return false;
  }
}

auto FileHandler::appendTask(Task& task) -> bool{
  std::ofstream file(filepath);

  try {
    if (!file.is_open()) {
      throw std::runtime_error("Could not open file");
    } 

    file<<task.toFileString()<<'\n';

    file.close();
    return true;

  } catch (const std::exception& e) {
    std::cerr << "Error while saving: " << e.what() << '\n';
    return false;
  }
}

auto FileHandler::loadFromFile() -> std::vector<Task>{
  std::vector<Task> tasks;
  std::ifstream file(filepath);

  try {
    if (!file.is_open()) {
      throw std::runtime_error("Could not open file");
      return tasks;
    }

    std::string line;
    int lineNum = 0;

    while (std::getline(file, line)) {
      ++lineNum;

      if (line.empty()) { continue; }

      if (isValidTaskLine(line)){
        tasks.emplace_back(parseTaskFromLine(line));

      } else {
        throw std::runtime_error("Invalid line " + std::to_string(lineNum) + ": " + line);
      } 
      
    }
  } catch (const std::exception& e) {
      std::cerr << "Error while loading tasks: "<< e.what() << '\n'; 
  }

  file.close();
  return tasks;
}
