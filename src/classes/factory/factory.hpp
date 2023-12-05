#ifndef FACTORY_HPP
#define FACTORY_HPP

#include <thread>
#include <vector>
#include <algorithm>

#include "stringSortingQueue/stringSortingQueue.hpp"

class SortingFactory
{
public:
    SortingFactory(){}
    
    std::vector<std::string> operator()(stringSorting::queue& queue)
    {
        return toWork(queue);
    }
private:
    std::vector<std::string> toWork(stringSorting::queue& queue)
    {
        std::vector<std::string> result;
        result.reserve(queue.size());
        while(!queue.empty())
        {
            auto threadData = queue.get();
            auto function = threadData.first;
            result.push_back(threadData.second);
            threads.push_back(std::thread(function, std::ref(result[result.size() - 1])));

        }
        for(auto& thread : threads)
            thread.join();

        return result;
    }

    std::vector<std::thread> threads;
};


#endif //WINPROJ_WORKQUEUE_HPP
