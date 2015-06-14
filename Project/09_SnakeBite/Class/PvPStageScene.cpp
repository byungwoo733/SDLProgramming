/** 
	@file	PvPStageScene.cpp
	@date	2013-03-03
	@author ����ȯ(sim436@gmail.com)
	@brief	Sanke ���ӿ��� ��������� Scene Ŭ����
*/

#include "StdAfx.h"
#include "PvPStageScene.h"

#include "Game.h"
#include "SnakeMap.h"
#include "Wall.h"
#include "ItemManager.h"
#include "Snake.h"
#include "TextFieldFactory.h"

/**
	@brief Scene �� �ʱ�ȭ �Լ�
	@param owner Scene�� �����ϴ� StateMachine�� �������ִ� Game ��ü
*/
void PvPStageScene::Init(Game* owner)
{
	snakeMap = new SnakeMap(30, 20);

	wall = new Wall("stage01.txt");	///< �� ����
	wall->SetScreen(owner->Screen());
	wall->SetSnakeMap(snakeMap);
	wall->Init();

	itemMgr = new ItemManager(); ///< ������ ����
	itemMgr->SetScreen(owner->Screen());
	itemMgr->SetSnakeMap(snakeMap);
	itemMgr->Init();

	snake_1p = new Snake(3, 3);	 ///< 1p �� ����	
	snake_1p->SetSnakeMap(snakeMap);
	snake_1p->SetItemManager( itemMgr );
	snake_1p->SetScreen(owner->Screen());
	snake_1p->Init();

	snake_2p = new Snake(10, 3); ///< 2p �� ����	
	snake_2p->SetSnakeMap(snakeMap);
	snake_2p->SetItemManager( itemMgr );
	snake_2p->SetScreen(owner->Screen());
	snake_2p->Init();
}

/**
	@brief Scene �� ���� �Լ�
	@param owner Scene�� �����ϴ� StateMachine�� �������ִ� Game ��ü
*/
void PvPStageScene::Execute(Game* owner)
{
	this->Input(owner);	
	this->Update(owner);
	this->Rendder(owner);


	if( snake_1p->IsArrive() == false ) ///< 1p ���� ������..
	{}
	if( snake_2p->IsArrive() == false ) ///< 2p ���� ������..
	{}
}

/**
	@brief Scene �� ���� �Լ�.\n
		   �ַ� �ɹ� ������ �޸� ������ �Ѵ�.
	@param owner Scene�� �����ϴ� StateMachine�� �������ִ� Game ��ü
*/
void PvPStageScene::Exit(Game* owner) 
{
	delete wall;		wall = NULL;
	delete itemMgr;		itemMgr = NULL;
	delete snake_1p;	snake_1p = NULL;
	delete snake_2p;	snake_2p = NULL;
	delete snakeMap;	snakeMap = NULL;
}

/**
	@brief Scene �� �Է��� ó���ϴ� �Լ�\n
	       �� �÷��̾��� Ű �Է����� �� �������� ó���Ѵ�.
	@param owner Scene�� �����ϴ� StateMachine�� �������ִ� Game ��ü
*/
void PvPStageScene::Input(Game* owner)
{
	if(SDL_PollEvent(&event)) {
		switch(event.type) {
		case SDL_QUIT: break;
		case SDL_KEYUP:			
			if(event.key.keysym.sym == SDLK_UP) ///< 1p 
			{
				snake_1p->SetDir(Snake::kUP);
			}
			if(event.key.keysym.sym == SDLK_DOWN)
			{
				snake_1p->SetDir(Snake::kDOWN);
			}
			if(event.key.keysym.sym == SDLK_LEFT)
			{
				snake_1p->SetDir(Snake::kLEFT);
			}
			if(event.key.keysym.sym == SDLK_RIGHT)
			{
				snake_1p->SetDir(Snake::kRIGHT);
			}
			
			if(event.key.keysym.sym == SDLK_w) ///< 2p
			{
				snake_2p->SetDir(Snake::kUP);
			}
			if(event.key.keysym.sym == SDLK_s)
			{
				snake_2p->SetDir(Snake::kDOWN);
			}
			if(event.key.keysym.sym == SDLK_a)
			{
				snake_2p->SetDir(Snake::kLEFT);
			}
			if(event.key.keysym.sym == SDLK_d)
			{
				snake_2p->SetDir(Snake::kRIGHT);
			}

			if(event.key.keysym.sym == SDLK_ESCAPE) ///< ����
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
void PvPStageScene::Update(Game* owner)
{
	wall->Update();
	itemMgr->Update();
	snake_1p->Update();
	snake_2p->Update();
}

void PvPStageScene::Rendder(Game* owner)
{
	wall->Draw();
	itemMgr->Draw();
	snake_1p->Draw();
	snake_2p->Draw();
}