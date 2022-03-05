#include <string>
#include <memory>
#include <iostream>
#include <unordered_map>

class MenuOption {
public:
	virtual void Render() {
		std::cout << _itemContent;
	}

	virtual void Execute() { }

protected:
	std::string _itemContent;
};

class MenuItemGroup {
public:
	void AddMenuOption(std::string indentificator, std::unique_ptr<MenuOption> option){
		_menuOptions.insert(std::make_pair(indentificator, std::move(option)));
	}

	void Render() {
		RenderHeader();
		RenderMenuItems();
	}

	void OnUserChoice(std::string choice) {
		auto optionSearched = _menuOptions.find(choice);
		if (optionSearched != _menuOptions.end()) {
			optionSearched->second->Execute();
		}
		else {
			std::cout << "Choice \"" << choice << "\" not found" << std::endl;
		}
	}

protected:
	std::string _headerData;
	std::unordered_map<std::string, std::unique_ptr<MenuOption>> _menuOptions;

	virtual void RenderHeader() {
		std::cout << _headerData << std::endl;
	}

	virtual void RenderMenuItems() {
		int ctr = 1;
		for (auto& menuOption : _menuOptions) {
			std::cout << menuOption.first;
			menuOption.second->Render();
			std::cout << std::endl;
		}
	}
};


class UserMenu {
public:
	UserMenu() {}
	~UserMenu() {}

	void SetNewMenuItem(std::unique_ptr<MenuItemGroup> menuItemToSet) {
		_menuGroup = std::move(menuItemToSet);
	}

	void Update() {
		while (_isAppRunning) {

			_menuGroup->Render();

			std::string userInput;
			std::getline(std::cin, userInput);

			_menuGroup->OnUserChoice(userInput);
		}
	}

private:
	std::unique_ptr<MenuItemGroup> _menuGroup;
	bool _isAppRunning = true;
};

class WelcomeMenuGroup : public MenuItemGroup {
public:
	WelcomeMenuGroup() {
		_headerData = "Welcome to my application!";
	}

	void OnUserChoice() {

	}
};


class SecondMenuGroup : public MenuItemGroup {
public:
	SecondMenuGroup() {
		_headerData = "This is the second menu:";
	}
	std::vector<std::unique_ptr<MenuOption>> MenuOptions;
};


class GoSecondMenu : public MenuOption {
public:
	GoSecondMenu(UserMenu& userMenu) : _userMenu(userMenu) {
		_itemContent = "Go to second menu";
	}

	void Execute() override {
		_userMenu.SetNewMenuItem(std::make_unique<SecondMenuGroup>());
	}

private:
	UserMenu& _userMenu;
};
