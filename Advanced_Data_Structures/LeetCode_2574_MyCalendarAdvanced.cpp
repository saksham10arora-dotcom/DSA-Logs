```cpp
// My Calendar III, https://leetcode.com/problems/my-calendar-iii/, 
// Implement a MyCalendarThree class to store the events of a calendar.

#include <iostream>
#include <map>

class MyCalendarThree {
public:
    std::map<int, int> events;

    MyCalendarThree() {}

    int book(int start, int end) {
        events[start]++;
        events[end]--;
        int maxEvents = 0, currentEvents = 0;
        for (auto& event : events) {
            currentEvents += event.second;
            maxEvents = std::max(maxEvents, currentEvents);
        }
        return maxEvents;
    }
};

int main() {
    MyCalendarThree calendar;
    std::cout << calendar.book(10, 20) << std::endl;  // Output: 1
    std::cout << calendar.book(50, 60) << std::endl;  // Output: 1
    std::cout << calendar.book(10, 40) << std::endl;  // Output: 2
    std::cout << calendar.book(5, 15) << std::endl;  // Output: 3
    std::cout << calendar.book(5, 10) << std::endl;  // Output: 3
    std::cout << calendar.book(25, 55) << std::endl;  // Output: 3
    return 0;
}
```