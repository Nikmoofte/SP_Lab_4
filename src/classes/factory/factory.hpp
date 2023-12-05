#ifndef FACTORY_HPP
#define FACTORY_HPP

#include <thread>
#include <vector>
#include <algorithm>

#include "stringSortingQueue/stringSortingQueue.hpp"

class SortingFactory
{
public:
    SortingFactory(stringSorting::queue& queue)
    {

        threads.reserve(queue.size());
        toWork(queue);
    }

private:
    void toWork(stringSorting::queue& queue)
    {
        size_t i = 0;
        while(!queue.empty())
        {
            auto threadData = queue.get();
            auto function = threadData.first;
            auto args = threadData.second;
            threads.push_back(std::thread(function, std::ref(args)));
            i++;
        }
        for(auto& thread : threads)
            thread.join();
        
    }

    std::vector<std::thread> threads;
};


#endif //WINPROJ_WORKQUEUE_HPP
