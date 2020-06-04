#include <iostream>
#include <string>
#include <locale.h>
#include <math.h>
#include <stdexcept>
#include <list>
#include "flower.h"
#include "bouquet.h"

/*Flower::Flower(const std::string &name_, colours colour_, double state_, double full_life_time_water, double full_life_time_no_water, double base_price_, bool is_in_water_)
	:name(name_)
{
    if(state < 0 || state > 1) throw std::out_of_range("state");
    if(full_life_time_water < 0 || full_life_time_no_water < 0) throw std::out_of_range("water life time");
    if(base_price < 0) throw std::out_of_range("base_price");
    if(full_life_time_no_water > full_life_time_water) throw std::invalid_argument("full_life_time_no_water > full_life_time_water");

    colour = Flower_Colour(colour_);
	base_price = base_price_;
    state = state_;
	full_speed_water = full_life_time_water;
	full_speed_no_water = full_life_time_no_water;
	speed_water = full_speed_water * state;
	speed_no_water = full_speed_no_water * state;
	is_in_water = is_in_water_;
}

std::string Flower::Flower_Colour(Flower::colours colour)
{
    switch(colour)
    {
        case Flower::colours::white: return("белый"); break;
        case Flower::colours::black: return("чёрный"); break;
        case Flower::colours::red: return("красный"); break;
        case Flower::colours::blue: return("синий"); break;
        case Flower::colours::yellow: return("жёлтый"); break;
        case Flower::colours::green: return("зелёный"); break;
        case Flower::colours::pink: return("розовый"); break;
        case Flower::colours::orange: return("оранжевый"); break;
        case Flower::colours::brown: return("коричневый"); break;
        case Flower::colours::purple: return("фиолетовый"); break;
    }
}

std::string Flower::Get_Name() const{ return name; }

std::string Flower::Get_Colour() const{ return colour; }

double Flower::Get_State() const{ return state; }

double Flower::Get_Speed_Water() const{ return speed_water; }

double Flower::Get_Speed_No_Water() const{ return speed_no_water; }

bool Flower::Is_In_Water() const{ return is_in_water; }

double Flower::Get_Base_Price() const{ return base_price; }

double Flower::Get_Real_Price() const{ return base_price*state; }

std::string Flower::Flower_State() // проверка цветка на увядание
{
	if (state == 0 || speed_water == 0 || speed_no_water == 0) return "Цветок завял";
	else return "Цветок не завял" ;
}

bool Flower::Water_Move() { return !is_in_water; }

double Flower::Change_Speed(double t) // изменение состояния цветка при изменении времени
{
    double t2 = full_speed_no_water/full_speed_water;

	if (is_in_water == true)
	{
        if (speed_water > 0)
        {
            speed_no_water += t * t2;
            speed_water += t;
            if(speed_water > full_speed_water) speed_water = full_speed_water;
            if(speed_no_water > full_speed_no_water) speed_no_water = full_speed_no_water;
            state += t / full_speed_water;
            if(speed_water < 0)
            {
                speed_water = 0;
                speed_no_water = 0;
            }
            if(state > 1) state = 1;
            if(state < 0) state = 0; 
	    }
        else return 0;
    }

	else
	{
        if(speed_no_water > 0)
        {
            speed_no_water += t;
            speed_water += t * pow(t2,-1);
            if(speed_water > full_speed_water) speed_water = full_speed_water;
            if(speed_no_water > full_speed_no_water) speed_no_water = full_speed_no_water;
            state += t / full_speed_no_water;
            if(speed_no_water < 0)
            {
                speed_water = 0;
                speed_no_water = 0;
            }
            if(state > 1) state = 1;
            if(state < 0) state = 0;  
        }
        else return 0;
	}
    return state;
}*/
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

/*Bouquet::Bouquet(bool is_in_water_)
{
    is_in_water = is_in_water_;
    Flowers_All_To();
}

void Bouquet::Add_Flower(const Flower& flower)
{
    List_Adder(bouquet, flower, true);
}

//Flower Bouquet::Remove_Flower(const Flower& flower)
//{
    //for (Flower flower_ : bouquet)
    //{
    //    if (flower_ == flower)
    //}
    //return flower;
//}

void Bouquet::List_Adder(list<Flower> bouquet_, const Flower& flower, bool is_add)
{
    bouquet.push_back(flower);
}

void Bouquet::Flowers_All_To()
{
    for(Flower flower : bouquet)
    {
        if(flower.Is_In_Water() != is_in_water) flower.Water_Move();
    }
}

std::string Bouquet::Move_To_Water()
{
    if(is_in_water == 0) return "Уже в воде";
    else
    {
        for(Flower flower : bouquet)
        {
            flower.Water_Move();
        }
    }
    return "Букет перемещён в воду";
}

std::string Bouquet::Move_Out_Water()
{
    if(is_in_water == 1) return "Уже вне воды";
    else
    {
        for(Flower flower : bouquet)
        {
            flower.Water_Move();
        }
    }
    return "Букет извлечён из воды";
}

double Bouquet::Get_Base_Price()
{
    double base_price = 0;

    for(Flower flower : bouquet)
    {
        base_price += flower.Get_Base_Price();
    }
    return base_price;
}

double Bouquet::Get_Real_Price()
{
    double real_price = 0;

    for(Flower flower : bouquet)
    {
        real_price += flower.Get_Real_Price();
    }

    return real_price;
}

double Bouquet::State()
{
    double state = 0;
    size_t count = 0;
    for(Flower flower : bouquet)
    {
        count += 1;
        state += flower.Get_State();
    }
    
    return state/count;
}

size_t Bouquet::Count_Flowers()
{
    return bouquet.size();
}

size_t Bouquet::Count_Spoiled()
{
    size_t count_spoiled = 0;

    for(Flower flower : bouquet)
    {
        if(flower.Get_State() == 0) count_spoiled++;
    }
    return count_spoiled;
}

void Bouquet::Change_Speed(double t)
{
    for(Flower flower : bouquet)
    {
        flower.Change_Speed(t);
    }
}

void Bouquet::Bouquet_Content()
{
    size_t flower_number = 1;

    for(Flower flower : bouquet)
    {
        std::cout << "Цветок №" << flower_number << std::endl;

        std::cout << "Название: " << flower.Get_Name() << "||"; 
	    std::cout << "Цвет: " << flower.Get_Colour() << "||"; 
	    std::cout << "Состояние: " << flower.Get_State() << "||";
	    std::cout << "Завянет в воде через: " << flower.Get_Speed_Water() << " ч" << "||"; 
	    std::cout << "Завянет без воды через : " << flower.Get_Speed_No_Water() << " ч" << "||"; 
	    std::cout << "Цена: " << flower.Get_Base_Price() << "руб" << "||"; 
	    std::cout << "Стоимость: " << flower.Get_Real_Price() << "руб" << "||"; 
	    std::cout << "Состояние: " << flower.Flower_State() << std::endl; 

        flower_number++;
    }
}*/

void Bouquet_Info(Bouquet bouquet)
{
    std::cout << "Цена: " << bouquet.Get_Base_Price() << "руб" << std::endl;
    std::cout << "Стоимость: " << bouquet.Get_Real_Price() << "руб" << std::endl;
    std::cout << "Состояние: "<< bouquet.State() << std::endl;
    std::cout << "Всего цветов: "<< bouquet.Count_Flowers() << std::endl;
    std::cout << "Испорченных цветов: " <<bouquet.Count_Spoiled() << std::endl;
    //bouquet.Bouquet_Content();
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
    Bouquet_Info(bouquet);
    return 0;
}
