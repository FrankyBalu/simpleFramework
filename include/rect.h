/*
 * rect.h
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


#ifndef _SIMPLEFRAMEWORK_RECT
#define _SIMPLEFRAMEWORK_RECT

#include "point.h"

namespace SF {


template <typename T> class Rect;
/**
 * \brief Ein rechteckiger Bereich, der den linken oberen Punkt von @Point Erbt
 */
template <>
class Rect<int> : public Point<int> {
protected:
	int _w; /**< Briete des Bereiches*/
	int _h; /**< Höhe des Bereiches*/
	
public:
	/**
	 * \brief Konstruktor, der ein leeres Rechteck mit der minimal größe 
	 * 1x1 an punkt 0,0 erstellt
	 */
	Rect ( void );
	
	/**
	 * \brief Konstruktor
	 *
	 * \param p Punkt der linken oberen Ecke
	 * \param w Breite des Bereiches
	 * \param h Höhe des Bereiches
	 */
	Rect ( Point p, int w, int h );
	
	/**
	 * \brief Konstruktor
	 *
	 * \param x X-Wert der linken oberen Ecke
	 * \param y Y-Wert der linken oberen Ecke
	 * \param w Breite des Bereiches
	 * \param h Höhe des Bereiches
	 */
	Rect ( int x, int y, int w, int h );
	
	/**
	 * \brief Destruktor
	 */
	~Rect();
	
	/**
	 * \brief Gibt die Breite zurück
	 *
	 * \return Breite des Bereiches
	 */
	int W ( void );
	/**
	 * \brief Gibt die Höhe zurück
	 *
	 * \return Höhe des Bereiches
	 */
	int H ( void );
	
	/**
	 * \brief Setzt eine neue Breite
	 *
	 * \param w Die neue Breite
	 */
	void W ( int w );
	/**
	 * \brief Setzt eine neue Höhe
	 *
	 * \param w Die neue Höhe
	 */
	void H ( int h );
	
	
	/**
	 * \brief Überprüft ob sich der angegebene Punkt im Rect befindet
	 */
	bool PointIsIn ( Point p );
	
	/**
	 * \brief Überprüft ob dieses Rect und das das als paramerer angegebene Rect
	 *			überschneiden
	 *
	 * \return true wenn es einen Schnittpunkt gibt, sonst false
	 */
	bool HasIntersection ( Rect& r );
	
	Rect &operator= ( const Rect &rhs);
	bool operator== ( const Rect& rhs);
		
};


/**
 * \brief Ein rechteckiger Bereich, der den linken oberen Punkt von @Point Erbt
 */
template <>
class Rect<float> : public Point<float> {
protected:
	float _w; /**< Briete des Bereiches*/
	float _h; /**< Höhe des Bereiches*/
	
public:
	/**
	 * \brief Konstruktor, der ein leeres Rechteck mit der minimal größe 
	 * 1x1 an punkt 0,0 erstellt
	 */
	Rect ( void );
	
	/**
	 * \brief Konstruktor
	 *
	 * \param p Punkt der linken oberen Ecke
	 * \param w Breite des Bereiches
	 * \param h Höhe des Bereiches
	 */
	Rect ( Point p, float w, float h );
	
	/**
	 * \brief Konstruktor
	 *
	 * \param x X-Wert der linken oberen Ecke
	 * \param y Y-Wert der linken oberen Ecke
	 * \param w Breite des Bereiches
	 * \param h Höhe des Bereiches
	 */
	Rect ( float x, float y, float w, float h );
	
	/**
	 * \brief Destruktor
	 */
	~Rect();
	
	/**
	 * \brief Gibt die Breite zurück
	 *
	 * \return Breite des Bereiches
	 */
	float W ( void );
	/**
	 * \brief Gibt die Höhe zurück
	 *
	 * \return Höhe des Bereiches
	 */
	float H ( void );
	
	/**
	 * \brief Setzt eine neue Breite
	 *
	 * \param w Die neue Breite
	 */
	void W ( float w );
	/**
	 * \brief Setzt eine neue Höhe
	 *
	 * \param w Die neue Höhe
	 */
	void H ( float h );
	
	
	/**
	 * \brief Überprüft ob sich der angegebene Punkt im Rect befindet
	 */
	bool PointIsIn ( Point p );
	
	/**
	 * \brief Überprüft ob dieses Rect und das das als paramerer angegebene Rect
	 *			überschneiden
	 *
	 * \return true wenn es einen Schnittpunkt gibt, sonst false
	 */
	bool HasIntersection ( Rect& r );
	
	Rect &operator= ( const Rect &rhs);
	bool operator== ( const Rect& rhs);
		
};
} //namespace SF

#endif //__SIMPLEFRAMEWORK_RECT
