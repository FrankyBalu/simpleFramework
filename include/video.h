/*
 * video.h
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


#ifndef _SIMPLEFRAMEWORK_VIDEODRIVER
#define _SIMPLEFRAMEWORK_VIDEODRIVER

#include <string>


namespace SF {


/**
 * entspricht einem SDL_Window
 */
typedef struct rawWindow rawWindow;

/**
 *  \brief Flags für das erzeugen eines Fensters, von SDL2 geliehen
 */
typedef enum
{
    WINDOW_FULLSCREEN = 0x00000001,         /**< VOllbild */
    WINDOW_OPENGL = 0x00000002,             /**< Fenster kann mit OpenGL genutz werden */
    WINDOW_SHOWN = 0x00000004,              /**< Fenster ist sichtbar */
    WINDOW_HIDDEN = 0x00000008,             /**< Fenster ist unsichtbar */
    WINDOW_BORDERLESS = 0x00000010,         /**< Fenster hat keinen Rand */
    WINDOW_RESIZABLE = 0x00000020,          /**< Die größe des Fensters kann geändert werden */
    WINDOW_MINIMIZED = 0x00000040,          /**< Fenster ist minimiert */
    WINDOW_MAXIMIZED = 0x00000080,          /**< Fenster ist maximiert */
    WINDOW_INPUT_GRABBED = 0x00000100,      /**< Fenster hat Fokus */
    WINDOW_INPUT_FOCUS = 0x00000200,        /**< Fenster hat Eingabefokus */
    WINDOW_MOUSE_FOCUS = 0x00000400,        /**< Fenster hat Mausfokus */
    WINDOW_FULLSCREEN_DESKTOP = ( WINDOW_FULLSCREEN | 0x00001000 ),
    WINDOW_FOREIGN = 0x00000800,            /**< Fenster wurde nicht von SDL erstellt */
    WINDOW_ALLOW_HIGHDPI = 0x00002000,      /**< Fenster soll im HDPI-Modus erstellt werden */
    WINDOW_MOUSE_CAPTURE = 0x00004000,      /**< Fenster hat die Maus gefangen */
    WINDOW_ALWAYS_ON_TOP = 0x00008000,      /**< Fenster ist immer oberhalb anderer Fenster */
    WINDOW_SKIP_TASKBAR  = 0x00010000,      /**< Fenster soll nicht an die Fensterliste (Taskbar) angeheftet werden */
    WINDOW_UTILITY       = 0x00020000,      /**< Fenster soll als "utility window" makiert werden */
    WINDOW_TOOLTIP       = 0x00040000,      /**< Fenster soll als "tooltip" makiert werden */
    WINDOW_POPUP_MENU    = 0x00080000,      /**< Fenster soll als "popup menu" makiert werden */
    WINDOW_VULKAN        = 0x10000000       /**< Fenster ist mit Vulkan nutzbar */
} WindowFlags;

#define WINDOWPOS_CENTERED_MASK    0x2FFF0000u
#define WINDOWPOS_CENTERED_DISPLAY(X)  (WINDOWPOS_CENTERED_MASK|(X))
#define _WINDOWPOS_CENTERED         WINDOWPOS_CENTERED_DISPLAY(0)
#define WINDOWPOS_ISCENTERED(X)    \
            (((X)&0xFFFF0000) == WINDOWPOS_CENTERED_MASK)

class VideoDriver {
private:
	/**
	 * Das Videosubsystem kann nur einmal gestartet werden,
	 * also machen wir ein singleton daraus
	 */
	static VideoDriver *_Instance;
	VideoDriver ( void );
	/**
 	 *  \brief Schliesst das Videosubsystem .
  	 *
 	 *  Schliesst alle Fenster.
 	 *
  	 *  \sa VideoInit()
 	 */
	~VideoDriver(void);
	
	/**
	 * true wenn das Videosubsystem Initialisiert wurde, sonst false
	 */
	bool _Init;

public:

	/**
	 * Wenn noch keines existier, wird ein Objekt der KLasse angelegt
	 * und ein Zeiger darauf zurück gegeben
	 */
	static VideoDriver *Inst( void );
	/**
 	 *  \brief Gibt die Anzahl der verfügbaren Videotreibers zurück
 	 *
  	 *  \sa getVideoDriver()
  	 */
	int getNumVideoDrivers ( void );
	
	/**
 	 *  \brief Gibt den namen des Videotreibers zurück.
 	 *
 	 *  \sa getNumVideoDrivers()
 	 */
	std::string getVideoDriver ( int index );
	
	/**
 	 *  \brief Initialisiert das Videosubsystem.
 	 *
 	 *  \param driver_name Initialisiert mit diesen Treiber, nullptr für default Treiber.
 	 *
 	 *  \return true wenn alles geklappt hat, false wenn es Fehler gab
 	 *
 	 */
	bool Init(const char *driver_name);


	/**
 	 *  \brief Erstellt ein Fenster an der angebenen stelle, mit angegebener größe und Flags.
 	 *
 	 *  \param title Der Name des Fensters, in UTF-8 encodiert.
 	 *  \param x     Die X-Position des Fensters, ::WINDOWPOS_CENTERED.
 	 *  \param y     Die Y-Position des Fensters, ::WINDOWPOS_CENTERED.
 	 *  \param w     Die Breite des Fensters.
 	 *  \param h     Die Höhe des Fensters.
 	 *  \param flags Flags für das Fenster.
 	 *
 	 *  \return Zeiger auf das erstellet Fenster, nullptr bei einem Fehler.
 	 *
	 *  \sa destroyWindow()
	 */
	rawWindow* CreateWindow( std::string title, int x, int y, int w, int h, uint32_t flags );

};

}//namespace SF

#endif //_SIMPLEFRAMEWORK_VIDEODRIVER
