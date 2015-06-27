/** 
	@file	Stage01Scene.cpp
	@date	2013-03-03
	@author ����ȯ(sim436@gmail.com)
	@brief	Sanke ���ӿ��� Stage 1 �� Scene Ŭ����
*/

#include "stdafx.h"
#include "Stage01Scene.h"
#include "Stage02Scene.h"
#include "GameOverScene.h"

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

void Stage01Scene::Init(Game* owner)
{
	snakeMap = new SnakeMap(30, 20); ///< Ÿ�� ���� ����

	wall = new Wall("stage01.txt");	///< �� ����
	wall->SetScreen(owner->Screen());
	wall->SetSnakeMap(snakeMap);
	wall->Init();

	itemMgr = new ItemManager(); ///< ������ ����
	itemMgr->SetScreen(owner->Screen());
	itemMgr->SetSnakeMap(snakeMap);
	itemMgr->Init();

	snake = new Snake(3, 3); ///< �� ����	
	snake->SetSnakeMap(snakeMap);
	snake->SetItemManager( itemMgr );
	snake->SetScreen(owner->Screen());
	snake->Init();

	clear_tailCount = 20; ///< Ŭ���� ���� ����
}

/**
	@brief Scene �� ���� �Լ�
	@param owner Scene�� �����ϴ� StateMachine�� �������ִ� Game ��ü
*/
void Stage01Scene::Execute(Game* owner)
{
	this->Input(owner);
	this->Update(owner);
	this->Rendder(owner);
	
	if(clear_tailCount < snake->BodyCount()) ///< Ŭ���� ��ǥ�� �޼��ϸ�
	{ 
		owner->FSM()->ChangeState( Stage02Scene::Shaerd() ); ///< Stage2 �� �Ѿ
		return;
	}

	if( snake->IsArrive() == false ) ///< ���� ������
	{
		owner->SetLife( owner->Life()-1 ); ///< life 1 ����
		int life = owner->Life();

		if(life == 0 ) ///< ����� 0���� ���ӿ���
			owner->FSM()->ChangeState( GameOverScene::Shaerd() );

		else ///< ����� �������� �������� �ٽ� ����
			owner->FSM()->ChangeState( Stage01Scene::Shaerd() );
	}
}

/**
	@brief Scene �� ���� �Լ�.\n
		   �ַ� �ɹ� ������ �޸� ������ �Ѵ�.
	@param owner Scene�� �����ϴ� StateMachine�� �������ִ� Game ��ü
*/
void Stage01Scene::Exit(Game* owner) 
{
	delete wall;		wall = NULL;
	delete itemMgr;		itemMgr = NULL;
	delete snake;		snake = NULL;
	delete snakeMap;	snakeMap = NULL;
}