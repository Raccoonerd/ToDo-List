#pragma once
#include <string>
#include <sstream>

class Task{
private:
    static int nextId;
    int id;
    std::string description;
    bool isCompleted;

public:
    Task(std::string& desc);
    
    [[nodiscard]] auto getId() const -> int;
    [[nodiscard]] auto getIsCompleted() const -> bool;
    [[nodiscard]] auto getDescription() const -> std::string;
    
    void toggleCompleted();

    [[nodiscard]] auto toString() const -> std::string;
    [[nodiscard]] auto toFileString() const -> std::string;
};
