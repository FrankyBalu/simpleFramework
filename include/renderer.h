/*
 * renderer.h
 * Copyright (C) 2020 Frank Kartheuser <frank.kurbatsch@gmail.com>
 *
 * libGUI is free software: you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * libGUI is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License along
 * with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef __SIMPLEFRAMEWORK_RENDERER
#define __SIMPLEFRAMEWORK_RENDERER

#include "video.h"
#include "point.h"
#include "rect.h"

namespace SF {

struct rawRenderer;
typedef struct rawRenderer rawRenderer;

typedef enum
{
    RENDERER_SOFTWARE 		= 0x00000001,	/**< Software Fallback */
    RENDERER_ACCELERATED 	= 0x00000002,	/**< Hardware beschleunigter Renderer */
    RENDERER_PRESENTVSYNC 	= 0x00000004,	/**< VSYNC eingeschalten */
    RENDERER_TARGETTEXTURE 	= 0x00000008	/**< Renderer unterstützt rendern auf Texture */
} RendererFlags;

typedef enum
{
    FLIP_NONE		 	= 0x00000000,	/**< Keine Spiegelung */
    FLIP_HORIZONTAL		= 0x00000001,	/**< Horizontal Gespiegelt */
    FLIP_VERTICAL 		= 0x00000002	/**< Vertikal Gespiegelt */
} RendererFlip;

typedef struct RendererInfo
{
    const char *name;           /**< Name des Rendertreibers */
    uint32_t flags;               /**< Unterstützte ::RendererFlags */
    uint32_t num_texture_formats; /**< Anzahl unterstützer Texturformate */
    uint32_t texture_formats[16]; /**< Die verfügbaren Textureformate */
    int max_texture_width;      /**< Maximale Textur Briete */
    int max_texture_height;     /**< Maximale Textur Höhe */
} RendererInfo;

/**
 *  Anzahl der verfügbaren Treiber
 */
int GetNumRenderDrivers ( void );
	
/**
 *  \brief Info über spezifizierten Treiber.
 *
 *  \param index Index von dem Treiber von dem man die Information möchte.
 *  \param info  Zeiger auf Info struktur die mit den Treiberdaten gefüllt wird.
 *
 *  \return 0 wenn erfolgreich, -1 wenn es zu dem Index keinen Treiber gibt.
 *
 *  \sa CreateRenderer()
 */
int GetRenderDriverInfo(int index, RendererInfo * info);

/**
 * \brief Gibt die informationen zu einem Treiber mit LOG aus
 */
void PrintDriverInfo ( RendererInfo *info );

class Renderer {
private:
	RendererInfo *_info;
	rawRenderer *_renderer;
	rawWindow *_window;

	/**
	 * füllt die info struktur
	 */
	void Info( void );
public:
	Renderer ( rawWindow *win );
	Renderer ( rawWindow *win, int index, uint32_t flags );
	
	~Renderer ( void );
	
	rawRenderer* Get( void );
	int DrawColor( uint8_t r, uint8_t g, uint8_t b, uint8_t a);
	int DrawColor( uint8_t * r, uint8_t * g, uint8_t * b, uint8_t * a );
	int Clear( void );
	int DrawPoint( int x, int y);
	int DrawPoint( Point<int> &point);
	int DrawLine( int x1, int y1, int x2, int y2);
	int DrawLine( Point<int> &point1, Point<int> &point2);
	int DrawRect( Rect<int> *rect );
	int DrawFillRect( Rect<int> * rect);
	void Present( void );
};



}//namespace SF

#endif //__SIMPLEFRAMEWORK_RENDERER
