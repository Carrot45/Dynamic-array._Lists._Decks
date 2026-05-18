#include <iostream>
#include <string>
#include <windows.h>


void print_dynamic_array(int* arr, int logical_size, int actual_size);
void append_to_dynamic_array(int*& arr, int& logical_size, int& actual_size, int append);

int main(int argc, char* argv[])
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int actual_size{};
    int logical_size{};
    int append{};
    std::cout << "Введите фактичеcкий размер массива: ";
    std::cin >> actual_size;
    int* array = new int[actual_size];
    std::cout << "Введите логический размер массива: ";
    std::cin >> logical_size;
    while (logical_size > actual_size)
    {
        std::cout << "Ошибка! Логический размер массива не может превышать фактический!" << std::endl;
        std::cout << "Введите логический размер массива: ";
        std::cin >> logical_size;
    }
    for (int item{}; item < logical_size; item++)
    {
        std::cout << "Введите arr[" << item << "]: ";
        std::cin >> array[item];
    }
    print_dynamic_array(array, logical_size, actual_size);
    std::cout << std::endl;
    std::cout << "Введите элемент для добавления: ";
    std::cin >> append;
    while (append != 0)
    {
        append_to_dynamic_array(array, logical_size, actual_size, append);
        print_dynamic_array(array, logical_size, actual_size);
        std::cout << std::endl;
        std::cout << "Введите элемент для добавления: ";
        std::cin >> append;
    }
    delete[] array;
    return EXIT_SUCCESS;
}

void print_dynamic_array(int* arr, int logical_size, int actual_size)
{
    std::cout << "Динамический массив: ";
    for (int item{}; item < logical_size; item++)
    {
        std::cout << arr[item] << " ";
    }
    for (int zero{ logical_size }; zero < actual_size; zero++)
    {
        std::cout << "_ ";
    }
}

void append_to_dynamic_array(int*& arr, int& logical_size, int& actual_size, int append)
{
    if (logical_size < actual_size)
    {
        arr[logical_size] = append;
        ++logical_size;
    }
    else 
    {
        int* new_arr = new int[actual_size * 2];
        for (int item{}; item < logical_size; item++)
        {
            new_arr[item] = arr[item];
        }
        new_arr[logical_size] = append;
        ++logical_size;
        actual_size = actual_size * 2;  
        delete[] arr;
        arr = new_arr;        
    }
}
