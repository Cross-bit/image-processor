#include "UserMenu.h"

class SecondMenuGroup : public MenuItemGroup {
public:
	SecondMenuGroup() {
		_headerData = "This is the second menu:";
	}

	std::vector<std::unique_ptr<MenuOption>> MenuOptions;

};