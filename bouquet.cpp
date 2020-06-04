#include <iostream>
#include <string>
#include <locale.h>
#include <math.h>
#include <stdexcept>
#include <list>
#include "flower.h"
#include "bouquet.h"

Bouquet::Bouquet(bool is_in_water_)
{
    is_in_water = is_in_water_;
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
