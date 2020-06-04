#include <iostream>
#include <string>
#include <locale.h>
#include "flower.h"
#include "bouquet.h"

void Flower_Info(Flower flower)
{
    std::cout << "Название: " << flower.Get_Name() << "||";
    std::cout << "Цвет: " << flower.Get_Colour() << "||";
    std::cout << "Состояние: " << flower.Get_State() << "||";
    std::cout << "Завянет в воде через: " << flower.Get_Speed_Water() << " ч" << "||";
    std::cout << "Завянет без воды через : " << flower.Get_Speed_No_Water() << " ч" << "||";
    std::cout << "Цена: " << flower.Get_Base_Price() << "руб" << "||";
    std::cout << "Стоимость: " << flower.Get_Real_Price() << "руб" << "||";
    std::cout << flower.Flower_State() << std::endl;
}

void Bouquet::Bouquet_Content()
{
    size_t flower_number = 1;

    for(Flower flower : bouquet_list)
    {
        std::cout << "Цветок №" << flower_number << std::endl;
        Flower_Info(flower);
        flower_number++;
    }
}

void Bouquet_Info(Bouquet bouquet)
{
    std::cout << "Цена: " << bouquet.Get_Base_Price() << "руб" << std::endl;
    std::cout << "Стоимость: " << bouquet.Get_Real_Price() << "руб" << std::endl;
    std::cout << "Состояние: " << bouquet.State() << std::endl;
    std::cout << "Всего цветов: " << bouquet.Count_Flowers() << std::endl;
    std::cout << "Испорченных цветов: " << bouquet.Count_Spoiled() << std::endl;
    bouquet.Bouquet_Content();
}

int main()
{
    setlocale(0, "");

    Flower rose = Flower("Роза", Flower::colours::red, 0.75, 72, 36, 100, true);
    Flower primrose = Flower("Примула", Flower::colours::purple, 0.6, 96, 48, 200, false);
    Flower orchid = Flower("Орхидея", Flower::colours::pink, 0.8, 100, 70, 250, true);

    Bouquet bouquet = Bouquet(true);
    bouquet.Add_Flower(rose);
    bouquet.Add_Flower(primrose);
    bouquet.Add_Flower(orchid);
    bouquet.Flowers_All_To();
    Bouquet_Info(bouquet);

    bouquet.Remove_Flower(1);
    Bouquet_Info(bouquet);
    return 0;
}
