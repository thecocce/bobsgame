#include "stdafx.h"

#include "src/Utility/audio/AudioManager.h"

#include "stdlib.h"

#include "Room.h"


//=========================================================================================================================
void BobsGame::setupMenus()
{//=========================================================================================================================

	super::setupMenus();

	numTitleMenuTextureFrames = 11;// 22;//;//91; //139;//with quotes

}

bool BobsGame::updateMenus()
{ //=========================================================================================================================

	//titleMenuShowing = false;
	//customGameEditorMenuShowing = true;
	//gameSequenceEditorMenuShowing = true;
	//globalSettingsMenuShowing = true;
	//gameSetupMenuShowing = true;

	bool updatedMenu = false;

	if (super::updateMenus() == true)updatedMenu = true;


	if (gettingGamesFromServerMenuShowing)
	{
		gettingGamesFromServerMenuUpdate();
		return true;
	}

	if (startScreenMenuShowing)
	{
		startScreenMenuUpdate();
		return true;
	}

	if (controllerMenuShowing)
	{
		controllerMenuUpdate();
		return true;
	}

	if (localMultiplayerPlayerJoinMenuShowing)
	{
		localMultiplayerPlayerJoinMenuUpdate();
		return true;
	}

	if (loginMenuShowing)
	{
		loginMenuUpdate();
		return true;
	}

	if (createAccountMenuShowing)
	{
		createAccountMenuUpdate();
		return true;
	}

	if (networkMultiplayerLobbyMenuShowing)
	{
		networkMultiplayerLobbyMenuUpdate();
		return true;
	}

	if (networkMultiplayerPlayerJoinMenuShowing)
	{
		networkMultiplayerPlayerJoinMenuUpdate();
		return true;
	}

	if (customGameEditorMenuShowing)
	{
		customGameEditorMenuUpdate();
		return true;
	}

	if (gameSequenceEditorMenuShowing)
	{
		gameSequenceEditorMenuUpdate();
		return true;
	}

	if (gameTestMenuShowing)
	{
		gameTestMenuUpdate();
		return true;
	}

	if (globalSettingsMenuShowing)
	{
		globalSettingsMenuUpdate();
		return true;
	}

	if (gameSetupMenuShowing)
	{
		gameSetupMenuUpdate();
		return true;
	}

	if (statsMenuShowing)
	{
		statsMenuUpdate();
		return true;
	}

//	if (selectGameSequenceOrSingleGameTypeMenuShowing)
//	{
//		selectGameSequenceOrSingleGameTypeMenuUpdate();
//		updatedMenu = true;
//	}
//
//	if (selectGameSequenceMenuShowing)
//	{
//		selectGameSequenceMenuUpdate();
//		updatedMenu = true;
//	}
//
//	if (selectSingleGameTypeMenuShowing)
//	{
//		selectSingleGameTypeMenuUpdate();
//		updatedMenu = true;
//	}
//
//	if (difficultyMenuShowing)
//	{
//		difficultyMenuUpdate();
//		updatedMenu = true;
//	}
//
//	if (gameSequenceOptionsMenuShowing)
//	{
//		gameSequenceOptionsMenuUpdate();
//		updatedMenu = true;
//	}
//
//	if (gameObjectiveMenuShowing)
//	{
//		gameObjectiveMenuUpdate();
//		updatedMenu = true;
//	}

	if (multiplayerOptionsMenuShowing)
	{
		multiplayerOptionsMenuUpdate();
		return true;
	}

//	if (gameSetupMenuShowing)
//	{
//		gameSetupMenuUpdate();
//		updatedMenu = true;
//	}

	if(updatedMenu == false)unloadTitleMenuTextures();
	return updatedMenu;
}

bool BobsGame::renderMenus()
{//=========================================================================================================================

	bool renderedMenu = false;

	if (super::renderMenus() == true)renderedMenu = true;


	if (gettingGamesFromServerMenuShowing)
	{
		gettingGamesFromServerMenuRender();
		return true;
	}

	if (startScreenMenuShowing)
	{
		startScreenMenuRender();
		return true;
	}

	if (controllerMenuShowing)
	{
		controllerMenuRender();
		return true;
	}

	if (localMultiplayerPlayerJoinMenuShowing)
	{
		localMultiplayerPlayerJoinMenuRender();
		return true;
	}

	if (loginMenuShowing)
	{
		loginMenuRender();
		return true;
	}

	if (createAccountMenuShowing)
	{
		createAccountMenuRender();
		return true;
	}

	if (networkMultiplayerLobbyMenuShowing)
	{
		networkMultiplayerLobbyMenuRender();
		return true;
	}

	if (networkMultiplayerPlayerJoinMenuShowing)
	{
		networkMultiplayerPlayerJoinMenuRender();
		return true;
	}

	if (customGameEditorMenuShowing)
	{
		customGameEditorMenuRender();
		return true;
	}

	if (gameSequenceEditorMenuShowing)
	{
		gameSequenceEditorMenuRender();
		return true;
	}

	if (gameTestMenuShowing)
	{
		gameTestMenuRender();
		return true;
	}

	if (globalSettingsMenuShowing)
	{
		globalSettingsMenuRender();
		return true;
	}

	if (gameSetupMenuShowing)
	{
		gameSetupMenuRender();
		return true;
	}

	if (statsMenuShowing)
	{
		statsMenuRender();
		return true;
	}

//	if (selectGameSequenceOrSingleGameTypeMenuShowing)
//	{
//		selectGameSequenceOrSingleGameTypeMenuRender();
//		renderedMenu = true;
//	}
//
//	if (selectGameSequenceMenuShowing)
//	{
//		selectGameSequenceMenuRender();
//		renderedMenu = true;
//	}
//
//	if (selectSingleGameTypeMenuShowing)
//	{
//		selectSingleGameTypeMenuRender();
//		renderedMenu = true;
//	}
//
//	if (difficultyMenuShowing)
//	{
//		difficultyMenuRender();
//		renderedMenu = true;
//	}
//
//	if (gameSequenceOptionsMenuShowing)
//	{
//		gameSequenceOptionsMenuRender();
//		renderedMenu = true;
//	}
//
//	if (gameObjectiveMenuShowing)
//	{
//		gameObjectiveMenuRender();
//		renderedMenu = true;
//	}

	if (multiplayerOptionsMenuShowing)
	{
		multiplayerOptionsMenuRender();
		return true;
	}
//	if (gameSetupMenuShowing)
//	{
//		gameSetupMenuRender();
//		renderedMenu = true;
//	}
	return renderedMenu;

}

//=========================================================================================================================
void BobsGame::updateTitleScreenLogo()
{//=========================================================================================================================

	titleMenuFrameTicks += super::engineTicksPassed();
	if (titleMenuFrameTicks > 20)
	{
		titleMenuFrameTicks = 0;
		if (currentTitleMenuTextureFrameIncrementDecrementToggle)
		{
			currentTitleMenuTextureFrame++;
			if (currentTitleMenuTextureFrame >= numTitleMenuTextureFrames)
			{
				currentTitleMenuTextureFrame = numTitleMenuTextureFrames-1;
				currentTitleMenuTextureFrameIncrementDecrementToggle = !currentTitleMenuTextureFrameIncrementDecrementToggle;
			}
		}
		else
		{
			currentTitleMenuTextureFrame--;
			if (currentTitleMenuTextureFrame < 0)
			{
				currentTitleMenuTextureFrame = 0;
				currentTitleMenuTextureFrameIncrementDecrementToggle = !currentTitleMenuTextureFrameIncrementDecrementToggle;
			}
		}

		updateTitleMenuLogoTexture();
	}
}

//=========================================================================================================================
void BobsGame::updateTitleMenuLogoTexture()
{//=========================================================================================================================

//	if(titleScreenTexture!= nullptr)
//	{
//		titleScreenTexture->release();
//		titleScreenTexture= nullptr;
//	}

//	string numString = ""+to_string(currentTitleScreenTextureFrame);
//	int len = numString.length();
//	for(int n=0;n<2-len;n++)numString = "0"+numString;//pad to 2 zeros

	//titleScreenTexture = GLUtils::getTextureFromPNG("data/guiBackground/logo/"+numString+".png");

	if(titleMenuTextures==nullptr)titleMenuTextures = new ArrayList<BobTexture*>();// [numTileScreenTextureFrames];
	if(titleMenuTextures->size()==0)
	{
		for (int i = 0; i<numTitleMenuTextureFrames; i++)
		{
			string numString = "" + to_string(i);
			int len = (int)numString.length();
			for (int n = 0; n<2 - len; n++)numString = "0" + numString;//pad to 2 zeros

			titleMenuTextures->add(GLUtils::getTextureFromPNGExePath("data/guiBackground/logo/" + numString + ".png"));
		}
	}
}

//=========================================================================================================================
void BobsGame::titleMenuUpdate()
{//=========================================================================================================================

	if (titleMenu == nullptr)
	{
		titleMenu = new BobMenu(this, "");
		titleMenu->spacing = 1.2f;

		titleMenu->addInfo("Connecting to server...","Login");
		titleMenu->add("Play Offline");
		titleMenu->add("Exit Game");

		titleMenu->cursorPosition = titleMenuCursorPosition;
	}

	bool leaveMenu = false;

	if (getServerConnection()->getConnectedToServer_S())
	{
		if(FileUtils::readSessionTokenFromCache()!="")
		{
			titleMenu->getMenuItemByID("Login")->setText("Logging in...");
			titleMenu->getMenuItemByID("Login")->info = true;
		}
		else
		{
			if (titleMenu->getMenuItemByID("Login")->info)
			{
				titleMenu->getMenuItemByID("Login")->setText("Login Or Create Account");
				titleMenu->getMenuItemByID("Login")->info = false;
				titleMenu->getMenuItemByID("Login")->setColor(BobMenu::menuColor);
				titleMenu->setSelectedID("Login");
			}
		}

		if (getServerConnection()->getAuthorizedOnServer_S())
		{
			leaveMenu = true;
			startScreenMenuShowing = true;
		}
	}

	if (getControlsManager()->miniGame_UP_Pressed())
	{
		titleMenu->up();
	}

	if (getControlsManager()->miniGame_DOWN_Pressed())
	{
		titleMenu->down();
	}

	bool confirm = getControlsManager()->miniGame_CONFIRM_Pressed();//, clicked, mx, my
	bool clicked = getControlsManager()->mouse_LEFTBUTTON_Pressed();
	int mx = getControlsManager()->getMouseX();
	int my = getControlsManager()->getMouseY();

	if (confirm || clicked)
	{

		if (titleMenu->isSelectedID("Login", clicked, mx, my))
		{
			if (titleMenu->getMenuItemByID("Login")->info == false)
			{
				loginMenuShowing = true;
				leaveMenu = true;
			}
		}

		if (titleMenu->isSelectedID("Play Offline", clicked, mx, my))
		{
			startScreenMenuShowing = true;
			leaveMenu = true;
		}

		if (titleMenu->isSelectedID("Exit Game", clicked, mx, my))
		{
			Main::quit = true;
		}
	}

	if (leaveMenu)
	{
		titleMenuShowing = false;

		if (titleMenu != nullptr)
		{
			titleMenuCursorPosition = titleMenu->cursorPosition;
			delete titleMenu;
			titleMenu = nullptr;
		}
	}
}

void BobsGame::titleMenuRender()
{ //=========================================================================================================================

	GLUtils::drawFilledRect(255, 255, 255, 0, (float)getWidth(), 0, (float)getHeight(), 1.0f);

	BobTexture *t = nullptr;

	if (titleMenuTextures != nullptr && titleMenuTextures->size()>0)t = titleMenuTextures->get(currentTitleMenuTextureFrame);
	if (titleMenuTexture != nullptr)t = titleMenuTexture;

	if (titleMenu == nullptr)return;

	if (t != nullptr)
	{
		titleMenu->setGraphic(t, getWidth() / 3*2, getHeight() / 10);
		titleMenu->render();
	}

}

void BobsGame::startScreenMenuUpdate()
{ //=========================================================================================================================

	updateTitleScreenLogo();

	if (startScreenMenu == nullptr)
	{
		startScreenMenu = new BobMenu(this, "");
		startScreenMenu->spacing = 1.2f;
		startScreenMenu->setFontSize(32);

		//pressEnterCaption = getCaptionManager()->newManagedCaption(Caption::CENTERED_X, y-60, -1, "Press Enter to begin", oswald_24, infoColor, clearColor, RenderOrder::OVER_GUI);
		//pressEnterCaption->flashing = true;
		//pressEnterCaption->flashingTicksPerFlash = 3000;

		startScreenMenu->add("Single Player");
		startScreenMenu->add("Local Multiplayer");
		startScreenMenu->add("Online Multiplayer","", BobMenu::disabledMenuColor);
		startScreenMenu->add("Stats And Leaderboards","Stats", BobMenu::disabledMenuColor);
		startScreenMenu->add("Vote On New Games", "", BobMenu::disabledMenuColor);
		startScreenMenu->add("Custom Game Editor");
		startScreenMenu->add("Game Sequence Creator");
		startScreenMenu->add("Global Settings");
		startScreenMenu->add("Controller Test");
		//startScreenMenu->add("Report Bug");
		//startScreenMenu->add("Support On Patreon", "Donate");
		startScreenMenu->add("Exit Game");

		startScreenMenu->cursorPosition = startScreenMenuCursorPosition;
	}

	if (infoMenu == nullptr)
	{
		infoMenu = new BobMenu(this, "");
		infoMenu->center = false;
		infoMenu->setFontSize(10);
		infoMenu->outline = false;
		infoMenu->addInfo("Build " + Main::version + " " + __TIMESTAMP__);// +" - Support this game: ", "Build Number");
		infoMenu->addInfo("This game is actively developed by one person for free and will have bugs. I rely on your feedback!");
		infoMenu->addInfo("Please report problems, crashes, and suggestions to bugs@bobsgame.com or ", "Open Forum");
//		infoMenu->addInfo("There are no built in games, they are downloaded. If no games show in the menu the server might be overloaded, wait a bit or restart a few times.");
//		infoMenu->addInfo("Currently working on: Better leaderboards, Android/iOS ports.");
	}


//	if (patreonMenu == nullptr)
//	{
//		patreonMenu = new BobMenu(this, "");
//		patreonMenu->center = false;
//		patreonMenu->font = 10;
//		patreonMenu->outline = false;
//		patreonMenu->addInfo("https://patreon.com/bobsgame", "Patreon", BobColor::lightBlue);
//	}


	if (forumMenu == nullptr)
	{
		forumMenu = new BobMenu(this, "");
		forumMenu->center = false;
		forumMenu->setFontSize(10);
		forumMenu->outline = false;
		forumMenu->addInfo("https://bobsgame.com/forum", "Open Forum",BobColor::lightBlue);
	}

	if(getServerConnection()->getConnectedToServer_S())
	{
		startScreenMenu->getMenuItemByID("Online Multiplayer")->setColor(BobMenu::menuColor);
		startScreenMenu->getMenuItemByID("Online Multiplayer")->info = false;

		startScreenMenu->getMenuItemByID("Stats")->setColor(BobMenu::menuColor);
		startScreenMenu->getMenuItemByID("Stats")->info = false;

		startScreenMenu->getMenuItemByID("Vote On New Games")->setColor(BobMenu::menuColor);
		startScreenMenu->getMenuItemByID("Vote On New Games")->info = false;
	}
	else
	{
		startScreenMenu->getMenuItemByID("Online Multiplayer")->info = true;
		startScreenMenu->getMenuItemByID("Vote On New Games")->info = true;
	}

	if (getControlsManager()->miniGame_UP_Pressed())
	{
		startScreenMenu->up();
	}

	if (getControlsManager()->miniGame_DOWN_Pressed())
	{
		startScreenMenu->down();
	}

	bool confirm = getControlsManager()->miniGame_CONFIRM_Pressed();//, clicked, mx, my
	bool clicked = getControlsManager()->mouse_LEFTBUTTON_Pressed();
	int mx = getControlsManager()->getMouseX();
	int my = getControlsManager()->getMouseY();
	if (confirm || clicked)
	{

		bool leaveMenu = false;

		if (startScreenMenu->isSelectedID("Single Player", clicked, mx, my))
		{
			localMultiplayer = false;
			networkMultiplayer = false;
			gameSetupMenuShowing = true;
			leaveMenu = true;
		}
		if (startScreenMenu->isSelectedID("Local Multiplayer", clicked, mx, my))
		{
			localMultiplayer = true;
			networkMultiplayer = false;
			multiplayerOptionsMenuShowing = true;
			leaveMenu = true;
		}

		if (startScreenMenu->isSelectedID("Online Multiplayer", clicked, mx, my))
		{
			if (getServerConnection()->getConnectedToServer_S())
			{
				localMultiplayer = false;
				networkMultiplayer = true;
				loginMenuShowing = true;
				leaveMenu = true;
			}
		}

		if (startScreenMenu->isSelectedID("Stats", clicked, mx, my))
		{
			if (getServerConnection()->getConnectedToServer_S())
			{
				statsMenuShowing = true;
				leaveMenu = true;
			}
		}

		if (startScreenMenu->isSelectedID("Vote On New Games", clicked, mx, my))
		{
			if (getServerConnection()->getConnectedToServer_S())
			{
				gameTestMenuShowing = true;
				leaveMenu = true;
			}
		}

		if (startScreenMenu->isSelectedID("Custom Game Editor", clicked, mx, my))
		{
			customGameEditorMenuShowing = true;
			leaveMenu = true;
		}

		if (startScreenMenu->isSelectedID("Game Sequence Creator", clicked, mx, my))
		{
			gameSequenceEditorMenuShowing = true;
			leaveMenu = true;
		}

		if (startScreenMenu->isSelectedID("Global Settings", clicked, mx, my))
		{
			globalSettingsMenuShowing = true;
			leaveMenu = true;
		}

		if (startScreenMenu->isSelectedID("Controller Test", clicked, mx, my))
		{
			controllerMenuShowing = true;
			leaveMenu = true;
		}

		if (startScreenMenu->isSelectedID("Exit Game", clicked, mx, my))
		{
			Main::quit = true;
		}

		if (confirm == false && clicked == true)
		{
//			if (patreonMenu!=nullptr && patreonMenu->isSelectedID("Patreon", clicked, mx, my))
//			{
//				Main::openURL("https://www.patreon.com/bobsgame");
//			}
//
			if (forumMenu!=nullptr && forumMenu->isSelectedID("Open Forum", clicked, mx, my))
			{
				Main::openURL("https://www.bobsgame.com/forum");
			}
		}

		if (leaveMenu)
		{
			startScreenMenuShowing = false;

			if(startScreenMenu!=nullptr)
			{
				startScreenMenuCursorPosition = startScreenMenu->cursorPosition;
				delete startScreenMenu;
				startScreenMenu = nullptr;
			}
			if (infoMenu != nullptr)
			{
				delete infoMenu;
				infoMenu = nullptr;
			}
			if (patreonMenu != nullptr)
			{
				delete patreonMenu;
				patreonMenu = nullptr;
			}
			if (forumMenu != nullptr)
			{
				delete forumMenu;
				forumMenu = nullptr;
			}
		}
	}
}

void BobsGame::startScreenMenuRender()
{ //=========================================================================================================================

	GLUtils::drawFilledRect(255,255,255, 0, (float)getWidth(), 0, (float)getHeight(), 1.0f);

	BobTexture *t = nullptr;

	if (titleMenuTextures != nullptr && titleMenuTextures->size()>0)t = titleMenuTextures->get(currentTitleMenuTextureFrame);
	if (titleMenuTexture != nullptr)t = titleMenuTexture;

	if (startScreenMenu == nullptr)return;

	if (t != nullptr)
	{
		startScreenMenu->setGraphic(t, getWidth()/3*2, getHeight() / 10, getHeight()/3);
		startScreenMenu->render();
	}

	infoMenu->render(0, 6);// getHeight() - (infoMenu->getAmountOfMenuItems() * 20), 10);

//	if(patreonMenu!=nullptr)
//	{
//		Caption *c = infoMenu->getMenuItemByID("Build Number")->caption;
//		int x = c->screenX + c->getWidth();
//		int y = c->screenY;
//		patreonMenu->render(y, x);
//	}
//
	if(forumMenu!=nullptr)
	{
		Caption *c = infoMenu->getMenuItemByID("Open Forum")->caption;
		int x = x = c->screenX + c->getWidth();
		int y = y = c->screenY;
		forumMenu->render(y, x);
	}
}


void BobsGame::gettingGamesFromServerMenuUpdate()
{ //=========================================================================================================================

	updateTitleScreenLogo();

	if (gettingGamesFromServerMenu == nullptr)
	{
		gettingGamesFromServerMenu = new BobMenu(this, "");
		gettingGamesFromServerMenu->spacing = 1.2f;
		gettingGamesFromServerMenu->setFontSize(24);
		gettingGamesFromServerMenu->addInfo("Downloading games from server...","Downloading");
	}

	long long currentTime = System::currentHighResTimer();
	long long startTime = gettingGamesFromServerDotsTime;
	int ticksPassed = (int)(System::getTicksBetweenTimes(startTime, currentTime));
	if (ticksPassed > 300)
	{
		gettingGamesFromServerDotsTime = currentTime;
		gettingGamesFromServerCount++;
		gettingGamesFromServerMenu->getMenuItemByID("Downloading")->setText("Downloading games from server" + cycleDots(gettingGamesFromServerCount));
	}


}

void BobsGame::gettingGamesFromServerMenuRender()
{ //=========================================================================================================================

	GLUtils::drawFilledRect(255,255,255, 0, (float)getWidth(), 0, (float)getHeight(), 1.0f);

	BobTexture *t = nullptr;

	if (titleMenuTextures != nullptr && titleMenuTextures->size()>0)t = titleMenuTextures->get(currentTitleMenuTextureFrame);
	if (titleMenuTexture != nullptr)t = titleMenuTexture;

	if (gettingGamesFromServerMenu == nullptr)return;

	if (t != nullptr)
	{
		gettingGamesFromServerMenu->setGraphic(t, getWidth()/3*2, getHeight() / 10);
		gettingGamesFromServerMenu->render();
	}

}

void BobsGame::decreaseVolume()
{//=========================================================================================================================
	if (Main::globalSettings->musicVolume > 0)Main::globalSettings->musicVolume -= 1;
	if (Main::globalSettings->musicVolume < 0)Main::globalSettings->musicVolume = 0;
	music->setVolume(((float)Main::globalSettings->musicVolume / 100.0f));
}

void BobsGame::increaseVolume()
{//=========================================================================================================================
	if (Main::globalSettings->musicVolume < 100)Main::globalSettings->musicVolume += 1;
	if (Main::globalSettings->musicVolume > 100)Main::globalSettings->musicVolume = 100;
	music->setVolume(((float)Main::globalSettings->musicVolume / 100.0f));
}

//=========================================================================================================================
void BobsGame::pauseMenuUpdate()
{//=========================================================================================================================

	if(pauseMenu == nullptr)
	{
		pauseMenu = new BobMenu(this,"Paused");

		pauseMenu->add("Back To Game", "Back To Game");
		settingsMenuInit(pauseMenu);
		playerControllerSettingsMenuInit(pauseMenu, getPlayer1());
		pauseMenu->add("Quit Game And Return To Title Screen","Quit Game And Return To Title Screen");

		pauseMenu->cursorPosition = pauseMenuCursorPosition;
	}


	if(getControlsManager()->miniGame_UP_Pressed())
	{
		pauseMenu->up();
	}

	if(getControlsManager()->miniGame_DOWN_Pressed())
	{
		pauseMenu->down();
	}



	if (getControlsManager()->MINIGAME_LEFT_HELD)
	{
		settingsMenuLeft(pauseMenu);
	}
	if (getControlsManager()->MINIGAME_RIGHT_HELD)
	{
		settingsMenuRight(pauseMenu);
	}
	if (getControlsManager()->miniGame_LEFT_Pressed())
	{
		settingsMenuToggle(pauseMenu);
		playerControllerSettingsMenuToggle(pauseMenu,getPlayer1());
	}
	if (getControlsManager()->miniGame_RIGHT_Pressed())
	{
		settingsMenuToggle(pauseMenu);
		playerControllerSettingsMenuToggle(pauseMenu, getPlayer1());
	}

	bool leaveMenu = false;

	bool confirm = getControlsManager()->miniGame_CONFIRM_Pressed();//, clicked, mx, my
	bool clicked = getControlsManager()->mouse_LEFTBUTTON_Pressed();
	int mx = getControlsManager()->getMouseX();
	int my = getControlsManager()->getMouseY();
	if (confirm || clicked)
	{

		settingsMenuToggle(pauseMenu);
		playerControllerSettingsMenuToggle(pauseMenu, getPlayer1());

		if (pauseMenu->isSelectedID("Defaults", clicked, mx, my))
		{
			settingsMenuSetDefaults(pauseMenu);
		}

		if(pauseMenu->isSelectedID("Back To Game", clicked, mx, my))
		{
			leaveMenu = true;
		}

		if (pauseMenu->isSelectedID("Quit Game And Return To Title Screen", clicked, mx, my))
		{
			leaveMenu = true;
			startScreenMenuShowing = true;
			initPlayer();
		}

	}

	if (getControlsManager()->miniGame_CANCEL_Pressed())
	{
		leaveMenu = true;
	}

	if(leaveMenu)
	{
		pauseMenuShowing = false;

		if (pauseMenu != nullptr)
		{
			pauseMenuCursorPosition = pauseMenu->cursorPosition;
			delete pauseMenu;
			pauseMenu = nullptr;
		}
	}
}

//=========================================================================================================================
void BobsGame::pauseMenuRender()
{//=========================================================================================================================

//	if (pauseMenu != nullptr)
//	{
//		if(
//			pauseMenu->isSelectedID("Brightness") == false &&
//			pauseMenu->isSelectedID("Contrast") == false &&
//			pauseMenu->isSelectedID("Saturation") == false
//		)
//		{
//			GLUtils::drawFilledRect(255, 255, 255, 0, (float)getWidth(), 0, (float)getHeight(), 0.7f);
//		}
//	}

	BobTexture* t = keyboardTexture;

	if (pauseMenu == nullptr)return;

	if (t != nullptr)
	{
		pauseMenu->setGraphic(t, getWidth() / 8 * 5, getHeight() / 8);
	}

	pauseMenu->render(0, getWidth()/4, getHeight(), true, nullptr, nullptr, true);
}


