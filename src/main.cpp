#include <fstream>
#include <iterator>
#include <print>
#include <algorithm>
#include <string>
#include <chrono>

#include "stringSortingQueue/stringSortingQueue.hpp"
#include "factory/factory.hpp"

constexpr size_t numberOfStrings = 12;

void sortLess(std::string& str)
{
    std::print("Thread started\n");
    std::sort(str.begin(), str.end());
}

int main()
{
    using namespace std;
    auto progBegin = chrono::high_resolution_clock::now();
    fstream in("../src/assets/text.txt");
    istream_iterator<char> iter(in);
    std::string text(iter, {});
    size_t textSize = text.size();

    const size_t substringSize = textSize / numberOfStrings + 1;
    std::vector<std::string> strings;
    strings.reserve(numberOfStrings);
    for(int i = 0; i < numberOfStrings; ++i)
    {
        strings.push_back(text.substr(i*substringSize, substringSize));
    }

    stringSorting::queue work;
    for(auto& str : strings)
        work.add(sortLess, str);

    vector<string> completeWork = SortingFactory{}(work);
    
    std::string res;
    res.reserve(textSize);
    for(size_t count = 0; count < textSize; ++count)
    {
        size_t stringInd = 0;
        while(completeWork[stringInd].empty())
            ++stringInd;
        for(size_t i = stringInd + 1; i < completeWork.size(); ++i)
            if(!completeWork[i].empty() && completeWork[i][0] < completeWork[stringInd][0])
                stringInd = i;

        res.push_back(completeWork[stringInd][0]);
        completeWork[stringInd] = completeWork[stringInd].substr(1, textSize);
    }

    print("{0} \n time: {1} sec" , res, chrono::duration<double>(chrono::high_resolution_clock::now() - progBegin).count());

    return 0;
}