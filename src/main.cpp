#include <fstream>
#include <iterator>
#include <string>

#include "stringSortingQueue/stringSortingQueue.hpp"
#include "factory/factory.hpp"

int main()
{
    using namespace std;
    fstream in("../src/assets/text.txt");
    istream_iterator<char> iter(in);
    std::string text(iter, {});




    return 0;
}