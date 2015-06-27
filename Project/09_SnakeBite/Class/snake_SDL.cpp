/** 
	@file	sanke_SDL.cpp
	@date	2013-03-03
	@author ����ȯ(sim436@gmail.com)
	@brief	�ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
*/

#include "stdafx.h"
#include "common.h"
#include "Game.h"
#include "SDLSingleton.h"

#ifdef WIN32
#include <vld.h>
#pragma comment(lib, "vld.lib")
#pragma comment(lib, "SDL2.lib")
#pragma comment(lib, "SDL2_ttf.lib")
#pragma comment(lib, "SDL2_image.lib")
#endif

#ifdef WIN32
int _tmain(int argc, _TCHAR* argv[])
#else
extern "C" int SDL_main(int argc, char *argv[])
#endif
{
	if (false == SDLSingleton::GetInstance()->InitSystem())
		return 0;

	TTF_Init();					///< TTF �ʱ�ȭ

	Game *pGame = new Game(SDLSingleton::GetInstance()->GetSurface());

	while(1) {
		pGame->Update();	///< ���� ����
		SDL_Delay(10);		///< 10ms ������
	}

	SDL_Quit();	///< SDL ����
	TTF_Quit();	///< TTF ����

	delete pGame; ///< Game ��ü ����
	pGame = NULL;

	return 0;
}