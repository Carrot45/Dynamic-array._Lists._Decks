#include <iostream>
#include <string>
#include <windows.h>


void print_dynamic_array(int* arr, int logical_size, int actual_size);
void remove_dynamic_array_head(int*& arr, int& logical_size, int& actual_size);

int main(int argc, char* argv[])
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int actual_size{};
    int logical_size{};
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
    std::cout << "Динамический массив: ";
    print_dynamic_array(array, logical_size, actual_size);
    std::cout << std::endl;
    std::string choice{};
    std::cout << "Удалить первый элемент?";
    std::cin >> choice;
    while (choice == "да")
    {
        if (logical_size == 0)
        {
            std::cout << "Невозможно удалить первый элемент, так как массив пустой.До свидания!";
            break;
        }
        remove_dynamic_array_head(array, logical_size, actual_size);
        std::cout << "Динамический массив: ";
        print_dynamic_array(array, logical_size, actual_size);
        std::cout << std::endl;
        std::cout << "Удалить первый элемент?";
        std::cin >> choice;
    }

    if (choice == "нет")
    {
        std::cout << "Спасибо! Ваш динамический массив: ";
        print_dynamic_array(array, logical_size, actual_size);
    }

    delete[] array;
    return EXIT_SUCCESS;
}

void print_dynamic_array(int* arr, int logical_size, int actual_size)
{    
    for (int item{}; item < logical_size; item++)
    {
        std::cout << arr[item] << " ";
    }
    for (int zero{ logical_size }; zero < actual_size; zero++)
    {
        std::cout << "_ ";
    }
}

void remove_dynamic_array_head(int*& arr, int& logical_size, int& actual_size)
{
    if ((logical_size - 1) > ((actual_size / 3) - 1))
    {
        for (int item{}; item < logical_size - 1; item++)
        {
            arr[item] = arr[item + 1];
        }       
        --logical_size;
    }
    else 
    {
        int* new_arr = new int[actual_size / 3];
        for (int item{}; item < logical_size - 1; item++)
        {
            new_arr[item] = arr[item + 1];
        }
        --logical_size;
        actual_size = actual_size / 3;
        delete[] arr;
        arr = new_arr;
    }
}
