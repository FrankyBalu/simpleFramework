/*
 * event.h
 * Copyright (C) 2020 Frank Kartheuser <frank.kurbatsch@gmail.com>
 *
 * simpleFramework is free software: you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * simpleFramework is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License along
 * with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef _SIMPLEFRAMEWORK_EVENT
#define _SIMPLEFRAMEWORK_EVENT

namespace SF {

#define RELEASED    0
#define PRESSED 	1

typedef enum
{
    NOEVENT     	= 0x0,	/**< Es gibt kein Event */
    QUIT           	= 0x1,	/**< Vom benutzer beendet */
    WINDOWRESIZE    = 0x2,	/**< Window state change */
    MOUSEMOTION    	= 0x4,	/**< Maus wurde bewegt */
    MOUSEBUTTONDOWN	= 0x8,  /**< Mausknopf wurde gedrückt */
    MOUSEBUTTONUP	= 0x10, /**< Mausknopf wurde losgelassen */
    FINGERDOWN      = 0x20, /**< Touchbildschirm mit Finger berüht */
    FINGERUP		= 0x40, /**< Finger hochgenommen */
    FINGERMOTION	= 0x80, /**< Finger wurde bewegt */
    LASTEVENT		= 0x100
} EventType;

typedef struct Event
{
    uint32_t	Type;		/**< Event Typ */
    uint32_t	WindowID;	/**< Fenster des Events */
	uint32_t	NewW;		/**< Neu Breite bei WINDOWRESIZE-Event */
	uint32_t	NewH;		/**< Neu Höhe bei WINDOWRESIZE-Event */
	int32_t		X;			/**< X Position bei MOUSEBUTTON/FINGER/UP/DOWN event */
	int32_t		Y;			/**< Y Position bei MOUSEBUTTON/FINGER/UP/DOWN event */
	int32_t		XRel;		/**< relative X Position bei MOUSEBUTTON/FINGER/UP/DOWN event */
	int32_t		YRel;		/**< relative Y Position bei MOUSEBUTTON/FINGER/UP/DOWN event */
	uint8_t		Clicks;		/**< anzahl der Mausklicks ( einfach, doppel u.s.w.) */
	float		x;			/**< relative X Position bei FINGER/UP/DOWN event 0...1*/
	float		y;			/**< relative Y Position bei FINGER/UP/DOWN event 0...1*/
	float		xRel;		/**< relative X Position bei FINGER/UP/DOWN event -1...-1*/
	float		yRel; 		/**< relative Y Position bei FINGER/UP/DOWN event -1...-1*/
	void		*data;
} Event;

class cEvent {
private:
	/**
     * Sicherstellen das es nur ein Low Level Event Objekt gibt
     */ 
    static cEvent *_Instance;
	cEvent ( void );
	~cEvent ( void );
		
	/**
	 * Wenn es bei Update ein neues Event gibt wird dieses hier gespeichert.
	 * Wird die Funktion Get () aufgerufen, wird dieses Event gelöscht;
	 *
	 * TODO eventuell als vector anlegen um mehrere events zu speichern?
	 */
	Event _Event;
	
	/**
	 * Intern für Maus/Finger-motion wichtig ;)
	 * 
     */
	bool _MouseButtonDown;
	bool _FingerDown;
		
public:
    /**
     * Zeiger auf das Objekt der Klasse zurückgeben
     */
	static cEvent *Inst ( void );    
	
	/**
	 * Gibt die aktuelle Event-Struktur zurück und löscht diese intern
	 */
    Event Get ( void );
    
    /**
     * Prüft ob neue Events anliegen
     * true wenn neue Events verfügbar sind, sonst false
     */
    bool Update ( void );
};


}//namespace SF

#endif //_SIMPLEFRAMEWORK_EVENT
