#include <iostream>

void jumpLine()
{
    std::cout << "\n";
}

void recorrer(const auto &arr)
{
    int i = 0;
    for (auto val : arr)
    {
        std::cout << "Posición: " << i << ", valor: " << val << std::endl;
        i += 1;
    }
}

int main()
{
    int arr[5] = {1, 2, 3, 4, 5};
    std::string arr1[5] = {"Juan", "Camila", "Santiago", "Jose", "Andres"};
    jumpLine();
    recorrer(arr1);
    jumpLine();
    return 0;
}