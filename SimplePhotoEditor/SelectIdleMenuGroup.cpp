#include "UserMenu.h"

class IdleMenuOption : public MenuOption {
public:

	IdleMenuOption(UserMenu& userMenu) : _userMenu(userMenu) {
		_itemContent = "Go to welcome menu";
	}

	void Execute() override {
		//_userMenu.SetNewMenuItem(std::make_unique<IdleMenuGroup>());
	}

private:
	UserMenu& _userMenu;
};