//=========================================================================================================================
void BobsGame::controllerMenuUpdate()
{//=========================================================================================================================

	if (controllerMenu == nullptr)
	{

		//Game controllers are automatically detected.
		//Test your buttons here, press Esc to stop.
		//If your controller was not detected, you can create a new mapping for it.
		//This will be saved to disk and loaded automatically.

		//Test controls
		//Testing... Press Esc to stop.
		//Create custom mapping

		controllerMenu = new BobMenu(this, "Controller Test");
		controllerMenu->addInfo("Game controllers should be automatically detected.");
#ifdef _WINDOWS_
		controllerMenu->addInfo("If your controller does not work, try downloading x360ce.");
		controllerMenu->addInfo("You can also try the controller map tool in /data/ControllerMapTool");
#endif
		controllerMenu->addInfo("If it still does not work, please report to bugs@bobsgame.com");
		controllerMenu->addInfo(" ");
#ifdef _WINDOWS_
		controllerMenu->add("Use XInput (better controller support but 4 player max)", "XInput");
		controllerMenu->addInfo("");
#endif
		controllerMenu->add("Use Analog Sticks: ","Use Analog Sticks");
		controllerMenu->add("Test detected button mapping");
		controllerMenu->add("Return to Title Screen");
		controllerMenu->addInfo(" ", "Testing Caption");
		controllerMenu->addInfo(" ", "Button Press Caption");

		controllerMenu->cursorPosition = controllerMenuCursorPosition;
	}

#ifdef _WINDOWS_
	if(Main::globalSettings->useXInput)controllerMenu->getMenuItemByID("XInput")->setText("Use XInput (better controller support but 4 player max)");
	else controllerMenu->getMenuItemByID("XInput")->setText("Use DirectInput (worse controller support but no player limit)");
#endif

	if (Main::globalSettings->useAnalogSticks)controllerMenu->getMenuItemByID("Use Analog Sticks")->setText("Use Analog Sticks: Yes");
	else controllerMenu->getMenuItemByID("Use Analog Sticks")->setText("Use Analog Sticks: No");

	if(controllerMenuTestingButtons)
	{
		controllerMenu->getMenuItemByID("Testing Caption")->setColor(BobColor::lightGreen);
		controllerMenu->getMenuItemByID("Testing Caption")->setText("Testing buttons... Press Esc key or hold Start and Select on controller to stop");

		BobMenu::MenuItem *m = controllerMenu->getMenuItemByID("Button Press Caption");

		for (int i = 0; i < getControlsManager()->gameControllers.size(); i++)
		{
			GameController *g = getControlsManager()->gameControllers.get(i);

			m->setColor(BobColor::lightRed);

			if (g->up_Pressed())m->setText("Controller "+to_string(i)+" Up Pressed");
			if (g->down_Pressed())m->setText("Controller " + to_string(i) + " Down Pressed");
			if (g->left_Pressed())m->setText("Controller " + to_string(i) + " Left Pressed");
			if (g->right_Pressed())m->setText("Controller " + to_string(i) + " Right Pressed");
			if (g->b_Pressed())m->setText("Controller " + to_string(i) + " B Pressed");
			if (g->a_Pressed())m->setText("Controller " + to_string(i) + " A Pressed");
			if (g->x_Pressed())m->setText("Controller " + to_string(i) + " X Pressed");
			if (g->y_Pressed())m->setText("Controller " + to_string(i) + " Y Pressed");
			if (g->start_Pressed())m->setText("Controller " + to_string(i) + " Start Pressed");
			if (g->select_Pressed())m->setText("Controller " + to_string(i) + " Select Pressed");
			if (g->l_Pressed())m->setText("Controller " + to_string(i) + " L Pressed");
			if (g->r_Pressed())m->setText("Controller " + to_string(i) + " R Pressed");
		}

		if (getControlsManager()->key_ESC_Pressed() || (getControlsManager()->MINIGAME_START_HELD && getControlsManager()->MINIGAME_SELECT_HELD))
		{
			controllerMenuTestingButtons = false;
			controllerMenu->getMenuItemByID("Testing Caption")->setText(" ");
			controllerMenu->getMenuItemByID("Button Press Caption")->setText(" ");
		}

	}
	else
	{

		if (getControlsManager()->miniGame_UP_Pressed())
		{
			controllerMenu->up();
		}

		if (getControlsManager()->miniGame_DOWN_Pressed())
		{
			controllerMenu->down();
		}

		bool leaveMenu = false;

		bool confirm = getControlsManager()->miniGame_CONFIRM_Pressed();//, clicked, mx, my
		bool clicked = getControlsManager()->mouse_LEFTBUTTON_Pressed();
		int mx = getControlsManager()->getMouseX();
		int my = getControlsManager()->getMouseY();

		if (confirm || clicked)
		{

			if (controllerMenu->isSelectedID("Use Analog Sticks", clicked, mx, my))
			{
				Main::globalSettings->useAnalogSticks = !Main::globalSettings->useAnalogSticks;
			}

			if (controllerMenu->isSelectedID("XInput", clicked, mx, my))
			{
				Main::globalSettings->useXInput = !Main::globalSettings->useXInput;
				controllerMenu->getMenuItemByID("Button Press Caption")->setText("Must Restart To Apply Changes!");
			}

			if (controllerMenu->isSelectedID("Test detected button mapping", clicked, mx, my))
			{
				//testing
				controllerMenuTestingButtons = true;
			}
			if (controllerMenu->isSelectedID("Return to Title Screen", clicked, mx, my))
			{
				startScreenMenuShowing = true;
				leaveMenu = true;
			}
		}

		if(getControlsManager()->miniGame_CANCEL_Pressed())
		{
			startScreenMenuShowing = true;
			leaveMenu = true;
		}

		if(leaveMenu)
		{
			controllerMenuShowing = false;

			if (controllerMenu != nullptr)
			{
				controllerMenuCursorPosition = controllerMenu->cursorPosition;
				delete controllerMenu;
				controllerMenu = nullptr;
			}
		}
	}
}

//=========================================================================================================================
void BobsGame::controllerMenuRender()
{//=========================================================================================================================

	GLUtils::drawFilledRect(BobMenu::bgColor->ri(), BobMenu::bgColor->gi(), BobMenu::bgColor->bi(), 0, (float)getWidth(), 0, (float)getHeight(), 1.0f);

	BobTexture* t = controllerTexture;

	if (controllerMenu == nullptr)return;

	if (t != nullptr)
	{
		controllerMenu->setGraphic(t, getWidth() / 3 * 1, getHeight() / 8);
	}

	controllerMenu->render();
}



//=========================================================================================================================
void BobsGame::playerSettingsMenuInit(BobMenu* m, PuzzlePlayer *p)
{//=========================================================================================================================

	m->add("Player Hue Shift: " + to_string((int)(p->hue * 100)) + "%", "Player Hue Shift");
}
//=========================================================================================================================
void BobsGame::playerSettingsMenuLeft(BobMenu* m, PuzzlePlayer *p)
{//=========================================================================================================================

	if (m->isSelectedID("Player Hue Shift"))
	{
		long long startTime = timeLastChangedSetting;
		long long currentTime = System::currentHighResTimer();
		int ticksPassed = (int)(System::getTicksBetweenTimes(startTime, currentTime));

		if (ticksPassed > 15)
		{
			timeLastChangedSetting = currentTime;
			if (p->hue > 0)p->hue -= 0.01f;
			if (p->hue < 0)p->hue = 0;
			m->getMenuItemByID("Player Hue Shift")->setText("Player Hue Shift: " + to_string((int)(p->hue * 100)) + "%");
		}
	}

}

//=========================================================================================================================
void BobsGame::playerSettingsMenuRight(BobMenu* m, PuzzlePlayer *p)
{//=========================================================================================================================

	if (m->isSelectedID("Player Hue Shift"))
	{
		long long startTime = timeLastChangedSetting;
		long long currentTime = System::currentHighResTimer();
		int ticksPassed = (int)(System::getTicksBetweenTimes(startTime, currentTime));

		if (ticksPassed > 15)
		{
			timeLastChangedSetting = currentTime;
			if (p->hue < 1)p->hue += 0.01f;
			if (p->hue > 1)p->hue = 1;
			m->getMenuItemByID("Player Hue Shift")->setText("Player Hue Shift: " + to_string((int)(p->hue * 100)) + "%");
		}
	}

}
//=========================================================================================================================
void BobsGame::playerControllerSettingsMenuInit(BobMenu* m, PuzzlePlayer *p)
{//=========================================================================================================================

	m->add("Slam With Up: " + string(p->slamWithUp ? "On" : "Off"), "Slam With Up");
	m->add("Slam Lock: " + string(p->slamLock ? "On" : "Off"), "Slam Lock");
	m->add("Single Down Lock: " + string(p->singleDownLock ? "On" : "Off"), "Single Down Lock");
	m->add("Double Down Lock: " + string(p->doubleDownLock ? "On" : "Off"), "Double Down Lock");

}

//=========================================================================================================================
void BobsGame::playerControllerSettingsMenuToggle(BobMenu* m, PuzzlePlayer *p)
{//=========================================================================================================================

	if (m->isSelectedID("Slam With Up"))
	{
		long long startTime = timeLastChangedSetting;
		long long currentTime = System::currentHighResTimer();
		int ticksPassed = (int)(System::getTicksBetweenTimes(startTime, currentTime));

		if (ticksPassed > 15)
		{
			timeLastChangedSetting = currentTime;
			p->slamWithUp = !p->slamWithUp;
			m->getMenuItemByID("Slam With Up")->setText("Slam With Up: " + string(p->slamWithUp ? "On" : "Off"));
		}
	}

	if (m->isSelectedID("Slam Lock"))
	{
		long long startTime = timeLastChangedSetting;
		long long currentTime = System::currentHighResTimer();
		int ticksPassed = (int)(System::getTicksBetweenTimes(startTime, currentTime));

		if (ticksPassed > 15)
		{
			timeLastChangedSetting = currentTime;
			p->slamLock = !p->slamLock;
			m->getMenuItemByID("Slam Lock")->setText("Slam Lock: " + string(p->slamLock ? "On" : "Off"));
		}
	}

	if (m->isSelectedID("Single Down Lock"))
	{
		long long startTime = timeLastChangedSetting;
		long long currentTime = System::currentHighResTimer();
		int ticksPassed = (int)(System::getTicksBetweenTimes(startTime, currentTime));

		if (ticksPassed > 15)
		{
			timeLastChangedSetting = currentTime;
			p->singleDownLock = !p->singleDownLock;
			m->getMenuItemByID("Single Down Lock")->setText("Single Down Lock: " + string(p->singleDownLock ? "On" : "Off"));
		}
	}

	if (m->isSelectedID("Double Down Lock"))
	{
		long long startTime = timeLastChangedSetting;
		long long currentTime = System::currentHighResTimer();
		int ticksPassed = (int)(System::getTicksBetweenTimes(startTime, currentTime));

		if (ticksPassed > 15)
		{
			timeLastChangedSetting = currentTime;
			p->doubleDownLock = !p->doubleDownLock;
			m->getMenuItemByID("Double Down Lock")->setText("Double Down Lock: " + string(p->doubleDownLock ? "On" : "Off"));
		}
	}



}

//=========================================================================================================================
void BobsGame::playerPauseMiniMenuUpdate(PuzzlePlayer *p)
{//=========================================================================================================================

	if (p != nullptr)
	{
		if (p->menu == nullptr)
		{
			p->menu = new BobMenu(this, "");

			p->menu->add("Back To Game", "Back To Game", BobColor::white);
			settingsMenuInit(p->menu);

			playerSettingsMenuInit(p->menu, p);


			playerControllerSettingsMenuInit(p->menu, p);

			p->menu->addInfo(" ");
			p->menu->add("Forfeit", "Forfeit", BobColor::white);
		}

		if (p->upPressed())
		{
			p->menu->up();
		}

		if (p->downPressed())
		{
			p->menu->down();
		}

		if (p->LEFT_HELD)
		{
			settingsMenuLeft(p->menu);
			playerSettingsMenuLeft(p->menu,p);
		}
		if (p->RIGHT_HELD)
		{
			settingsMenuRight(p->menu);
			playerSettingsMenuRight(p->menu, p);
		}

		if (p->leftPressed())
		{
			settingsMenuToggle(p->menu);
			playerControllerSettingsMenuToggle(p->menu, p);
		}
		if (p->rightPressed())
		{
			settingsMenuToggle(p->menu);
			playerControllerSettingsMenuToggle(p->menu, p);
		}

		bool leaveMenu = false;
		//bool deletePlayer = false;

		if (p->confirmPressed())
		{

			settingsMenuToggle(p->menu);
			playerControllerSettingsMenuToggle(p->menu, p);


			if (p->menu->isSelectedID("Defaults"))
			{
				settingsMenuSetDefaults(p->menu);

				p->hue = 1.0f;
				p->menu->getMenuItemByID("Player Hue Shift")->setText("Player Hue Shift: " + to_string((int)(p->hue * 100)) + "%");


			}

			if (p->menu->isSelectedID("Back To Game"))
			{
				leaveMenu = true;
			}

			if (p->menu->isSelectedID("Forfeit"))
			{
				//if (isMultiplayer())
				{
					if (isNetworkGame())
					{
						tellAllPeersOneOfMyPlayersForfeitsGame(p);
					}

					p->gameLogic->died = true;
					//players.remove(p);
					//deletePlayer = true;

					bool allLocalPlayersDead = true;
					for (int i = 0; i < players.size(); i++)
					{
						PuzzlePlayer *o = players.get(i);
						if (o->isNetworkPlayer() == false && o->gameLogic->died==false)allLocalPlayersDead = false;
					}

					if (allLocalPlayersDead)
					{
						if (isNetworkGame())
						{

							if (hosting)
							{
								//send to all friends disconnected
								tellAllPeersIAmNotHosting();
							}

							tellAllJoinedPeersIHaveLeftTheGame();

							BobNet::myStatus = BobNet::status_AVAILABLE;
							joinedPeers->clear();
							networkMultiplayerLobbyMenuShowing = true;
						}
						else
						{
							localMultiplayerPlayerJoinMenuShowing = true;
						}


						initPlayer();
					}
					leaveMenu = true;
				}
			}
		}

		if (p->cancelPressed())
		{
			leaveMenu = true;
		}

		if (leaveMenu)
		{
			if (p->menu != nullptr)
			{
				delete p->menu;
				p->menu = nullptr;
			}
			p->gameLogic->pauseMiniMenuShowing = false;

//			if(deletePlayer)
//			{
//				delete p;
//				return false;
//			}
//			return true;
		}
	}
	//return true;
}

//=========================================================================================================================
void BobsGame::playerPauseMiniMenuRender(PuzzlePlayer *p, float x0, float x1, float y0, float y1)
{//=========================================================================================================================

	//GLUtils::drawFilledRect(255,255,255, x0,x1,y0,y1, 0.7f);

	if (p->menu != nullptr)
	{
		p->menu->render((int)(y0+((y1-y0)/2)), (int)(x0 + ((x1 - x0) / 2)),getHeight(),true,nullptr,nullptr,true);
	}
}

//=========================================================================================================================
void BobsGame::loginMenuUpdate()
{//=========================================================================================================================

	//log in
	//save login
	//create account

	int y = (int)(getHeight() / 4 * 3);

	if (statusLabel == nullptr)statusLabel = getCaptionManager()->newManagedCaption(Caption::Position::CENTERED_X, 0, y, -1, " ", 16, true, BobMenu::statusColor, BobMenu::clearColor, RenderOrder::OVER_GUI);
	if (errorLabel == nullptr)errorLabel = getCaptionManager()->newManagedCaption(Caption::Position::CENTERED_X, 0, y, -1, " ", 16, true, BobMenu::errorColor, BobMenu::clearColor, RenderOrder::OVER_GUI);

	if (loginMenu == nullptr)
	{
		loginMenu = new BobMenu(this, "Login");
		//loginMenu->center = false;
		loginMenu->add("Username or Email: " + userNameOrEmailText,"Username or Email", BobMenu::statusColor);
		loginMenu->add("Password: " + passwordStarsText, "Password", BobMenu::statusColor);
		loginMenu->add("Stay logged in: Yes", "Stay logged in");
		loginMenu->add("Log in");
		loginMenu->addInfo(" ");
		loginMenu->add("Create new account");
		loginMenu->add("Forgot password");
		loginMenu->addInfo(" ");
		loginMenu->add("Return to title screen");

		loginMenu->cursorPosition = loginMenuCursorPosition;
	}

	int mx = getControlsManager()->getMouseX();
	int my = getControlsManager()->getMouseY();

	if (mx != lastMX || my != lastMY)
	{
		if (textStarted) { SDL_StopTextInput(); textStarted = false; }
		lastMX = mx;
		lastMY = my;
	}

	if (getControlsManager()->miniGame_UP_Pressed())
	{
		loginMenu->up();

		if (textStarted) { SDL_StopTextInput(); textStarted = false; }
	}

	if (getControlsManager()->miniGame_DOWN_Pressed() || getControlsManager()->key_TAB_Pressed())
	{
		loginMenu->down();

		if (textStarted) { SDL_StopTextInput(); textStarted = false; }
	}

	bool confirm = getControlsManager()->miniGame_CONFIRM_Pressed();//, clicked, mx, my
	bool clicked = getControlsManager()->mouse_LEFTBUTTON_Pressed();

	if (confirm || clicked || (getControlsManager()->miniGame_LEFT_Pressed() || getControlsManager()->miniGame_RIGHT_Pressed()))
	{
		if (loginMenu->isSelectedID("Stay logged in", clicked, mx, my))
		{
			stayLoggedIn = !stayLoggedIn;

			if (stayLoggedIn)loginMenu->getMenuItemByID("Stay logged in")->setText("Stay logged in: Yes");
			else loginMenu->getMenuItemByID("Stay logged in")->setText("Stay logged in: No");

		}
	}

	if (loginMenu->isSelectedID("Username or Email"))
	{
		if (!textStarted) { SDL_StartTextInput(); getControlsManager()->text = userNameOrEmailText; textStarted = true;}
		userNameOrEmailText = getControlsManager()->text;
		loginMenu->getMenuItemByID("Username or Email")->setText("Username or Email: " + userNameOrEmailText);
	}

	if (loginMenu->isSelectedID("Password"))
	{
		if (!textStarted) { SDL_StartTextInput(); getControlsManager()->text = passwordText; textStarted = true; }
		passwordText = getControlsManager()->text;
		passwordStarsText = "";
		for (int i = 0; i < (int)passwordText.length(); i++)passwordStarsText += "*";
		loginMenu->getMenuItemByID("Password")->setText("Password: " + passwordStarsText);
	}

	bool leaveMenu = false;

	if (confirm || clicked)
	{

		if (loginMenu->isSelectedID("Log in", clicked, mx, my) || loginMenu->isSelectedID("Password", clicked, mx, my))
		{
			getServerConnection()->doLogin(statusLabel, errorLabel,userNameOrEmailText,passwordText,stayLoggedIn);
		}

		if (loginMenu->isSelectedID("Create new account", clicked, mx, my))
		{
			leaveMenu = true;
			createAccountMenuShowing = true;
		}

		if (loginMenu->isSelectedID("Forgot password", clicked, mx, my))
		{
			getServerConnection()->doForgotPassword(statusLabel,errorLabel,userNameOrEmailText);
		}

		if (loginMenu->isSelectedID("Return to title screen", clicked, mx, my))
		{
			//back to title screen
			leaveMenu = true;
			titleMenuShowing = true;
		}

	}

	if (getServerConnection()->getAuthorizedOnServer_S())
	{
		leaveMenu = true;
		if (networkMultiplayer)networkMultiplayerLobbyMenuShowing = true;
		else startScreenMenuShowing = true;
	}

	if (getControlsManager()->key_ESC_Pressed() || getControlsManager()->miniGame_SELECT_Pressed())
	{
		leaveMenu = true;
		startScreenMenuShowing = true;
	}

	if (leaveMenu)
	{
		if (textStarted) { SDL_StopTextInput(); textStarted = false; }
		getControlsManager()->text = "";

		loginMenuShowing = false;

		if (loginMenu != nullptr)
		{
			loginMenuCursorPosition = loginMenu->cursorPosition;
			delete loginMenu;
			loginMenu = nullptr;
		}

		if (statusLabel != nullptr)
		{
			statusLabel->setToBeDeletedImmediately();
			statusLabel = nullptr;
		}

		if (errorLabel != nullptr)
		{
			errorLabel->setToBeDeletedImmediately();
			errorLabel = nullptr;
		}
	}

}


//=========================================================================================================================
void BobsGame::loginMenuRender()
{//=========================================================================================================================

	GLUtils::drawFilledRect(BobMenu::bgColor->ri(), BobMenu::bgColor->gi(), BobMenu::bgColor->bi(), 0, (float)getWidth(), 0, (float)getHeight(), 1.0f);

	BobTexture* t = onlineTexture;

	if (loginMenu == nullptr)return;

	if (t != nullptr)
	{
		loginMenu->setGraphic(t, getWidth() / 8 * 4, 100);
	}

	if (statusLabel != nullptr && errorLabel != nullptr)
	{
		errorLabel->screenY = (float)(getHeight() / 4 * 3);
		statusLabel->screenY = (float)((getHeight() / 4 * 3) + 24);
	}

	loginMenu->render();
}

//=========================================================================================================================
void BobsGame::createAccountMenuUpdate()
{//=========================================================================================================================

	if (createAccountMenu == nullptr)
	{
		int y = (int)(getHeight() / 4 * 3);

		if (statusLabel == nullptr)statusLabel = getCaptionManager()->newManagedCaption(Caption::Position::CENTERED_X, 0, y, -1, " ", 16, true, BobMenu::statusColor, BobMenu::clearColor, RenderOrder::OVER_GUI);
		if (errorLabel == nullptr)errorLabel = getCaptionManager()->newManagedCaption(Caption::Position::CENTERED_X, 0, y, -1, " ", 16, true, BobMenu::errorColor, BobMenu::clearColor, RenderOrder::OVER_GUI);

		if (userNameOrEmailText.length()>0)
		{
			if (userNameOrEmailText.find("@") != string::npos)
				emailText = userNameOrEmailText;
			else
				userNameText = userNameOrEmailText;
		}

		createAccountMenu = new BobMenu(this, "Create Account");
		//createAccountMenu->center = false;
		createAccountMenu->add("Username: " + userNameText, "Username");
		createAccountMenu->add("Email: " + emailText, "Email");
		createAccountMenu->add("Password: " + passwordStarsText, "Password");
		createAccountMenu->add("Confirm password: " + confirmPasswordStarsText, "Confirm");
		createAccountMenu->add("Create account");
		createAccountMenu->addInfo(" ");
		createAccountMenu->add("Return to login screen");
	}

	int mx = getControlsManager()->getMouseX();
	int my = getControlsManager()->getMouseY();

	if(mx!=lastMX || my !=lastMY)
	{
		if (textStarted) { SDL_StopTextInput(); textStarted = false; }
		lastMX = mx;
		lastMY = my;
	}

	if (getControlsManager()->miniGame_UP_Pressed())
	{
		createAccountMenu->up();

		if (textStarted) { SDL_StopTextInput(); textStarted = false; }
	}

	if (getControlsManager()->miniGame_DOWN_Pressed() || getControlsManager()->key_TAB_Pressed())
	{
		createAccountMenu->down();

		if (textStarted) { SDL_StopTextInput(); textStarted = false; }
	}

	if (createAccountMenu->isSelectedID("Username"))
	{
		if (!textStarted) { SDL_StartTextInput(); getControlsManager()->text = userNameText; textStarted = true; }
		userNameText = getControlsManager()->text;
		createAccountMenu->getMenuItemByID("Username")->setText("Username: " + userNameText);
	}

	if (createAccountMenu->isSelectedID("Email"))
	{
		if (!textStarted) { SDL_StartTextInput(); getControlsManager()->text = emailText; textStarted = true; }
		emailText = getControlsManager()->text;
		createAccountMenu->getMenuItemByID("Email")->setText("Email: " + emailText);
	}

	if (createAccountMenu->isSelectedID("Password"))
	{
		if (!textStarted) { SDL_StartTextInput(); getControlsManager()->text = passwordText; textStarted = true; }
		passwordText = getControlsManager()->text;
		passwordStarsText = "";
		for (int i = 0; i < (int)passwordText.length(); i++)passwordStarsText += "*";
		createAccountMenu->getMenuItemByID("Password")->setText("Password: " + passwordStarsText);
	}

	if (createAccountMenu->isSelectedID("Confirm"))
	{
		if (!textStarted) { SDL_StartTextInput(); getControlsManager()->text = confirmPasswordText; textStarted = true; }
		confirmPasswordText = getControlsManager()->text;
		confirmPasswordStarsText = "";
		for (int i = 0; i < (int)confirmPasswordText.length(); i++)confirmPasswordStarsText += "*";
		createAccountMenu->getMenuItemByID("Confirm")->setText("Confirm password: " + confirmPasswordStarsText);
	}

	bool leaveMenu = false;

	bool confirm = getControlsManager()->miniGame_CONFIRM_Pressed();//, clicked, mx, my
	bool clicked = getControlsManager()->mouse_LEFTBUTTON_Pressed();
	if (confirm || clicked)
	{
		if (createAccountMenu->isSelectedID("Create account", clicked, mx, my))
		{
			if(getServerConnection()->doCreateAccount(statusLabel,errorLabel,userNameText,emailText,passwordText,confirmPasswordText)==true)
			{

				Main::delay(2000);

				if(getServerConnection()->doLogin(statusLabel, errorLabel, userNameText, passwordText, true)==true)
				{
					startScreenMenuShowing = true;
				}
				else
				{
					loginMenuShowing = true;
				}
				leaveMenu = true;

			}
		}

		if (createAccountMenu->isSelectedID("Return to login screen", clicked, mx, my))
		{
			//back to title screen
			leaveMenu = true;
			loginMenuShowing = true;
		}
	}

	if (getControlsManager()->key_ESC_Pressed() || getControlsManager()->miniGame_SELECT_Pressed())
	{
		leaveMenu = true;
		loginMenuShowing = true;
	}

	if (leaveMenu)
	{
		if (textStarted) { SDL_StopTextInput(); textStarted = false; }
		getControlsManager()->text = "";

		createAccountMenuShowing = false;

		if(createAccountMenu != nullptr)
		{
			delete createAccountMenu;
			createAccountMenu = nullptr;
		}

		if (statusLabel != nullptr)
		{
			statusLabel->setToBeDeletedImmediately();
			statusLabel = nullptr;
		}

		if (errorLabel != nullptr)
		{
			errorLabel->setToBeDeletedImmediately();
			errorLabel = nullptr;
		}
	}

}


