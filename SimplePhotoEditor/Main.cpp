// SimplePhotoEditor.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include <functional>
#include <array>
#include <vector>
#include <memory>
#include <string>
#include <fstream>
#include "UserMenu.cpp"

using namespace std;


int main(int argv, char ** argc) 
{
	UserMenu menu;

	auto welcomeGroup = std::make_unique<WelcomeMenuGroup>();


	std::unique_ptr<MenuOption> goSecond = std::make_unique<GoSecondMenu>(menu);
	welcomeGroup->AddMenuOption("a", std::move(goSecond));



	menu.SetNewMenuItem(std::move(welcomeGroup));

	unique_ptr<MenuItemGroup> aha = std::make_unique<SecondMenuGroup>();

	//menu.Render();

	menu.Update();


}