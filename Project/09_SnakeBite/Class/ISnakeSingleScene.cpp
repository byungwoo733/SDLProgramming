/** 
	@file	ISnakeSingleScene.cpp
	@date	2013-03-03
	@author ����ȯ(sim436@gmail.com)
	@brief	Sanke ���ӿ��� �̱۸���� Stage �� ���� �߻�Ŭ����
*/

#include "StdAfx.h"

#include "ISnakeSingleScene.h"
#include "SDLSingleton.h"
#include "Game.h"
#include "SnakeMap.h"
#include "Wall.h"
#include "ItemManager.h"
#include "Snake.h"
#include "TextFieldFactory.h"

/**
	@brief ���ڿ�+���� ������ ���ڿ��� ȭ�鿡 �׷��ִ� �Լ�.
	@param screen �׷��� ȭ��(SDL_Surface)�� ������
	@param label �ѷ��� ���ڿ�
	@param value �ѷ��� ����
	@param posx �ѷ��� ȭ���� ��ǥ x
	@param posy �ѷ��� ȭ���� ��ǥ y
*/
void ISnakeSingleScene::DrawTextFiledLabelWithValue(SDL_Surface* screen, std::string label, int value, int posx, int posy)
{
	/*std::string str = TextFieldFactory::Shared()->StringAndInt(label, value);
	char *ch = const_cast<char*>(str.c_str());
	SDL_Surface *textField = TextFieldFactory::Shared()->CreateTextFieldSurface(ch);
	DrawSurface(screen , posx, posy, textField);
	SDL_FreeSurface(textField);*/
}

/**
	@brief Scene �� �Է��� ó���ϴ� �Լ� \n
		   Ű�Է����� ���� �������� ó���Ѵ�.
	@param owner Scene�� �����ϴ� StateMachine�� �������ִ� Game ��ü
*/
void ISnakeSingleScene::Input(Game* owner)
{	
	while(SDL_PollEvent(&event)) {
		switch(event.type) {
		case SDL_QUIT: break;
		case SDL_FINGERUP:
		{
			float fingerX = event.tfinger.x;
			float fingerY = event.tfinger.y;

			fingerX *= SDLSingleton::GetInstance()->m_winWidth;
			fingerY *= SDLSingleton::GetInstance()->m_winHeight;

			if (fingerX < (GAME_WIDTH / 4))
				snake->SetDir(Snake::kLEFT);
			else if (fingerX >(GAME_WIDTH - (GAME_WIDTH / 4)))
				snake->SetDir(Snake::kRIGHT);
			else if (fingerY < (GAME_HEIGHT / 4))
				snake->SetDir(Snake::kUP);
			else if (fingerY >(GAME_HEIGHT - (GAME_HEIGHT / 4)))
				snake->SetDir(Snake::kDOWN);
		}
		break;
		case SDL_KEYUP: 
			if(event.key.keysym.sym == SDLK_UP) ///< snake ������
			{
				snake->SetDir(Snake::kUP);
			}
			if(event.key.keysym.sym == SDLK_DOWN)
			{
				snake->SetDir(Snake::kDOWN);
			}
			if(event.key.keysym.sym == SDLK_LEFT)
			{
				snake->SetDir(Snake::kLEFT);
			}
			if(event.key.keysym.sym == SDLK_RIGHT)
			{
				snake->SetDir(Snake::kRIGHT);
			}
			 
			if(event.key.keysym.sym == SDLK_ESCAPE) ///< ���� ����
			{
				exit(1);
			}
			break;
		}
	}
}

/**
	@brief Scene �� ������ �ִ� ��ü���� ������ ó���ϱ� ���� �Լ�
	@param owner Scene�� �����ϴ� StateMachine�� �������ִ� Game ��ü
*/
void ISnakeSingleScene::Update(Game* owner)
{
	wall->Update();
	itemMgr->Update();
	snake->Update();
}

/**
	@brief Scene �� ������ �ִ� ��ü���� �������� ó���ϱ� ���� �Լ�
	@param owner Scene�� �����ϴ� StateMachine�� �������ִ� Game ��ü
*/
void ISnakeSingleScene::Rendder(Game* owner)
{
	wall->Draw();
	itemMgr->Draw();
	snake->Draw();

	DrawTextFiledLabelWithValue(
		owner->Screen(), 
		"Life : ", owner->Life(), 
		0, 420);
	DrawTextFiledLabelWithValue(
		owner->Screen(), 
		"Tail Count : ", snake->BodyCount(), 
		200, 420);
}