//=========================================================================================================================
void BobsGame::createAccountMenuRender()
{//=========================================================================================================================

	GLUtils::drawFilledRect(BobMenu::bgColor->ri(), BobMenu::bgColor->gi(), BobMenu::bgColor->bi(), 0, (float)getWidth(), 0, (float)getHeight(), 1.0f);

	BobTexture* t = onlineTexture;

	if (createAccountMenu == nullptr)return;

	if (t != nullptr)
	{
		createAccountMenu->setGraphic(t, getWidth() / 8 * 4, 20);
	}

	if (statusLabel != nullptr && errorLabel != nullptr)
	{
		errorLabel->screenY = (float)(getHeight() / 4 * 3);
		statusLabel->screenY = (float)((getHeight() / 4 * 3) + 24);
	}

	createAccountMenu->render();

}

//=========================================================================================================================
void BobsGame::settingsMenuInit(BobMenu* m)
{//=========================================================================================================================
	m->add("Music Volume: " + to_string((int)(music->getVolume() * 100)) + "%", "Music Volume");
	m->add("Brightness: " + to_string((int)(Main::globalSettings->brightness * 100)) + "%", "Brightness");
	m->add("Contrast: " + to_string((int)(Main::globalSettings->contrast * 100)) + "%", "Contrast");
	m->add("Saturation: " + to_string((int)(Main::globalSettings->saturation * 100)) + "%", "Saturation");

	m->add("Global Hue Shift: " + to_string((int)(Main::globalSettings->hue * 100)) + "%", "Global Hue Shift");
	m->add("Level Up Screen Flash: " + to_string((int)(Main::globalSettings->bobsGame_screenFlashOnLevelUpAlpha * 100 * 2)) + "%", "Screen Flash");
	m->add("Show Detailed Game Stats: " + string(Main::globalSettings->bobsGame_showDetailedGameInfoCaptions ? "On" : "Off"), "Game Stats");

	m->add("Defaults");
}

//=========================================================================================================================
void BobsGame::settingsMenuToggle(BobMenu* m)
{//=========================================================================================================================

	if (m->isSelectedID("Game Stats"))
	{
		long long startTime = timeLastChangedSetting;
		long long currentTime = System::currentHighResTimer();
		int ticksPassed = (int)(System::getTicksBetweenTimes(startTime, currentTime));

		if (ticksPassed > 15)
		{
			timeLastChangedSetting = currentTime;
			Main::globalSettings->bobsGame_showDetailedGameInfoCaptions = !Main::globalSettings->bobsGame_showDetailedGameInfoCaptions;

			getPlayer1Game()->deleteInfoCaptions();

			m->getMenuItemByID("Game Stats")->setText("Show Detailed Game Stats: " + string(Main::globalSettings->bobsGame_showDetailedGameInfoCaptions ? "On" : "Off"));
		}
	}

}



//=========================================================================================================================
void BobsGame::settingsMenuLeft(BobMenu* m)
{//=========================================================================================================================
	if (m->isSelectedID("Music Volume"))
	{
		long long startTime = timeLastChangedSetting;
		long long currentTime = System::currentHighResTimer();
		int ticksPassed = (int)(System::getTicksBetweenTimes(startTime, currentTime));

		if (ticksPassed > 15)
		{
			timeLastChangedSetting = currentTime;
			decreaseVolume();
			m->getMenuItemByID("Music Volume")->setText("Music Volume: " + to_string((int)(music->getVolume() * 100)) + "%");
		}
	}

	if (m->isSelectedID("Brightness"))
	{
		long long startTime = timeLastChangedSetting;
		long long currentTime = System::currentHighResTimer();
		int ticksPassed = (int)(System::getTicksBetweenTimes(startTime, currentTime));

		if (ticksPassed > 15)
		{
			timeLastChangedSetting = currentTime;
			if (Main::globalSettings->brightness > 0)Main::globalSettings->brightness -= 0.01f;
			if (Main::globalSettings->brightness < 0)Main::globalSettings->brightness = 0;
			m->getMenuItemByID("Brightness")->setText("Brightness: " + to_string((int)(Main::globalSettings->brightness * 100)) + "%");
		}
	}

	if (m->isSelectedID("Contrast"))
	{
		long long startTime = timeLastChangedSetting;
		long long currentTime = System::currentHighResTimer();
		int ticksPassed = (int)(System::getTicksBetweenTimes(startTime, currentTime));

		if (ticksPassed > 15)
		{
			timeLastChangedSetting = currentTime;
			if (Main::globalSettings->contrast > 0)Main::globalSettings->contrast -= 0.01f;
			if (Main::globalSettings->contrast < 0)Main::globalSettings->contrast = 0;
			m->getMenuItemByID("Contrast")->setText("Contrast: " + to_string((int)(Main::globalSettings->contrast * 100)) + "%");
		}
	}

	if (m->isSelectedID("Saturation"))
	{
		long long startTime = timeLastChangedSetting;
		long long currentTime = System::currentHighResTimer();
		int ticksPassed = (int)(System::getTicksBetweenTimes(startTime, currentTime));

		if (ticksPassed > 15)
		{
			timeLastChangedSetting = currentTime;
			if (Main::globalSettings->saturation > 0)Main::globalSettings->saturation -= 0.01f;
			if (Main::globalSettings->saturation < 0)Main::globalSettings->saturation = 0;
			m->getMenuItemByID("Saturation")->setText("Saturation: " + to_string((int)(Main::globalSettings->saturation * 100)) + "%");
		}
	}

	if (m->isSelectedID("Global Hue Shift"))
	{
		long long startTime = timeLastChangedSetting;
		long long currentTime = System::currentHighResTimer();
		int ticksPassed = (int)(System::getTicksBetweenTimes(startTime, currentTime));

		if (ticksPassed > 15)
		{
			timeLastChangedSetting = currentTime;
			if (Main::globalSettings->hue > 0)Main::globalSettings->hue -= 0.01f;
			if (Main::globalSettings->hue < 0)Main::globalSettings->hue = 0;
			m->getMenuItemByID("Global Hue Shift")->setText("Global Hue Shift: " + to_string((int)(Main::globalSettings->hue * 100)) + "%");
		}
	}

	if (m->isSelectedID("Screen Flash"))
	{
		long long startTime = timeLastChangedSetting;
		long long currentTime = System::currentHighResTimer();
		int ticksPassed = (int)(System::getTicksBetweenTimes(startTime, currentTime));

		if (ticksPassed > 15)
		{
			timeLastChangedSetting = currentTime;
			if (Main::globalSettings->bobsGame_screenFlashOnLevelUpAlpha > 0)Main::globalSettings->bobsGame_screenFlashOnLevelUpAlpha -= 0.01f;
			if (Main::globalSettings->bobsGame_screenFlashOnLevelUpAlpha < 0)Main::globalSettings->bobsGame_screenFlashOnLevelUpAlpha = 0;
			m->getMenuItemByID("Screen Flash")->setText("Level Up Screen Flash: " + to_string((int)(Main::globalSettings->bobsGame_screenFlashOnLevelUpAlpha * 100 * 2)) + "%");
		}
	}


}

//=========================================================================================================================
void BobsGame::settingsMenuRight(BobMenu* m)
{//=========================================================================================================================
	if (m->isSelectedID("Music Volume"))
	{
		long long startTime = timeLastChangedSetting;
		long long currentTime = System::currentHighResTimer();
		int ticksPassed = (int)(System::getTicksBetweenTimes(startTime, currentTime));

		if (ticksPassed > 15)
		{
			timeLastChangedSetting = currentTime;
			increaseVolume();
			m->getMenuItemByID("Music Volume")->setText("Music Volume: " + to_string((int)(music->getVolume() * 100)) + "%");
		}
	}
	if (m->isSelectedID("Brightness"))
	{
		long long startTime = timeLastChangedSetting;
		long long currentTime = System::currentHighResTimer();
		int ticksPassed = (int)(System::getTicksBetweenTimes(startTime, currentTime));

		if (ticksPassed > 15)
		{
			timeLastChangedSetting = currentTime;
			if (Main::globalSettings->brightness < 2)Main::globalSettings->brightness += 0.01f;
			if (Main::globalSettings->brightness > 2)Main::globalSettings->brightness = 2;
			m->getMenuItemByID("Brightness")->setText("Brightness: " + to_string((int)(Main::globalSettings->brightness * 100)) + "%");
		}
	}

	if (m->isSelectedID("Contrast"))
	{
		long long startTime = timeLastChangedSetting;
		long long currentTime = System::currentHighResTimer();
		int ticksPassed = (int)(System::getTicksBetweenTimes(startTime, currentTime));

		if (ticksPassed > 15)
		{
			timeLastChangedSetting = currentTime;
			if (Main::globalSettings->contrast < 2)Main::globalSettings->contrast += 0.01f;
			if (Main::globalSettings->contrast > 2)Main::globalSettings->contrast = 2;
			m->getMenuItemByID("Contrast")->setText("Contrast: " + to_string((int)(Main::globalSettings->contrast * 100)) + "%");
		}
	}

	if (m->isSelectedID("Saturation"))
	{
		long long startTime = timeLastChangedSetting;
		long long currentTime = System::currentHighResTimer();
		int ticksPassed = (int)(System::getTicksBetweenTimes(startTime, currentTime));

		if (ticksPassed > 15)
		{
			timeLastChangedSetting = currentTime;
			if (Main::globalSettings->saturation < 2)Main::globalSettings->saturation += 0.01f;
			if (Main::globalSettings->saturation > 2)Main::globalSettings->saturation = 2;
			m->getMenuItemByID("Saturation")->setText("Saturation: " + to_string((int)(Main::globalSettings->saturation * 100)) + "%");
		}
	}

	if (m->isSelectedID("Global Hue Shift"))
	{
		long long startTime = timeLastChangedSetting;
		long long currentTime = System::currentHighResTimer();
		int ticksPassed = (int)(System::getTicksBetweenTimes(startTime, currentTime));

		if (ticksPassed > 15)
		{
			timeLastChangedSetting = currentTime;
			if (Main::globalSettings->hue < 1)Main::globalSettings->hue += 0.01f;
			if (Main::globalSettings->hue > 1)Main::globalSettings->hue = 1;
			m->getMenuItemByID("Global Hue Shift")->setText("Global Hue Shift: " + to_string((int)(Main::globalSettings->hue * 100)) + "%");
		}
	}

	if (m->isSelectedID("Screen Flash"))
	{
		long long startTime = timeLastChangedSetting;
		long long currentTime = System::currentHighResTimer();
		int ticksPassed = (int)(System::getTicksBetweenTimes(startTime, currentTime));

		if (ticksPassed > 15)
		{
			timeLastChangedSetting = currentTime;
			if (Main::globalSettings->bobsGame_screenFlashOnLevelUpAlpha < 0.5f)Main::globalSettings->bobsGame_screenFlashOnLevelUpAlpha += 0.01f;
			if (Main::globalSettings->bobsGame_screenFlashOnLevelUpAlpha > 0.5f)Main::globalSettings->bobsGame_screenFlashOnLevelUpAlpha = 0.5f;
			m->getMenuItemByID("Screen Flash")->setText("Level Up Screen Flash: " + to_string((int)(Main::globalSettings->bobsGame_screenFlashOnLevelUpAlpha * 100 * 2)) + "%");
		}
	}


}

//=========================================================================================================================
void BobsGame::settingsMenuSetDefaults(BobMenu* m)
{//=========================================================================================================================

	GlobalSettings gs;
	Main::globalSettings->musicVolume = gs.musicVolume;
	Main::globalSettings->hue = gs.hue;
	Main::globalSettings->saturation = gs.saturation;
	Main::globalSettings->brightness = gs.brightness;
	Main::globalSettings->contrast = gs.contrast;
	Main::globalSettings->gamma = gs.gamma;
	Main::globalSettings->bobsGame_screenFlashOnLevelUpAlpha = gs.bobsGame_screenFlashOnLevelUpAlpha;
	Main::globalSettings->bobsGame_showDetailedGameInfoCaptions = gs.bobsGame_showDetailedGameInfoCaptions;

	music->setVolume(((float)Main::globalSettings->musicVolume / 100.0f));
	m->getMenuItemByID("Music Volume")->setText("Music Volume: " + to_string((int)(music->getVolume() * 100)) + "%");
	m->getMenuItemByID("Brightness")->setText("Brightness: " + to_string((int)(Main::globalSettings->brightness * 100)) + "%");
	m->getMenuItemByID("Contrast")->setText("Contrast: " + to_string((int)(Main::globalSettings->contrast * 100)) + "%");
	m->getMenuItemByID("Saturation")->setText("Saturation: " + to_string((int)(Main::globalSettings->saturation * 100)) + "%");
	m->getMenuItemByID("Global Hue Shift")->setText("Global Hue Shift: " + to_string((int)(Main::globalSettings->hue * 100)) + "%");
	m->getMenuItemByID("Screen Flash")->setText("Level Up Screen Flash: " + to_string((int)(Main::globalSettings->bobsGame_screenFlashOnLevelUpAlpha * 100 * 2)) + "%");
	m->getMenuItemByID("Game Stats")->setText("Show Detailed Game Stats: " + string(Main::globalSettings->bobsGame_showDetailedGameInfoCaptions ? "On" : "Off"));

}

//=========================================================================================================================
void BobsGame::globalSettingsMenuUpdate()
{//=========================================================================================================================

	if (globalSettingsMenu == nullptr)
	{
		globalSettingsMenu = new BobMenu(this, "Global Settings");

		settingsMenuInit(globalSettingsMenu);
		globalSettingsMenu->add("Back To Title Screen", "Back To Title Screen");

		globalSettingsMenu->cursorPosition = globalSettingsMenuCursorPosition;
	}

	if (getControlsManager()->miniGame_UP_Pressed())
	{
		globalSettingsMenu->up();
	}

	if (getControlsManager()->miniGame_DOWN_Pressed())
	{
		globalSettingsMenu->down();
	}

	if (getControlsManager()->MINIGAME_LEFT_HELD)
	{
		settingsMenuLeft(globalSettingsMenu);
	}
	if (getControlsManager()->MINIGAME_RIGHT_HELD)
	{
		settingsMenuRight(globalSettingsMenu);
	}
	if (getControlsManager()->miniGame_LEFT_Pressed())
	{
		settingsMenuToggle(globalSettingsMenu);
	}
	if (getControlsManager()->miniGame_RIGHT_Pressed())
	{
		settingsMenuToggle(globalSettingsMenu);
	}

	bool leaveMenu = false;

	bool confirm = getControlsManager()->miniGame_CONFIRM_Pressed();//, clicked, mx, my
	bool clicked = getControlsManager()->mouse_LEFTBUTTON_Pressed();
	int mx = getControlsManager()->getMouseX();
	int my = getControlsManager()->getMouseY();
	if (confirm || clicked)
	{

		settingsMenuToggle(globalSettingsMenu);

		if (globalSettingsMenu->isSelectedID("Defaults", clicked, mx, my))
		{
			settingsMenuSetDefaults(globalSettingsMenu);
		}
		if (globalSettingsMenu->isSelectedID("Back To Title Screen", clicked, mx, my))
		{
			leaveMenu = true;
		}

	}

	if (getControlsManager()->miniGame_CANCEL_Pressed())
	{
		leaveMenu = true;
	}

	if (leaveMenu)
	{
		globalSettingsMenuShowing = false;
		startScreenMenuShowing = true;

		if (globalSettingsMenu != nullptr)
		{
			globalSettingsMenuCursorPosition = globalSettingsMenu->cursorPosition;
			delete globalSettingsMenu;
			globalSettingsMenu = nullptr;
		}

	}
}

//=========================================================================================================================
void BobsGame::globalSettingsMenuRender()
{//=========================================================================================================================

	GLUtils::drawFilledRect(BobMenu::bgColor->ri(), BobMenu::bgColor->gi(), BobMenu::bgColor->bi(), 0, (float)getWidth(), 0, (float)getHeight(), 1.0f);

	BobTexture* t = gearsTexture;

	if (globalSettingsMenu == nullptr)return;

	if (t != nullptr)
	{
		globalSettingsMenu->setGraphic(t, getWidth() / 3, getHeight() / 8);
	}

	globalSettingsMenu->render();
}

//=========================================================================================================================
void BobsGame::resetAllStatsMenuVars()
{//=========================================================================================================================
	statsMenu_totalTimePlayed = false;
	statsMenu_totalBlocksCleared = false;
	statsMenu_planeswalkerPoints = false;
	statsMenu_eloScore = false;
	statsMenu_timeLasted = false;
	statsMenu_blocksCleared = false;
}
//=========================================================================================================================
void BobsGame::whichStatsMiniMenuUpdate()
{//=========================================================================================================================

	//populate leaderBoardMiniMenu
	if (whichStatsMiniMenu == nullptr)
	{
		whichStatsMiniMenu = new BobMenu(this, "");
		whichStatsMiniMenu->center = false;
		whichStatsMiniMenu->setFontSize(12);

		whichStatsMiniMenu->add("Top Players By Total Time Played", "totalTimePlayed");
		whichStatsMiniMenu->add("Top Players By Total Blocks Cleared", "totalBlocksCleared");
		whichStatsMiniMenu->add("Top Players By Planeswalker Points", "planeswalkerPoints");
		whichStatsMiniMenu->add("Top Players By Elo Score", "eloScore");
		whichStatsMiniMenu->add("Top Games By Time Lasted", "timeLasted");
		whichStatsMiniMenu->add("Top Games By Blocks Cleared", "blocksCleared");
	}

	if (getControlsManager()->miniGame_UP_Pressed())
	{
		whichStatsMiniMenu->up();
	}

	if (getControlsManager()->miniGame_DOWN_Pressed())
	{
		whichStatsMiniMenu->down();
	}

	bool leaveMenu = false;

	bool confirm = getControlsManager()->miniGame_CONFIRM_Pressed();//, clicked, mx, my
	bool clicked = getControlsManager()->mouse_LEFTBUTTON_Pressed();
	int mx = getControlsManager()->getMouseX();
	int my = getControlsManager()->getMouseY();
	if (confirm || clicked)
	{

		if (whichStatsMiniMenu->isSelectedID("totalTimePlayed"))
		{
			resetAllStatsMenuVars();
			statsMenu_totalTimePlayed = true;
		}
		if (whichStatsMiniMenu->isSelectedID("totalBlocksCleared"))
		{
			resetAllStatsMenuVars();
			statsMenu_totalBlocksCleared = true;
		}
		if (whichStatsMiniMenu->isSelectedID("planeswalkerPoints"))
		{
			resetAllStatsMenuVars();
			statsMenu_planeswalkerPoints = true;
		}
		if (whichStatsMiniMenu->isSelectedID("eloScore"))
		{
			resetAllStatsMenuVars();
			statsMenu_eloScore = true;
		}
		if (whichStatsMiniMenu->isSelectedID("timeLasted"))
		{
			resetAllStatsMenuVars();
			statsMenu_timeLasted = true;
		}
		if (whichStatsMiniMenu->isSelectedID("blocksCleared"))
		{
			resetAllStatsMenuVars();
			statsMenu_blocksCleared = true;
		}

		leaveMenu = true;
	}

	//	if (getControlsManager()->miniGame_CANCEL_Pressed())
	//	{
	//		selectGameSequenceOrSingleGameTypeMenuShowing = true;
	//		leaveMenu = true;
	//	}

	if (leaveMenu)
	{
		whichStatsMiniMenuShowing = false;

		if (whichStatsMiniMenu != nullptr)
		{
			delete whichStatsMiniMenu;
			whichStatsMiniMenu = nullptr;
		}
	}

}


//=========================================================================================================================
void BobsGame::statsMenuUpdate()
{//=========================================================================================================================

	if (statsMenu == nullptr)
	{
		statsMenu = new BobMenu(this, "Stats And Leaderboards");

		statsMenu->add("Leaderboard Type", "Stats Type");
		statsMenu->add("Game: All Games", "Game");
		statsMenu->add("Difficulty: All Difficulties", "Difficulty");
		statsMenu->add("Objective: Play To Credits", "Objective");
		statsMenu->addInfo(" ");
		statsMenu->add("Back To Title Screen", "Back To Title Screen");

		statsMenu->cursorPosition = statsMenuCursorPosition;
	}

	if (statsMenu_difficultyName == "OVERALL") whichDifficultyToShow = 0;
	if (statsMenu_difficultyName == "Beginner")whichDifficultyToShow = 1;
	if (statsMenu_difficultyName == "Easy")	   whichDifficultyToShow = 2;
	if (statsMenu_difficultyName == "Normal")  whichDifficultyToShow = 3;
	if (statsMenu_difficultyName == "Hard")	   whichDifficultyToShow = 4;
	if (statsMenu_difficultyName == "Insane")  whichDifficultyToShow = 5;

	statsMenu->getMenuItemByID("Difficulty")->setText("Difficulty: " + statsMenu_difficultyName);

	statsMenu->getMenuItemByID("Game")->setText("Game: " + statsMenu_gameSequenceOrTypeName);

	statsMenu->getMenuItemByID("Objective")->setText("Objective: " + statsMenu_objectiveName);



	bool leaveMenu = false;

	int mx = getControlsManager()->getMouseX();
	int my = getControlsManager()->getMouseY();

	bool clicked = false;
	bool confirm = false;

	if (whichStatsMiniMenuShowing)
	{
		whichStatsMiniMenuUpdate();
	}
	else
	if (selectGameSequenceOrSingleGameTypeMenuShowing)
	{
		selectGameSequenceOrSingleGameTypeMenuUpdate();
	}
	else
		if (selectGameSequenceMenuShowing)
		{
			selectGameSequenceMenuUpdate();
		}
		else
			if (selectSingleGameTypeMenuShowing)
			{
				selectSingleGameTypeMenuUpdate();
			}
			else
				if (gameSequenceOptionsMenuShowing)
				{
					gameSequenceOptionsMenuUpdate();
				}
				else
						if (difficultyMenuShowing)
						{
							difficultyMenuUpdate();
						}
						else
						{
							if (getControlsManager()->miniGame_UP_Pressed())
							{
								statsMenu->up();
							}

							if (getControlsManager()->miniGame_DOWN_Pressed())
							{
								statsMenu->down();
							}

							confirm = getControlsManager()->miniGame_CONFIRM_Pressed();//, clicked, mx, my
							clicked = getControlsManager()->mouse_LEFTBUTTON_Pressed();


							if (clicked == true && confirm == false)
							{

								if (yourStatsMenu->isSelectedID(yourStatsMenu->getSelectedMenuItem()->id, clicked, mx, my)
									||
									leaderBoardMenu->isSelectedID(leaderBoardMenu->getSelectedMenuItem()->id, clicked, mx, my)
									)
								{
									whichDifficultyToShow++;
									if (whichDifficultyToShow > 5)whichDifficultyToShow = 0;
									if (whichDifficultyToShow == 0)statsMenu_difficultyName = "OVERALL";
									if (whichDifficultyToShow == 1)statsMenu_difficultyName = "Beginner";
									if (whichDifficultyToShow == 2)statsMenu_difficultyName = "Easy";
									if (whichDifficultyToShow == 3)statsMenu_difficultyName = "Normal";
									if (whichDifficultyToShow == 4)statsMenu_difficultyName = "Hard";
									if (whichDifficultyToShow == 5)statsMenu_difficultyName = "Insane";
								}

							}

							if (confirm || clicked)
							{
								if (statsMenu->isSelectedID("Back To Title Screen", clicked, mx, my))
								{
									leaveMenu = true;
								}
								if (statsMenu->isSelectedID("Stats Type", clicked, mx, my))
								{
									whichStatsMiniMenuShowing = true;
								}

								if (statsMenu->isSelectedID("Game", clicked, mx, my))
								{
									selectGameSequenceOrSingleGameTypeMenuShowing = true;
								}

								if (statsMenu->isSelectedID("Difficulty", clicked, mx, my))
								{
									difficultyMenuShowing = true;
								}

								if (statsMenu->isSelectedID("Objective", clicked, mx, my))
								{
									if (statsMenu_objectiveName == "Endless Mode")statsMenu_objectiveName = "Play To Credits";
									else statsMenu_objectiveName = "Endless Mode";

								}

							}
						}

	if (yourStatsMenu == nullptr)
	{
		yourStatsMenu = new BobMenu(this, "");
		yourStatsMenu->center = false;
		yourStatsMenu->setFontSize(12);
		yourStatsMenu->outline = false;
		yourStatsMenu->defaultMenuColor = BobColor::darkGray;

		populateUserStatsForSpecificGameAndDifficultyMenu(yourStatsMenu, "OVERALL", "OVERALL", statsMenu_objectiveName);

	}

	if (leaderBoardMenu == nullptr)
	{
		leaderBoardMenu = new BobMenu(this, "");
		leaderBoardMenu->center = false;
		leaderBoardMenu->setFontSize(12);
		leaderBoardMenu->outline = false;
		leaderBoardMenu->defaultMenuColor = BobColor::darkGray;

		populateLeaderBoardOrHighScoreBoardMenu(leaderBoardMenu, "OVERALL", "OVERALL", statsMenu_objectiveName,
			statsMenu_totalTimePlayed, statsMenu_totalBlocksCleared, statsMenu_planeswalkerPoints, statsMenu_eloScore, statsMenu_timeLasted, statsMenu_blocksCleared);
	}

	long long currentTime = System::currentHighResTimer();
	long long startTime = updateStatsTime;
	int ticksPassed = (int)(System::getTicksBetweenTimes(startTime, currentTime));
	if (ticksPassed > 200)
	{
		updateStatsTime = currentTime;

		yourStatsMenu->clear();
		leaderBoardMenu->clear();


		if (whichDifficultyToShow > 5)whichDifficultyToShow = 0;
		if (whichDifficultyToShow == 0)statsMenu_difficultyName = "OVERALL";
		if (whichDifficultyToShow == 1)statsMenu_difficultyName = "Beginner";
		if (whichDifficultyToShow == 2)statsMenu_difficultyName = "Easy";
		if (whichDifficultyToShow == 3)statsMenu_difficultyName = "Normal";
		if (whichDifficultyToShow == 4)statsMenu_difficultyName = "Hard";
		if (whichDifficultyToShow == 5)statsMenu_difficultyName = "Insane";

		populateUserStatsForSpecificGameAndDifficultyMenu(yourStatsMenu, statsMenu_gameSequenceOrTypeUUID, statsMenu_difficultyName, statsMenu_objectiveName);

		populateLeaderBoardOrHighScoreBoardMenu(leaderBoardMenu, statsMenu_gameSequenceOrTypeUUID, statsMenu_difficultyName, statsMenu_objectiveName,
				statsMenu_totalTimePlayed, statsMenu_totalBlocksCleared, statsMenu_planeswalkerPoints, statsMenu_eloScore, statsMenu_timeLasted, statsMenu_blocksCleared);

		yourStatsMenu->setAllCaptionsToFullAlpha();
		leaderBoardMenu->setAllCaptionsToFullAlpha();
	}




	if (getControlsManager()->miniGame_CANCEL_Pressed())
	{
		leaveMenu = true;
	}

	if (leaveMenu)
	{
		statsMenuShowing = false;
		startScreenMenuShowing = true;

		if (statsMenu != nullptr)
		{
			statsMenuCursorPosition = statsMenu->cursorPosition;
			delete statsMenu;
			statsMenu = nullptr;
		}
		if (yourStatsMenu != nullptr)
		{
			delete yourStatsMenu;
			yourStatsMenu = nullptr;
		}
		if (leaderBoardMenu != nullptr)
		{
			delete leaderBoardMenu;
			leaderBoardMenu = nullptr;
		}

	}
}

