#ifndef STRINGSORTINGQUEUE_HPP
#define STRINGSORTINGQUEUE_HPP

#include <string>

#include "workQueue/workQueue.hpp"

namespace stringSorting
{
    typedef std::string ArgsType;
    typedef void(*FunctionType)(ArgsType&);

    class queue : public workQueue<FunctionType, ArgsType>
    {   
    };

}


#endif //WINPROJ_WORKQUEUE_HPP
