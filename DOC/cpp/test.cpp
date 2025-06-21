
#include <iostream>
#include <string.h>

int main()
{

    char buf[] = "hello wolrd@163.com";
    char del[] = "@.";

    char *dis = strtok(buf, del);
    std::cout << dis << std::endl;

    char *left = strtok(nullptr, del);
    while (left != nullptr)
    {

        std::cout<<left<<std::endl;
        left = strtok(nullptr, del);
    }

    return 0;
}