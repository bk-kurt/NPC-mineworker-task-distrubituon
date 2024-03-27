#include "Worker.h"
#include <cmath>
#include <limits>
#include "TaskManager.h"

Worker::Worker(std::string name, std::string role, std::unordered_map<std::string, int> skills)
    : name(name), role(role), utility(0), skills(skills) {}

std::string Worker::getName() const {
    return name;
}

float Worker::calculate_distance_to(std::pair<int, int> location) {
    // placeholder logic
    return std::sqrt(std::pow(location.first - 0, 2) + std::pow(location.second - 0, 2));
}

float Worker::calculate_utility(const std::string& task_name, int worker_count, int optimal_worker_count) {
    if (!TaskManager::TaskExists(task_name)) {
        std::cerr << "Error: Task '" << task_name << "' not found." << std::endl;
        return -std::numeric_limits<float>::infinity();
    }
    return TaskManager::CalculateUtility(task_name, skills, worker_count, optimal_worker_count);
}

std::string Worker::choose_task(const std::vector<std::string>& available_tasks, int worker_count, int optimal_worker_count) {
    float highest_utility = -std::numeric_limits<float>::infinity();
    std::string best_task;
    for (const auto& task_name : available_tasks) {
        float utility = calculate_utility(task_name, worker_count, optimal_worker_count);
        if (utility > highest_utility) {
            highest_utility = utility;
            best_task = task_name;
        }
    }
    return best_task;
}

void Worker::complete_task(const std::string& task_name) {
    if (TaskManager::TaskExists(task_name)) {
        TaskManager::CompleteTask(task_name, /* todo */);
    } else {
        std::cerr << "Attempted to complete an unknown task: " << task_name << std::endl;
    }
}
