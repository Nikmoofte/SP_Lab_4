#ifndef WORKQUEUE_HPP
#define WORKQUEUE_HPP

#include <queue>
#include <mutex>

template<class Function, class... Args > 
class workQueue
{
public:
    workQueue(){}
 
    void add(Function&& f, Args&&... args)
    {
        std::lock_guard<std::mutex> guard(ioMutex);
        _data.push({std::move(f), std::move(args)});
    }

    std::pair<Function, Args...> get()
    {
        std::lock_guard<std::mutex> guard(ioMutex);
        auto data = _data.front();
        _data.pop(); 
        return data;
    }

    bool empty()
    {
        return _data.empty();
    }

    auto size()
    {
        return _data.size();
    }

private:
    std::mutex ioMutex;
    std::queue<std::pair<Function, Args...>> _data;
};


#endif //WINPROJ_WORKQUEUE_HPP
