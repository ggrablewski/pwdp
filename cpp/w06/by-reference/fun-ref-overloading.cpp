#include <iostream>
#include <vector>

std::ostream& operator<<(std::ostream& out, std::vector<int>& v)
{
    out << "[";
    if (!v.empty())
        out << v[0];
    for (int i = 1; i < v.size(); i++)
        out << ", " << v[i];
    out << "]";
    return out;
}

int main()
{
    std::vector<int> tab = {1, 2, 3, -1, -2};
    std::cout << tab << "\n";
}
