#include <iostream>
#include <string>
#include <locale.h>
#include <math.h>
#include <stdexcept>
#include <list>
#include "flower.h"


Flower::Flower(const std::string &name_, colours colour_, double state_, double full_life_time_water, double full_life_time_no_water, double base_price_, bool is_in_water_)
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
}