/** 
	@file	SnakeMap.cpp
	@date	2013-03-03
	@author ����ȯ(sim436@gmail.com)
	@brief	������ ��� ������Ʈ�� ������ Ÿ���� ������ ������ �ִ� Ŭ����
*/

#include "StdAfx.h"
#include "SnakeMap.h"

/**
	@brief ������. 
	@param width Ÿ���� �ʺ�
	@param height Ÿ���� ����
*/

SnakeMap::~SnakeMap()
{
	tilesInfo_.clear();
}

SnakeMap::SnakeMap(int width, int height)
	: width_(width), height_(height), tilesInfo_(NULL)
{
	for(int h=0; h<height_; h++)	///< Ÿ���� ��� ' ;(����) ���� �ʱ�ȭ
	{
		std::vector<char> horizontal_info;
		for(int w=0; w<width_; w++)
		{
			horizontal_info.push_back(' ');
		}
		tilesInfo_.push_back(horizontal_info);
	}
}

/**
	@brief x, y ��ǥ Ÿ���� ������ �����Ѵ�.
	@param x��ǥ
	@param y��ǥ
	@return x, y ��ǥ Ÿ���� ����
*/
char SnakeMap::TilesInfoOfIndex(int x, int y) const
{
	return tilesInfo_.at(y).at(x);
}

/**
	@brief x, y ��ǥ Ÿ���� ������ �����Ѵ�.
	@param x x��ǥ 
	@param y y��ǥ
	@param ch ������ ����
*/
void SnakeMap::SetTilesInfoOfIndex(int x, int y, char ch)
{
	tilesInfo_.at(y).at(x) = ch;
}

/**
	@brief Ÿ���� �ʺ� ��ȯ�ϴ� �Լ�.
	@return Ÿ���� �ʺ�
*/
int SnakeMap::Width() const
{
	return width_;
}

/**
	@brief Ÿ���� ���̸� ��ȯ�ϴ� �Լ�.
	@return Ÿ���� ����
*/
int SnakeMap::Height() const
{
	return height_;
}