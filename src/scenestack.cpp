#include "scenestack.h"


void SceneStack::mainscreen(SDL_graphics &graphics_engine) {
	SDL_Renderer *renderer = graphics_engine.getRenderer();

	int SCREEN_WIDTH = graphics_engine.getScreenWidth();
	int SCREEN_HEIGHT = graphics_engine.getScreenHeight();
	///LOAD SOME FONTS
	TTF_Font *Verdana;
	Verdana=TTF_OpenFont("res/fonts/Verdana.ttf", 55);
	if(!Verdana) {
		printf("TTF_OpenFont Verdana: %s\n", TTF_GetError());
	}
	TTF_Font *Bookman;
	Bookman=TTF_OpenFont("res/fonts/Bookman.ttf", 30);
	if(!Bookman) {
		printf("TTF_OpenFont Bookman: %s\n", TTF_GetError());
	}

	///LOAD SOME COLORS
	//	SDL_Color Teal = {100, 200, 200, 0};
	SDL_Color White = {255, 255, 255, 0};
	SDL_Color Black = {0,0,0,0};

	///SOLID FULL SCREEN SIZED RECTANGLE FOR A BACKDROP
	SDL_Rect backdropRect = {0, 0, SCREEN_WIDTH, SCREEN_HEIGHT};

	/// MENU RECT LOCATIONS
	const int ITEM3_X = 873;
	const int ITEM3AND4_Y = 420;
	const int ITEM4_X = 1201;
	const int ITEM2_X = 825;
	const int ITEM2AND5_Y = 330;
	const int ITEM5_X = 1249;
	const int ITEM1_X = 853;
	const int ITEM1_Y = 230;

	const int BEGINBUTTONX = 955;
	const int BEGINBUTTONY = 615;


	///TITLE TEXT
	std::string titleText = "CHARACTERS";
	std::string infoText = "Lorem ipsum dolor sit amet, vocent aliquid similique et eos. Apeirian disputationi duo ea, nemore pericula an has.";

	//		 TTF_SetFontHinting(Verdana, TTF_HINTING_LIGHT);
	//		 TTF_SetFontStyle(Verdana, TTF_STYLE_BOLD);

	TTF_SetFontHinting(Bookman, TTF_HINTING_MONO);

	enum SelectedItem { CHARACTERS = 0, MAGIC_ITEMS, RANDOM_ENCOUNTER, TOOLS, SAVE };
	SelectedItem selectedItem = CHARACTERS;

	Texture defaultScene;
	defaultScene.setRenderer(renderer);
	defaultScene.load("res/pngs/defaultScene.png");
	//	defaultScene.setBlendMode(SDL_BLENDMODE_BLEND);
	//	defaultScene.setAlpha(200);

	Texture infoBackground;
	infoBackground.setRenderer(renderer);
	infoBackground.load("res/pngs/defaultInfo.png");

	Texture separatorBar;
	separatorBar.setRenderer(renderer);
	separatorBar.load("res/pngs/separatorBar.png");

	Texture titleItem1;
	titleItem1.setRenderer(renderer);
	titleItem1.load("res/pngs/charactersMenu.png");

	Texture titleItem2;
	titleItem2.setRenderer(renderer);
	titleItem2.load("res/pngs/defaultItem2.png");

	Texture titleItem3;
	titleItem3.setRenderer(renderer);
	titleItem3.load("res/pngs/defaultItem3.png");

	Texture titleItem4;
	titleItem4.setRenderer(renderer);
	titleItem4.load("res/pngs/defaultItem4.png");

	Texture titleItem5;
	titleItem5.setRenderer(renderer);
	titleItem5.load("res/pngs/defaultItem5.png");

	SDL_Rect subItem = {0,0,144,90};

	Texture beginButton;
	beginButton.setRenderer(renderer);
	beginButton.load("res/pngs/defaultBeginButton.png");
	beginButton.setBlendMode(SDL_BLENDMODE_BLEND);
	beginButton.setAlpha(200);


	SDL_Surface *surfaceMessage;

	surfaceMessage = TTF_RenderText_Solid(Verdana, titleText.c_str(), White);
	SDL_Texture *titleArea = SDL_CreateTextureFromSurface(renderer, surfaceMessage);
	SDL_Rect titleRect = {830, 65, 550, 115};

	surfaceMessage = TTF_RenderText_Blended_Wrapped(Bookman, infoText.c_str(), Black, 635);
	SDL_Texture *infoArea = SDL_CreateTextureFromSurface(renderer, surfaceMessage);

	int w,h;
	w = surfaceMessage->w;
	h = surfaceMessage->h;
	SDL_Rect infoSrcRect = {0, 0, w, h};
	SDL_Rect infoDestRect = {48, 460, w, h};


	int mouseLeftX, mouseLeftY;

	bool quit = false;
	SDL_Event e;

	SDL_FreeSurface(surfaceMessage);


	while (!quit)
	{
		//Handle events on queue
		//		HandleInput();
		while (SDL_PollEvent (&e) != 0) {
			switch (e.type) {
			case SDL_QUIT:
				quit = true;
				break;
			case SDL_KEYDOWN:
				switch (e.key.keysym.sym) {
				case SDLK_UP:

					//					if (cursorY > 265) {
					//						cursorY -= cursorIncrement;
					//					}

					break;
				case SDLK_DOWN:

					//					if (cursorY < 685) {
					//						cursorY += cursorIncrement;

					//					}

					break;
				default: break;

				}
			case SDL_MOUSEMOTION:
				mouseLeftX = e.motion.x;
				mouseLeftY = e.motion.y;

//                    if (mouseLeftX > 48 && mouseLeftY < 48+683 && mouseLeftY > 30 && mouseLeftY < 30+395 ) {
//                        defaultScene.setAlpha(255);
//                    } else {
//                        defaultScene.setAlpha(200);
//                    }

				if ((mouseLeftX > BEGINBUTTONX && mouseLeftX < BEGINBUTTONX+beginButton.getWidth()) && (mouseLeftY > BEGINBUTTONY && mouseLeftY < BEGINBUTTONY+beginButton.getWidth()) ) {
					beginButton.setAlpha(255);
				} else {
					beginButton.setAlpha(200);

				}

				break;

			case SDL_MOUSEBUTTONDOWN:

				switch (e.button.button) {
				case SDL_BUTTON_LEFT: {
					mouseLeftX = e.button.x;
					mouseLeftY = e.button.y;
					if ((mouseLeftX > ITEM1_X && mouseLeftX < ITEM1_X+titleItem1.getWidth()) && (mouseLeftY > 230 && mouseLeftY < 230+titleItem1.getHeight())) {
						// ???
					} else if ((mouseLeftX > ITEM2_X && mouseLeftX < (ITEM2_X+subItem.w)) && (mouseLeftY > ITEM2AND5_Y && mouseLeftY < (ITEM2AND5_Y+subItem.h))) {
						selectedItem = (SelectedItem)CycleRight_5(1, (int)selectedItem);
					} else if ((mouseLeftX > ITEM3_X && mouseLeftX < (ITEM3_X+subItem.w)) && (mouseLeftY > ITEM3AND4_Y && mouseLeftY < (ITEM3AND4_Y+subItem.h))) {
						selectedItem = (SelectedItem)CycleRight_5(2, (int)selectedItem);
					} else if ((mouseLeftX > ITEM4_X && mouseLeftX < (ITEM4_X+subItem.w)) && (mouseLeftY > ITEM3AND4_Y && mouseLeftY < (ITEM3AND4_Y+subItem.h))) {
						selectedItem = (SelectedItem)CycleRight_5(3, (int)selectedItem);
					} else if ((mouseLeftX > ITEM5_X && mouseLeftX < (ITEM5_X+subItem.w)) && (mouseLeftY > ITEM2AND5_Y && mouseLeftY < (ITEM2AND5_Y+subItem.h))) {
						selectedItem = (SelectedItem)CycleRight_5(4, (int)selectedItem);
					} else if ((mouseLeftX > 960 && mouseLeftX < (960+beginButton.getWidth())) && (mouseLeftY> 620 && mouseLeftY< (620+beginButton.getHeight()))) {
						//begin button stuff
						printf("BEGIN clicked at loc: (%d, %d)", mouseLeftX, mouseLeftY);
					}
				}
					break;
				default: break;
				}
			default: break;
			}
			//			if (SDL_GetMouseState(NULL, NULL) & SDL_BUTTON(SDL_BUTTON_LEFT))
			//			{
			//				SDL_Log("Mouse Button 1 (left) is pressed.");
			//			}
		}
		graphics_engine.clear();   //clear screen
		SDL_RenderFillRect(renderer, &backdropRect);  // render black background rect

		defaultScene.draw(48, 30);

		infoBackground.draw(48, 460);

		separatorBar.draw(730, 0);

		switch (selectedItem) {
		case CHARACTERS: //0
			titleItem3.draw(ITEM3_X, ITEM3AND4_Y, nullptr, &subItem);
			titleItem4.draw(ITEM4_X, ITEM3AND4_Y, nullptr, &subItem);
			titleItem2.draw(ITEM2_X, ITEM2AND5_Y, nullptr, &subItem);
			titleItem5.draw(ITEM5_X, ITEM2AND5_Y, nullptr, &subItem);
			titleItem1.draw(ITEM1_X, ITEM1_Y);
			titleText = "CHARACTERS";
			surfaceMessage = TTF_RenderText_Solid(Verdana, titleText.c_str(), White);
			titleArea = SDL_CreateTextureFromSurface(renderer, surfaceMessage);

			break;
		case MAGIC_ITEMS:  //1
			titleItem4.draw(ITEM3_X, ITEM3AND4_Y, nullptr, &subItem);
			titleItem5.draw(ITEM4_X, ITEM3AND4_Y, nullptr, &subItem);
			titleItem3.draw(ITEM2_X, ITEM2AND5_Y, nullptr, &subItem);
			titleItem1.draw(ITEM5_X, ITEM2AND5_Y, nullptr, &subItem);
			titleItem2.draw(ITEM1_X, ITEM1_Y);
			titleText = "MAGIC ITEMS";
			surfaceMessage = TTF_RenderText_Solid(Verdana, titleText.c_str(), White);
			titleArea = SDL_CreateTextureFromSurface(renderer, surfaceMessage);

			break;
		case RANDOM_ENCOUNTER:  //2
			titleItem5.draw(ITEM3_X, ITEM3AND4_Y, nullptr, &subItem);
			titleItem1.draw(ITEM4_X, ITEM3AND4_Y, nullptr, &subItem);
			titleItem4.draw(ITEM2_X, ITEM2AND5_Y, nullptr, &subItem);
			titleItem2.draw(ITEM5_X, ITEM2AND5_Y, nullptr, &subItem);
			titleItem3.draw(ITEM1_X, ITEM1_Y);
			titleText = "ENCOUNTERS";
			surfaceMessage = TTF_RenderText_Solid(Verdana, titleText.c_str(), White);
			titleArea = SDL_CreateTextureFromSurface(renderer, surfaceMessage);

			break;
		case TOOLS:   //3
			titleItem1.draw(ITEM3_X, ITEM3AND4_Y, nullptr, &subItem);
			titleItem2.draw(ITEM4_X, ITEM3AND4_Y, nullptr, &subItem);
			titleItem5.draw(ITEM2_X, ITEM2AND5_Y, nullptr, &subItem);
			titleItem3.draw(ITEM5_X, ITEM2AND5_Y, nullptr, &subItem);
			titleItem4.draw(ITEM1_X, ITEM1_Y);
			titleText = "TOOLS";
			surfaceMessage = TTF_RenderText_Solid(Verdana, titleText.c_str(), White);
			titleArea = SDL_CreateTextureFromSurface(renderer, surfaceMessage);

			break;
		case SAVE: //4
			titleItem2.draw(ITEM3_X, ITEM3AND4_Y, nullptr, &subItem);
			titleItem3.draw(ITEM4_X, ITEM3AND4_Y, nullptr, &subItem);
			titleItem1.draw(ITEM2_X, ITEM2AND5_Y, nullptr, &subItem);
			titleItem4.draw(ITEM5_X, ITEM2AND5_Y, nullptr, &subItem);
			titleItem5.draw(ITEM1_X, ITEM1_Y);
			titleText = "SAVE & EXPORT";
			surfaceMessage = TTF_RenderText_Solid(Verdana, titleText.c_str(), White);
			titleArea = SDL_CreateTextureFromSurface(renderer, surfaceMessage);

			break;
		default:
			printf("ruh roh!  \n");
			break;
		}


		beginButton.draw(BEGINBUTTONX, BEGINBUTTONY);
		SDL_RenderCopy(renderer, titleArea, NULL, &titleRect);
		SDL_RenderCopy(renderer, infoArea, &infoSrcRect, &infoDestRect);
		graphics_engine.render();
	}

	TTF_CloseFont(Verdana);
	TTF_CloseFont(Bookman);

	Verdana = NULL;
	Bookman = NULL;

	SDL_FreeSurface(surfaceMessage);

}



///returns 0-4 as appropriate for our special case cycling menu
    int SceneStack::CycleRight_5(const int &amt, const int &current){
        switch (amt) {
        case 1: {
            switch (current) {
            case 0: return 1;
            case 1: return 2;
            case 2: return 3;
            case 3: return 4;
            case 4: return 0;
            default:break;
            } break;
        }
        case 2:{
            switch (current) {
            case 0: return 2;
            case 1: return 3;
            case 2: return 4;
            case 3: return 0;
            case 4: return 1;
            default:break;
            } break;
        }
        case 3:{
            switch (current) {
            case 0: return 3;
            case 1: return 4;
            case 2: return 0;
            case 3: return 1;
            case 4: return 2;
            default:break;
            } break;
        }
        case 4:{
            switch (current) {
            case 0: return 4;
            case 1: return 0;
            case 2: return 1;
            case 3: return 2;
            case 4: return 3;
            default:break;
            } break;
        }
        default:break;
        }

        return 0;


        //or we could do it the obvious fast way but the numbers go to high like that
        //	return (current + amt);
    }