//=========================================================================================================================
void BobsGame::statsMenuRender()
{//=========================================================================================================================

	GLUtils::drawFilledRect(BobMenu::bgColor->ri(), BobMenu::bgColor->gi(), BobMenu::bgColor->bi(), 0, (float)getWidth(), 0, (float)getHeight(), 1.0f);

	BobTexture* t = chartTexture;

	if (statsMenu == nullptr)return;

	if (t != nullptr)
	{
		statsMenu->setGraphic(t, getWidth() / 4, getHeight() / 10);
	}


	int startHeight = 0;
	int bottomHeight = 0;
	int leftX = 0;
	int rightX = 0;
	statsMenu->render(0, getWidth() / 6 * 1, getHeight(), true, &startHeight, &bottomHeight, false, &leftX, &rightX);
	yourStatsMenu->render(startHeight, rightX + 50, getHeight(), false, nullptr, nullptr, false, nullptr, &rightX);
	leaderBoardMenu->render(startHeight, rightX + 50, getHeight(), false);

	if (whichStatsMiniMenuShowing && whichStatsMiniMenu != nullptr)
	{
		Caption *c = statsMenu->getCaptionByID("Stats Type");
		whichStatsMiniMenu->render(c->screenY + c->getHeight() + 8, c->screenX + c->getWidth() / 2, getHeight(), true, nullptr, nullptr, true);
	}

	if (selectGameSequenceOrSingleGameTypeMenuShowing && selectGameSequenceOrSingleGameTypeMenu != nullptr)
	{
		Caption *c = statsMenu->getCaptionByID("Game");
		selectGameSequenceOrSingleGameTypeMenu->render(c->screenY + c->getHeight() + 8, c->screenX + c->getWidth() / 2, getHeight(), true, nullptr, nullptr, true);
	}

	if (selectGameSequenceMenuShowing && selectGameSequenceMenu != nullptr)
	{
		Caption *c = statsMenu->getCaptionByID("Game");
		selectGameSequenceMenu->render(c->screenY + c->getHeight() + 8, c->screenX + c->getWidth() / 2, getHeight(), true, nullptr, nullptr, true);
	}

	if (selectSingleGameTypeMenuShowing && selectSingleGameTypeMenu != nullptr)
	{
		Caption *c = statsMenu->getCaptionByID("Game");
		selectSingleGameTypeMenu->render(c->screenY + c->getHeight() + 8, c->screenX + c->getWidth() / 2, getHeight(), true, nullptr, nullptr, true);
	}

	if (difficultyMenuShowing && difficultyMenu != nullptr)
	{
		Caption *c = statsMenu->getCaptionByID("Difficulty");
		difficultyMenu->render(c->screenY + c->getHeight() + 8, c->screenX + c->getWidth() / 2, getHeight(), true, nullptr, nullptr, true);
	}

}


//
//void selectedGameSequence(BobsGame *b, string name)
//{
//	//get game sequence by name
//	//set current game sequence
//}
//
//void selectedGameType(BobsGame *b, string name)
//{
//	//select game type by name
//	//create new game sequence with only that one game type
//	//set current game sequence
//}
//
//void selectedDifficulty(BobsGame *b, string name)
//{
//	//set current difficulty type
//}
//
//void selectedObjective(BobsGame *b, string& name)
//{
//	if(name=="End At Credits Level")
//	{
//
//	}
//
//	if(name == "Endless")
//	{
//
//	}
//}
//

//enum class StartWithOption
//{
//	FIRST_GAME,
//	RANDOM,
//};
//
//enum class PlayOrderOption
//{
//	RANDOM_BAG,
//	TOTALLY_RANDOM,
//	IN_ORDER,
//};

//enum class GameObjective
//{
//	PLAY_TO_CREDITS_LEVEL,
//	ENDLESS,
//	LAST,
//};




//=========================================================================================================================
void BobsGame::saveRoomConfigMenuUpdate()
{//=========================================================================================================================


	if (saveRoomConfigMenu == nullptr)
	{
		saveRoomConfigMenu = new BobMenu(this, "");
		saveRoomConfigMenu->center = false;
		//saveRoomConfigMenu->outline = false;

		saveRoomConfigNameText = "" + currentRoom->gameSequence->name + " " + currentRoom->difficultyName + " ";


		saveRoomConfigMenu->add("Name: " + saveRoomConfigNameText,"Name", BobMenu::statusColor);
		saveRoomConfigMenu->add("Save");
		saveRoomConfigMenu->add("Cancel");




		saveRoomConfigMenu->cursorPosition = saveRoomConfigMenuCursorPosition;
	}

	int mx = getControlsManager()->getMouseX();
	int my = getControlsManager()->getMouseY();

	if (mx != lastMX || my != lastMY)
	{
		if (textStarted) { SDL_StopTextInput(); textStarted = false; }
		lastMX = mx;
		lastMY = my;
	}

	if (getControlsManager()->miniGame_UP_Pressed())
	{
		saveRoomConfigMenu->up();

		if (textStarted) { SDL_StopTextInput(); textStarted = false; }
	}

	if (getControlsManager()->miniGame_DOWN_Pressed() || getControlsManager()->key_TAB_Pressed())
	{
		saveRoomConfigMenu->down();

		if (textStarted) { SDL_StopTextInput(); textStarted = false; }
	}


	if (saveRoomConfigMenu->isSelectedID("Name"))
	{
		if (!textStarted) { SDL_StartTextInput(); getControlsManager()->text = saveRoomConfigNameText; textStarted = true; }
		saveRoomConfigNameText = getControlsManager()->text;
		saveRoomConfigMenu->getMenuItemByID("Name")->setText("Name: " + saveRoomConfigNameText);
	}

	bool leaveMenu = false;
	bool confirm = getControlsManager()->miniGame_CONFIRM_Pressed();//, clicked, mx, my
	bool clicked = getControlsManager()->mouse_LEFTBUTTON_Pressed();

	if (confirm || clicked)
	{

		if (saveRoomConfigMenu->isSelectedID("Save", clicked, mx, my))
		{
			if (name.length() > 0)
			{

				time_t t = time(0); // get time now
				struct tm * now = localtime(&t);
				string year = to_string(now->tm_year + 1900);
				string month = to_string((now->tm_mon + 1));
				string day = to_string(now->tm_mday);
				string hour = to_string(now->tm_hour);
				string minute = to_string(now->tm_min);
				string second = to_string(now->tm_sec);

				string name = saveRoomConfigNameText + " " + year + "-" + month + "-" + day + "-" + hour + "-" + minute + "-" + second + ".roomConfig";

				name = FileUtils::removeIllegalFilenameChars(name);

				leaveMenu = true;

				BobsGame::saveRoomConfigToFile(currentRoom, name);
			}
		}

		if (saveRoomConfigMenu->isSelectedID("Cancel", clicked, mx, my))
		{
			leaveMenu = true;
		}
	}

	if (leaveMenu)
	{
		if (textStarted) { SDL_StopTextInput(); textStarted = false; }
		saveRoomConfigMenuShowing = false;
		if (saveRoomConfigMenu != nullptr)
		{
			saveRoomConfigMenuCursorPosition = saveRoomConfigMenu->cursorPosition;
			delete saveRoomConfigMenu;
			saveRoomConfigMenu = nullptr;
		}
	}
}


//=========================================================================================================================
void BobsGame::loadRoomConfigMenuUpdate()
{//=========================================================================================================================

	if (loadRoomConfigMenu == nullptr)
	{
		loadRoomConfigMenu = new BobMenu(this, "");
		loadRoomConfigMenu->center = false;
		//loadRoomConfigMenu->outline = false;



		ArrayList<string> roomConfigNames = BobsGame::getRoomConfigsList();

		for (int i = 0; i < roomConfigNames.size(); i++)
		{
			loadRoomConfigMenu->add(roomConfigNames.get(i));
		}

		loadRoomConfigMenu->add("Cancel");

		loadRoomConfigMenu->cursorPosition = loadRoomConfigMenuCursorPosition;
	}

	if (getControlsManager()->miniGame_UP_Pressed())
	{
		loadRoomConfigMenu->up();
	}
	if (getControlsManager()->miniGame_DOWN_Pressed())
	{
		loadRoomConfigMenu->down();
	}
	bool leaveMenu = false;
	bool confirm = getControlsManager()->miniGame_CONFIRM_Pressed();//, clicked, mx, my
	bool clicked = getControlsManager()->mouse_LEFTBUTTON_Pressed();
	int mx = getControlsManager()->getMouseX();
	int my = getControlsManager()->getMouseY();
	if (confirm || clicked)
	{


		if (loadRoomConfigMenu->isSelectedID("Cancel", clicked, mx, my))
		{
			leaveMenu = true;
		}
		else
		{

			ArrayList<string> ids = loadRoomConfigMenu->getArrayListOfMenuItemIDs();

			for (int i = 0; i < ids.size(); i++)
			{
				if (loadRoomConfigMenu->isSelectedID(ids.get(i), clicked, mx, my))
				{
					Room *r = BobsGame::loadRoomConfig(ids.get(i));

					if (r != nullptr)currentRoom = r;
					leaveMenu = true;
				}
			}
		}



	}

	if (leaveMenu)
	{
		loadRoomConfigMenuShowing = false;
		if (loadRoomConfigMenu != nullptr)
		{
			loadRoomConfigMenuCursorPosition = loadRoomConfigMenu->cursorPosition;
			delete loadRoomConfigMenu;
			loadRoomConfigMenu = nullptr;
		}
	}
}


//=========================================================================================================================
void BobsGame::gameObjectiveMenuUpdate()
{//=========================================================================================================================

	const string PLAY_TO_CREDITS_LEVEL = "Play To Credits Level";
	const string ENDLESS = "Endless";
	if (gameObjectiveMenu == nullptr)
	{
		gameObjectiveMenu = new BobMenu(this, "");
		//gameObjectiveMenu->outline = false;

		gameObjectiveMenu->add(PLAY_TO_CREDITS_LEVEL);
		gameObjectiveMenu->add(ENDLESS);
		gameObjectiveMenu->cursorPosition = gameObjectiveMenuCursorPosition;
	}
	if (getControlsManager()->miniGame_UP_Pressed())
	{
		gameObjectiveMenu->up();
	}
	if (getControlsManager()->miniGame_DOWN_Pressed())
	{
		gameObjectiveMenu->down();
	}
	bool leaveMenu = false;
	bool confirm = getControlsManager()->miniGame_CONFIRM_Pressed();//, clicked, mx, my
	bool clicked = getControlsManager()->mouse_LEFTBUTTON_Pressed();
	int mx = getControlsManager()->getMouseX();
	int my = getControlsManager()->getMouseY();
	if (confirm || clicked)
	{

		if (gameObjectiveMenu->isSelectedID(PLAY_TO_CREDITS_LEVEL, clicked, mx, my))
		{
			//selectedObjectiveIndex = (int)GameObjective::PLAY_TO_CREDITS_LEVEL;
			if (currentRoom != nullptr)currentRoom->endlessMode = false;
		}

		if (gameObjectiveMenu->isSelectedID(ENDLESS, clicked, mx, my))
		{
			//selectedObjectiveIndex = (int)GameObjective::ENDLESS;
			if (currentRoom != nullptr)currentRoom->endlessMode = true;
		}

		leaveMenu = true;
	}

	if (leaveMenu)
	{
		gameObjectiveMenuShowing = false;
		if (gameObjectiveMenu != nullptr)
		{
			gameObjectiveMenuCursorPosition = gameObjectiveMenu->cursorPosition;
			delete gameObjectiveMenu;
			gameObjectiveMenu = nullptr;
		}
	}
}
//=========================================================================================================================
void BobsGame::sendGarbageToMenuUpdate()
{//=========================================================================================================================

	const string SEND_GARBAGE_TO_ALL_PLAYERS="All Other Players";
	const string SEND_GARBAGE_TO_ALL_PLAYERS_50_PERCENT_CHANCE="All Other Players 50% Chance";
	const string SEND_GARBAGE_TO_RANDOM_PLAYER="One Random Player";
	const string SEND_GARBAGE_TO_EACH_PLAYER_IN_ROTATION="Rotate Between Other Players";
	const string SEND_GARBAGE_TO_PLAYER_WITH_LEAST_BLOCKS="Player With Least Blocks";

	if (sendGarbageToMenu == nullptr)
	{
		sendGarbageToMenu = new BobMenu(this, "");
		//sendGarbageToMenu->outline = false;


		sendGarbageToMenu->add(SEND_GARBAGE_TO_ALL_PLAYERS);
		sendGarbageToMenu->add(SEND_GARBAGE_TO_ALL_PLAYERS_50_PERCENT_CHANCE);
		if (networkMultiplayer == false)
		{
			sendGarbageToMenu->add(SEND_GARBAGE_TO_RANDOM_PLAYER);
			sendGarbageToMenu->add(SEND_GARBAGE_TO_EACH_PLAYER_IN_ROTATION);
			sendGarbageToMenu->add(SEND_GARBAGE_TO_PLAYER_WITH_LEAST_BLOCKS);
		}

		sendGarbageToMenu->cursorPosition = sendGarbageToMenuCursorPosition;
	}
	if (getControlsManager()->miniGame_UP_Pressed())
	{
		sendGarbageToMenu->up();
	}
	if (getControlsManager()->miniGame_DOWN_Pressed())
	{
		sendGarbageToMenu->down();
	}
	bool leaveMenu = false;
	bool confirm = getControlsManager()->miniGame_CONFIRM_Pressed();//, clicked, mx, my
	bool clicked = getControlsManager()->mouse_LEFTBUTTON_Pressed();
	int mx = getControlsManager()->getMouseX();
	int my = getControlsManager()->getMouseY();
	if (confirm || clicked)
	{
		if (sendGarbageToMenu->isSelectedID(SEND_GARBAGE_TO_ALL_PLAYERS, clicked, mx, my))currentRoom->multiplayer_SendGarbageTo = (int)SendGarbageToRule::SEND_GARBAGE_TO_ALL_PLAYERS;
		if (sendGarbageToMenu->isSelectedID(SEND_GARBAGE_TO_ALL_PLAYERS_50_PERCENT_CHANCE, clicked, mx, my))currentRoom->multiplayer_SendGarbageTo = (int)SendGarbageToRule::SEND_GARBAGE_TO_ALL_PLAYERS_50_PERCENT_CHANCE;
		if (sendGarbageToMenu->isSelectedID(SEND_GARBAGE_TO_RANDOM_PLAYER, clicked, mx, my))currentRoom->multiplayer_SendGarbageTo = (int)SendGarbageToRule::SEND_GARBAGE_TO_RANDOM_PLAYER;
		if (sendGarbageToMenu->isSelectedID(SEND_GARBAGE_TO_EACH_PLAYER_IN_ROTATION, clicked, mx, my))currentRoom->multiplayer_SendGarbageTo = (int)SendGarbageToRule::SEND_GARBAGE_TO_EACH_PLAYER_IN_ROTATION;
		if (sendGarbageToMenu->isSelectedID(SEND_GARBAGE_TO_PLAYER_WITH_LEAST_BLOCKS, clicked, mx, my))currentRoom->multiplayer_SendGarbageTo = (int)SendGarbageToRule::SEND_GARBAGE_TO_PLAYER_WITH_LEAST_BLOCKS;

		leaveMenu = true;
	}

	if (leaveMenu)
	{
		sendGarbageToMenuShowing = false;
		if (sendGarbageToMenu != nullptr)
		{
			sendGarbageToMenuCursorPosition = sendGarbageToMenu->cursorPosition;
			delete sendGarbageToMenu;
			sendGarbageToMenu = nullptr;
		}
	}
}

float myMax(float a, float b)
{
    if(a>b)return a;
    return b;
}
//=========================================================================================================================
void BobsGame::leftRightMenuAdjustFloat(bool left, bool right, float& variable, float min, float max, float minIncrement, float maxIncrement)
{//=========================================================================================================================
	long long startTime = timeLastChangedSetting;
	long long currentTime = System::currentHighResTimer();
	int ticksPassed = (int)(System::getTicksBetweenTimes(startTime, currentTime));

	if (ticksPassed > 200)
	{
		timeStartedChangedSetting = currentTime;
	}
	float timeSinceStart = float(currentTime - timeStartedChangedSetting);
	if (timeSinceStart < 200)timeSinceStart = 0;
	float increment = minIncrement + (myMax((timeSinceStart / 500.0f),1.0f) * (maxIncrement - minIncrement));

	if (ticksPassed > 15)
	{
		timeLastChangedSetting = currentTime;

		if (left)
		{
			if (variable > min)variable -= increment;
			if (variable < min)variable = min;
		}

		if (right)
		{
			if (variable < max)variable += increment;
			if (variable > max)variable = max;
		}
	}
}


//=========================================================================================================================
void BobsGame::leftRightMenuAdjustInt(bool left, bool right, int& variable, int min, int max, int minIncrement, int maxIncrement)
{//=========================================================================================================================
	long long startTime = timeLastChangedSetting;
	long long currentTime = System::currentHighResTimer();
	int ticksPassed = (int)(System::getTicksBetweenTimes(startTime, currentTime));

	if (ticksPassed > 200)
	{
		timeStartedChangedSetting = currentTime;
	}
	float timeSinceStart = float(currentTime - timeStartedChangedSetting);
	if (timeSinceStart < 200)timeSinceStart = 0;
	int increment = minIncrement + (myMax((timeSinceStart / 500.0f), 1.0f) * (maxIncrement - minIncrement));

	if (ticksPassed > 15)
	{
		timeLastChangedSetting = currentTime;

		if (left)
		{
			if (variable > min)variable -= increment;
			if (variable < min)variable = min;
		}

		if (right)
		{
			if (variable < max)variable += increment;
			if (variable > max)variable = max;
		}
	}
}


