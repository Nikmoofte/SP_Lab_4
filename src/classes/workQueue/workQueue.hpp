#ifndef WORKQUEUE_HPP
#define WORKQUEUE_HPP

#include <queue>
#include <mutex>

template<class Function, class Arg> 
class workQueue
{
public:
    workQueue(){}
 
    void add(Function&& f, Arg arg)
    {
        std::lock_guard<std::mutex> guard(ioMutex);
        _data.push({std::move(f), arg});
    }

    std::pair<Function, Arg> get()
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

    auto begin()
    {
        return _data.begin();
    }
    auto end()
    {
        return _data.end();
    }

private:
    std::mutex ioMutex;
    std::queue<std::pair<Function, Arg>> _data;
};


#endif //WINPROJ_WORKQUEUE_HPP
