#ifndef STL_TASKS_H
#define STL_TASKS_H

#include <vector>
#include <list>
#include <map>
#include <algorithm>
#include <iostream>
#include <stdexcept>

inline void removeDuplicates(std::vector<int>& vec) {
    std::sort(vec.begin(), vec.end());
    auto last = std::unique(vec.begin(), vec.end());
    vec.erase(last, vec.end());
}

inline bool isSorted(const std::list<int>& lst) {
    if (lst.empty()) return true;
    for (auto it = lst.begin(), nextIt = std::next(lst.begin()); nextIt != lst.end(); ++it, ++nextIt) {
        if (*it > *nextIt) return false;
    }
    return true;
}

inline void addOrUpdateStudent(std::map<std::string, int>& students, const std::string& name, int grade) {
    students[name] = grade;
}

#endif