//=========================================================================================================================
void BobsGame::roomOptionsMenuUpdate()
{//=========================================================================================================================

	//const string OBJECTIVE = "Objective";


	if (roomOptionsMenu == nullptr)
	{
		if (descriptionCaption != nullptr) { delete descriptionCaption; descriptionCaption = nullptr; }
		descriptionCaption = new Caption(this, Caption::Position::CENTERED_X, 0, 0, -1, "", 18, false, BobColor::darkGray, BobColor::clear);
		roomOptionsMenu = new BobMenu(this, "");
		roomOptionsMenu->center = false;
		roomOptionsMenu->setFontSize(24);
		//roomOptionsMenu->outline = false;
		//roomOptionsMenu->defaultMenuColor = BobColor::gray;


		roomOptionsMenu->add("Game Speed Start: ", "Game Speed Start");
		roomOptionsMenu->add("Game Speed Increase Rate: ", "Game Speed Change Rate");
		roomOptionsMenu->add("Game Speed Maximum: ", "Game Speed Maximum");
		roomOptionsMenu->addInfo(" ");
		roomOptionsMenu->add("Score Needed To Level Up Multiplier: ", "Levelup Multiplier");
		roomOptionsMenu->add("Score Needed To Level Up Compound Multiplier: ", "Levelup Compound Multiplier");
		roomOptionsMenu->addInfo(" ");
		roomOptionsMenu->add("Floor Movement Limit: ", "Floor Movement Limit");
		roomOptionsMenu->add("Total Lock Delay Limit: ", "Total Lock Delay Limit");
		roomOptionsMenu->add("Lock Delay Decrease Rate: ", "Lock Delay Decrease Rate");
		roomOptionsMenu->add("Lock Delay Minimum: ", "Lock Delay Minimum");
		roomOptionsMenu->addInfo(" ");
		roomOptionsMenu->add("Stack Wait Limit: ", "Stack Wait Limit");
		roomOptionsMenu->add("Spawn Delay Limit: ", "Spawn Delay Limit");
		roomOptionsMenu->add("Spawn Delay Decrease Rate: ", "Spawn Delay Decrease Rate");
		roomOptionsMenu->add("Spawn Delay Minimum: ", "Spawn Delay Minimum");
		roomOptionsMenu->add("Drop Delay Minimum: ", "Drop Delay Minimum");

		if (localMultiplayer || networkMultiplayer)
		{
			roomOptionsMenu->addInfo(" ");
			roomOptionsMenu->addInfo("Multiplayer Options:");


			//roomOptionsMenu->add("Allow New Players To Join During Game: ", "Allow Join");
			//roomOptionsMenu->add("Use Teams: ", "Use Teams");
			roomOptionsMenu->add("End Rule: Game Ends When One Player Remains", "End Rule");
			roomOptionsMenu->add("Finish Rule: End On First Completion", "Finish Rule");
			roomOptionsMenu->addInfo(" ");
			roomOptionsMenu->add("VS Garbage: ", "Garbage Rule");
			roomOptionsMenu->add("Garbage Multiplier: ", "Garbage Multiplier");
			roomOptionsMenu->add("Garbage Limit: ", "Garbage Limit");
			roomOptionsMenu->add("Scale Garbage By Difficulty: ", "Garbage Scale");
			roomOptionsMenu->add("Send Garbage To: ", "Garbage Scale");



			//TODO: infinite spin max time ?
			//lock delay limit, floor kick limit, 128 turns, step delay
			//allow teams(your team sends garbage to other team only), team victory, colored border, maybe caption
			//add select team to player setup minimenu

		}

		roomOptionsMenu->addInfo(" ");
		roomOptionsMenu->add("Set Defaults", "Defaults");
		roomOptionsMenu->addInfo(" ");
		roomOptionsMenu->add("Apply Options And Close", "Apply");

		roomOptionsMenu->cursorPosition = roomOptionsMenuCursorPosition;
	}


	roomOptionsMenu->getMenuItemByID("Game Speed Start")->setText("Game Speed Start: " + to_string((int)(currentRoom->gameSpeedStart * 100)) + "%");
	roomOptionsMenu->getMenuItemByID("Game Speed Change Rate")->setText("Game Speed Change Rate: " + to_string((int)(currentRoom->gameSpeedChangeRate * 100)) + "%");
	roomOptionsMenu->getMenuItemByID("Game Speed Maximum")->setText("Game Speed Maximum: " + to_string((int)(currentRoom->gameSpeedMaximum * 100)) + "%");
	roomOptionsMenu->getMenuItemByID("Levelup Multiplier")->setText("Score Needed To Level Up Multiplier: " + to_string((int)(currentRoom->levelUpMultiplier * 100)) + "%");
	roomOptionsMenu->getMenuItemByID("Levelup Compound Multiplier")->setText("Score To Level Up Compound Multiplier: " + to_string((int)(currentRoom->levelUpCompoundMultiplier * 100)) + "%");
	roomOptionsMenu->getMenuItemByID("Floor Movement Limit")->setText("Floor Movement Limit: " + string((currentRoom->floorSpinLimit > -1) ? to_string(currentRoom->floorSpinLimit) : "No Limit"));
	roomOptionsMenu->getMenuItemByID("Total Lock Delay Limit")->setText("Total Lock Delay Limit: " + string((currentRoom->totalYLockDelayLimit > -1) ? to_string(currentRoom->totalYLockDelayLimit) + "ms" : "No Limit"));
	roomOptionsMenu->getMenuItemByID("Lock Delay Decrease Rate")->setText("Lock Delay Decrease Rate: " + string((currentRoom->lockDelayDecreaseRate > 0) ? to_string((int)(currentRoom->lockDelayDecreaseRate * 100)) + "%" : "None"));
	roomOptionsMenu->getMenuItemByID("Lock Delay Minimum")->setText("Lock Delay Minimum: " + string((currentRoom->lockDelayMinimum > 0) ? to_string(currentRoom->lockDelayMinimum) + "ms" : "None"));
	roomOptionsMenu->getMenuItemByID("Stack Wait Limit")->setText("Stack Wait Limit: " + string((currentRoom->stackWaitLimit > -1) ? to_string(currentRoom->stackWaitLimit) + "ms" : "No Limit"));
	roomOptionsMenu->getMenuItemByID("Spawn Delay Limit")->setText("Spawn Delay Limit: " + string((currentRoom->spawnDelayLimit > -1) ? to_string(currentRoom->spawnDelayLimit) + "ms" : "No Limit"));
	roomOptionsMenu->getMenuItemByID("Spawn Delay Decrease Rate")->setText("Spawn Delay Decrease Rate: " + string((currentRoom->spawnDelayDecreaseRate > 0) ? to_string((int)(currentRoom->spawnDelayDecreaseRate * 100)) + "%" : "None"));
	roomOptionsMenu->getMenuItemByID("Spawn Delay Minimum")->setText("Spawn Delay Minimum: " + string((currentRoom->spawnDelayMinimum > 0) ? to_string(currentRoom->spawnDelayMinimum) + "ms" : "None"));
	roomOptionsMenu->getMenuItemByID("Drop Delay Minimum")->setText("Drop Delay Minimum: " + string((currentRoom->dropDelayMinimum > 0) ? to_string(currentRoom->dropDelayMinimum) + "ms" : "None"));


	if (localMultiplayer || networkMultiplayer)
	{

		roomOptionsMenu->getMenuItemByID("Allow Join")->setText("Allow New Players To Join During Game: " + string(currentRoom->multiplayer_AllowNewPlayersDuringGame ? "On" : "Off"));
		roomOptionsMenu->getMenuItemByID("Use Teams")->setText("Use Teams: " + string(currentRoom->multiplayer_UseTeams ? "On" : "Off"));

		if (currentRoom->multiplayer_GameEndsWhenOnePlayerRemains)
			roomOptionsMenu->getMenuItemByID("End Rule")->setText("End Rule: Game Ends When One Player Remains");
		else roomOptionsMenu->getMenuItemByID("End Rule")->setText("End Rule: Continue Until All Players Lose");

		if (currentRoom->multiplayer_GameEndsWhenSomeoneCompletesCreditsLevel)
			roomOptionsMenu->getMenuItemByID("Finish Rule")->setText("Finish Rule: End On First Completion");
		else roomOptionsMenu->getMenuItemByID("Finish Rule")->setText("Finish Rule: Free Play To Completion");

		if (currentRoom->endlessMode)
		{
			roomOptionsMenu->getMenuItemByID("Finish Rule")->setText("Finish Rule: Endless Mode");
			roomOptionsMenu->getMenuItemByID("Finish Rule")->info = true;
		}
		else
		{
			roomOptionsMenu->getMenuItemByID("Finish Rule")->info = false;
		}

		roomOptionsMenu->getMenuItemByID("Garbage Rule")->setText("VS Garbage: " + string((currentRoom->multiplayer_DisableVSGarbage) ? "Off" : "On"));
		roomOptionsMenu->getMenuItemByID("Garbage Multiplier")->setText("Garbage Multiplier: " + to_string((int)(currentRoom->multiplayer_GarbageMultiplier * 100)) + "%");
		roomOptionsMenu->getMenuItemByID("Garbage Limit")->setText("Garbage Limit: " + string((currentRoom->multiplayer_GarbageLimit > 0) ? to_string(currentRoom->multiplayer_GarbageLimit) : "No Limit"));
		roomOptionsMenu->getMenuItemByID("Garbage Scale")->setText("Scale Garbage By Difficulty: " + string(currentRoom->multiplayer_GarbageScaleByDifficulty ? "On" : "Off"));

		if (currentRoom->multiplayer_SendGarbageTo == (int)SendGarbageToRule::SEND_GARBAGE_TO_ALL_PLAYERS)roomOptionsMenu->getMenuItemByID("Send Garbage To")->setText("Send Garbage To: All Other Players");
		if (currentRoom->multiplayer_SendGarbageTo == (int)SendGarbageToRule::SEND_GARBAGE_TO_ALL_PLAYERS_50_PERCENT_CHANCE)roomOptionsMenu->getMenuItemByID("Send Garbage To")->setText("Send Garbage To: All Other Players 50% Chance");
		if (currentRoom->multiplayer_SendGarbageTo == (int)SendGarbageToRule::SEND_GARBAGE_TO_RANDOM_PLAYER)roomOptionsMenu->getMenuItemByID("Send Garbage To")->setText("Send Garbage To: One Random Player");
		if (currentRoom->multiplayer_SendGarbageTo == (int)SendGarbageToRule::SEND_GARBAGE_TO_EACH_PLAYER_IN_ROTATION)roomOptionsMenu->getMenuItemByID("Send Garbage To")->setText("Send Garbage To: Rotate Between Other Players");
		if (currentRoom->multiplayer_SendGarbageTo == (int)SendGarbageToRule::SEND_GARBAGE_TO_PLAYER_WITH_LEAST_BLOCKS)roomOptionsMenu->getMenuItemByID("Send Garbage To")->setText("Send Garbage To: Player With Least Blocks");

	}




	if (sendGarbageToMenuShowing)
	{
		sendGarbageToMenuUpdate();
	}
	else
	{

		if (getControlsManager()->miniGame_UP_Pressed())
		{
			roomOptionsMenu->up();
		}

		if (getControlsManager()->miniGame_DOWN_Pressed())
		{
			roomOptionsMenu->down();
		}


		bool leftHeld = getControlsManager()->MINIGAME_LEFT_HELD;
		bool rightHeld = getControlsManager()->MINIGAME_RIGHT_HELD;

		if (leftHeld || rightHeld)
		{

			if (roomOptionsMenu->isSelectedID("Game Speed Start"))
			{
				leftRightMenuAdjustFloat(leftHeld, rightHeld, currentRoom->gameSpeedStart, 0.01f, 1.0f, 0.01f, 0.02f);
			}

			if (roomOptionsMenu->isSelectedID("Game Speed Change Rate"))
			{
				leftRightMenuAdjustFloat(leftHeld, rightHeld, currentRoom->gameSpeedChangeRate, -1.0f, 1.0f, 0.01f, 0.02f);
			}

			if (roomOptionsMenu->isSelectedID("Game Speed Maximum"))
			{
				leftRightMenuAdjustFloat(leftHeld, rightHeld, currentRoom->gameSpeedMaximum, 0.01f, 5.0f, 0.01f, 0.02f);
			}

			if (roomOptionsMenu->isSelectedID("Levelup Multiplier"))
			{
				leftRightMenuAdjustFloat(leftHeld, rightHeld, currentRoom->levelUpMultiplier, 0.01f, 10.0f, 0.01f, 0.02f);
			}

			if (roomOptionsMenu->isSelectedID("Levelup Compound Multiplier"))
			{
				leftRightMenuAdjustFloat(leftHeld, rightHeld, currentRoom->levelUpCompoundMultiplier, -1.0f, 1.0f, 0.01f, 0.02f);
			}

			if (roomOptionsMenu->isSelectedID("Garbage Multiplier"))
			{
				leftRightMenuAdjustFloat(leftHeld, rightHeld, currentRoom->multiplayer_GarbageMultiplier, 0.01f, 2.0f, 0.01f, 0.02f);
			}

			if (roomOptionsMenu->isSelectedID("Garbage Limit"))
			{
				leftRightMenuAdjustInt(leftHeld, rightHeld, currentRoom->multiplayer_GarbageLimit, 0, 50, 1, 2);
			}

			if (roomOptionsMenu->isSelectedID("Floor Movement Limit"))
			{
				leftRightMenuAdjustInt(leftHeld, rightHeld, currentRoom->floorSpinLimit, -1, 128, 1, 2);
			}

			if (roomOptionsMenu->isSelectedID("Total Lock Delay Limit"))
			{
				leftRightMenuAdjustInt(leftHeld, rightHeld, currentRoom->totalYLockDelayLimit, -1, 10000, 1, 200);
			}

			if (roomOptionsMenu->isSelectedID("Lock Delay Decrease Rate"))
			{
				leftRightMenuAdjustFloat(leftHeld, rightHeld, currentRoom->lockDelayDecreaseRate, 0.0f, 1.0f, 0.01f, 0.02f);
			}

			if (roomOptionsMenu->isSelectedID("Lock Delay Minimum"))
			{
				leftRightMenuAdjustInt(leftHeld, rightHeld, currentRoom->lockDelayMinimum, 0, 10000, 1, 200);
			}

			if (roomOptionsMenu->isSelectedID("Stack Wait Limit"))
			{
				leftRightMenuAdjustInt(leftHeld, rightHeld, currentRoom->stackWaitLimit, -1, 10000, 1, 200);
			}

			if (roomOptionsMenu->isSelectedID("Spawn Delay Limit"))
			{
				leftRightMenuAdjustInt(leftHeld, rightHeld, currentRoom->spawnDelayLimit, -1, 10000, 1, 200);
			}

			if (roomOptionsMenu->isSelectedID("Spawn Delay Decrease Rate"))
			{
				leftRightMenuAdjustFloat(leftHeld, rightHeld, currentRoom->spawnDelayDecreaseRate, 0.0f, 1.0f, 0.01f, 0.02f);
			}

			if (roomOptionsMenu->isSelectedID("Spawn Delay Minimum"))
			{
				leftRightMenuAdjustInt(leftHeld, rightHeld, currentRoom->spawnDelayMinimum, 0, 10000, 1, 200);
			}

			if (roomOptionsMenu->isSelectedID("Drop Delay Minimum"))
			{
				leftRightMenuAdjustInt(leftHeld, rightHeld, currentRoom->dropDelayMinimum, 0, 10000, 1, 200);
			}
		}


		if (roomOptionsMenu->isSelectedID("Game Speed Start"))
		{
			descriptionCaption->setText("Percent speed at which the game begins. Default is 0%.");
		}

		if (roomOptionsMenu->isSelectedID("Game Speed Change Rate"))
		{
			descriptionCaption->setText("Percent speed the game changes each level. Default is 2%. Can be negative.");
		}

		if (roomOptionsMenu->isSelectedID("Game Speed Maximum"))
		{
			descriptionCaption->setText("Additional multiplier applied to the maximum game speed (defined in the selected difficulty). Default is 100%.");
		}

		if (roomOptionsMenu->isSelectedID("Levelup Multiplier"))
		{
			descriptionCaption->setText("Multiplier applied globally to score needed (pieces cleared, lines made, etc) to level up. Default is 100%.");
		}

		if (roomOptionsMenu->isSelectedID("Levelup Compound Multiplier"))
		{
			descriptionCaption->setText("Multiplier applied every level to score needed to level up, making each level longer/shorter than the last. Default is 0%. Can be negative");
		}

		if (roomOptionsMenu->isSelectedID("Garbage Multiplier"))
		{
			descriptionCaption->setText("Multiplier for sent garbage. Default is 100%.");
		}

		if (roomOptionsMenu->isSelectedID("Garbage Limit"))
		{
			descriptionCaption->setText("Hard limit on garbage queued. Default is no limit.");
		}

		if (roomOptionsMenu->isSelectedID("Floor Movement Limit"))
		{
			descriptionCaption->setText("How many times a piece can be spun in place or moved on the same Y position before locking. Set to 0 to always lock instantly. Default is no limit (infinite spin).");
		}

		if (roomOptionsMenu->isSelectedID("Total Lock Delay Limit"))
		{
			descriptionCaption->setText("Maximum total milliseconds a piece can stay in the same Y position before locking. Set to 0 to always lock instantly. Default is no limit.");
		}

		if (roomOptionsMenu->isSelectedID("Lock Delay Decrease Rate"))
		{
			descriptionCaption->setText("Percent the lock delay will decrease each level. Default is 0 (Lock delay does not decrease).");
		}

		if (roomOptionsMenu->isSelectedID("Lock Delay Minimum"))
		{
			descriptionCaption->setText("Minimum milliseconds before a piece locks. Resets every movement or rotation. Set to 0 to always lock instantly. Default is 500.");
		}

		if (roomOptionsMenu->isSelectedID("Stack Wait Limit"))
		{
			descriptionCaption->setText("Maximum milliseconds that the stack can be waiting to scroll after a combo. Set to 0 to always scroll. Default is no limit.");
		}

		if (roomOptionsMenu->isSelectedID("Spawn Delay Limit"))
		{
			descriptionCaption->setText("Maximum milliseconds that a piece will wait at the top before moving down. Set to 0 to always spawn instantly. Default is no limit.");
		}

		if (roomOptionsMenu->isSelectedID("Spawn Delay Decrease Rate"))
		{
			descriptionCaption->setText("Percent the initial spawn delay will decrease each level. Making combos can increase it up to the limit. Default is 0 (Spawn delay does not decrease).");
		}

		if (roomOptionsMenu->isSelectedID("Spawn Delay Minimum"))
		{
			descriptionCaption->setText("Minimum milliseconds for a spawned piece to move down. Does nothing if spawn rate does not decrease. Default is 500.");
		}

		if (roomOptionsMenu->isSelectedID("Drop Delay Minimum"))
		{
			descriptionCaption->setText("Minimum milliseconds for a piece to move down a row. Overrides minimum set in difficulty. Default is 500.");
		}

		if (roomOptionsMenu->isSelectedID("End Rule"))
		{
			descriptionCaption->setText("");
		}

		if (roomOptionsMenu->isSelectedID("Finish Rule"))
		{
			descriptionCaption->setText("");
		}

		if (roomOptionsMenu->isSelectedID("Garbage Rule"))
		{
			descriptionCaption->setText("");
		}

		if (roomOptionsMenu->isSelectedID("Allow Join"))
		{
			descriptionCaption->setText("Allow new players to join while the match is going, for more casual ongoing games.");
		}

		if (roomOptionsMenu->isSelectedID("Use Teams"))
		{
			descriptionCaption->setText("Players can select a team color, and their garbage will only be sent to the other teams. The winning player's team wins.");
		}

		if (roomOptionsMenu->isSelectedID("Garbage Scale"))
		{
			descriptionCaption->setText("This will scale the amount of garbage sent based on the difference in difficulty. Insane will send 0.25x to Beginner, but receive 4x.");
		}

		if (roomOptionsMenu->isSelectedID("Send Garbage To"))
		{
			descriptionCaption->setText("");
		}

		if (roomOptionsMenu->isSelectedID("Defaults"))
		{
			descriptionCaption->setText("Set all options to default.");
		}

		if (roomOptionsMenu->isSelectedID("Apply"))
		{
			descriptionCaption->setText("Apply settings and return to game setup screen.");
		}


		bool left = getControlsManager()->miniGame_LEFT_Pressed();
		bool right = getControlsManager()->miniGame_RIGHT_Pressed();

		bool leaveMenu = false;

		bool confirm = getControlsManager()->miniGame_CONFIRM_Pressed();//, clicked, mx, my
		bool clicked = getControlsManager()->mouse_LEFTBUTTON_Pressed();
		int mx = getControlsManager()->getMouseX();
		int my = getControlsManager()->getMouseY();
		if (confirm || clicked || left || right)
		{




			if (roomOptionsMenu->isSelectedID("End Rule", clicked, mx, my))
			{
				currentRoom->multiplayer_GameEndsWhenOnePlayerRemains = !currentRoom->multiplayer_GameEndsWhenOnePlayerRemains;
			}

			if (roomOptionsMenu->isSelectedID("Finish Rule", clicked, mx, my))
			{
				currentRoom->multiplayer_GameEndsWhenSomeoneCompletesCreditsLevel = !currentRoom->multiplayer_GameEndsWhenSomeoneCompletesCreditsLevel;
			}

			if (roomOptionsMenu->isSelectedID("Garbage Rule", clicked, mx, my))
			{
				currentRoom->multiplayer_DisableVSGarbage = !currentRoom->multiplayer_DisableVSGarbage;
			}

			if (roomOptionsMenu->isSelectedID("Allow Join", clicked, mx, my))
			{
				currentRoom->multiplayer_AllowNewPlayersDuringGame = !currentRoom->multiplayer_AllowNewPlayersDuringGame;
			}

			if (roomOptionsMenu->isSelectedID("Use Teams", clicked, mx, my))
			{
				currentRoom->multiplayer_UseTeams = !currentRoom->multiplayer_UseTeams;
			}

			if (roomOptionsMenu->isSelectedID("Garbage Scale", clicked, mx, my))
			{
				currentRoom->multiplayer_GarbageScaleByDifficulty = !currentRoom->multiplayer_GarbageScaleByDifficulty;
			}

			if (roomOptionsMenu->isSelectedID("Send Garbage To", clicked, mx, my))
			{
				if (confirm || clicked)sendGarbageToMenuShowing = true;
				else
				{

					if(networkMultiplayer)
					{
						if (left)
						{
							currentRoom->multiplayer_SendGarbageTo--;
							if (currentRoom->multiplayer_SendGarbageTo < 0)currentRoom->multiplayer_SendGarbageTo = (int)SendGarbageToRule::SEND_GARBAGE_TO_ALL_PLAYERS_50_PERCENT_CHANCE;
						}
						if (right)
						{
							currentRoom->multiplayer_SendGarbageTo++;
							if (currentRoom->multiplayer_SendGarbageTo > (int)SendGarbageToRule::SEND_GARBAGE_TO_ALL_PLAYERS_50_PERCENT_CHANCE)currentRoom->multiplayer_SendGarbageTo = 0;
						}

					}
					else
					{
						if (left)
						{
							currentRoom->multiplayer_SendGarbageTo--;
							if (currentRoom->multiplayer_SendGarbageTo < 0)currentRoom->multiplayer_SendGarbageTo = (int)SendGarbageToRule::LAST - 1;
						}
						if (right)
						{
							currentRoom->multiplayer_SendGarbageTo++;
							if (currentRoom->multiplayer_SendGarbageTo >= (int)SendGarbageToRule::LAST)currentRoom->multiplayer_SendGarbageTo = 0;
						}
					}

				}
			}
		}

		if (confirm || clicked)
		{
			if (roomOptionsMenu->isSelectedID("Defaults", clicked, mx, my))
			{
				currentRoom->setDefaults();
			}

			if (roomOptionsMenu->isSelectedID("Apply", clicked, mx, my))
			{
				leaveMenu = true;
			}
		}

		if (leaveMenu)
		{
			roomOptionsMenuShowing = false;

			if (descriptionCaption != nullptr) { delete descriptionCaption; descriptionCaption = nullptr; }

			if (roomOptionsMenu != nullptr)
			{
				roomOptionsMenuCursorPosition = roomOptionsMenu->cursorPosition;
				delete roomOptionsMenu;
				roomOptionsMenu = nullptr;
			}
		}
	}

}



//=========================================================================================================================
void BobsGame::gameSetupMenuUpdate()
{//=========================================================================================================================

	if (gameSetupMenu == nullptr)
	{

		errorLabel = new Caption(this, Caption::Position::CENTERED_X, 0, 0, -1, "", 16, false, BobColor::red, BobColor::clear);

		gameSetupMenu = new BobMenu(this, "Setup Game Options");

		gameSetupMenu->add("Start Game", "Start Game", BobColor::green);
		gameSetupMenu->addInfo(" ", " ");
		gameSetupMenu->add("Select Game Sequence Or Single Game Type...", "Select Game");
		gameSetupMenu->add("Difficulty: Beginner", "Difficulty");
		gameSetupMenu->add("Objective: ", "Objective");

		gameSetupMenu->add("More Options...", "Options");
		gameSetupMenu->addInfo(" ", " ");
		gameSetupMenu->add("Save Config...", "Save");
		gameSetupMenu->add("Load Config...", "Load");
		gameSetupMenu->addInfo(" ", " ");
		gameSetupMenu->add("Back To Title Screen", "Back To Title Screen");

		gameSetupMenu->cursorPosition = gameSetupMenuCursorPosition;

	}


	if(currentRoom->isDefaultSettings()==false)
	{
		errorLabel->setText("Settings are not default, score will not count towards leaderboard ranking.");
	}
	else
	{
		errorLabel->setText("");
	}

	{
		string selectedDifficultyName = "";
		if (localMultiplayer || networkMultiplayer)
		{
			if (currentRoom == nullptr)currentRoom = new Room();

			if (currentRoom->difficultyName != "")
			{
				selectedDifficultyName = currentRoom->difficultyName;
			}
		}
		else
		{
			if (getPlayer1Game()->currentGameSequence != nullptr)
				selectedDifficultyName = getPlayer1Game()->currentGameSequence->currentDifficultyName;
		}

		if (selectedDifficultyName != "")
		{

			GameType gt;
			for (int i = 0; i < gt.difficultyTypes.size(); i++)
			{
				string difficultyName = gt.difficultyTypes.get(i)->name;
				if (selectedDifficultyName == difficultyName)selectedDifficultyIndex = i;
			}


			if (currentRoom == nullptr)currentRoom = new Room();
			if (currentRoom->difficultyName != "")
			{
				currentRoom->difficultyName = selectedDifficultyName;
			}

			if (getPlayer1Game()->currentGameSequence != nullptr)
				getPlayer1Game()->currentGameSequence->currentDifficultyName = selectedDifficultyName;


			gameSetupMenu->getMenuItemByID("Difficulty")->setText("Difficulty: " + selectedDifficultyName);
		}
	}


	{
		GameSequence *selectedGameSequence = nullptr;
		if (localMultiplayer || networkMultiplayer)
		{
			selectedGameSequence = currentRoom->gameSequence;
		}
		else
		{
			selectedGameSequence = getPlayer1Game()->currentGameSequence;
		}

		if(selectedGameSequence == nullptr)
		{
			selectedGameSequence = getGameSequenceByName("bob's game");
			if (selectedGameSequence == nullptr)
			{
				selectedGameSequence = new GameSequence();
				selectedGameSequence->gameTypes.add(new GameType());
			}
			currentRoom->gameSequence = selectedGameSequence;
			getPlayer1Game()->currentGameSequence = selectedGameSequence;
		}

		{
			BobMenu::MenuItem *c = gameSetupMenu->getMenuItemByID("Select Game");
			if (c != nullptr)
			{
				if (selectedGameSequence->gameTypes.size() > 1)c->setText("Game Sequence: " + selectedGameSequence->name);
				if (selectedGameSequence->gameTypes.size() == 1)c->setText("Game Type: " + selectedGameSequence->name);
			}
		}

		gameSetupMenu->getMenuItemByID("Start Game")->setColor(BobMenu::menuColor);
		gameSetupMenu->getMenuItemByID("Start Game")->info = false;

	}

	{
		string objectiveString = "";

		if (currentRoom->endlessMode)
		{
			objectiveString = "Play As Long As You Can (Endless Mode)";
		}
		else
		{
			objectiveString = "Play To Credits Level";
		}
		gameSetupMenu->getMenuItemByID("Objective")->setText("Objective: " + objectiveString);
	}

	int mx = getControlsManager()->getMouseX();
	int my = getControlsManager()->getMouseY();



	if (loadRoomConfigMenuShowing)
	{
		loadRoomConfigMenuUpdate();
	}
	else
	if (saveRoomConfigMenuShowing)
	{
		saveRoomConfigMenuUpdate();
	}
	else
	if (selectGameSequenceOrSingleGameTypeMenuShowing)
	{
		selectGameSequenceOrSingleGameTypeMenuUpdate();
	}
	else
	if (selectGameSequenceMenuShowing)
	{
		selectGameSequenceMenuUpdate();
	}
	else
	if (selectSingleGameTypeMenuShowing)
	{
		selectSingleGameTypeMenuUpdate();
	}
	else
	if (gameSequenceOptionsMenuShowing)
	{
		gameSequenceOptionsMenuUpdate();
	}
	else
	if (difficultyMenuShowing)
	{
		difficultyMenuUpdate();
	}
	else
	if (gameObjectiveMenuShowing)
	{
		gameObjectiveMenuUpdate();
	}
	else
	if (roomOptionsMenuShowing)
	{
		roomOptionsMenuUpdate();
	}
	else
	{
		if (getControlsManager()->miniGame_UP_Pressed())
		{
			gameSetupMenu->up();
		}

		if (getControlsManager()->miniGame_DOWN_Pressed())
		{
			gameSetupMenu->down();
		}

		bool left = getControlsManager()->miniGame_LEFT_Pressed();
		bool right = getControlsManager()->miniGame_RIGHT_Pressed();

		if (left || right)
		{
			if (gameSetupMenu->isSelectedID("Difficulty"))
			{
				GameType gt;
				if (left)
				{
					selectedDifficultyIndex--;
					if (selectedDifficultyIndex < 0)selectedDifficultyIndex = gt.difficultyTypes.size() - 1;
				}
				if (right)
				{
					selectedDifficultyIndex++;
					if (selectedDifficultyIndex >= gt.difficultyTypes.size())selectedDifficultyIndex = 0;
				}

				DifficultyType *d = gt.difficultyTypes.get(selectedDifficultyIndex);
				string difficultyName = d->name;
				currentRoom->difficultyName = difficultyName;
				if (getPlayer1Game()->currentGameSequence != nullptr)
					getPlayer1Game()->currentGameSequence->currentDifficultyName = difficultyName;
			}

		}

		bool leaveMenu = false;


		bool confirm = false;

		//assign controller to p1 if start or b pressed
		for (int i = 0; i < getControlsManager()->gameControllers.size(); i++)
		{
			GameController *g = getControlsManager()->gameControllers.get(i);
			if (g->b_Pressed())
			{
				confirm = true;
				getPlayer1()->gameController = g;
				getPlayer1()->rotateCWPressed();//cancel this
			}
			if (g->start_Pressed())
			{
				confirm = true;
				getPlayer1()->gameController = g;
				getPlayer1()->pausePressed();//cancel this so it doesn't pause immediately
			}
		}

		//check enter and space
		if (getControlsManager()->miniGame_CONFIRM_Pressed())confirm = true;//, clicked, mx, my


		bool clicked = getControlsManager()->mouse_LEFTBUTTON_Pressed();

		if(confirm || clicked || left || right)
		{
			if (gameSetupMenu->isSelectedID("Objective", clicked, mx, my))
			{
				if (confirm || clicked) gameObjectiveMenuShowing = true;
				else
				{
					currentRoom->endlessMode = !currentRoom->endlessMode;
					//if (left)
					//{
					//	selectedObjectiveIndex--;
					//	if (selectedObjectiveIndex < 0)selectedObjectiveIndex = (int)GameObjective::LAST - 1;
					//}
					//if (right)
					//{
					//	selectedObjectiveIndex++;
					//	if (selectedObjectiveIndex >= (int)GameObjective::LAST)selectedObjectiveIndex = 0;
					//}
					//if (selectedObjectiveIndex == (int)GameObjective::PLAY_TO_CREDITS_LEVEL)
					//{
					//	if (currentRoom != nullptr)currentRoom->endlessMode = false;
					//}
					//if (selectedObjectiveIndex == (int)GameObjective::ENDLESS)
					//{
					//	if (currentRoom != nullptr)currentRoom->endlessMode = true;
					//}
				}
			}
		}

		if (confirm || clicked)
		{

			if (gameSetupMenu->isSelectedID("Select Game", clicked, mx, my))
			{
				selectGameSequenceOrSingleGameTypeMenuShowing = true;
			}

			if (gameSetupMenu->isSelectedID("Difficulty", clicked, mx, my))
			{
				difficultyMenuShowing = true;
			}

			if (gameSetupMenu->isSelectedID("Options", clicked, mx, my))
			{
				roomOptionsMenuShowing = true;
			}

			if (gameSetupMenu->isSelectedID("Save", clicked, mx, my))
			{
				saveRoomConfigMenuShowing = true;
			}

			if (gameSetupMenu->isSelectedID("Load", clicked, mx, my))
			{
				loadRoomConfigMenuShowing = true;
			}

			if (gameSetupMenu->isSelectedID("Start Game", clicked, mx, my))
			{

				if(getPlayer1Game()->currentGameSequence == nullptr)getPlayer1Game()->currentGameSequence = currentRoom->gameSequence;

				GameType gt;
				DifficultyType *d = gt.difficultyTypes.get(selectedDifficultyIndex);
				string difficultyName = d->name;
				currentRoom->difficultyName = difficultyName;
				if (getPlayer1Game()->currentGameSequence != nullptr)
					getPlayer1Game()->currentGameSequence->currentDifficultyName = difficultyName;

				if (currentRoom->isDefaultSettings() == false)
				{
					leaderboardScoreDisabled = true;
				}
				else
				{
					leaderboardScoreDisabled = false;
				}

				sentStats = false;

				//if game type selected, else gray out
				leaveMenu = true;
			}

			if (gameSetupMenu->isSelectedID("Back To Title Screen", clicked, mx, my))
			{
				startScreenMenuShowing = true;

				leaveMenu = true;
			}
		}

		if (getControlsManager()->miniGame_CANCEL_Pressed())
		{

			startScreenMenuShowing = true;

			leaveMenu = true;
		}

		if (leaveMenu)
		{
			gameSetupMenuShowing = false;

			if(errorLabel!=nullptr)
			{
				delete errorLabel;
				errorLabel = nullptr;
			}

			if (gameSetupMenu != nullptr)
			{
				gameSetupMenuCursorPosition = gameSetupMenu->cursorPosition;
				delete gameSetupMenu;
				gameSetupMenu = nullptr;
			}

		}
	}
}

