#ifndef WORKER_H
#define WORKER_H

#include <string>
#include <unordered_map>
#include <vector>
#include "TaskManager.h"

struct TaskInfo;

class Worker {
private:
    std::string name;
    std::string role;
    float utility;
    std::unordered_map<std::string, int> skills;

public:
    Worker(std::string name, std::string role, std::unordered_map<std::string, int> skills);
    std::string getName() const;
    std::string choose_task(const std::vector<std::string>& available_tasks, int worker_count, int optimal_worker_count);
};

#endif
