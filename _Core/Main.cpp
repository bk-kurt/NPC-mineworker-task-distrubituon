#include "Worker.h"
#include "TaskManager.h"
#include <iostream>
#include <vector>
#include <string>

int main() {
    std::vector<Worker> workers;
    std::unordered_map<std::string, int> worker_skills = {{"mining", 3}, {"transport", 2}};

    for (int i = 0; i < 100; ++i) {
        workers.emplace_back("Worker_" + std::to_string(i), worker_skills);
    }

    std::vector<std::string> available_tasks = TaskManager::GetAvailableTasks();

    if (available_tasks.empty()) {
        std::cout << "No tasks available. Workers are idle." << std::endl;
    } else {
        for (auto& worker : workers) {
            std::string chosen_task = worker.choose_task(available_tasks, 10, 20); 
            if (chosen_task.empty()) {
                std::cout << worker.getName() << " could not find a suitable task." << std::endl;
            } else {
                std::cout << worker.getName() << " assigned to: " << chosen_task << std::endl;
                worker.complete_task(chosen_task);
            }
        }
    }

    return 0;
}