//=========================================================================================================================
void BobsGame::gameSetupMenuRender()
{//=========================================================================================================================

	GLUtils::drawFilledRect(BobMenu::bgColor->ri(), BobMenu::bgColor->gi(), BobMenu::bgColor->bi(), 0, (float)getWidth(), 0, (float)getHeight(), 1.0f);

	BobTexture* t = keyboardTexture;

	if (gameSetupMenu == nullptr)return;

	if (t != nullptr)
	{
		gameSetupMenu->setGraphic(t, getWidth() / 8 * 6, getHeight() / 10, getHeight() / 3);
	}

	{
		int bottomOfCaptions = 0;
		gameSetupMenu->render(0,0,getHeight(),true,nullptr,&bottomOfCaptions);
		if (errorLabel != nullptr)
		{
			errorLabel->screenY = bottomOfCaptions + 24;
			errorLabel->update();
			errorLabel->render();
		}
	}

	if(selectGameSequenceOrSingleGameTypeMenuShowing && selectGameSequenceOrSingleGameTypeMenu != nullptr)
	{
		Caption *c = gameSetupMenu->getCaptionByID("Select Game");
		selectGameSequenceOrSingleGameTypeMenu->render(c->screenY + c->getHeight() + 8, c->screenX + c->getWidth() / 2, getHeight(), true, nullptr, nullptr, true);
	}

	if (selectGameSequenceMenuShowing && selectGameSequenceMenu != nullptr)
	{
		Caption *c = gameSetupMenu->getCaptionByID("Select Game");
		selectGameSequenceMenu->render(c->screenY + c->getHeight() + 8, c->screenX + c->getWidth() / 2, getHeight(), true, nullptr, nullptr, true);
	}

	if (selectSingleGameTypeMenuShowing && selectSingleGameTypeMenu != nullptr)
	{
		Caption *c = gameSetupMenu->getCaptionByID("Select Game");
		selectSingleGameTypeMenu->render(c->screenY + c->getHeight() + 8, c->screenX + c->getWidth() / 2, getHeight(), true, nullptr, nullptr, true);
	}

	if (gameSequenceOptionsMenuShowing && gameSequenceOptionsMenu != nullptr)
	{
		Caption *c = gameSetupMenu->getCaptionByID("Select Game");
		gameSequenceOptionsMenu->render(c->screenY + c->getHeight() + 8, c->screenX + c->getWidth() / 2, getHeight(), true, nullptr, nullptr, true);
	}

	if (difficultyMenuShowing && difficultyMenu!=nullptr)
	{
		Caption *c = gameSetupMenu->getCaptionByID("Difficulty");
		difficultyMenu->render(c->screenY + c->getHeight() + 8, c->screenX + c->getWidth() / 2, getHeight(), true, nullptr, nullptr, true);
	}

	if (saveRoomConfigMenuShowing && saveRoomConfigMenu!=nullptr)
	{
		Caption *c = gameSetupMenu->getCaptionByID("Save");
		saveRoomConfigMenu->render(c->screenY + c->getHeight() + 8, c->screenX + c->getWidth() / 2, getHeight(), true, nullptr, nullptr, true);
	}

	if (loadRoomConfigMenuShowing && loadRoomConfigMenu!=nullptr)
	{
		Caption *c = gameSetupMenu->getCaptionByID("Load");
		loadRoomConfigMenu->render(c->screenY + c->getHeight() + 8, c->screenX + c->getWidth() / 2, getHeight(), true, nullptr, nullptr, true);
	}

	if (gameObjectiveMenuShowing && gameObjectiveMenu != nullptr)
	{
		Caption *c = gameSetupMenu->getCaptionByID("Objective");
		gameObjectiveMenu->render(c->screenY + c->getHeight() + 8, c->screenX + c->getWidth() / 2, getHeight(), true, nullptr, nullptr, true);
	}

	if (roomOptionsMenuShowing && roomOptionsMenu != nullptr)
	{
		int bottomOfCaptions = 0;

		{
			//Caption *c = gameSetupMenu->getCaptionByID("Options");
			//roomOptionsMenu->render(c->screenY + c->getHeight() + 8, c->screenX + c->getWidth() / 2, getHeight(), true, nullptr, &bottomOfCaptions, true);
			roomOptionsMenu->render(getHeight()/6, 0, getHeight(), true, nullptr, &bottomOfCaptions, true);
		}

		if (descriptionCaption != nullptr)
		{
			descriptionCaption->screenY = getHeight() - 30;// bottomOfCaptions + 24;
			descriptionCaption->update();
			descriptionCaption->render();
		}

		if (sendGarbageToMenuShowing && sendGarbageToMenu != nullptr)
		{
			Caption *c = roomOptionsMenu->getCaptionByID("Send Garbage To");
			sendGarbageToMenu->render(c->screenY + c->getHeight() + 8, c->screenX + c->getWidth() / 2, getHeight(), true, nullptr, nullptr, true);
		}
	}
}

//=========================================================================================================================
void BobsGame::selectGameSequenceOrSingleGameTypeMenuUpdate()
{//=========================================================================================================================


	//TODO: store default difficulty in GlobalSettings

	if (selectGameSequenceOrSingleGameTypeMenu == nullptr)
	{
		selectGameSequenceOrSingleGameTypeMenu = new BobMenu(this, "");

		if(localMultiplayer || networkMultiplayer)
		{
			selectGameSequenceOrSingleGameTypeMenu->add("Allow Different Game Sequences Or Types");
		}

		if (statsMenuShowing)
		{
			selectGameSequenceOrSingleGameTypeMenu->add("Any Game Type Or Sequence", "Allow Different Game Sequences Or Types");
			selectGameSequenceOrSingleGameTypeMenu->add("Select Game Sequence", "Play Game Sequence");
			selectGameSequenceOrSingleGameTypeMenu->add("Select Single Game Type", "Play Single Game Type");
		}
		else
		{
			selectGameSequenceOrSingleGameTypeMenu->add("Play Game Sequence", "Play Game Sequence");
			selectGameSequenceOrSingleGameTypeMenu->add("Play Single Game Type", "Play Single Game Type");
		}

		selectGameSequenceOrSingleGameTypeMenu->cursorPosition = selectGameSequenceOrSingleGameTypeMenuCursorPosition;
	}


	if (getControlsManager()->miniGame_UP_Pressed())
	{
		selectGameSequenceOrSingleGameTypeMenu->up();
	}

	if (getControlsManager()->miniGame_DOWN_Pressed())
	{
		selectGameSequenceOrSingleGameTypeMenu->down();
	}

	bool leaveMenu = false;

	bool confirm = getControlsManager()->miniGame_CONFIRM_Pressed();//, clicked, mx, my
	bool clicked = getControlsManager()->mouse_LEFTBUTTON_Pressed();
	int mx = getControlsManager()->getMouseX();
	int my = getControlsManager()->getMouseY();
	if (confirm || clicked)
	{

		if (selectGameSequenceOrSingleGameTypeMenu->isSelectedID("Allow Different Game Sequences Or Types", clicked, mx, my))
		{
			if (localMultiplayer || networkMultiplayer)
			{
				currentRoom->multiplayer_AllowDifferentGameSequences = true;
			}

			if(statsMenuShowing)
			{
				statsMenu_gameSequenceOrTypeUUID = "OVERALL";
				statsMenu_gameSequenceOrTypeName = "OVERALL";
			}
		}

		if (selectGameSequenceOrSingleGameTypeMenu->isSelectedID("Play Game Sequence", clicked, mx, my))
		{
			if (statsMenuShowing == false)
			{
				currentRoom->multiplayer_AllowDifferentGameSequences = false;
			}
			selectGameSequenceMenuShowing = true;
		}

		if (selectGameSequenceOrSingleGameTypeMenu->isSelectedID("Play Single Game Type", clicked, mx, my))
		{
			if (statsMenuShowing == false)
			{
				currentRoom->multiplayer_AllowDifferentGameSequences = false;
			}
			selectSingleGameTypeMenuShowing = true;
		}

		leaveMenu = true;
	}

//	if (getControlsManager()->miniGame_CANCEL_Pressed())
//	{
//		if(localMultiplayer || networkMultiplayer)
//		{
//			multiplayerOptionsMenuShowing = true;
//		}
//		else
//		{
//			titleMenuShowing = true;
//		}
//		leaveMenu = true;
//	}

	if (leaveMenu)
	{
		selectGameSequenceOrSingleGameTypeMenuShowing = false;

		if (selectGameSequenceOrSingleGameTypeMenu != nullptr)
		{
			selectGameSequenceOrSingleGameTypeMenuCursorPosition = selectGameSequenceOrSingleGameTypeMenu->cursorPosition;
			delete selectGameSequenceOrSingleGameTypeMenu;
			selectGameSequenceOrSingleGameTypeMenu = nullptr;
		}
	}

}

//=========================================================================================================================
void BobsGame::selectGameSequenceOrSingleGameTypeMenuRender()
{//=========================================================================================================================

	GLUtils::drawFilledRect(BobMenu::bgColor->ri(), BobMenu::bgColor->gi(), BobMenu::bgColor->bi(), 0, (float)getWidth(), 0, (float)getHeight(), 1.0f);

	BobTexture* t = keyboardTexture;

	if (selectGameSequenceOrSingleGameTypeMenu == nullptr)return;

	if (t != nullptr)
	{
		selectGameSequenceOrSingleGameTypeMenu->setGraphic(t, getWidth() / 3 * 2, getHeight() / 10);
	}

	selectGameSequenceOrSingleGameTypeMenu->render(getHeight()/2);
}


//=========================================================================================================================
void BobsGame::selectGameSequenceMenuUpdate()
{//=========================================================================================================================

	if (selectGameSequenceMenu == nullptr)
	{
		selectGameSequenceMenu = new BobMenu(this, "");
		selectGameSequenceMenu->center = false;
		selectGameSequenceMenu->outline = false;

		populateGameSequencesMenu(selectGameSequenceMenu);

		selectGameSequenceMenu->cursorPosition = selectGameSequenceMenuCursorPosition;
	}

	if (getControlsManager()->miniGame_UP_Pressed())
	{
		selectGameSequenceMenu->up();
	}

	if (getControlsManager()->miniGame_DOWN_Pressed())
	{
		selectGameSequenceMenu->down();
	}

	bool leaveMenu = false;

	bool confirm = getControlsManager()->miniGame_CONFIRM_Pressed();//, clicked, mx, my
	bool clicked = getControlsManager()->mouse_LEFTBUTTON_Pressed();
	int mx = getControlsManager()->getMouseX();
	int my = getControlsManager()->getMouseY();
	if (confirm || clicked)
	{
		for (int i = 0; i<loadedGameSequences.size(); i++)
		{
			GameSequence *g = loadedGameSequences.get(i);
			if (selectGameSequenceMenu->isSelectedID(g->uuid, clicked, mx, my))
			{
				if(statsMenuShowing)
				{
					statsMenu_gameSequenceOrTypeUUID = g->uuid;
					statsMenu_gameSequenceOrTypeName = g->name;
				}
				else
				{
					currentRoom->gameSequence = g;
					getPlayer1Game()->currentGameSequence = g;

					gameSequenceOptionsMenuShowing = true;
				}
			}
		}

		leaveMenu = true;
	}

//	if (getControlsManager()->miniGame_CANCEL_Pressed())
//	{
//		selectGameSequenceOrSingleGameTypeMenuShowing = true;
//		leaveMenu = true;
//	}

	if (leaveMenu)
	{
		selectGameSequenceMenuShowing = false;

		if (selectGameSequenceMenu != nullptr)
		{
			selectGameSequenceMenuCursorPosition = selectGameSequenceMenu->cursorPosition;
			delete selectGameSequenceMenu;
			selectGameSequenceMenu = nullptr;
		}
	}

}

//=========================================================================================================================
void BobsGame::selectGameSequenceMenuRender()
{//=========================================================================================================================

	GLUtils::drawFilledRect(BobMenu::bgColor->ri(), BobMenu::bgColor->gi(), BobMenu::bgColor->bi(), 0, (float)getWidth(), 0, (float)getHeight(), 1.0f);

	BobTexture* t = keyboardTexture;

	if (selectGameSequenceMenu == nullptr)return;

	if (t != nullptr)
	{
		selectGameSequenceMenu->setGraphic(t, getWidth() / 3 * 2, getHeight() / 10);
	}

	selectGameSequenceMenu->render(getHeight()/2);
}


//=========================================================================================================================
void BobsGame::gameSequenceOptionsMenuUpdate()
{//=========================================================================================================================

	const string RANDOMIZE_SEQUENCE = "Randomize Sequence";
	const string PLAY_THROUGH_SEQUENCE_IN_ORDER = "Play Through Sequence In Order";

	if (gameSequenceOptionsMenu == nullptr)
	{
		gameSequenceOptionsMenu = new BobMenu(this,"");

		gameSequenceOptionsMenu->add(RANDOMIZE_SEQUENCE);
		gameSequenceOptionsMenu->add(PLAY_THROUGH_SEQUENCE_IN_ORDER);

		gameSequenceOptionsMenu->cursorPosition = gameSequenceOptionsMenuCursorPosition;
	}


	if (getControlsManager()->miniGame_UP_Pressed())
	{
		gameSequenceOptionsMenu->up();
	}

	if (getControlsManager()->miniGame_DOWN_Pressed())
	{
		gameSequenceOptionsMenu->down();
	}

	bool leaveMenu = false;

	bool confirm = getControlsManager()->miniGame_CONFIRM_Pressed();//, clicked, mx, my
	bool clicked = getControlsManager()->mouse_LEFTBUTTON_Pressed();
	int mx = getControlsManager()->getMouseX();
	int my = getControlsManager()->getMouseY();
	if (confirm || clicked)
	{

		if (gameSequenceOptionsMenu->isSelectedID(RANDOMIZE_SEQUENCE, clicked, mx, my))
		{
			if (currentRoom->gameSequence != nullptr)currentRoom->gameSequence->randomizeSequence = true;
			if (currentRoom != nullptr)currentRoom->singleplayer_RandomizeSequence = true;
		}

		if (gameSequenceOptionsMenu->isSelectedID(PLAY_THROUGH_SEQUENCE_IN_ORDER, clicked, mx, my))
		{
			if (currentRoom->gameSequence != nullptr)currentRoom->gameSequence->randomizeSequence = false;
			if (currentRoom != nullptr)currentRoom->singleplayer_RandomizeSequence = false;
		}

		//gameObjectiveMenuShowing = true;

		leaveMenu = true;
	}

//	if (getControlsManager()->miniGame_CANCEL_Pressed())
//	{
//		selectGameSequenceMenuShowing = true;
//		leaveMenu = true;
//	}

	if (leaveMenu)
	{
		gameSequenceOptionsMenuShowing = false;

		if (gameSequenceOptionsMenu != nullptr)
		{
			gameSequenceOptionsMenuCursorPosition = gameSequenceOptionsMenu->cursorPosition;
			delete gameSequenceOptionsMenu;
			gameSequenceOptionsMenu = nullptr;
		}
	}

}

//=========================================================================================================================
void BobsGame::gameSequenceOptionsMenuRender()
{//=========================================================================================================================

	GLUtils::drawFilledRect(BobMenu::bgColor->ri(), BobMenu::bgColor->gi(), BobMenu::bgColor->bi(), 0, (float)getWidth(), 0, (float)getHeight(), 1.0f);

	BobTexture* t = keyboardTexture;

	if (gameSequenceOptionsMenu == nullptr)return;

	if (t != nullptr)
	{
		gameSequenceOptionsMenu->setGraphic(t, getWidth() / 3 * 2, getHeight() / 10);
	}

	gameSequenceOptionsMenu->render();
}


//=========================================================================================================================
/// <summary>
/// Calculates the Wilson Score based on the total votes and upvotes
/// </summary>
/// <param name="up">Number of upvotes</param>
/// <param name="total">Total number of votes</param>
/// <param name="confidence">Confidence used in calculation, default 1.644853 (95%)</param>
double BobsGame::wilsonScore(double up, double total, double confidence)
{//=========================================================================================================================
	/** Based on http://www.evanmiller.org/how-not-to-sort-by-average-rating.html **/
	if (total <= 0 || total < up)
		return 0;

	double phat = up / total;
	double z2 = confidence * confidence;

	return (phat + z2 / (2 * total) - confidence * sqrt((phat * (1 - phat) + z2 / (4 * total)) / total)) / (1 + z2 / total);
}

//=========================================================================================================================
ArrayList<pair<GameType*,pair<string,BobColor*>>> BobsGame::getSortedGameTypes()
{//=========================================================================================================================

	ArrayList<pair<GameType*, pair<string, BobColor*>>> gamesStringColor;

//	for (int i = 0; i<loadedGameTypes.size(); i++)
//	{
//		GameType *g = loadedGameTypes.get(i);
//		if (g->builtInType)
//		{
//			string name = g->name;
//			BobColor *color = BobColor::darkGreen;
//			pair<string, BobColor*> stringColorPair = pair<string, BobColor*>(name,color);
//			pair<GameType*, pair<string, BobColor*>> gameTypeStringColorPairPair = pair<GameType*, pair<string, BobColor*>>(g, stringColorPair);
//			gamesStringColor.add(gameTypeStringColorPairPair);
//		}
//	}
	for (int i = 0; i<loadedGameTypes.size(); i++)
	{
		GameType *g = loadedGameTypes.get(i);
		if (g->downloaded == false)//g->builtInType == false &&
		{
			string name = g->creatorUserName + " - " + g->name;
			BobColor *color = BobColor::purple;
			pair<string, BobColor*> stringColorPair = pair<string, BobColor*>(name, color);
			pair<GameType*, pair<string, BobColor*>> gameTypeStringColorPairPair = pair<GameType*, pair<string, BobColor*>>(g, stringColorPair);
			gamesStringColor.add(gameTypeStringColorPairPair);
		}
	}

	ArrayList<GameType*> downloadedGames;
	for (int i = 0; i<loadedGameTypes.size(); i++)
	{
		GameType *g = loadedGameTypes.get(i);
		if (g->downloaded == true)//g->builtInType == false &&
		{
			downloadedGames.add(g);
		}
	}

	multimap<double, GameType*> games;
	for (int i = 0; i < downloadedGames.size(); i++)
	{
		GameType *g = downloadedGames.get(i);

		double up = (double)(g->upVotes);
		double total = (double)(g->upVotes + g->downVotes);
		double score = wilsonScore(up, total);

		games.insert(std::pair<double, GameType*>(score, g));
	}

	long long currentSecondsSinceEpoch = (long long)time(nullptr);

	multimap<double, GameType*>::iterator pos;
	for (pos = games.begin(); pos != games.end(); ++pos)
	{
		GameType *g = pos->second;

		long long secondsSinceEpoch = g->dateCreated / 1000;
		long long secondsExisted = currentSecondsSinceEpoch - secondsSinceEpoch;
		int daysExisted = (int)(secondsExisted / 60 / 60 / 24);

		string name = g->creatorUserName + " - " + g->name + " | Score: " + to_string(g->upVotes - g->downVotes) + " Age: " + to_string(daysExisted) + " days";

		BobColor *color = BobColor::darkGray;
		pair<string, BobColor*> stringColorPair = pair<string, BobColor*>(name, color);
		pair<GameType*, pair<string, BobColor*>> gameTypeStringColorPairPair = pair<GameType*, pair<string, BobColor*>>(g, stringColorPair);
		gamesStringColor.add(gameTypeStringColorPairPair);
	}

	return gamesStringColor;

}

//=========================================================================================================================
ArrayList<pair<GameSequence*, pair<string, BobColor*>>> BobsGame::getSortedGameSequences()
{//=========================================================================================================================

	ArrayList<pair<GameSequence*, pair<string, BobColor*>>> gamesStringColor;

//	for (int i = 0; i<loadedGameSequences.size(); i++)
//	{
//		GameSequence *g = loadedGameSequences.get(i);
//		if (g->builtInType)
//		{
//			string name = g->name;
//			BobColor *color = BobColor::darkGreen;
//			pair<string, BobColor*> stringColorPair = pair<string, BobColor*>(name, color);
//			pair<GameSequence*, pair<string, BobColor*>> gameSequenceStringColorPairPair = pair<GameSequence*, pair<string, BobColor*>>(g, stringColorPair);
//			gamesStringColor.add(gameSequenceStringColorPairPair);
//		}
//	}
	for (int i = 0; i<loadedGameSequences.size(); i++)
	{
		GameSequence *g = loadedGameSequences.get(i);
		if (g->downloaded == false)//g->builtInType == false &&
		{
			string name = g->creatorUserName + " - " + g->name;
			BobColor *color = BobColor::purple;
			pair<string, BobColor*> stringColorPair = pair<string, BobColor*>(name, color);
			pair<GameSequence*, pair<string, BobColor*>> gameSequenceStringColorPairPair = pair<GameSequence*, pair<string, BobColor*>>(g, stringColorPair);
			gamesStringColor.add(gameSequenceStringColorPairPair);
		}
	}

	ArrayList<GameSequence*> downloadedGames;
	for (int i = 0; i<loadedGameSequences.size(); i++)
	{
		GameSequence *g = loadedGameSequences.get(i);
		if (g->downloaded == true)//g->builtInType == false &&
		{
			downloadedGames.add(g);
		}
	}

	multimap<double, GameSequence*> games;
	for (int i = 0; i < downloadedGames.size(); i++)
	{
		GameSequence *g = downloadedGames.get(i);

		double up = (double)(g->upVotes);
		double total = (double)(g->upVotes + g->downVotes);
		double score = wilsonScore(up, total);

		games.insert(std::pair<double, GameSequence*>(score, g));
	}

	long long currentSecondsSinceEpoch = (long long)time(nullptr);

	multimap<double, GameSequence*>::iterator pos;
	for (pos = games.begin(); pos != games.end(); ++pos)
	{
		GameSequence *g = pos->second;

		long long secondsSinceEpoch = g->dateCreated / 1000;
		long long secondsExisted = currentSecondsSinceEpoch - secondsSinceEpoch;
		int daysExisted = (int)(secondsExisted / 60 / 60 / 24);

		string name = g->creatorUserName + " - " + g->name + " | Score: " + to_string(g->upVotes - g->downVotes) + " Age: " + to_string(daysExisted) + " days";

		BobColor *color = BobColor::darkGray;
		pair<string, BobColor*> stringColorPair = pair<string, BobColor*>(name, color);
		pair<GameSequence*, pair<string, BobColor*>> gameSequenceStringColorPairPair = pair<GameSequence*, pair<string, BobColor*>>(g, stringColorPair);
		gamesStringColor.add(gameSequenceStringColorPairPair);
	}

	return gamesStringColor;

}
//=========================================================================================================================
void BobsGame::populateGameTypesMenu(BobMenu *menu)
{//=========================================================================================================================


	//need to sort and color
	//make built in games green maybe
	//make usermade by me under those, make blue
	//make downloaded ones have user info, sorted by some voodoo metric of upvotes / timeexisted
	//use smaller font
	//username - game name - upvotes/downvotes

	ArrayList<pair<GameType*, pair<string, BobColor*>>> gamesStringColor = getSortedGameTypes();
	for (int i = 0; i < gamesStringColor.size(); i++)
	{
		pair<GameType*, pair<string, BobColor*>> gameTypeStringColorPairPair = gamesStringColor.get(i);
		GameType *g = gameTypeStringColorPairPair.first;
		pair<string, BobColor*> stringColorPair = gameTypeStringColorPairPair.second;
		string name = stringColorPair.first;
		BobColor *color = stringColorPair.second;

		BobMenu::MenuItem *m = menu->add(name, g->uuid);
		m->setColor(color);

	}
	//TODO:maybe show preview of game running really fast ???
}

//=========================================================================================================================
void BobsGame::populateGameSequencesMenu(BobMenu *menu)
{//=========================================================================================================================

	ArrayList<pair<GameSequence*, pair<string, BobColor*>>> gamesStringColor = getSortedGameSequences();
	for (int i = 0; i < gamesStringColor.size(); i++)
	{
		pair<GameSequence*, pair<string, BobColor*>> gameSequenceStringColorPairPair = gamesStringColor.get(i);
		GameSequence *g = gameSequenceStringColorPairPair.first;
		pair<string, BobColor*> stringColorPair = gameSequenceStringColorPairPair.second;
		string name = stringColorPair.first;
		BobColor *color = stringColorPair.second;

		BobMenu::MenuItem *m = menu->add(name, g->uuid);
		m->setColor(color);

	}
}








//=========================================================================================================================

string getNiceTime(long long ms)
{//=========================================================================================================================
	int sec = ms / 1000;
	int min = sec / 60;
	int hrs = min / 60;

	string niceTime = "";
	if (hrs > 0 && hrs < 10)niceTime += "0"+to_string(hrs) + "h ";
	if (hrs > 0 && hrs >= 10)niceTime += to_string(hrs) + "h ";

	if (min > 0 && min < 10)niceTime += "0" + to_string(min) + "m ";
	if (min > 0 && min >= 10)niceTime += to_string(min) + "m ";

	if (sec > 0 && sec < 10)niceTime += "0" + to_string(sec) + "s ";
	if (sec > 0 && sec >= 10)niceTime += to_string(sec) + "s ";
	return niceTime;
}


#include <time.h>

//=========================================================================================================================

