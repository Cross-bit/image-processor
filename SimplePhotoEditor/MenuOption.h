#pragma once

#include <string>
#include <memory>
#include <iostream>
#include <unordered_map>

class MenuOption {
public:
	virtual void Render();

	virtual void Execute() = 0;

protected:
	std::string _itemContent = "";
};
