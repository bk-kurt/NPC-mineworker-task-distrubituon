#include "TaskManager.h"
#include <iostream>

std::unordered_map<std::string, TaskInfo> TaskManager::tasks_info = {
    {"mine_gold", {"mining", 2, 3, {10, 20}}},
    {"fetch_vehicle", {"transport", 1, 2, {5, 15}}}
};

std::unordered_map<std::string, float> TaskManager::utility_weights = {
    {"distance", -1},
    {"urgency", 2},
    {"saturation", -1.5},
    {"skill_match", 3},
    {"difficulty", -2}
};

bool TaskManager::TaskExists(const std::string& task_name) {
    return tasks_info.find(task_name) != tasks_info.end();
}

std::vector<std::string> TaskManager::GetAvailableTasks() {
    std::vector<std::string> availableTasks;
    for (const auto& task : tasks_info) {
        availableTasks.push_back(task.first);
    }
    return availableTasks;
}

void TaskManager::CompleteTask(const std::string& task_name, std::vector<std::string>& available_tasks) {
    if (TaskExists(task_name)) {
        tasks_info.erase(task_name);
        std::cout << "Task '" << task_name << "' completed and removed from the task list." << std::endl;

        // modify, add-remove todo
    } else {
        std::cerr << "Error: Attempted to complete an unknown task '" << task_name << "'." << std::endl;
    }
}

float TaskManager::CalculateUtility(const std::string& task_name, 
                                    const std::unordered_map<std::string, int>& worker_skills, 
                                    int worker_count, 
                                    int optimal_worker_count) {
    if (!TaskExists(task_name)) {
        std::cerr << "Error: Task '" << task_name << "' not found." << std::endl;
        return -std::numeric_limits<float>::infinity();
    }

    const auto& task = tasks_info[task_name];
    float utility = 0.0f;

    float skill_match = worker_skills.at(task.type);
    float urgency_factor = task.urgency_level;
    float difficulty_penalty = -task.difficulty_level;
    
    float saturation = static_cast<float>(worker_count) / optimal_worker_count;
    float saturation_penalty = saturation > 1.0f ? -saturation : 0;

    utility += skill_match * utility_weights["skill_match"];
    utility += urgency_factor * utility_weights["urgency"];
    utility += difficulty_penalty * utility_weights["difficulty"];
    utility += saturation_penalty * utility_weights["saturation"];

    return utility;
}