string getDateFromEpochTime(long long ms)
{//=========================================================================================================================
	std::time_t seconds = ms / 1000;
	tm * time = localtime(&seconds);
	string s = std::asctime(time);
	std::string::size_type i = s.find("\n");
	if (i != std::string::npos)
		s.erase(i, s.length());
	return s;
}


//=========================================================================================================================
//gameTypeOrSequenceString or difficulty string can be "OVERALL"
void BobsGame::populateUserStatsForSpecificGameAndDifficultyMenu(BobMenu *menu, string gameTypeOrSequenceUUID, string difficultyString, string objectiveString)
{//=========================================================================================================================

	BobsGameUserStatsForSpecificGameAndDifficulty *stats = nullptr;
	for(int i=0;i<userStatsPerGameAndDifficulty.size();i++)
	{
		BobsGameUserStatsForSpecificGameAndDifficulty *s = userStatsPerGameAndDifficulty.get(i);
		if (s->gameTypeUUID == gameTypeOrSequenceUUID || s->gameSequenceUUID == gameTypeOrSequenceUUID || s->isGameTypeOrSequence == gameTypeOrSequenceUUID)
		{
			if (s->difficultyName == difficultyString)
			{
				if (s->objectiveString == objectiveString)
				{
					stats = s;
					break;
				}
			}
		}
	}
	bool deleteStats = false;
	if (stats == nullptr)
	{
		stats = new BobsGameUserStatsForSpecificGameAndDifficulty();
		deleteStats = true;
	}

	string gameName = "";
	if (gameTypeOrSequenceUUID == "OVERALL")
	{
		gameName = "All Games";
	}
	else
	{
		GameType* gt = getGameTypeByUUID(gameTypeOrSequenceUUID);
		GameSequence *gs = getGameSequenceByUUID(gameTypeOrSequenceUUID);
		if (gt != nullptr)gameName = gt->name;
		if (gs != nullptr)gameName = gs->name;
	}

	string difficultyName = "";
	if (difficultyString == "OVERALL")
	{
		difficultyName = "All Difficulties";
	}
	else
	{
		difficultyName = difficultyString;
	}

	menu->add("Your Stats");
	menu->add(gameName);
	menu->add(difficultyName);
	menu->add(objectiveString);
	menu->addInfo(" ");
	menu->add("Total Games Played: " + to_string(stats->totalGamesPlayed));
	menu->add("Single Player Games Played: " + to_string(stats->singlePlayerGamesPlayed));
	menu->add("Single Player Games Completed: " + to_string(stats->singlePlayerGamesCompleted));
	menu->add("Single Player Games Failed: " + to_string(stats->singlePlayerGamesLost));
	menu->add("Local Multiplayer Games Played: " + to_string(stats->localMultiplayerGamesPlayed));
	menu->add("Tournament Games Played: " + to_string(stats->tournamentGamesPlayed));
	menu->add("Tournament Games Won: " + to_string(stats->tournamentGamesWon));
	menu->add("Tournament Games Lost: " + to_string(stats->tournamentGamesLost));
	menu->add("Longest Game Length: " + getNiceTime(stats->longestGameLength));
	menu->add("Average Game Length: " + getNiceTime(stats->averageGameLength));
	menu->add("Total Time Played: " + getNiceTime(stats->totalTimePlayed));
	menu->add("First Time Played: " + getDateFromEpochTime(stats->firstTimePlayed));
	menu->add("Last Time Played: " + getDateFromEpochTime(stats->lastTimePlayed));
	menu->add("Most Blocks Cleared: " + to_string(stats->mostBlocksCleared));
	menu->add("Total Blocks Made: " + to_string(stats->totalBlocksMade));
	menu->add("Total Blocks Cleared: " + to_string(stats->totalBlocksCleared));
	menu->add("Total Pieces Made: " + to_string(stats->totalPiecesMade));
	menu->add("Total Pieces Placed: " + to_string(stats->totalPiecesPlaced));
	menu->add("Total Combos Made: " + to_string(stats->totalCombosMade));
	menu->add("Biggest Combo: " + to_string(stats->biggestCombo));
	menu->add("Elo Score: " + to_string(stats->eloScore));
	menu->add("Planeswalker Score: " + to_string(stats->planesWalkerPoints));

	if (deleteStats)delete stats;
}

/*

static ArrayList<BobsGameUserStatsForSpecificGameAndDifficulty*> userStatsPerGameAndDifficulty;
static ArrayList<BobsGameLeaderBoardAndHighScoreBoard*> topPlayersByTotalTimePlayed;
static ArrayList<BobsGameLeaderBoardAndHighScoreBoard*> topPlayersByTotalBlocksCleared;
static ArrayList<BobsGameLeaderBoardAndHighScoreBoard*> topPlayersByPlaneswalkerPoints;
static ArrayList<BobsGameLeaderBoardAndHighScoreBoard*> topPlayersByEloScore;

//TODO: could do highest level reached
//TODO: could do biggest combo
static ArrayList<BobsGameLeaderBoardAndHighScoreBoard*> topGamesByTimeLasted;
static ArrayList<BobsGameLeaderBoardAndHighScoreBoard*> topGamesByBlocksCleared;
*/

//=========================================================================================================================
void BobsGame::populateLeaderBoardOrHighScoreBoardMenu(BobMenu *menu, string gameTypeOrSequenceUUID, string difficultyString, string objectiveString,
	bool totalTimePlayed,
	bool totalBlocksCleared,
	bool planeswalkerPoints,
	bool eloScore,
	bool timeLasted,
	bool blocksCleared
)
{//=========================================================================================================================

	BobsGameLeaderBoardAndHighScoreBoard *stats = nullptr;

	ArrayList<BobsGameLeaderBoardAndHighScoreBoard*> *board = &topPlayersByTotalTimePlayed;

	if (totalTimePlayed)board = &topPlayersByTotalTimePlayed;
	if (totalBlocksCleared)board = &topPlayersByTotalBlocksCleared;
	if (planeswalkerPoints)board = &topPlayersByPlaneswalkerPoints;
	if (eloScore)board = &topPlayersByEloScore;
	if (timeLasted)board = &topGamesByTimeLasted;
	if (blocksCleared)board = &topGamesByBlocksCleared;

	for (int i = 0; i<board->size(); i++)
	{
		BobsGameLeaderBoardAndHighScoreBoard *s = board->get(i);
		if (s->gameTypeUUID == gameTypeOrSequenceUUID || s->gameSequenceUUID == gameTypeOrSequenceUUID || s->isGameTypeOrSequence == gameTypeOrSequenceUUID)
		{
			if (s->difficultyName == difficultyString)
			{
				if (s->objectiveString == objectiveString)
				{
					stats = s;
					break;
				}
			}
		}
	}
	bool deleteStats = false;
	if (stats == nullptr)
	{
		stats = new BobsGameLeaderBoardAndHighScoreBoard();
		deleteStats = true;
	}

	string gameName = "";
	if (gameTypeOrSequenceUUID == "OVERALL")
	{
		gameName = "All Games";
	}
	else
	{
		GameType* gt = getGameTypeByUUID(gameTypeOrSequenceUUID);
		GameSequence *gs = getGameSequenceByUUID(gameTypeOrSequenceUUID);
		if (gt != nullptr)gameName = gt->name;
		if (gs != nullptr)gameName = gs->name;
	}

	string difficultyName = "";
	if (difficultyString == "OVERALL")
	{
		difficultyName = "All Difficulties";
	}
	else
	{
		difficultyName = difficultyString;
	}

	/*

		class BobsGameLeaderBoardAndHighScoreBoardEntry
	{
	public:
		string userName = "";
		long userID = -1;

		//elo score should handle most of this
		int totalGamesPlayed = 0;
		int singlePlayerGamesPlayed = 0;
		int tournamentGamesPlayed = 0;
		int localMultiplayerGamesPlayed = 0;
		int tournamentGamesWon = 0;
		int tournamentGamesLost = 0;
		int singlePlayerGamesCompleted = 0;
		int singlePlayerGamesLost = 0;
		int singlePlayerHighestLevelReached = 0;
		long totalTimePlayed = 0;
		long longestGameLength = 0;
		long firstTimePlayed = 0;
		long lastTimePlayed = 0;
		long timeRecordSet = 0;
		double eloScore = 0;
		long planesWalkerPoints = 0;
		long totalBlocksCleared = 0;
		int biggestCombo = 0;
		int mostBlocksClearedInOneGame = 0;
		string statsUUID = "";
	};

	ArrayList<BobsGameLeaderBoardAndHighScoreBoardEntry*> entries;
	*/

	string titleName = "";

	if (totalTimePlayed)titleName = "Top Players (Total Time Played)";
	if (totalBlocksCleared)titleName = "Top Players (Total Blocks Cleared)";
	if (planeswalkerPoints)titleName = "Top Players (Planeswalker Points)";
	if (eloScore)titleName = "Top Players (Elo Score)";
	if (timeLasted)titleName = "Top Games (Time Lasted)";
	if (blocksCleared)titleName = "Top Games (Total Time Played)";

	menu->add(titleName);
	menu->add(gameName);
	menu->add(difficultyName);
	menu->add(objectiveString);
	menu->addInfo(" ");

	for (int i = 0; i < stats->entries.size(); i++)
	{
		BobsGameLeaderBoardAndHighScoreBoard::BobsGameLeaderBoardAndHighScoreBoardEntry* e = stats->entries.get(i);
		string s = to_string(i)+") " + e->userName + " | ";

		if (totalTimePlayed)
		{
			menu->add(s+"Total Time Played: " + getNiceTime(e->totalTimePlayed));
		}
		if (totalBlocksCleared)
		{
			menu->add(s + "Total Blocks Cleared: " + to_string(e->totalBlocksCleared));
		}

		if (planeswalkerPoints)
		{
			menu->add(s + "Planeswalker Score: " + to_string(e->planesWalkerPoints));
		}

		if (eloScore)
		{
			menu->add(s + "Elo Score: " + to_string(e->eloScore));
		}

		if (timeLasted)
		{
			menu->add(s + "Longest Game Length: " + getNiceTime(e->longestGameLength));
		}

		if (blocksCleared)
		{
			menu->add(s + "Most Blocks Cleared: " + to_string(e->mostBlocksClearedInOneGame));
		}

//		menu->add("Total Games Played: " + to_string(e->totalGamesPlayed));
//		menu->add("Single Player Games Played: " + to_string(e->singlePlayerGamesPlayed));
//		menu->add("Single Player Games Completed: " + to_string(e->singlePlayerGamesCompleted));
//		menu->add("Single Player Games Failed: " + to_string(e->singlePlayerGamesLost));
//		menu->add("Local Multiplayer Games Played: " + to_string(e->localMultiplayerGamesPlayed));
//		menu->add("Tournament Games Played: " + to_string(e->tournamentGamesPlayed));
//		menu->add("Tournament Games Won: " + to_string(e->tournamentGamesWon));
//		menu->add("Tournament Games Lost: " + to_string(e->tournamentGamesLost));
//		menu->add("First Time Played: " + getDateFromEpochTime(e->firstTimePlayed));
//		menu->add("Time Record Set: " + getDateFromEpochTime(e->timeRecordSet));
//		menu->add("Biggest Combo: " + to_string(e->biggestCombo));


		menu->addInfo(" ");
	}

	if (deleteStats)delete stats;

}


//=========================================================================================================================
void BobsGame::selectSingleGameTypeMenuUpdate()
{//=========================================================================================================================

	if (selectSingleGameTypeMenu == nullptr)
	{
		selectSingleGameTypeMenu = new BobMenu(this, "");
		selectSingleGameTypeMenu->center = false;
		selectSingleGameTypeMenu->setFontSize(14);
		selectSingleGameTypeMenu->outline = false;

		populateGameTypesMenu(selectSingleGameTypeMenu);


		selectSingleGameTypeMenu->cursorPosition = selectSingleGameTypeMenuCursorPosition;
	}

	//make key repeat work
	if (getControlsManager()->MINIGAME_UP_HELD)
	{
		long long currentTime = System::currentHighResTimer();

		if(upRepeatedStarted==false)
		{
			selectSingleGameTypeMenu->up();
			upRepeatedStarted = true;
			upLastTime = currentTime;
		}
		else
		{

			long long startTime = upLastTime;
			int ticksPassed = (int)(System::getTicksBetweenTimes(startTime, currentTime));

			if (upRepeating == false)
			{
				if (ticksPassed > 300)
				{
					upLastTime = currentTime;
					selectSingleGameTypeMenu->up();
					upRepeating = true;
				}
			}
			else
			{
				if (ticksPassed > 30)
				{
					upLastTime = currentTime;
					selectSingleGameTypeMenu->up();
				}
			}
		}
	}
	else
	{
		upRepeating = false;
		upRepeatedStarted = false;
	}

	if (getControlsManager()->MINIGAME_DOWN_HELD)
	{
		long long currentTime = System::currentHighResTimer();

		if (downRepeatedStarted == false)
		{
			selectSingleGameTypeMenu->down();
			downRepeatedStarted = true;
			downLastTime = currentTime;
		}
		else
		{
			long long startTime = downLastTime;
			int ticksPassed = (int)(System::getTicksBetweenTimes(startTime, currentTime));

			if (downRepeating == false)
			{
				if (ticksPassed > 300)
				{
					downLastTime = currentTime;
					selectSingleGameTypeMenu->down();
					downRepeating = true;
				}
			}
			else
			{
				if (ticksPassed > 30)
				{
					downLastTime = currentTime;
					selectSingleGameTypeMenu->down();
				}
			}
		}
	}
	else
	{
		downRepeating = false;
		downRepeatedStarted = false;
	}

	bool leaveMenu = false;

	bool confirm = getControlsManager()->miniGame_CONFIRM_Pressed();//, clicked, mx, my
	bool clicked = getControlsManager()->mouse_LEFTBUTTON_Pressed();
	int mx = getControlsManager()->getMouseX();
	int my = getControlsManager()->getMouseY();
	if (confirm || clicked)
	{

		for (int i = 0; i<loadedGameTypes.size(); i++)
		{
			GameType *g = loadedGameTypes.get(i);
			if (selectSingleGameTypeMenu->isSelectedID(g->uuid, clicked, mx, my))
			{

				if(statsMenuShowing)
				{
					statsMenu_gameSequenceOrTypeUUID = g->uuid;
					statsMenu_gameSequenceOrTypeName = g->name;
				}
				else
				{

					currentRoom->gameSequence = new GameSequence();
					currentRoom->gameSequence->gameTypes.add(g);
					currentRoom->gameSequence->name = g->name;

					getPlayer1Game()->currentGameSequence = currentRoom->gameSequence;
				}
			}
		}

		//gameObjectiveMenuShowing = true;


		leaveMenu = true;
	}

//	if (getControlsManager()->miniGame_CANCEL_Pressed())
//	{
//		selectGameSequenceOrSingleGameTypeMenuShowing = true;
//		leaveMenu = true;
//	}

	if (leaveMenu)
	{
		selectSingleGameTypeMenuShowing = false;

		if (selectSingleGameTypeMenu != nullptr)
		{
			selectSingleGameTypeMenuCursorPosition = selectSingleGameTypeMenu->cursorPosition;
			delete selectSingleGameTypeMenu;
			selectSingleGameTypeMenu = nullptr;
		}
	}

}






//=========================================================================================================================
void BobsGame::difficultyMenuUpdate()
{//=========================================================================================================================

	GameType gt;

	if (difficultyMenu == nullptr)
	{
		difficultyMenu = new BobMenu(this, "");
		difficultyMenu->center = false;

		if (localMultiplayer || networkMultiplayer)
		{
			difficultyMenu->add("Allow Different Difficulties");
		}

		if(statsMenuShowing)
		{
			difficultyMenu->add("All Difficulties", "Allow Different Difficulties");
		}

		for (int i = 0; i<gt.difficultyTypes.size(); i++)
		{
			difficultyMenu->add(gt.difficultyTypes.get(i)->name);
		}

		difficultyMenu->cursorPosition = difficultyMenuCursorPosition;
	}


	if (getControlsManager()->miniGame_UP_Pressed())
	{
		difficultyMenu->up();
	}

	if (getControlsManager()->miniGame_DOWN_Pressed())
	{
		difficultyMenu->down();
	}

	bool leaveMenu = false;

	bool confirm = getControlsManager()->miniGame_CONFIRM_Pressed();//, clicked, mx, my
	bool clicked = getControlsManager()->mouse_LEFTBUTTON_Pressed();
	int mx = getControlsManager()->getMouseX();
	int my = getControlsManager()->getMouseY();
	if (confirm || clicked)
	{

		if (difficultyMenu->isSelectedID("Allow Different Difficulties", clicked, mx, my))
		{
			if (localMultiplayer || networkMultiplayer)
			{
				currentRoom->multiplayer_AllowDifferentDifficulties = true;
			}

			if(statsMenuShowing)
			{
				statsMenu_difficultyName = "OVERALL";
			}
		}

		for (int i = 0; i<gt.difficultyTypes.size(); i++)
		{

			string difficultyName = gt.difficultyTypes.get(i)->name;
			if (difficultyMenu->isSelectedID(difficultyName, clicked, mx, my))
			{

				if (statsMenuShowing == false)
				{
					currentRoom->multiplayer_AllowDifferentDifficulties = false;
					currentRoom->difficultyName = difficultyName;

					if (getPlayer1Game()->currentGameSequence != nullptr)
						getPlayer1Game()->currentGameSequence->currentDifficultyName = currentRoom->difficultyName;
				}
				else
				{
					statsMenu_difficultyName = difficultyName;
				}

			}
		}

//		if (localMultiplayer)
//		{
//			localMultiplayerPlayerJoinMenuShowing = true;
//		}
//		else
//			if (networkMultiplayer)
//			{
//				networkMultiplayerPlayerJoinMenuShowing = true;
//			}
//			else
//			{
//				//start single player game
//			}

		leaveMenu = true;
	}

//	if (getControlsManager()->miniGame_CANCEL_Pressed())
//	{
//		if (localMultiplayer || networkMultiplayer)
//		{
//			multiplayerOptionsMenuShowing = true;
//		}
//		else
//		{
//			selectGameSequenceOrSingleGameTypeMenuShowing = true;
//		}
//		leaveMenu = true;
//	}

	if (leaveMenu)
	{
		difficultyMenuShowing = false;

		if (difficultyMenu != nullptr)
		{
			difficultyMenuCursorPosition = difficultyMenu->cursorPosition;
			delete difficultyMenu;
			difficultyMenu = nullptr;
		}
	}

}


//=========================================================================================================================
void BobsGame::multiplayerOptionsMenuUpdate()
{//=========================================================================================================================

	//const string ALLOW_DIFFERENT_GAME_SEQUENCES_OR_TYPES = "Game Sequence: Allow Different Game Sequences Or Types";
	//const string ALLOW_DIFFERENT_DIFFICULTIES = "Difficulty: Allow Different Difficulties";
	//const string GAME_ENDS_WHEN_ALL_OPPONENTS_LOSE = "Game Ends When All Opponents Lose";
	//const string GAME_ENDS_WHEN_SOMEONE_COMPLETES_CREDITS_LEVEL = "Game Ends When Someone Completes Credits Level";
	//const string DISABLE_VS_GARBAGE = "Disable Sending VS Garbage";
	//const string CONTINUE = "Continue";

	if (multiplayerOptionsMenu == nullptr)
	{

		if(networkMultiplayer)
		{
			multiplayerOptionsMenu = new BobMenu(this, "Set Network Multiplayer Room Options");
			//multiplayerOptionsMenu->center = false;
			multiplayerOptionsMenu->add("Visibility: Public", "Public Or Private");
			multiplayerOptionsMenu->add("Score Mode: Free Play", "Free Play Or Tournament");
			multiplayerOptionsMenu->add("Max Players: Unlimited", "Max Players");
			multiplayerOptionsMenu->addInfo(" ", " ");

		}
		else
		{
			multiplayerOptionsMenu = new BobMenu(this, "Set Local Multiplayer Options");
			//multiplayerOptionsMenu->center = false;
		}

		multiplayerOptionsMenu->add("Game Sequence: Allow Different Game Sequences Or Types", "Select Game");
		multiplayerOptionsMenu->add("Difficulty: Allow Different Difficulties", "Difficulty");
		multiplayerOptionsMenu->add("Objective: ", "Objective");
		multiplayerOptionsMenu->add("More Options...", "Options");
		multiplayerOptionsMenu->addInfo(" "," ");
		multiplayerOptionsMenu->add("Continue");
		multiplayerOptionsMenu->addInfo(" ", " ");
		multiplayerOptionsMenu->add("Save Config...", "Save");
		multiplayerOptionsMenu->add("Load Config...", "Load");
		multiplayerOptionsMenu->addInfo(" ", " ");
		if(networkMultiplayer)multiplayerOptionsMenu->add("Back To Network Multiplayer Lobby");
		else multiplayerOptionsMenu->add("Back To Title Screen");


		multiplayerOptionsMenu->cursorPosition = multiplayerOptionsMenuCursorPosition;
	}

	if(currentRoom==nullptr)
	{
		currentRoom = new Room();
	}

	if(currentRoom->gameSequence == nullptr)
	{
		currentRoom->gameSequence = new GameSequence();
		currentRoom->gameSequence->gameTypes.add(new GameType());
	}

	if(currentRoom->multiplayer_AllowDifferentGameSequences)
	{
		multiplayerOptionsMenu->getMenuItemByID("Select Game")->setText("Game Sequence: Allow Different Game Sequences Or Types");
	}
	else
	if (currentRoom->gameSequence != nullptr)
	{
		{
			BobMenu::MenuItem *c = multiplayerOptionsMenu->getMenuItemByID("Select Game");
			if (c != nullptr)
			{
				if (currentRoom->gameSequence->gameTypes.size() > 1)c->setText("Game Sequence: " + currentRoom->gameSequence->name);
				if (currentRoom->gameSequence->gameTypes.size() == 1)c->setText("Game Type: " + currentRoom->gameSequence->name);
			}
		}
	}

	if (currentRoom->multiplayer_AllowDifferentDifficulties)
	{
		multiplayerOptionsMenu->getMenuItemByID("Difficulty")->setText("Difficulty: Allow Different Difficulties");
	}
	else
	if (currentRoom->difficultyName != "")
	{

		GameType gt;
		for (int i = 0; i < gt.difficultyTypes.size(); i++)
		{
			string difficultyName = gt.difficultyTypes.get(i)->name;
			if (currentRoom->difficultyName == difficultyName)selectedDifficultyIndex = i + 1;
		}

		DifficultyType *d = gt.difficultyTypes.get(selectedDifficultyIndex - 1);
		string difficultyName = d->name;
		currentRoom->difficultyName = difficultyName;
		if (getPlayer1Game()->currentGameSequence != nullptr)
			getPlayer1Game()->currentGameSequence->currentDifficultyName = difficultyName;

		multiplayerOptionsMenu->getMenuItemByID("Difficulty")->setText("Difficulty: " + difficultyName);
	}

	{
		string objectiveString = "";

		if (currentRoom->endlessMode)
		{
			objectiveString = "Play As Long As You Can (Endless Mode)";
		}
		else
		{
			objectiveString = "Play To Credits Level";
		}
		multiplayerOptionsMenu->getMenuItemByID("Objective")->setText("Objective: " + objectiveString);
	}

	if (networkMultiplayer)
	{
		if (currentRoom->multiplayer_PrivateRoom)multiplayerOptionsMenu->getMenuItemByID("Public Or Private")->setText("Visibility: Private (Friends Only)");
		else multiplayerOptionsMenu->getMenuItemByID("Public Or Private")->setText("Visibility: Public");

		if (currentRoom->multiplayer_TournamentRoom)multiplayerOptionsMenu->getMenuItemByID("Free Play Or Tournament")->setText("Score Mode: Tournament (Counts Towards Ranking)");
		else multiplayerOptionsMenu->getMenuItemByID("Free Play Or Tournament")->setText("Score Mode: Free Play");

		if (currentRoom->multiplayer_MaxPlayers < 2)multiplayerOptionsMenu->getMenuItemByID("Max Players")->setText("Max Players: Unlimited");
		else multiplayerOptionsMenu->getMenuItemByID("Max Players")->setText("Max Players: " + to_string(currentRoom->multiplayer_MaxPlayers));
	}




	if (selectGameSequenceOrSingleGameTypeMenuShowing)
	{
		selectGameSequenceOrSingleGameTypeMenuUpdate();
	}
	else
	if (selectGameSequenceMenuShowing)
	{
		selectGameSequenceMenuUpdate();
	}
	else
	if (selectSingleGameTypeMenuShowing)
	{
		selectSingleGameTypeMenuUpdate();
	}
	else
	if (gameSequenceOptionsMenuShowing)
	{
		gameSequenceOptionsMenuUpdate();
	}
	else
	if (difficultyMenuShowing)
	{
		difficultyMenuUpdate();
	}
	else
	if (gameObjectiveMenuShowing)
	{
		gameObjectiveMenuUpdate();
	}
	else
	if (roomOptionsMenuShowing)
	{
		roomOptionsMenuUpdate();
	}
	else
	{

		if (getControlsManager()->miniGame_UP_Pressed())
		{
			multiplayerOptionsMenu->up();
		}

		if (getControlsManager()->miniGame_DOWN_Pressed())
		{
			multiplayerOptionsMenu->down();
		}

		bool leaveMenu = false;

		bool left = getControlsManager()->miniGame_LEFT_Pressed();
		bool right = getControlsManager()->miniGame_RIGHT_Pressed();

		if(left || right)
		{

			if (multiplayerOptionsMenu->isSelectedID("Difficulty"))
			{
				GameType gt;
				if (left)
				{
					selectedDifficultyIndex--;
					if (selectedDifficultyIndex < 0)selectedDifficultyIndex = gt.difficultyTypes.size();//-1
				}
				if (right)
				{
					selectedDifficultyIndex++;
					if (selectedDifficultyIndex > gt.difficultyTypes.size())selectedDifficultyIndex = 0;
				}

				if (selectedDifficultyIndex > 0)
				{
					currentRoom->multiplayer_AllowDifferentDifficulties = false;
					DifficultyType *d = gt.difficultyTypes.get(selectedDifficultyIndex - 1);
					string difficultyName = d->name;
					currentRoom->difficultyName = difficultyName;
					if (getPlayer1Game()->currentGameSequence != nullptr)
						getPlayer1Game()->currentGameSequence->currentDifficultyName = difficultyName;
				}
				else
				{
					currentRoom->multiplayer_AllowDifferentDifficulties = true;
				}
			}



		}

		bool confirm = getControlsManager()->miniGame_CONFIRM_Pressed();//, clicked, mx, my
		bool clicked = getControlsManager()->mouse_LEFTBUTTON_Pressed();
		int mx = getControlsManager()->getMouseX();
		int my = getControlsManager()->getMouseY();
		if (confirm || left || right || clicked)
		{



			if (multiplayerOptionsMenu->isSelectedID("Public Or Private", clicked, mx, my))
			{
				currentRoom->multiplayer_PrivateRoom = !currentRoom->multiplayer_PrivateRoom;
			}

			if (multiplayerOptionsMenu->isSelectedID("Free Play Or Tournament", clicked, mx, my))
			{
				currentRoom->multiplayer_TournamentRoom = !currentRoom->multiplayer_TournamentRoom;
			}

			if (multiplayerOptionsMenu->isSelectedID("Max Players", clicked, mx, my))
			{
				currentRoom->multiplayer_MaxPlayers = 0;
			}

			if (multiplayerOptionsMenu->isSelectedID("Objective", clicked, mx, my))
			{
				if (confirm || clicked) gameObjectiveMenuShowing = true;
				else
				{
					currentRoom->endlessMode = !currentRoom->endlessMode;
					//if (left)
					//{
					//	selectedObjectiveIndex--;
					//	if (selectedObjectiveIndex < 0)selectedObjectiveIndex = (int)GameObjective::LAST - 1;
					//}
					//if (right)
					//{
					//	selectedObjectiveIndex++;
					//	if (selectedObjectiveIndex >= (int)GameObjective::LAST)selectedObjectiveIndex = 0;
					//}
					//if (selectedObjectiveIndex == (int)GameObjective::PLAY_TO_CREDITS_LEVEL)
					//{
					//	if (currentRoom != nullptr)currentRoom->endlessMode = false;
					//}
					//if (selectedObjectiveIndex == (int)GameObjective::ENDLESS)
					//{
					//	if (currentRoom != nullptr)currentRoom->endlessMode = true;
					//}
				}
			}

		}



		if(left)
		{
			if (multiplayerOptionsMenu->isSelectedID("Max Players"))
			{
				long long startTime = timeLastChangedSetting;
				long long currentTime = System::currentHighResTimer();
				int ticksPassed = (int)(System::getTicksBetweenTimes(startTime, currentTime));

				if (ticksPassed > 15)
				{
					timeLastChangedSetting = currentTime;
					if (currentRoom->multiplayer_MaxPlayers > 0) currentRoom->multiplayer_MaxPlayers--;
					if (currentRoom->multiplayer_MaxPlayers < 2)currentRoom->multiplayer_MaxPlayers = 0;
				}
			}
		}

		if(right)
		{
			if (multiplayerOptionsMenu->isSelectedID("Max Players"))
			{
				long long startTime = timeLastChangedSetting;
				long long currentTime = System::currentHighResTimer();
				int ticksPassed = (int)(System::getTicksBetweenTimes(startTime, currentTime));

				if (ticksPassed > 15)
				{
					timeLastChangedSetting = currentTime;
					if (currentRoom->multiplayer_MaxPlayers < 2)currentRoom->multiplayer_MaxPlayers = 2;
					currentRoom->multiplayer_MaxPlayers++;
				}
			}
		}

		if (confirm || clicked)
		{

			if (multiplayerOptionsMenu->isSelectedID("Select Game", clicked, mx, my))
			{
				selectGameSequenceOrSingleGameTypeMenuShowing = true;
			}

			if (multiplayerOptionsMenu->isSelectedID("Difficulty", clicked, mx, my))
			{
				difficultyMenuShowing = true;
			}

			if (multiplayerOptionsMenu->isSelectedID("Options", clicked, mx, my))
			{
				roomOptionsMenuShowing = true;
			}

			if (multiplayerOptionsMenu->isSelectedID("Save", clicked, mx, my))
			{
				saveRoomConfigMenuShowing = true;
			}

			if (multiplayerOptionsMenu->isSelectedID("Load", clicked, mx, my))
			{
				loadRoomConfigMenuShowing = true;
			}


			if (multiplayerOptionsMenu->isSelectedID("Continue", clicked, mx, my))
			{

				if (localMultiplayer)
				{
					localMultiplayerPlayerJoinMenuShowing = true;
				}
				else
					if (networkMultiplayer)
					{
						networkMultiplayerPlayerJoinMenuShowing = true;
					}

				leaveMenu = true;
			}

			if (multiplayerOptionsMenu->isSelectedID("Back To Title Screen", clicked, mx, my))
			{
				startScreenMenuShowing = true;

				leaveMenu = true;
			}

			if (multiplayerOptionsMenu->isSelectedID("Back To Network Multiplayer Lobby", clicked, mx, my))
			{
				networkMultiplayerLobbyMenuShowing = true;

				leaveMenu = true;
			}
		}

		if (getControlsManager()->miniGame_CANCEL_Pressed())
		{
			if(networkMultiplayer)networkMultiplayerLobbyMenuShowing = true;
			else startScreenMenuShowing = true;

			leaveMenu = true;
		}

		if (leaveMenu)
		{
			multiplayerOptionsMenuShowing = false;

			if (multiplayerOptionsMenu != nullptr)
			{
				multiplayerOptionsMenuCursorPosition = multiplayerOptionsMenu->cursorPosition;
				delete multiplayerOptionsMenu;
				multiplayerOptionsMenu = nullptr;
			}
		}
	}

}

