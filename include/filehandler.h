#pragma once
#include <string>
#include <sstream>
#include <fstream>
#include <vector>
#include "task.h"

class FileHandler{
private:
  std::string filepath;
  char separator;

  [[nodiscard]] auto parseTaskFromLine(const std::string& line) const -> Task;
  [[nodiscard]] auto isValidTaskLine(const std::string& line) const -> bool;

public:
  FileHandler(const std::string& filename);
  FileHandler(const std::string& filename, char separator);

  auto saveToFile(std::vector<Task>& tasks) -> bool;
  auto appendTask(Task& task) -> bool;

  auto loadFromFile() -> std::vector<Task>;
  [[nodiscard]] auto fileExist() const -> bool;
  [[nodiscard]] auto isEmpty() const -> bool;

};
