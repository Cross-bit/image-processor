#include "UserMenu.h"

class GoSecondMenu : public MenuOption {
public:
	GoSecondMenu(UserMenu& userMenu) : _userMenu(userMenu) {
		_itemContent = "Go to second menu";
	}

	void Execute() override {

		/*auto secondMenu = std::make_unique<SecondMenuGroup>();
		secondMenu->AddMenuOption("a", std::make_unique<GoFirstMenu>(_userMenu));
		_userMenu.SetNewMenuItem(std::move(secondMenu));*/
	}

private:
	UserMenu& _userMenu;
};
