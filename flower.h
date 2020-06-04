#pragma once
#include <string>
#include <list>

class Flower
{
	public:
        enum class colours
        {
            white, 
            black, 
            red, 
            blue, 
            yellow, 
            green, 
            pink, 
            orange, 
            brown, 
            purple
        };

		Flower(const std::string &name_, colours colour_, double state_, double full_life_time_water, double full_life_time_no_water, double base_price_, bool is_in_water_);
		
        std::string Flower_Colour(colours colour);

		std::string Get_Name() const;

		std::string Get_Colour() const;
		

		double Get_State() const;
		
		double Get_Speed_Water() const;
		
		double Get_Speed_No_Water() const;

		bool Is_In_Water() const;
        
		double Get_Base_Price() const;

        double Get_Real_Price() const;
		
		std::string Flower_State(); // проверка цветка на увядание
		
		bool Water_Move(); // перемещение цветка из воды/в воду

		double Change_Speed(double t); // изменение состояния цветка при изменении времени
		

	private:
		
		std::string colour;
		const std::string name;
		double state;
		double speed_water;
		double full_speed_water;
		double speed_no_water;
		double full_speed_no_water;
		bool is_in_water;
		double base_price;
};
