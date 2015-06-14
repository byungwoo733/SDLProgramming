/** 
	@file	TextFieldFactory.cpp
	@date	2013-03-03
	@author ����ȯ(sim436@gmail.com)
	@brief	SDL ���̺귯������ TextƲ ���� ���� Surface�� ������ִ� �̱��� Ŭ����.
*/

#include "StdAfx.h"
#include "TextFieldFactory.h"
#include "han2unicode.h"
#include <sstream>

/**
	@brief	�̱��� �Լ�. �ڱ� �ڽ��� ��ü ��ȯ
	@return �ڽ��� ��ü
*/
TextFieldFactory* TextFieldFactory::Shared()
{
	static TextFieldFactory* instance = NULL;
	if(instance == NULL)
		instance = new TextFieldFactory;
	return instance;
}


/**
	@brief SDL_Surface�� �ѷ��� TTF�� �������ִ� �Լ�
	@param text �ѷ��� ���ڿ�
	@param fontsize ��Ʈ ũ��
	@param r ��Ʈ �� r
	@param g ��Ʈ �� g
	@param b ��Ʈ �� b
	@return ���ڰ����� ������ SDL_Surface
*/
SDL_Surface* 
TextFieldFactory::CreateTextFieldSurface(char* text, int fontsize, int r, int g, int b)
{
	TTF_Font* font = TTF_OpenFont("arial.ttf", fontsize);

	SDL_Color color;
	color.r = r;
	color.g = g;
	color.b = b;

	unsigned short unicode[128];
	han2unicode(text ,unicode); ///< char* �� unicode�� ��ȯ

	return TTF_RenderUNICODE_Blended(font, unicode, color);
}

/**
	@brief "���ڿ�" ���ڰ� ������ ���ڿ��� ������ִ� �Լ�.
	@param str ���ڿ�
	@param number ���ڰ�
	@return ���ڿ� ���ڰ� �� �̾��� ������ ���ڿ�
*/
std::string 
TextFieldFactory::StringAndInt(std::string str, int number)
{
	std::stringstream ss;
	ss << str << number;

	return ss.str();
}