#ifndef TASKINFO_H
#define TASKINFO_H

#include <string>
#include <unordered_map>

struct TaskInfo {
    std::string type;
    int difficulty_level;
    int urgency_level;
    std::pair<int, int> location;

    TaskInfo(std::string type, int difficulty, int urgency, std::pair<int, int> loc)
        : type(type), difficulty_level(difficulty), urgency_level(urgency), location(loc) {}
};

#endif
