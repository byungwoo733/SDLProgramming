/** 
	@file	stdafx.h
	@date	2013-03-03
	@author ����ȯ(sim436@gmail.com)
	@brief	���� ��������� ���� ��������� �ʴ� ǥ�� �ý��� ���� ���� �� \n
			������Ʈ ���� ���� ������ ��� �ִ� ���� �����Դϴ�. \n
			TODO: ���α׷��� �ʿ��� �߰� ����� ���⿡�� �����մϴ�.
*/

#pragma once

#include "targetver.h"
#include <stdio.h>
#include <tchar.h>

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <vector>
#include <time.h>

/**
	@brief dst Surface�� scr ��ο� �ִ� �̹��� x, y ��ǥ�� ���.
	@param dst scr�� ����� SDL_Surface�� ������
	@param x   ��� �� x ��ǥ 
	@param y   ��� �� y ��ǥ
	@param src ����� SDL_Surface�� ������
*/ 
inline void DrawSurface(SDL_Surface *dst,int x,int y,SDL_Surface *src)
{	
	SDL_Rect rectDst;
	rectDst.x = x;
	rectDst.y = y;
	SDL_BlitSurface(src,NULL,dst,&rectDst);
}

/**
	@brief ���� 2���� �����ȿ��� �������� ����մϴ�.
	@param x x ����
	@param y y ����
	@return x~y �� ���� �� ������
*/
inline int BaseRand(int x, int y){
	static int z = 0;
	int tmp;
	if(z==0){
		srand((int)time(NULL));
		rand();rand();rand();rand();
		srand(rand());
		z=1;
	}

	tmp = rand()%(y-x+1)+x;
	return tmp;
}
