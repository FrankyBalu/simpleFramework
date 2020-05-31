#ifndef _SIMPLE_FRAMEWORK_POINT
#define _SIMPLE_FRAMEWORK_POINT

namespace SF
{

/**
 * @class Point
 * @author Frank Kartheuser <frank.kurbatsch@gmail.com>
 * @date 28.05.2020
 * @file point.h
 * @brief Beschreibt einen Punkt im X/Y-Koordinatensystem
 */
template <typename T>
class Point;

template<>
class Point<int> {
protected:
	int _x; /**<Punkt auf der X-Achse*/
	int _y; /**<Punkt auf der Y-Achse*/
	
public:

	/**
	 * \brief Initialisiert einen Punkt mit den Werten 0,0
	 */
	Point ( void );
	
	/**
	 * \brief Initialisiert einen Punkt mit den angegebenen Werten
	 *
	 * \param x Punkt auf der X-Achse
	 * \param y Punkt auf der Y-Achse
	 */
	Point ( int x, int y );
	 /**
	  * \brief destruktor
	  */
	~Point ( void );
	
	/**
	 * \bief Gibt den X-Wert zurück
	 *
	 * \return Den Wert von X
	 */
	int X ( void );
	
	/**
	 * \brief Gibt den Y-Wert zurück
	 *
	 * \return Den Wert von Y
	 */
	int Y ( void );
	
	/**
	 * \brief Setzt den X-Wert
	 *
	 * \param x Der neue X-Wert
	 */
	void X ( int x );
	
	/**
	 * \brief Setzt den Y-Wert
	 *
	 * \param y der neue Y-Wert
	 */
	void Y ( int y );
	
	/**
	 * \brief Ist gleich Operator
	 */
	Point &operator= ( const Point &rhs);
	
	/**
	 * \brief Vergleichs Operator, ist gleich
	 */
	bool operator==(const Point& rhs);

};

template <>
class Point<float> {
protected:
	float _x; /**<Punkt auf der X-Achse*/
	float _y; /**<Punkt auf der Y-Achse*/
	
public:

	/**
	 * \brief Initialisiert einen Punkt mit den Werten 0,0
	 */
	Point ( void );
	
	/**
	 * \brief Initialisiert einen Punkt mit den angegebenen Werten
	 *
	 * \param x Punkt auf der X-Achse
	 * \param y Punkt auf der Y-Achse
	 */
	Point ( float x, float y );
	 /**
	  * \brief destruktor
	  */
	~Point ( void );
	
	/**
	 * \bief Gibt den X-Wert zurück
	 *
	 * \return Den Wert von X
	 */
	float X ( void );
	
	/**
	 * \brief Gibt den Y-Wert zurück
	 *
	 * \return Den Wert von Y
	 */
	float Y ( void );
	
	/**
	 * \brief Setzt den X-Wert
	 *
	 * \param x Der neue X-Wert
	 */
	void X ( float x );
	
	/**
	 * \brief Setzt den Y-Wert
	 *
	 * \param y der neue Y-Wert
	 */
	void Y ( float y );
	
	/**
	 * \brief Ist gleich Operator
	 */
	Point &operator= ( const Point &rhs);
	
	/**
	 * \brief Vergleichs Operator, ist gleich
	 */
	bool operator==(const Point& rhs);

};
}

#endif // _SIMPLE_FRAMEWORK_POINT
