#pragma once

#include "flower.h"
#include <list>

using namespace std;

class Bouquet
{
    public:
		Bouquet(bool is_in_water_);
		void Add_Flower(const Flower& flower); // добавление цветка в список хранения
		Flower Remove_Flower(const Flower& flower); // извлечение цветка из списка хранения, возвращает извлечённый цветок
        void List_Adder(list<Flower> bouquet_, const Flower& flower, bool is_add); // операции со списком хранения цветов
		void Flowers_All_To(); // стандартизация букета (при is_in_water == true все цветы помещаются в воду, при is_in_water == false все цветы убираются из воды)
		void Bouquet_Content(); // просмотр содержимого букета
		std::string Move_To_Water(); // помещение букета в воду
		std::string Move_Out_Water(); // извлечение букета из воды
		double Get_Base_Price(); // базовая цена букета
		double Get_Real_Price(); // реальная цена букета
		double State(); // состояние букета
		size_t Count_Flowers(); // число цветов в букете
		size_t Count_Spoiled(); // число увядших цветов
		void Change_Speed(double t); // сдвиг внутренних часов

    private:
        list<Flower> bouquet; // список для хранения цветов
		bool is_in_water; // нахождение букета в воде
};
