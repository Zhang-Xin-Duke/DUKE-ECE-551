#include <iostream>
#include <vector>

int main()
{
    std::vector<int> c = {1, 2, 3};
    std::cout << "The vector holds: ";
    for(auto& el: c) std::cout << el << ' ';
    std::cout << '\n';
    std::cout << "size() = " << c.size() << std::endl;
    std::cout << "capacity() = " << c.capacity() << std::endl;

    std::cout << std::endl << std::endl;
    c.resize(7);
    std::cout << "After resize up to 5: ";
    for(auto& el: c) std::cout << el << ' ';
    std::cout << '\n';
    std::cout << "size() = " << c.size() << std::endl;
    std::cout << "capacity() = " << c.capacity() << std::endl;

    std::cout << std::endl << std::endl;
    c.resize(2);
    std::cout << "After resize down to 2: ";
    for(auto& el: c) std::cout << el << ' ';
    std::cout << '\n';
    std::cout << "size() = " << c.size() << std::endl;
    std::cout << "capacity() = " << c.capacity() << std::endl;
}
