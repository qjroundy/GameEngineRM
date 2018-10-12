#pragma once
#ifndef	  __GUI_RENDERER_H
#define	  __GUI_RENDERER_H

#include "utility/common.hpp"
#include "Renderer.h"
#include "assimp/material.h"

class GUIRenderer : public Renderer
	{
	public:
		//void addBGImage();
		//void addStatusText();
		//void updateStatusText();
		//void updateProgressBar(GLfloat newProgress);

		void init()		override;
		void start()	override;
		void stop()		override;
		void render()	override;

//		void onRender();
//		void onInit();
//		void onStart();
//		void onStop();
//		void onCleanUp();

		GUIRenderer();
		~GUIRenderer();
	};

#endif /* __GUI_RENDERER_H */
