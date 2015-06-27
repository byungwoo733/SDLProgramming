/** 
	@file	GameOverScene.cpp
	@date	2013-03-03
	@author ����ȯ(sim436@gmail.com)
	@brief	���ӿ��� Scene Ŭ����.
*/

#include "stdafx.h"
#include "GameOverScene.h"
#include "IntroScene.h"
#include "Game.h"

/**
	@brief Scene �� �ʱ�ȭ �Լ�
	@param owner Scene�� �����ϴ� StateMachine�� �������ִ� Game ��ü
*/
void GameOverScene::Init(Game* owner)
{
	
}

GameOverScene::GameOverScene()
{
	bg = IMG_Load("GameOverBG.bmp");
}

/**
	@brief Scene �� ���� �Լ�
	@param owner Scene�� �����ϴ� StateMachine�� �������ִ� Game ��ü
*/
void GameOverScene::Execute(Game* owner)
{
	this->Input(owner);	
	this->Update(owner);
	this->Rendder(owner);
}

/**
	@brief Scene �� ���� �Լ�.\n
		   �ַ� �ɹ� ������ �޸� ������ �Ѵ�.
	@param owner Scene�� �����ϴ� StateMachine�� �������ִ� Game ��ü
*/
void GameOverScene:: Exit(Game* owner) 
{
	SDL_FreeSurface(bg);
	bg = NULL;
}

/**
	@brief Scene �� �Է��� ó���ϴ� �Լ�
	@param owner Scene�� �����ϴ� StateMachine�� �������ִ� Game ��ü
*/
void GameOverScene::Input(Game* owner)
{
	if(SDL_PollEvent(&event)) {
		switch(event.type) {
		case SDL_QUIT: break;
		case SDL_KEYUP: ///< �ƹ�Ű�� ������ �޴� ȭ������ ���ư�
			owner->FSM()->ChangeState(IntroScene::Shaerd());
			break;
		case SDL_FINGERUP:
		{

			owner->FSM()->ChangeState(IntroScene::Shaerd());
		}
		break;
		}

	}
}

/**
	@brief Scene �� ������ �ִ� ��ü���� ������ ó���ϱ� ���� �Լ�
	@param owner Scene�� �����ϴ� StateMachine�� �������ִ� Game ��ü
*/
void GameOverScene::Update(Game* owner)
{}

/**
	@brief Scene �� ������ �ִ� ��ü���� �������� ó���ϱ� ���� �Լ�
	@param owner Scene�� �����ϴ� StateMachine�� �������ִ� Game ��ü
*/
void GameOverScene::Rendder(Game* owner)
{
	if(bg!=NULL) 
	{
		DrawSurface(owner->Screen(), 0, 0, bg);
	}
}