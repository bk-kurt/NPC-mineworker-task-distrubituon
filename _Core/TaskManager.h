#ifndef TASKMANAGER_H
#define TASKMANAGER_H

#include "TaskInfo.h"
#include <string>
#include <unordered_map>
#include <vector>

class TaskManager {
public:
    static bool TaskExists(const std::string& task_name);
    static void CompleteTask(const std::string& task_name, std::vector<std::string>& available_tasks);
    static float CalculateUtility(const std::string& task_name, const std::unordered_map<std::string, int>& worker_skills, int worker_count, int optimal_worker_count);

private:
    static std::unordered_map<std::string, TaskInfo> tasks_info;
    static std::unordered_map<std::string, float> utility_weights;

    TaskManager();
};

#endif
