#pragma once
#ifndef	  __IMAGE_BUFFER_H
#define	  __IMAGE_BUFFER_H

#include <type_traits>
#include <cstdlib>

class rgb8i
{
public:
	unsigned char r;
	unsigned char g;
	unsigned char b;

} ;

class rgba8i
{
public:
	unsigned char r;
	unsigned char g;
	unsigned char b;
	unsigned char a;

};

class rgb16i
{
public:
	unsigned short int r;
	unsigned short int g;
	unsigned short int b;
} ;

class rgba16i
{
	unsigned short int r;
	unsigned short int g;
	unsigned short int b;
	unsigned short int a;

};
enum COLORTYPE {
	RGB8I,
	RGBA8I,
	RGB16I,
	RGBA16I
};

template<COLORTYPE C>
using _MyType = C;
class image_data
{
public:
	COLORTYPE image_type;
	
	explicit image_data(void * data = NULL) 
	{
		this->data->raw_data = data;
	}

	union
	{
		void	* raw_data;
		rgb8i	* _rgb8i;
		rgba8i	* _rgba8i;
		rgb16i	* _rgb16i;
		rgba16i	* _rgba16i;
	} *data;

	unsigned int size;

	template<typename T, COLORTYPE C = _MyType> T r()
	{
		switch (C)
			case RGB8I:
				return reinterpret_cast<RGB8I*>(_data)->r;
			case RGBA8I:
				return reinterpret_cast<RGBA8I*>(_data)->r;
			case RGB16I:
				return reinterpret_cast<RGB16I*>(_data)->r;
			case RGBA16I:
				return reinterpret_cast<RGBA16I*>(_data)->r;
			default:
				throw - 1;
				break;

	};
	template<typename T, COLORTYPE C = _MyType> T getG()
	{
		switch (C)
			case RGB8I:
				return reinterpret_cast<RGB8I*>(_data)->g;
			case RGBA8I:
				return reinterpret_cast<RGBA8I*>(_data)->g;
			case RGB16I:
				return reinterpret_cast<RGB16I*>(_data)->g;
			case RGBA16I:
				return reinterpret_cast<RGBA16I*>(_data)->g;
			default:
				throw - 1;
				break;
	}
	template<typename T, COLORTYPE C = _MyType> T getB();
	template<typename T, COLORTYPE C = _MyType> T getA();
};

template<COLORTYPE C = RGB8I>
class ImageBuffer
{
	using _MyType = C;

private:

	void * _data;
	void * _rawData;

	COLORTYPE _MyType_;

public:


	template<COLORTYPE C = _MyType>
	ImageBuffer(image_data* data) : _MyType_(C) {
		_rawData = data;

		switch (COLORTYPE)
		case RGB8I:
			_data = data->data->_rgb8i;
			break;
		case RGBA8I:
			_data = data->data->_rgba8i;
			break;
		case RGB16I:
			_data = data->data->_rgb16i;
			break;
		case RGBA16I:
			_data = data->data->_rgba16i;
			break;
	}
	
	image_data operator[](unsigned int idx) { return _data[idx]; }

		~ImageBuffer();
	};
image_data *image = new image_data;
//ImageBuffer<RGB16I> _kk{ image };
//_kk[2].r = 2;
//auto x = _kk[2].r;

/*
x = r;
r = x;
r = func(r);
func(r) = r;

leftside/rightside

r/p/q/x/t

T
T*
T&
T&&
T**
T***.....
T[] : T*
&T


*/


#endif /* __IMAGE_BUFFER_H */