//=========================================================================================================================
void BobsGame::multiplayerOptionsMenuRender()
{//=========================================================================================================================

	GLUtils::drawFilledRect(BobMenu::bgColor->ri(), BobMenu::bgColor->gi(), BobMenu::bgColor->bi(), 0, (float)getWidth(), 0, (float)getHeight(), 1.0f);

	BobTexture* t = onlineTexture;

	if (multiplayerOptionsMenu == nullptr)return;

	if (t != nullptr)
	{
		multiplayerOptionsMenu->setGraphic(t, getWidth() / 3 * 2, getHeight() / 8);
	}

	multiplayerOptionsMenu->render(getHeight() / 2, getWidth() / 2 - 50);

	if (selectGameSequenceOrSingleGameTypeMenuShowing && selectGameSequenceOrSingleGameTypeMenu != nullptr)
	{
		Caption *c = multiplayerOptionsMenu->getCaptionByID("Select Game");
		selectGameSequenceOrSingleGameTypeMenu->render(c->screenY + c->getHeight() + 8, c->screenX + c->getWidth() / 2, getHeight(), true, nullptr, nullptr, true);
	}

	if (selectGameSequenceMenuShowing && selectGameSequenceMenu != nullptr)
	{
		Caption *c = multiplayerOptionsMenu->getCaptionByID("Select Game");
		selectGameSequenceMenu->render(c->screenY + c->getHeight() + 8, c->screenX + c->getWidth() / 2, getHeight(), true, nullptr, nullptr, true);
	}

	if (selectSingleGameTypeMenuShowing && selectSingleGameTypeMenu != nullptr)
	{
		Caption *c = multiplayerOptionsMenu->getCaptionByID("Select Game");
		selectSingleGameTypeMenu->render(c->screenY + c->getHeight() + 8, c->screenX + c->getWidth() / 2, getHeight(), true, nullptr, nullptr, true);
	}

	if (gameSequenceOptionsMenuShowing && gameSequenceOptionsMenu != nullptr)
	{
		Caption *c = multiplayerOptionsMenu->getCaptionByID("Select Game");
		gameSequenceOptionsMenu->render(c->screenY + c->getHeight() + 8, c->screenX + c->getWidth() / 2, getHeight(), true, nullptr, nullptr, true);
	}

	if (difficultyMenuShowing && difficultyMenu != nullptr)
	{
		Caption *c = multiplayerOptionsMenu->getCaptionByID("Difficulty");
		difficultyMenu->render(c->screenY + c->getHeight() + 8, c->screenX + c->getWidth() / 2, getHeight(), true, nullptr, nullptr, true);
	}

	if (gameObjectiveMenuShowing && gameObjectiveMenu != nullptr)
	{
		Caption *c = multiplayerOptionsMenu->getCaptionByID("Objective");
		gameObjectiveMenu->render(c->screenY + c->getHeight() + 8, c->screenX + c->getWidth() / 2, getHeight(), true, nullptr, nullptr, true);
	}

	if (roomOptionsMenuShowing && roomOptionsMenu != nullptr)
	{
		int bottomOfCaptions = 0;

		{
			//Caption *c = multiplayerOptionsMenu->getCaptionByID("Options");
			//roomOptionsMenu->render(c->screenY + c->getHeight() + 8, c->screenX + c->getWidth() / 2, getHeight(), true, nullptr, &bottomOfCaptions, true);
			roomOptionsMenu->render(getHeight() / 6, 0, getHeight(), true, nullptr, &bottomOfCaptions, true);
		}

		if (descriptionCaption != nullptr)
		{
			descriptionCaption->screenY = getHeight() - 30;// bottomOfCaptions + 24;
			descriptionCaption->update();
			descriptionCaption->render();
		}

		if (sendGarbageToMenuShowing && sendGarbageToMenu != nullptr)
		{
			Caption *c = roomOptionsMenu->getCaptionByID("Send Garbage To");
			sendGarbageToMenu->render(c->screenY + c->getHeight() + 8, c->screenX + c->getWidth() / 2, getHeight(), true, nullptr, nullptr, true);
		}
	}

}




//=========================================================================================================================
void BobsGame::localMultiplayerPlayerJoinMenuUpdate()
{//=========================================================================================================================

	if (localMultiplayerPlayerJoinMenu == nullptr)
	{
		localMultiplayerPlayerJoinMenu = new BobMenu(this, "Local Multiplayer Host/Join Menu");
		localMultiplayerPlayerJoinMenu->addInfo("Press the Space key or A on your controller to join");
		localMultiplayerPlayerJoinMenu->addInfo("Press Esc or Select on your controller to return to Title Screen");

		players.deleteAll();
//		while (players.size()>0)
//		{
//			PuzzlePlayer *p = players.get(players.size() - 1);
//			players.removeAt(players.size() - 1);
//			delete p;
//		}
	}

	bool leaveMenu = false;

	//select player, show icon for gamepad or keyboard
	//show mini difficulty menu
	//if press a, ready
	//if both ready, game start

	bool ready = true;
	for (int i = 0; i<players.size(); i++)
	{
		PuzzlePlayer *p = players.get(i);
		if (p->confirmed == false)
		{
			ready = false;


			if (p->setGameSequence == false)
			{
				if (currentRoom->multiplayer_AllowDifferentGameSequences)
				{
					playerGameSequenceMiniMenuUpdate(p);
				}
				else
				{
					p->gameLogic->currentGameSequence = currentRoom->gameSequence;
					p->setGameSequence = true;
				}
			}
			else
			if (p->setDifficulty == false)
			{
				if (currentRoom->multiplayer_AllowDifferentDifficulties)
				{
					playerDifficultyMiniMenuUpdate(p);
				}
				else
				{
					p->gameLogic->currentGameSequence->currentDifficultyName = currentRoom->difficultyName;
					p->setDifficulty = true;
				}
			}
			else
			if(p->confirmed==false)
			{
				p->confirmed = true;

				p->gameCaption = getCaptionManager()->newManagedCaption(Caption::Position::NONE, 0, 0, -1, p->gameLogic->currentGameSequence->name, 12, true, BobMenu::menuColor, BobMenu::clearColor, RenderOrder::OVER_GUI);
				p->difficultyCaption = getCaptionManager()->newManagedCaption(Caption::Position::NONE, 0, 0, -1, p->gameLogic->currentGameSequence->currentDifficultyName, 12, true, BobMenu::menuColor, BobMenu::clearColor, RenderOrder::OVER_GUI);
			}


		}
	}

	if (players.size() > 1)
	{
		if (ready)
		{
			if (localMultiplayerPressStartCaption == nullptr)
			{
				localMultiplayerPressStartCaption = getCaptionManager()->newManagedCaption(Caption::Position::CENTERED_X, 0, (int)(getHeight() - 50), -1, "Press the Enter key or Start on your controller to start game", 16, true, BobMenu::menuColor, BobMenu::clearColor, RenderOrder::OVER_GUI);
				localMultiplayerPressStartCaption->flashing = true;
				localMultiplayerPressStartCaption->flashingTicksPerFlash = 1000;
			}

			if (getControlsManager()->miniGame_START_Pressed())
			{
				//start the game!

				leaveMenu = true;
			}
		}
	}

	if (players.size() <= 1 || ready == false)
	{
		if (localMultiplayerPressStartCaption != nullptr)
		{
			localMultiplayerPressStartCaption->setToBeDeletedImmediately();
			localMultiplayerPressStartCaption = nullptr;
		}
	}

	//int maxPlayers = 4;
	if (getControlsManager()->key_SPACE_Pressed())
	{
		//if (players.size() < maxPlayers)
		{
			bool alreadyInUse = false;
			for (int i = 0; i < players.size(); i++)
			{
				PuzzlePlayer *p = players.get(i);
				if (p->useKeyboard)alreadyInUse = true;
			}
			if (!alreadyInUse)
			{
				PuzzlePlayer *p = new PuzzlePlayer(new GameLogic(this, -1));
				p->useKeyboard = true;
				players.add(p);
				p->nameCaption = getCaptionManager()->newManagedCaption(Caption::Position::NONE, 0, 0, -1, "Local (Keyboard)", 12, true, BobMenu::menuColor, BobMenu::clearColor, RenderOrder::OVER_GUI);
			}
		}
	}
	if (getControlsManager()->key_LSHIFT_Pressed())
	{
		for (int i = 0; i < players.size(); i++)
		{
			PuzzlePlayer *p = players.get(i);
			if (p->useKeyboard)
			{
				players.removeAt(i);
				delete p;
				i = 0;
			}
		}
	}

	for (int controllerNum = 0; controllerNum < getControlsManager()->gameControllers.size(); controllerNum++)
	{
		GameController *g = getControlsManager()->gameControllers.get(controllerNum);

		if (g->a_Pressed())
		{
			//if (players.size() < maxPlayers)
			{
				bool alreadyInUse = false;
				for (int i = 0; i < players.size(); i++)
				{
					PuzzlePlayer *p = players.get(i);
					if (p->gameController == g)alreadyInUse = true;
				}

				if (!alreadyInUse)
				{
					PuzzlePlayer *p = new PuzzlePlayer(new GameLogic(this, -1));
					p->gameController = g;
					players.add(p);
					p->nameCaption = getCaptionManager()->newManagedCaption(Caption::Position::NONE, 0, 0, -1, "Local (Controller " + to_string(controllerNum) + ")", 12, true, BobMenu::menuColor, BobMenu::clearColor, RenderOrder::OVER_GUI);
				}
			}
		}

		if (g->b_Pressed())
		{
			for (int i = 0; i < players.size(); i++)
			{
				PuzzlePlayer *p = players.get(i);
				if (p->gameController == g)
				{
					players.removeAt(i);
					delete p;
					i = 0;
				}
			}
		}
	}

	if (getControlsManager()->key_ESC_Pressed() || getControlsManager()->miniGame_SELECT_Pressed())
	{
		leaveMenu = true;
		startScreenMenuShowing = true;

		initPlayer();
	}

	if (leaveMenu)
	{
		localMultiplayerPlayerJoinMenuShowing = false;

		if (localMultiplayerPlayerJoinMenu != nullptr)
		{
			delete localMultiplayerPlayerJoinMenu;
			localMultiplayerPlayerJoinMenu = nullptr;
		}

		if (localMultiplayerPressStartCaption != nullptr)
		{
			localMultiplayerPressStartCaption->setToBeDeletedImmediately();
			localMultiplayerPressStartCaption = nullptr;
		}
	}

}

//=========================================================================================================================
void BobsGame::localMultiplayerPlayerJoinMenuRender()
{//=========================================================================================================================

	GLUtils::drawFilledRect(BobMenu::bgColor->ri(), BobMenu::bgColor->gi(), BobMenu::bgColor->bi(), 0, (float)getWidth(), 0, (float)getHeight(), 1.0f);

	BobTexture* kt = keyboardIconTexture;
	BobTexture* gt = controllerIconTexture;

	for (int i = 0; i < players.size(); i++)
	{
		PuzzlePlayer *p = players.get(i);

		BobTexture *t = nullptr;

		if (p->useKeyboard)t = kt;
		else
			if (p->gameController != nullptr)t = gt;

		float sx0 = 0;
		float sx1 = 0;
		float sy0 = 0;
		float sy1 = 0;

		if (t != nullptr)
		{
			int slot = players.size();
			if (slot < 2)slot = 2;

			float tx0 = 0;
			float tx1 = (float)(t->getImageWidth()) / (float)(t->getTextureWidth());
			float ty0 = 0;
			float ty1 = (float)((float)(t->getImageHeight()) / (float)(t->getTextureHeight()));

			float ratio = (float)(getWidth() / slot / 6 * 2) / (float)(t->getImageWidth());

			sx0 = (float)((int)(getWidth() / slot*i + getWidth() / slot / 6 * 2));
			sx1 = sx0 + (int)((getWidth() / slot) / 6 * 2);
			sy0 = (float)((int)(getHeight() / 6 * 1));
			sy1 = sy0 + (float)((int)(t->getImageHeight() * ratio));

			GLUtils::drawTexture(t, tx0, tx1, ty0, ty1, sx0, sx1, sy0, sy1, 1.0f, GLUtils::FILTER_NEAREST);
		}

		float x = (float)((int)sx0);
		float y = (float)((int)sy1 + 6);
		if (p->confirmed == false)
		{
			playerDifficultyMiniMenuRender(p, x, y);
		}
		else
		{
			//draw greencheck mark or green box or something?
			GLUtils::drawFilledRect(0, 255, 0, sx0, sx1, sy0, sy1, 0.2f);

			if (p->gameCaption != nullptr)
			{
				p->gameCaption->screenX = sx0;
				p->gameCaption->screenY = sy1 + 4;
				//p->gameCaption->render();
			}
			if (p->difficultyCaption != nullptr)
			{
				p->difficultyCaption->screenX = sx0;
				p->difficultyCaption->screenY = sy1 + 4 + 16;
				//p->difficultyCaption->render();
			}
		}

		//need to render friend name and player number
		if (p->nameCaption != nullptr)
		{
			p->nameCaption->screenX = sx0;
			p->nameCaption->screenY = sy1 - 12;
			//p->nameCaption->render();
		}
	}

	if (localMultiplayerPlayerJoinMenu == nullptr)return;

	localMultiplayerPlayerJoinMenu->render(getHeight() / 4 * 3);

}


//=========================================================================================================================
void BobsGame::playerDifficultyMiniMenuUpdate(PuzzlePlayer *p)
{//=========================================================================================================================

	if (p != nullptr)
	{



		if (p->menu == nullptr)
		{
			p->menu = new BobMenu(this, "");
			p->menu->center = false;
			p->menu->setFontSize(12);
			GameType g;

			for (int i = 0; i<g.difficultyTypes.size(); i++)
			{
				p->menu->add(g.difficultyTypes.get(i)->name);
			}
		}

		{
			bool up = false;
			bool down = false;
			bool a = false;
			if (p->useKeyboard)
			{
				if (getControlsManager()->key_UP_Pressed())up = true;
				if (getControlsManager()->key_DOWN_Pressed())down = true;
				if (getControlsManager()->key_SPACE_Pressed())a = true;
			}
			else
			{
				GameController *g = p->gameController;
				if (g != nullptr)
				{
					if (g->up_Pressed())up = true;
					if (g->down_Pressed())down = true;
					if (g->a_Pressed())a = true;
				}
			}

			if (up)
			{
				p->menu->up();
			}

			if (down)
			{
				p->menu->down();
			}

			if (a)
			{
				GameLogic *game = p->gameLogic;
				GameType g;

				for (int i = 0; i<g.difficultyTypes.size(); i++)
				{
					string difficultyName = g.difficultyTypes.get(i)->name;

					if (p->menu->isSelectedID(difficultyName))
					{
						game->currentGameSequence->currentDifficultyName = difficultyName;
						p->setDifficulty = true;
					}
				}

				if (p->menu != nullptr)
				{
					delete p->menu;
					p->menu = nullptr;
				}


			}
		}
	}

}

//=========================================================================================================================
void BobsGame::playerDifficultyMiniMenuRender(PuzzlePlayer *p, float x, float y)
{//=========================================================================================================================

	if (p->menu != nullptr)
	{
		p->menu->render((int)y, (int)x);
	}
}

//=========================================================================================================================
void BobsGame::playerGameSequenceMiniMenuUpdate(PuzzlePlayer *p)
{//=========================================================================================================================

	const string PLAY_GAME_SEQUENCE = "Play Game Sequence";
	const string PLAY_SINGLE_GAME_TYPE = "Play Single Game Type";

	const string RANDOMIZE_SEQUENCE = "Randomize Sequence";
	const string PLAY_THROUGH_SEQUENCE_IN_ORDER = "Play Through Sequence In Order";

	if (p != nullptr)
	{
		if (p->menu == nullptr)
		{
			p->menu = new BobMenu(this, "");
			p->menu->center = false;
			p->menu->setFontSize(14);
			p->menu->outline = false;

			if (p->selectGameSequenceOrSingleGameTypeMiniMenuShowing)
			{
				p->menu->add(PLAY_GAME_SEQUENCE);
				p->menu->add(PLAY_SINGLE_GAME_TYPE);
			}

			if(p->selectGameSequenceMiniMenuShowing)
			{
				populateGameSequencesMenu(p->menu);
			}

			if (p->gameSequenceOptionsMiniMenuShowing)
			{
				p->menu->add(RANDOMIZE_SEQUENCE);
				p->menu->add(PLAY_THROUGH_SEQUENCE_IN_ORDER);
			}

			if(p->selectSingleGameTypeMiniMenuShowing)
			{
				populateGameTypesMenu(p->menu);
			}
		}

		{
			bool up = false;
			bool down = false;
			bool a = false;
			if (p->useKeyboard)
			{
				if (getControlsManager()->KEY_UP_HELD)up = true;
				if (getControlsManager()->KEY_DOWN_HELD)down = true;
				if (getControlsManager()->key_SPACE_Pressed())a = true;
			}
			else
			{
				GameController *g = p->gameController;
				if (g != nullptr)
				{
					if (g->UP_HELD)up = true;
					if (g->DOWN_HELD)down = true;
					if (g->a_Pressed())a = true;
				}
			}

			if (up)
			{
				long long currentTime = System::currentHighResTimer();

				if (p->upRepeatedStarted == false)
				{
					p->menu->up();
					p->upRepeatedStarted = true;
					p->upLastTime = currentTime;
				}
				else
				{

					long long startTime = p->upLastTime;
					int ticksPassed = (int)(System::getTicksBetweenTimes(startTime, currentTime));

					if (p->upRepeating == false)
					{
						if (ticksPassed > 300)
						{
							p->upLastTime = currentTime;
							p->menu->up();
							p->upRepeating = true;
						}
					}
					else
					{
						if (ticksPassed > 30)
						{
							p->upLastTime = currentTime;
							p->menu->up();
						}
					}
				}
			}
			else
			{
				p->upRepeating = false;
				p->upRepeatedStarted = false;
			}

			if (down)
			{
				long long currentTime = System::currentHighResTimer();

				if (p->downRepeatedStarted == false)
				{
					p->menu->down();
					p->downRepeatedStarted = true;
					p->downLastTime = currentTime;
				}
				else
				{
					long long startTime = p->downLastTime;
					int ticksPassed = (int)(System::getTicksBetweenTimes(startTime, currentTime));

					if (p->downRepeating == false)
					{
						if (ticksPassed > 300)
						{
							p->downLastTime = currentTime;
							p->menu->down();
							p->downRepeating = true;
						}
					}
					else
					{
						if (ticksPassed > 30)
						{
							p->downLastTime = currentTime;
							p->menu->down();
						}
					}
				}
			}
			else
			{
				p->downRepeating = false;
				p->downRepeatedStarted = false;
			}

			if (a)
			{
				GameLogic *game = p->gameLogic;

				if (p->selectGameSequenceOrSingleGameTypeMiniMenuShowing)
				{
					if (p->menu->isSelectedID(PLAY_GAME_SEQUENCE))
					{
						p->selectGameSequenceMiniMenuShowing = true;
					}
					if (p->menu->isSelectedID(PLAY_SINGLE_GAME_TYPE))
					{
						p->selectSingleGameTypeMiniMenuShowing = true;
					}

					p->selectGameSequenceOrSingleGameTypeMiniMenuShowing = false;
				}
				else
				if(p->selectGameSequenceMiniMenuShowing)
				{
					for (int i = 0; i<loadedGameSequences.size(); i++)
					{

						GameSequence *gs = loadedGameSequences.get(i);
						if (p->menu->isSelectedID(gs->uuid))
						{
							game->currentGameSequence = gs;
							p->gameSequenceOptionsMiniMenuShowing = true;
						}
					}

					p->selectGameSequenceMiniMenuShowing = false;

				}
				else
				if(p->gameSequenceOptionsMiniMenuShowing)
				{
					if (p->menu->isSelectedID(RANDOMIZE_SEQUENCE))
					{
						game->currentGameSequence->randomizeSequence = true;
					}

					if (p->menu->isSelectedID(PLAY_THROUGH_SEQUENCE_IN_ORDER))
					{
						game->currentGameSequence->randomizeSequence = false;
					}

					p->setGameSequence = true;
					p->gameSequenceOptionsMiniMenuShowing = false;

				}
				else
				if(p->selectSingleGameTypeMiniMenuShowing)
				{

					for (int i = 0; i<loadedGameTypes.size(); i++)
					{
						GameType *g = loadedGameTypes.get(i);
						if (p->menu->isSelectedID(g->uuid))
						{
							game->currentGameSequence = new GameSequence();
							game->currentGameSequence->gameTypes.add(g);
							game->currentGameSequence->name = g->name;
						}
					}

					p->setGameSequence = true;
					p->selectSingleGameTypeMiniMenuShowing = false;

				}

				if (p->menu != nullptr)
				{
					delete p->menu;
					p->menu = nullptr;
				}

			}
		}
	}

}

//=========================================================================================================================
void BobsGame::playerGameSequenceMiniMenuRender(PuzzlePlayer *p, float x, float y)
{//=========================================================================================================================

	if (p->menu != nullptr)
	{
		p->menu->render((int)y, (int)x);
	}
}

